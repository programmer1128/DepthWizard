"""Ring geometry for depthwizard.roofgraph.v1.

Mirrors the checks in drogon_service/gis_service/BuildingReconstruction/
HybridRoofGraphImporter.cc with the same arithmetic, so Python producers and
the C++ importer accept and reject the same rings.

Coordinates are (column, row) pixel-edge values. Outer rings have positive
shoelace area on (column, row) and holes negative; with rows growing
downwards a positive ring appears clockwise on screen.
"""

from typing import Callable, List, Optional, Sequence, Tuple

Point = Tuple[float, float]
Ring = List[Point]

MIN_RING_AREA = 1.0e-9  # square pixels


def signed_area(ring: Sequence[Point]) -> float:
    twice_area = 0.0
    count = len(ring)
    for index in range(count):
        current = ring[index]
        following = ring[(index + 1) % count]
        twice_area += current[0] * following[1] - following[0] * current[1]
    return 0.5 * twice_area


def orientation(a: Point, b: Point, c: Point) -> int:
    value = (b[0] - a[0]) * (c[1] - a[1]) - (b[1] - a[1]) * (c[0] - a[0])
    return (value > 0.0) - (value < 0.0)


def on_segment(a: Point, b: Point, p: Point) -> bool:
    """p is collinear with a-b; True when it lies on the closed segment."""
    return (min(a[0], b[0]) <= p[0] <= max(a[0], b[0])
            and min(a[1], b[1]) <= p[1] <= max(a[1], b[1]))


def segments_intersect(p1: Point, p2: Point, p3: Point, p4: Point) -> bool:
    """Closed segments: touching at an endpoint or overlapping counts."""
    d1 = orientation(p3, p4, p1)
    d2 = orientation(p3, p4, p2)
    d3 = orientation(p1, p2, p3)
    d4 = orientation(p1, p2, p4)
    if d1 * d2 < 0 and d3 * d4 < 0:
        return True
    return ((d1 == 0 and on_segment(p3, p4, p1)) or (d2 == 0 and on_segment(p3, p4, p2))
            or (d3 == 0 and on_segment(p1, p2, p3)) or (d4 == 0 and on_segment(p1, p2, p4)))


# (a, b, index, ring, min_column, max_column, min_row, max_row)
_Edge = Tuple[Point, Point, int, int, float, float, float, float]


def _edges(ring: Sequence[Point], tag: int) -> List[_Edge]:
    edges = []
    for index in range(len(ring)):
        a = ring[index]
        b = ring[(index + 1) % len(ring)]
        edges.append((a, b, index, tag, min(a[0], b[0]), max(a[0], b[0]), min(a[1], b[1]), max(a[1], b[1])))
    return edges


def _any_overlapping_pair(edges: List[_Edge], visit: Callable[[_Edge, _Edge], bool]) -> bool:
    """Calls visit for edge pairs with overlapping bounding boxes, sweeping by column."""
    edges.sort(key=lambda edge: edge[4])
    for i in range(len(edges)):
        e = edges[i]
        for j in range(i + 1, len(edges)):
            f = edges[j]
            if f[4] > e[5]:
                break
            if e[7] < f[6] or f[7] < e[6]:
                continue
            if visit(e, f):
                return True
    return False


def is_simple(ring: Sequence[Point]) -> bool:
    """Non-adjacent edges never touch and adjacent edges never fold back.

    Expects no repeated consecutive vertices.
    """
    count = len(ring)

    def bad_pair(e: _Edge, f: _Edge) -> bool:
        gap = abs(e[2] - f[2])
        if gap == 1 or gap == count - 1:
            first, second = (e, f) if (e[2] + 1) % count == f[2] else (f, e)
            dot = ((first[1][0] - first[0][0]) * (second[1][0] - second[0][0])
                   + (first[1][1] - first[0][1]) * (second[1][1] - second[0][1]))
            return orientation(first[0], first[1], second[1]) == 0 and dot < 0.0
        return segments_intersect(e[0], e[1], f[0], f[1])

    return not _any_overlapping_pair(_edges(ring, 0), bad_pair)


def boundaries_touch(first: Sequence[Point], second: Sequence[Point]) -> bool:
    edges = _edges(first, 0) + _edges(second, 1)
    return _any_overlapping_pair(
        edges, lambda e, f: e[3] != f[3] and segments_intersect(e[0], e[1], f[0], f[1]))


def point_inside(ring: Sequence[Point], point: Point) -> bool:
    """Even-odd test for a point known not to lie on the ring."""
    inside = False
    j = len(ring) - 1
    for i in range(len(ring)):
        a = ring[i]
        b = ring[j]
        if (a[1] > point[1]) != (b[1] > point[1]):
            crossing = (b[0] - a[0]) * (point[1] - a[1]) / (b[1] - a[1]) + a[0]
            if point[0] < crossing:
                inside = not inside
        j = i
    return inside


def all_collinear(ring: Sequence[Point]) -> bool:
    return all(orientation(ring[0], ring[1], ring[index]) == 0 for index in range(2, len(ring)))


def ring_problem(ring: Sequence[Point]) -> Optional[Tuple[str, str]]:
    """The first contract violation of an open ring as (code, message), or None."""
    if len(ring) >= 2 and tuple(ring[0]) == tuple(ring[-1]):
        return "closing_vertex", "repeats its first vertex at the end; rings must be open"
    if any(tuple(ring[index]) == tuple(ring[index + 1]) for index in range(len(ring) - 1)):
        return "repeated_vertex", "repeats consecutive vertices"
    distinct = len({tuple(point) for point in ring})
    if distinct < 3:
        return "too_few_vertices", f"has {distinct} distinct vertices; at least 3 are required"
    # Collinearity first: a bow-tie can also have zero signed area.
    if all_collinear(ring):
        return "degenerate_ring", "has zero area"
    if not is_simple(ring):
        return "self_intersection", "is not simple (its edges cross or touch)"
    if abs(signed_area(ring)) <= MIN_RING_AREA:
        return "degenerate_ring", "has zero area"
    return None


def hole_problem(outer: Sequence[Point], holes: Sequence[Sequence[Point]]) -> Optional[Tuple[str, str]]:
    """Holes must lie strictly inside the outer ring and be pairwise disjoint."""
    for index, hole in enumerate(holes):
        valid = not boundaries_touch(outer, hole) and point_inside(outer, hole[0])
        for other in holes[:index]:
            valid = valid and not boundaries_touch(other, hole) \
                and not point_inside(other, hole[0]) and not point_inside(hole, other[0])
        if not valid:
            return "invalid_hole", (f"hole {index} must lie strictly inside its outer ring "
                                    "without touching it or another hole")
    return None
