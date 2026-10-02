"""Common geometric primitives and validation utilities for DepthWizard ML services."""

from typing import List, Tuple, Sequence
import math

Point2D = Tuple[float, float]
Ring = List[Point2D]


def signed_area(ring: Sequence[Point2D]) -> float:
    """Calculate signed area of a 2D ring using the shoelace formula.
    
    Positive area denotes Counter-Clockwise (CCW) winding in standard Cartesian
    coordinate systems (col = x, row = y).
    """
    n = len(ring)
    if n < 3:
        return 0.0
    area = 0.0
    for i in range(n):
        curr_c, curr_r = ring[i]
        next_c, next_r = ring[(i + 1) % n]
        area += curr_c * next_r - next_c * curr_r
    return 0.5 * area


def is_ccw(ring: Sequence[Point2D]) -> bool:
    """Return True if ring winding is Counter-Clockwise (positive signed area)."""
    return signed_area(ring) > 0.0


def is_cw(ring: Sequence[Point2D]) -> bool:
    """Return True if ring winding is Clockwise (negative signed area)."""
    return signed_area(ring) < 0.0


def ensure_ccw(ring: Sequence[Point2D]) -> List[Point2D]:
    """Return a ring with Counter-Clockwise winding."""
    pts = list(ring)
    if not is_ccw(pts):
        pts.reverse()
    return pts


def ensure_cw(ring: Sequence[Point2D]) -> List[Point2D]:
    """Return a ring with Clockwise winding."""
    pts = list(ring)
    if not is_cw(pts):
        pts.reverse()
    return pts


def strip_closing_vertex(ring: Sequence[Point2D], tol: float = 1e-7) -> Tuple[List[Point2D], bool]:
    """Strip redundant closing vertex if the last vertex equals the first vertex.
    
    Returns (cleaned_ring, was_stripped).
    """
    pts = [tuple(p) for p in ring]
    if len(pts) >= 2:
        c0, r0 = pts[0]
        c_last, r_last = pts[-1]
        if math.isclose(c0, c_last, abs_tol=tol) and math.isclose(r0, r_last, abs_tol=tol):
            return pts[:-1], True
    return pts, False


def remove_redundant_vertices(
    ring: Sequence[Point2D],
    dup_tol: float = 1e-6,
    collinear_tol: float = 0.02
) -> List[Point2D]:
    """Removes duplicate and collinear vertices so that edges represent actual boundaries."""
    pts = [tuple(p) for p in ring]
    changed = True
    while changed and len(pts) > 3:
        changed = False
        n = len(pts)
        for i in range(n):
            prev_p = pts[(i + n - 1) % n]
            curr_p = pts[i]
            next_p = pts[(i + 1) % n]

            in_x = curr_p[0] - prev_p[0]
            in_y = curr_p[1] - prev_p[1]
            out_x = next_p[0] - curr_p[0]
            out_y = next_p[1] - curr_p[1]

            in_len = math.hypot(in_x, in_y)
            out_len = math.hypot(out_x, out_y)

            duplicate = in_len < dup_tol
            collinear = (
                in_len > 0.0
                and out_len > 0.0
                and abs(in_x * out_y - in_y * out_x) / (in_len * out_len) < collinear_tol
                and (in_x * out_x + in_y * out_y) > 0.0
            )

            if duplicate or collinear:
                del pts[i]
                changed = True
                break
    return pts


def segments_intersect(p1: Point2D, p2: Point2D, p3: Point2D, p4: Point2D) -> bool:
    """Return True if line segment p1-p2 strictly intersects line segment p3-p4."""
    def ccw(a: Point2D, b: Point2D, c: Point2D) -> float:
        return (c[1] - a[1]) * (b[0] - a[0]) - (b[1] - a[1]) * (c[0] - a[0])

    d1 = ccw(p3, p4, p1)
    d2 = ccw(p3, p4, p2)
    d3 = ccw(p1, p2, p3)
    d4 = ccw(p1, p2, p4)

    # Check for strict intersection (crosses properly)
    if ((d1 > 1e-9 and d2 < -1e-9) or (d1 < -1e-9 and d2 > 1e-9)) and \
       ((d3 > 1e-9 and d4 < -1e-9) or (d3 < -1e-9 and d4 > 1e-9)):
        return True
    return False


def has_self_intersection(ring: Sequence[Point2D]) -> bool:
    """Return True if ring has self-intersecting non-adjacent edges."""
    n = len(ring)
    if n < 4:
        return False
    for i in range(n):
        p1 = ring[i]
        p2 = ring[(i + 1) % n]
        # Check non-adjacent edges
        for j in range(i + 2, n):
            if (i == 0 and j == n - 1):
                continue  # adjacent in cycle
            p3 = ring[j]
            p4 = ring[(j + 1) % n]
            if segments_intersect(p1, p2, p3, p4):
                return True
    return False


def centre_to_edge(ring: Sequence[Point2D]) -> List[Point2D]:
    """Convert pixel-centre coordinates to GDAL pixel-edge coordinates by adding 0.5."""
    return [(c + 0.5, r + 0.5) for c, r in ring]


def edge_to_centre(ring: Sequence[Point2D]) -> List[Point2D]:
    """Convert GDAL pixel-edge coordinates to pixel-centre coordinates by subtracting 0.5."""
    return [(c - 0.5, r - 0.5) for c, r in ring]
