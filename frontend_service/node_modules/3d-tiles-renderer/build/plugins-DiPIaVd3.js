import { A as e, M as t, N as n, b as r, c as i, p as a, v as o } from "./renderer-tyqPdeD-.js";
import { c as s, d as c, m as l, o as u, s as d } from "./renderer-3xKvdklX.js";
import { i as f, o as p, s as m, t as h } from "./plugins-BN2uUf5f.js";
import { BatchedMesh as g, Box2 as _, Box3 as v, Box3Helper as y, BoxGeometry as b, BufferAttribute as x, BufferGeometry as S, CanvasTexture as C, Color as w, CustomBlending as T, DataTexture as E, DefaultLoadingManager as D, DoubleSide as O, EventDispatcher as k, FileLoader as A, FloatType as ee, Frustum as te, GreaterDepth as ne, Group as re, LineBasicMaterial as ie, LineSegments as ae, LinearFilter as oe, LinearMipMapLinearFilter as se, MathUtils as j, Matrix2 as ce, Matrix3 as le, Matrix4 as M, Mesh as N, MeshBasicMaterial as P, MeshLambertMaterial as ue, MeshStandardMaterial as de, OneFactor as fe, PlaneGeometry as pe, Points as me, PointsMaterial as he, Quaternion as ge, REVISION as _e, RGFormat as ve, Ray as ye, Raycaster as be, RedFormat as xe, SRGBColorSpace as Se, ShaderMaterial as Ce, Source as we, Sphere as Te, SphereGeometry as Ee, Texture as De, TextureUtils as Oe, Triangle as ke, UnsignedByteType as Ae, Vector2 as F, Vector3 as I, Vector4 as je, WebGLArrayRenderTarget as Me, WebGLRenderTarget as Ne, WebGLRenderer as Pe, ZeroFactor as Fe } from "three";
import { GLTFLoader as Ie } from "three/addons/loaders/GLTFLoader.js";
import { FullScreenQuad as Le } from "three/addons/postprocessing/Pass.js";
//#region src/three/plugins/images/utils/getCartographicToMeterDerivative.js
var Re = /* @__PURE__ */ new I(), ze = /* @__PURE__ */ new I();
function Be(e, t, n) {
	let r = 1e-5, i = n + r, a = t + r;
	Math.abs(a) > Math.PI / 2 && (a -= r), e.getCartographicToPosition(t, n, 0, Re), e.getCartographicToPosition(a, n, 0, ze);
	let o = Re.distanceTo(ze) / r;
	return e.getCartographicToPosition(t, i, 0, ze), [Re.distanceTo(ze) / r, o];
}
//#endregion
//#region src/three/plugins/images/utils/ProjectionScheme.js
var L = class {
	get isMercator() {
		return this.scheme === "EPSG:3857";
	}
	get isCartographic() {
		return this.scheme !== "none";
	}
	constructor(e = "EPSG:4326") {
		this.scheme = e, this.tileCountX = 1, this.tileCountY = 1, this.setScheme(e);
	}
	setScheme(e) {
		switch (this.scheme = e, e) {
			case "CRS:84":
			case "EPSG:4326":
				this.tileCountX = 2, this.tileCountY = 1;
				break;
			case "EPSG:3857":
				this.tileCountX = 1, this.tileCountY = 1;
				break;
			case "none":
				this.tileCountX = 1, this.tileCountY = 1;
				break;
			default: throw Error(`ProjectionScheme: Unknown projection scheme "${e}"`);
		}
	}
	convertNormalizedToLatitude(e) {
		if (this.scheme === "none") return e;
		if (this.isMercator) {
			let t = j.mapLinear(e, 0, 1, -1, 1);
			return 2 * Math.atan(Math.exp(t * Math.PI)) - Math.PI / 2;
		} else return j.mapLinear(e, 0, 1, -Math.PI / 2, Math.PI / 2);
	}
	convertNormalizedToLongitude(e) {
		return this.scheme === "none" ? e : j.mapLinear(e, 0, 1, -Math.PI, Math.PI);
	}
	convertLatitudeToNormalized(e) {
		return this.scheme === "none" ? e : this.isMercator ? 1 / 2 + 1 * Math.log(Math.tan(Math.PI / 4 + e / 2)) / (2 * Math.PI) : j.mapLinear(e, -Math.PI / 2, Math.PI / 2, 0, 1);
	}
	convertLongitudeToNormalized(e) {
		return this.scheme === "none" ? e : (e + Math.PI) / (2 * Math.PI);
	}
	getLongitudeDerivativeAtNormalized(e) {
		return this.scheme === "none" ? 1 : 2 * Math.PI;
	}
	getLatitudeDerivativeAtNormalized(e) {
		if (this.scheme === "none") return 1;
		{
			let t = 1e-5, n = e - t;
			return n < 0 && (n = e + t), this.isMercator ? Math.abs(this.convertNormalizedToLatitude(e) - this.convertNormalizedToLatitude(n)) / t : Math.PI;
		}
	}
	getBounds() {
		return this.scheme === "none" ? [
			0,
			0,
			1,
			1
		] : [
			this.convertNormalizedToLongitude(0),
			this.convertNormalizedToLatitude(0),
			this.convertNormalizedToLongitude(1),
			this.convertNormalizedToLatitude(1)
		];
	}
	toNormalizedPoint(e, t) {
		let n = [e, t];
		return n[0] = this.convertLongitudeToNormalized(n[0]), n[1] = this.convertLatitudeToNormalized(n[1]), n;
	}
	toNormalizedRange(e) {
		return [...this.toNormalizedPoint(e[0], e[1]), ...this.toNormalizedPoint(e[2], e[3])];
	}
	toCartographicPoint(e, t) {
		let n = [e, t];
		return n[0] = this.convertNormalizedToLongitude(n[0]), n[1] = this.convertNormalizedToLatitude(n[1]), n;
	}
	toCartographicRange(e) {
		return [...this.toCartographicPoint(e[0], e[1]), ...this.toCartographicPoint(e[2], e[3])];
	}
	clampToBounds(e, t = !1) {
		let n = [...e], r;
		r = t ? [
			0,
			0,
			1,
			1
		] : this.getBounds();
		let [i, a, o, s] = r;
		return n[0] = j.clamp(n[0], i, o), n[2] = j.clamp(n[2], i, o), n[1] = j.clamp(n[1], a, s), n[3] = j.clamp(n[3], a, s), n;
	}
};
//#endregion
//#region src/three/plugins/images/utils/TilingScheme.js
function Ve(e, t) {
	let [n, r, i, a] = e, [o, s, c, l] = t;
	return !(n >= c || i <= o || r >= l || a <= s);
}
var He = class {
	get levelCount() {
		return this._levels.length;
	}
	get maxLevel() {
		return this.levelCount - 1;
	}
	get minLevel() {
		let e = this._levels;
		for (let t = 0; t < e.length; t++) if (e[t] !== null) return t;
		return -1;
	}
	get contentBounds() {
		return this._contentBounds ?? this.projection.getBounds();
	}
	get aspectRatio() {
		let { pixelWidth: e, pixelHeight: t } = this.getLevel(this.maxLevel);
		return e / t;
	}
	constructor() {
		this.flipY = !1, this.pixelOverlap = 0, this._contentBounds = null, this.projection = new L("none"), this._levels = [];
	}
	setLevel(e, t = {}) {
		let n = this._levels;
		for (; n.length < e;) n.push(null);
		let { tileSplitX: r = 2, tileSplitY: i = 2 } = t, { tilePixelWidth: a = 256, tilePixelHeight: o = 256, tileCountX: s = r ** e, tileCountY: c = i ** e, tileBounds: l = null } = t, { pixelWidth: u = a * s, pixelHeight: d = o * c } = t;
		n[e] = {
			tilePixelWidth: a,
			tilePixelHeight: o,
			pixelWidth: u,
			pixelHeight: d,
			tileCountX: s,
			tileCountY: c,
			tileSplitX: r,
			tileSplitY: i,
			tileBounds: l
		};
	}
	generateLevels(e, t, n, r = {}) {
		let { minLevel: i = 0, tilePixelWidth: a = 256, tilePixelHeight: o = 256 } = r, s = e - 1, { pixelWidth: c = a * t * 2 ** s, pixelHeight: l = o * n * 2 ** s } = r;
		for (let t = i; t < e; t++) {
			let n = e - t - 1, r = Math.ceil(c * 2 ** -n), i = Math.ceil(l * 2 ** -n), s = Math.ceil(r / a), u = Math.ceil(i / o);
			this.setLevel(t, {
				tilePixelWidth: a,
				tilePixelHeight: o,
				pixelWidth: r,
				pixelHeight: i,
				tileCountX: s,
				tileCountY: u
			});
		}
	}
	getLevel(e) {
		return this._levels[e];
	}
	setContentBounds(e, t, n, r) {
		this._contentBounds = [
			e,
			t,
			n,
			r
		];
	}
	setProjection(e) {
		this.projection = e;
	}
	getTileAtPoint(e, t, n, r = !1) {
		let { flipY: i } = this, { tileCountY: a, tileBounds: o, pixelHeight: s, pixelWidth: c, tilePixelHeight: l, tilePixelWidth: u } = this.getLevel(n), d = u / c, f = l / s;
		if (r || ([e, t] = this.toNormalizedPoint(e, t)), o) {
			let n = this.toNormalizedRange(o);
			e = j.mapLinear(e, n[0], n[2], 0, 1), t = j.mapLinear(t, n[1], n[3], 0, 1);
		}
		let p = Math.floor(e / d), m = Math.floor(t / f);
		return i && (m = a - 1 - m), [p, m];
	}
	getTilesInRange(e, t, n, r, i, a = !1) {
		let o = [
			e,
			t,
			n,
			r
		], s = this.getContentBounds(a), c = this.getLevel(i).tileBounds;
		if (!Ve(o, s) || c && (a && (c = this.toNormalizedRange(c)), !Ve(o, s))) return [
			0,
			0,
			-1,
			-1
		];
		let [l, u, d, f] = this.clampToContentBounds(o, a), p = this.getTileAtPoint(l, u, i, a), m = this.getTileAtPoint(d, f, i, a);
		this.flipY && ([p[1], m[1]] = [m[1], p[1]]);
		let { tileCountX: h, tileCountY: g } = this.getLevel(i), [_, v] = p, [y, b] = m;
		return y < 0 || b < 0 || _ >= h || v >= g ? [
			0,
			0,
			-1,
			-1
		] : [
			j.clamp(_, 0, h - 1),
			j.clamp(v, 0, g - 1),
			j.clamp(y, 0, h - 1),
			j.clamp(b, 0, g - 1)
		];
	}
	getTileExists(e, t, n) {
		let [r, i, a, o] = this.contentBounds, [s, c, l, u] = this.getTileBounds(e, t, n);
		return !(s >= l || c >= u) && s <= a && c <= o && l >= r && u >= i;
	}
	getContentBounds(e = !1) {
		let { projection: t } = this, n = [...this.contentBounds];
		return e && (n[0] = t.convertLongitudeToNormalized(n[0]), n[1] = t.convertLatitudeToNormalized(n[1]), n[2] = t.convertLongitudeToNormalized(n[2]), n[3] = t.convertLatitudeToNormalized(n[3])), n;
	}
	getTileContentUVBounds(e, t, n) {
		let [r, i, a, o] = this.getTileBounds(e, t, n, !0, !0), [s, c, l, u] = this.getTileBounds(e, t, n, !0, !1);
		return [
			j.mapLinear(r, s, l, 0, 1),
			j.mapLinear(i, c, u, 0, 1),
			j.mapLinear(a, s, l, 0, 1),
			j.mapLinear(o, c, u, 0, 1)
		];
	}
	getTileBounds(e, t, n, r = !1, i = !0) {
		let { flipY: a, pixelOverlap: o, projection: s } = this, { tilePixelWidth: c, tilePixelHeight: l, pixelWidth: u, pixelHeight: d, tileBounds: f } = this.getLevel(n), p = c * e - o, m = l * t - o, h = p + c + o * 2, g = m + l + o * 2;
		if (p = Math.max(p, 0), m = Math.max(m, 0), h = Math.min(h, u), g = Math.min(g, d), p /= u, h /= u, m /= d, g /= d, a) {
			let e = (g - m) / 2, t = 1 - (m + g) / 2;
			m = t - e, g = t + e;
		}
		let _ = [
			p,
			m,
			h,
			g
		];
		if (f) {
			let e = this.toNormalizedRange(f);
			_[0] = j.mapLinear(_[0], 0, 1, e[0], e[2]), _[2] = j.mapLinear(_[2], 0, 1, e[0], e[2]), _[1] = j.mapLinear(_[1], 0, 1, e[1], e[3]), _[3] = j.mapLinear(_[3], 0, 1, e[1], e[3]);
		}
		return i && (_ = this.clampToBounds(_, !0)), r || (_[0] = s.convertNormalizedToLongitude(_[0]), _[1] = s.convertNormalizedToLatitude(_[1]), _[2] = s.convertNormalizedToLongitude(_[2]), _[3] = s.convertNormalizedToLatitude(_[3])), _;
	}
	toNormalizedPoint(e, t) {
		return this.projection.toNormalizedPoint(e, t);
	}
	toNormalizedRange(e) {
		return this.projection.toNormalizedRange(e);
	}
	toCartographicPoint(e, t) {
		return this.projection.toCartographicPoint(e, t);
	}
	toCartographicRange(e) {
		return this.projection.toCartographicRange(e);
	}
	clampToContentBounds(e, t = !1) {
		let n = [...e], [r, i, a, o] = this.getContentBounds(t);
		return n[0] = j.clamp(n[0], r, a), n[1] = j.clamp(n[1], i, o), n[2] = j.clamp(n[2], r, a), n[3] = j.clamp(n[3], i, o), n;
	}
	clampToBounds(e, t = !1) {
		return this.projection.clampToBounds(e, t);
	}
}, Ue = Symbol("TILE_X"), We = Symbol("TILE_Y"), Ge = Symbol("TILE_LEVEL"), Ke = 30, qe = 15, Je = 20, Ye = Symbol("OVERLAY_RANGE"), Xe = Symbol("OVERLAY_LEVEL"), Ze = /* @__PURE__ */ new I(), Qe = /* @__PURE__ */ new I(), $e = /* @__PURE__ */ new Te(), et = class {
	constructor(e = {}) {
		let { overlay: t = null, shape: n = "ellipsoid", endCaps: r = !0, center: i = !0, useRecommendedSettings: a = !0, applyOverlayTexture: o = !1 } = e;
		this.priority = -10, this.tiles = null, this.overlay = t, this.shape = n, this.endCaps = r, this.center = i, this.useRecommendedSettings = a, this.applyOverlayTexture = o, this._tiling = null;
	}
	init(e) {
		this.useRecommendedSettings && (e.errorTarget = 1), this.tiles = e;
	}
	async loadRootTileset() {
		let { overlay: e } = this;
		return e ? (await e.init(), this._tiling = e.tiling || this._createDefaultTiling()) : this._tiling = this._createDefaultTiling(), this.getTileset();
	}
	async parseToMesh(e, t, n, r, i) {
		if (n !== "generated_surface") return null;
		let a;
		a = this._useEllipsoid() ? this._createEllipsoidMesh(t) : this._createPlanarMesh(t);
		let { overlay: o, applyOverlayTexture: s } = this;
		if (o && s) {
			let e = t[Ue], n = t[We], r = t[Ge], s = this._tiling.getTileBounds(e, n, r, !0, !1);
			if (o.hasContent(s, r)) {
				try {
					await o.lockTexture(s, r);
				} catch (e) {
					if (e.name !== "AbortError") throw e;
					return null;
				}
				let e = o.getTexture(s, r);
				if (t[Ye] = s, t[Xe] = r, i.aborted) return o.releaseTexture(s, r), delete t[Ye], delete t[Xe], null;
				a.material.map = e, a.material.needsUpdate = !0;
			}
		}
		return a;
	}
	preprocessNode(e) {
		let t = this._tiling.maxLevel;
		e[Ge] < t && e.parent !== null && this.expandChildren(e);
	}
	disposeTile(e) {
		let t = e[Ye];
		this.overlay && t && (this.overlay.releaseTexture(t, e[Xe]), delete e[Ye], delete e[Xe]);
	}
	dispose() {
		this.tiles.forEachLoadedModel((e, t) => {
			this.disposeTile(t);
		});
	}
	getCartographicFromPosition(e, t = {}) {
		let { _tiling: n } = this, { projection: r } = n;
		if (!r.isCartographic) throw Error("GeneratedSurfacePlugin: getCartographicFromPosition requires a cartographic projection.");
		if (this._useEllipsoid()) return this.tiles.ellipsoid.getPositionToCartographic(e, t);
		let { center: i } = this, a = e.x / n.aspectRatio + (i ? .5 : 0), o = e.y + (i ? .5 : 0);
		return t.lat = r.convertNormalizedToLatitude(o), t.lon = r.convertNormalizedToLongitude(a), t;
	}
	getPositionFromCartographic(e, t, n = new I()) {
		let { _tiling: r } = this, { projection: i } = r;
		if (!i.isCartographic) throw Error("GeneratedSurfacePlugin: getPositionFromCartographic requires a cartographic projection.");
		if (this._useEllipsoid()) return this.tiles.ellipsoid.getCartographicToPosition(e, t, 0, n);
		let { center: a } = this, o = i.convertLongitudeToNormalized(t), s = i.convertLatitudeToNormalized(e);
		return n.x = (o - (a ? .5 : 0)) * r.aspectRatio, n.y = s - (a ? .5 : 0), n.z = 0, n;
	}
	_useEllipsoid() {
		return this._tiling.projection.isCartographic && this.shape === "ellipsoid";
	}
	_createPlanarMesh(e) {
		let t = e[Ue], n = e[We], r = e[Ge], i = e.boundingVolume.box, a = 1, o = 1, s = 0, c = 0, l = 0;
		i && ([s, c, l] = i, a = i[3], o = i[7]);
		let u = new pe(2 * a, 2 * o), d = new N(u, new P());
		d.position.set(s, c, l);
		let f = this._tiling.getTileContentUVBounds(t, n, r), { uv: p } = u.attributes;
		for (let e = 0; e < p.count; e++) p.setXY(e, j.mapLinear(p.getX(e), 0, 1, f[0], f[2]), j.mapLinear(p.getY(e), 0, 1, f[1], f[3]));
		return d;
	}
	_createEllipsoidMesh(e) {
		let { tiles: t, endCaps: n, _tiling: r } = this, { projection: i } = r, a = e[Ge], o = e[Ue], s = e[We], [c, l, u, d] = e.boundingVolume.region, f = Math.max(qe, Math.ceil((d - l) * j.RAD2DEG * .25)), p = Math.max(Ke, Math.ceil((u - c) * j.RAD2DEG * .25)), m = p + 3, h = f + 3, g = new pe(1, 1, p + 2, f + 2), [_, v, y, b] = r.getTileBounds(o, s, a, !0, !0), x = r.getTileContentUVBounds(o, s, a), { position: S, normal: C, uv: w } = g.attributes, T = S.count;
		e.engineData.boundingVolume.getSphere($e);
		for (let r = 0; r < T; r++) {
			let a = r % m, o = Math.floor(r / m), s = a === 0 || a === m - 1 || o === 0 || o === h - 1, c = Math.max(1, Math.min(m - 2, a)), u = Math.max(1, Math.min(h - 2, o)), g = (c - 1) / p, T = 1 - (u - 1) / f, E = i.convertNormalizedToLongitude(j.mapLinear(g, 0, 1, _, y)), D = i.convertNormalizedToLatitude(j.mapLinear(T, 0, 1, v, b));
			if (i.isMercator && n && (b === 1 && T === 1 && (D = Math.PI / 2), v === 0 && T === 0 && (D = -Math.PI / 2)), i.isMercator && T !== 0 && T !== 1) {
				let e = i.convertNormalizedToLatitude(1), t = 1 / f, n = j.mapLinear(T - t, 0, 1, l, d), r = j.mapLinear(T + t, 0, 1, l, d);
				D > e && n < e && (D = e), D < -e && r > -e && (D = -e);
			}
			t.ellipsoid.getCartographicToPosition(D, E, 0, Ze).sub($e.center), t.ellipsoid.getCartographicToNormal(D, E, Qe), s && Ze.addScaledVector(Qe, -e.geometricError);
			let O = j.mapLinear(i.convertLongitudeToNormalized(E), _, y, x[0], x[2]), k = j.mapLinear(i.convertLatitudeToNormalized(D), v, b, x[1], x[3]);
			S.setXYZ(r, Ze.x, Ze.y, Ze.z), C.setXYZ(r, Qe.x, Qe.y, Qe.z), w.setXY(r, O, k);
		}
		let E = new N(g, new P());
		return E.position.copy($e.center), E;
	}
	getTileset() {
		let { tiles: e, _tiling: t } = this, n = t.minLevel, { tileCountX: r, tileCountY: i } = t.getLevel(n), a = [];
		for (let e = 0; e < r; e++) for (let t = 0; t < i; t++) {
			let r = this.createChild(e, t, n);
			r !== null && a.push(r);
		}
		let o = {
			asset: { version: "1.1" },
			geometricError: Infinity,
			root: {
				refine: "REPLACE",
				geometricError: Infinity,
				boundingVolume: this.createBoundingVolume(0, 0, -1),
				children: a,
				[Ge]: -1,
				[Ue]: 0,
				[We]: 0
			}
		};
		return e.preprocessTileset(o, ""), o;
	}
	getUrl() {
		return "tile.generated_surface";
	}
	fetchData(e) {
		if (/generated_surface/.test(e)) return /* @__PURE__ */ new ArrayBuffer();
	}
	createBoundingVolume(e, t, n, r = 0) {
		let { _tiling: i } = this, a = n === -1;
		if (this._useEllipsoid()) {
			let { endCaps: o } = this, s, c;
			return a ? (s = i.getContentBounds(!0), c = i.getContentBounds()) : (s = i.getTileBounds(e, t, n, !0, !0), c = i.getTileBounds(e, t, n, !1, !0)), o && (s[3] === 1 && (c[3] = Math.PI / 2), s[1] === 0 && (c[1] = -Math.PI / 2)), { region: [
				...c,
				-r,
				1
			] };
		} else {
			let { center: r } = this, o;
			o = a ? i.getContentBounds(!0) : i.getTileBounds(e, t, n, !0);
			let [s, c, l, u] = o, d = (l - s) / 2, f = (u - c) / 2, p = s + d, m = c + f;
			return r && (p -= .5, m -= .5), p *= i.aspectRatio, d *= i.aspectRatio, { box: [
				p,
				m,
				0,
				d,
				0,
				0,
				0,
				f,
				0,
				0,
				0,
				0
			] };
		}
	}
	createChild(e, t, n) {
		let { _tiling: r } = this, { projection: i } = r;
		if (!r.getTileExists(e, t, n)) return null;
		let a, o = this._useEllipsoid();
		if (o) {
			let [o, s, c, l] = r.getTileBounds(e, t, n, !0), { tilePixelWidth: u, tilePixelHeight: d } = r.getLevel(n), f = (c - o) / u, p = (l - s) / d, [, m, h, g] = r.getTileBounds(e, t, n), _ = m > 0 == g > 0 ? Math.min(Math.abs(m), Math.abs(g)) : 0, v = i.convertLatitudeToNormalized(_), y = i.getLongitudeDerivativeAtNormalized(o), b = i.getLatitudeDerivativeAtNormalized(v), [x, S] = Be(this.tiles.ellipsoid, _, h);
			a = Math.max(f * y * x, p * b * S);
		} else {
			let { pixelWidth: e, pixelHeight: t } = r.getLevel(n);
			a = Math.max(r.aspectRatio / e, 1 / t);
		}
		return {
			refine: "REPLACE",
			geometricError: a,
			boundingVolume: this.createBoundingVolume(e, t, n, o ? a : 0),
			content: { uri: this.getUrl(e, t, n) },
			children: [],
			[Ue]: e,
			[We]: t,
			[Ge]: n
		};
	}
	expandChildren(e) {
		let t = e[Ge], n = e[Ue], r = e[We], { tileSplitX: i, tileSplitY: a } = this._tiling.getLevel(t);
		for (let o = 0; o < i; o++) for (let s = 0; s < a; s++) {
			let c = this.createChild(i * n + o, a * r + s, t + 1);
			c && e.children.push(c);
		}
	}
	_createDefaultTiling() {
		let e = new He();
		if (this.shape === "ellipsoid") {
			let t = new L("EPSG:3857");
			e.setProjection(t), e.generateLevels(Je, t.tileCountX, t.tileCountY);
		} else {
			let t = new L("none");
			e.setProjection(t), e.generateLevels(Je, 1, 1);
		}
		return e;
	}
}, tt = class extends DOMException {
	constructor() {
		super("DataCache: Item removed", "AbortError");
	}
};
function nt(...e) {
	return e.join("_");
}
var rt = class {
	constructor() {
		this.cache = {}, this.count = 0, this.cachedBytes = 0, this.active = 0;
	}
	fetchItem(e, t) {}
	disposeItem(e, t) {}
	getMemoryUsage(e) {
		return 0;
	}
	setData(...e) {
		let { cache: t } = this, n = e.pop(), r = nt(...e);
		if (r in t) throw Error(`DataCache: "${r}" is already present.`);
		return this.cache[r] = {
			abortController: new AbortController(),
			result: n,
			count: 1,
			bytes: this.getMemoryUsage(n)
		}, this.count++, this.cachedBytes += this.cache[r].bytes, n;
	}
	lock(...e) {
		let { cache: t } = this, n = nt(...e);
		if (n in t) t[n].count++;
		else {
			let t = new AbortController(), r = {
				abortController: t,
				result: null,
				count: 1,
				bytes: 0,
				args: e
			};
			this.active++, r.result = this.fetchItem(e, t.signal), r.result instanceof Promise ? r.result = r.result.then((e) => (t.signal.throwIfAborted(), r.result = e, r.bytes = this.getMemoryUsage(e), this.cachedBytes += r.bytes, e)).finally(() => {
				this.active--;
			}) : (this.active--, r.bytes = this.getMemoryUsage(r.result), this.cachedBytes += r.bytes), this.cache[n] = r, this.count++;
		}
		return t[n].result;
	}
	release(...e) {
		let t = nt(...e);
		this.releaseViaFullKey(t);
	}
	get(...e) {
		let { cache: t } = this, n = nt(...e);
		return n in t && t[n].count > 0 ? t[n].result : null;
	}
	has(...e) {
		let { cache: t } = this;
		return nt(...e) in t;
	}
	forEachItem(e) {
		let { cache: t } = this;
		for (let n in t) {
			let r = t[n];
			r.result instanceof Promise || e(r.result, r.args);
		}
	}
	dispose() {
		let { cache: e } = this;
		for (let t in e) {
			let { abortController: n } = e[t];
			n.abort(new tt()), this.releaseViaFullKey(t, !0);
		}
		this.cache = {};
	}
	releaseViaFullKey(e, t = !1) {
		let { cache: n } = this;
		if (e in n && n[e].count > 0) {
			let r = n[e];
			if (r.count--, r.count === 0 || t) {
				let i = () => {
					if (n[e] !== r) return;
					let { result: t, abortController: i } = r;
					i.abort(new tt()), t instanceof Promise ? t.then((e) => {
						this.disposeItem(e, r.args);
					}).catch(() => {
						this.disposeItem(null, r.args);
					}).finally(() => {
						this.count--, this.cachedBytes -= r.bytes;
					}) : (this.disposeItem(t, r.args), this.count--, this.cachedBytes -= r.bytes), delete n[e];
				};
				t ? i() : queueMicrotask(() => {
					r.count === 0 && i();
				});
			}
			return !0;
		}
		throw Error("DataCache: Attempting to release key that does not exist");
	}
}, it = class extends rt {
	constructor(e = {}) {
		super();
		let { fetchOptions: t = {} } = e;
		this.tiling = new He(), this.fetchOptions = t, this.fetchData = (...e) => fetch(...e);
	}
	init() {}
	async processBufferToTexture(e) {
		let t = new Blob([e]), n = new De(await createImageBitmap(t, {
			premultiplyAlpha: "none",
			colorSpaceConversion: "none",
			imageOrientation: "flipY"
		}));
		return n.generateMipmaps = !1, n.colorSpace = Se, n.needsUpdate = !0, n;
	}
	getMemoryUsage(e) {
		let { format: t, type: n, image: r, generateMipmaps: i } = e, { width: a, height: o } = r, s = Oe.getByteLength(a, o, t, n);
		return i ? s * 4 / 3 : s;
	}
	fetchItem(e, t) {
		let n = {
			...this.fetchOptions,
			signal: t
		}, r = this.getUrl(...e);
		return this.fetchData(r, n).then((e) => e.arrayBuffer()).then((e) => this.processBufferToTexture(e));
	}
	disposeItem(e) {
		e && (e.dispose(), e.image instanceof ImageBitmap && e.image.close());
	}
	getUrl(...e) {}
}, at = class extends it {
	constructor(e = {}) {
		let { levels: t = 20, tileDimension: n = 256, projection: r = "EPSG:3857", url: i = null, ...a } = e;
		super(a), this.tileDimension = n, this.levels = t, this.projection = r, this.url = i;
	}
	getUrl(e, t, n) {
		return this.url.replace(/{\s*z\s*}/gi, n).replace(/{\s*x\s*}/gi, e).replace(/{\s*(y|reverseY|-\s*y)\s*}/gi, t);
	}
	init() {
		let { tiling: e, tileDimension: t, levels: n, url: r, projection: i } = this;
		return e.flipY = !/{\s*reverseY|-\s*y\s*}/g.test(r), e.setProjection(new L(i)), e.setContentBounds(...e.projection.getBounds()), Array.isArray(n) ? n.forEach((n, r) => {
			n !== null && e.setLevel(r, {
				tilePixelWidth: t,
				tilePixelHeight: t,
				...n
			});
		}) : e.generateLevels(n, e.projection.tileCountX, e.projection.tileCountY, {
			tilePixelWidth: t,
			tilePixelHeight: t
		}), this.url = r, Promise.resolve();
	}
}, ot = class extends at {
	constructor(e = {}) {
		let { subdomains: t = ["t0"], ...n } = e;
		super(n), this.subdomains = t, this.subDomainIndex = 0;
	}
	getUrl(e, t, n) {
		return this.url.replace(/{\s*subdomain\s*}/gi, this._getSubdomain()).replace(/{\s*quadkey\s*}/gi, this._tileToQuadKey(e, t, n));
	}
	_tileToQuadKey(e, t, n) {
		let r = "";
		for (let i = n; i > 0; i--) {
			let n = 0, a = 1 << i - 1;
			(e & a) !== 0 && (n += 1), (t & a) !== 0 && (n += 2), r += n.toString();
		}
		return r;
	}
	_getSubdomain() {
		return this.subDomainIndex = (this.subDomainIndex + 1) % this.subdomains.length, this.subdomains[this.subDomainIndex];
	}
}, st = class extends it {
	constructor(e = {}) {
		let { url: t = null, ...n } = e;
		super(n), this.tileSets = null, this.extension = null, this.url = t;
	}
	getUrl(e, t, n) {
		let { url: r, extension: i, tileSets: a, tiling: o } = this;
		return new URL(`${parseInt(a[n - o.minLevel].href)}/${e}/${t}.${i}`, r).toString();
	}
	init() {
		let { url: e } = this;
		return this.fetchData(new URL("tilemapresource.xml", e), this.fetchOptions).then((e) => e.text()).then((t) => {
			let { tiling: n } = this, r = new DOMParser().parseFromString(t, "text/xml"), i = r.querySelector("BoundingBox"), a = r.querySelector("TileFormat"), o = [...r.querySelector("TileSets").querySelectorAll("TileSet")].map((e) => ({
				href: parseInt(e.getAttribute("href")),
				unitsPerPixel: parseFloat(e.getAttribute("units-per-pixel")),
				order: parseInt(e.getAttribute("order"))
			})).sort((e, t) => e.order - t.order), s = parseFloat(i.getAttribute("minx")) * j.DEG2RAD, c = parseFloat(i.getAttribute("maxx")) * j.DEG2RAD, l = parseFloat(i.getAttribute("miny")) * j.DEG2RAD, u = parseFloat(i.getAttribute("maxy")) * j.DEG2RAD, d = parseInt(a.getAttribute("width")), f = parseInt(a.getAttribute("height")), p = a.getAttribute("extension"), m = r.querySelector("SRS").textContent;
			this.extension = p, this.url = e, this.tileSets = o, n.setProjection(new L(m)), n.setContentBounds(s, l, c, u), o.forEach(({ order: e }) => {
				n.setLevel(e, {
					tileCountX: n.projection.tileCountX * 2 ** e,
					tilePixelWidth: d,
					tilePixelHeight: f
				});
			});
		});
	}
};
//#endregion
//#region src/three/plugins/images/overlays/utils.js
function R(e, t, n, r) {
	let [i, a, o, s] = e;
	a += 1e-8, i += 1e-8, s -= 1e-8, o -= 1e-8;
	let c = Math.max(Math.min(t, n.maxLevel), n.minLevel), [l, u, d, f] = n.getTilesInRange(i, a, o, s, c, !0);
	for (let e = l; e <= d; e++) for (let t = u; t <= f; t++) r(e, t, c);
}
function ct(e, t, n) {
	let r = new I(), i = {}, a = [], o = e.getAttribute("position");
	e.computeBoundingBox(), e.boundingBox.getCenter(r).applyMatrix4(t), n.getPositionToCartographic(r, i);
	let s = i.lat || 0, c = i.lon || 0, l = Infinity, u = Infinity, d = Infinity, f = -Infinity, p = -Infinity, m = -Infinity;
	for (let e = 0; e < o.count; e++) r.fromBufferAttribute(o, e).applyMatrix4(t), n.getPositionToCartographic(r, i), Math.abs(Math.abs(i.lat) - Math.PI / 2) < 1e-5 && (i.lon = c), Math.abs(c - i.lon) > Math.PI && (i.lon += Math.sign(c - i.lon) * Math.PI * 2), Math.abs(s - i.lat) > Math.PI && (i.lat += Math.sign(s - i.lat) * Math.PI * 2), a.push(i.lon, i.lat, i.height), l = Math.min(l, i.lat), f = Math.max(f, i.lat), u = Math.min(u, i.lon), p = Math.max(p, i.lon), d = Math.min(d, i.height), m = Math.max(m, i.height);
	let h = [
		u,
		l,
		p,
		f
	];
	return {
		uv: a,
		range: h,
		region: [
			...h,
			d,
			m
		]
	};
}
function lt(e, t, n = null, r = null, i = null) {
	let a = Infinity, o = Infinity, s = Infinity, c = -Infinity, l = -Infinity, u = -Infinity, d = [], f = new M();
	if (e.forEach((e) => {
		f.copy(e.matrixWorld), n && f.premultiply(n);
		let { uv: r, region: i } = ct(e.geometry, f, t);
		d.push(r), a = Math.min(a, i[1]), c = Math.max(c, i[3]), o = Math.min(o, i[0]), l = Math.max(l, i[2]), s = Math.min(s, i[4]), u = Math.max(u, i[5]);
	}), r !== null) {
		i === null && (i = r.clampToBounds([
			o,
			a,
			l,
			c
		]), i = r.toNormalizedRange(i));
		let [e, t, n, f] = i;
		d.forEach((i) => {
			for (let a = 0, o = i.length; a < o; a += 3) {
				let o = i[a + 0], c = i[a + 1], l = i[a + 2], [d, p] = r.toNormalizedPoint(o, c);
				d = j.clamp(d, 0, 1), p = j.clamp(p, 0, 1), i[a + 0] = j.mapLinear(d, e, n, 0, 1), i[a + 1] = j.mapLinear(p, t, f, 0, 1), i[a + 2] = j.mapLinear(l, s, u, 0, 1);
			}
		});
	}
	return {
		uvs: d,
		range: i,
		region: [
			o,
			a,
			l,
			c,
			s,
			u
		]
	};
}
function ut(e, t) {
	let n = new I(), r = [], i = e.getAttribute("position"), a = Infinity, o = Infinity, s = Infinity, c = -Infinity, l = -Infinity, u = -Infinity;
	for (let e = 0; e < i.count; e++) n.fromBufferAttribute(i, e).applyMatrix4(t), r.push(n.x, n.y, n.z), a = Math.min(a, n.x), c = Math.max(c, n.x), o = Math.min(o, n.y), l = Math.max(l, n.y), s = Math.min(s, n.z), u = Math.max(u, n.z);
	return {
		uv: r,
		range: [
			a,
			o,
			c,
			l
		],
		heightRange: [s, u]
	};
}
function dt(e, t) {
	let n = Infinity, r = Infinity, i = Infinity, a = -Infinity, o = -Infinity, s = -Infinity, c = [], l = new M();
	return e.forEach((e) => {
		l.copy(e.matrixWorld), t && l.premultiply(t);
		let { uv: u, range: d, heightRange: f } = ut(e.geometry, l);
		c.push(u), n = Math.min(n, d[0]), a = Math.max(a, d[2]), r = Math.min(r, d[1]), o = Math.max(o, d[3]), i = Math.min(i, f[0]), s = Math.max(s, f[1]);
	}), c.forEach((e) => {
		for (let t = 0, i = e.length; t < i; t += 3) {
			let i = e[t + 0], s = e[t + 1];
			e[t + 0] = j.mapLinear(i, n, a, 0, 1), e[t + 1] = j.mapLinear(s, r, o, 0, 1);
		}
	}), {
		uvs: c,
		range: [
			n,
			r,
			a,
			o
		],
		heightRange: [i, s]
	};
}
//#endregion
//#region src/three/plugins/images/overlays/wrapOverlaysMaterial.js
var ft = Symbol("OVERLAY_PARAMS");
function pt(e, t) {
	if (e[ft]) return e[ft];
	let n = {
		layerMaps: { value: [] },
		layerInfo: { value: [] }
	};
	return e[ft] = n, e.defines = {
		...e.defines || {},
		LAYER_COUNT: 0
	}, e.onBeforeCompile = (e) => {
		t && t(e), e.uniforms = {
			...e.uniforms,
			...n
		}, e.vertexShader = e.vertexShader.replace(/void main\(\s*\)\s*{/, (e) => `

				#pragma unroll_loop_start
					for ( int i = 0; i < 10; i ++ ) {

						#if UNROLLED_LOOP_INDEX < LAYER_COUNT

							attribute vec3 layer_uv_UNROLLED_LOOP_INDEX;
							varying vec3 v_layer_uv_UNROLLED_LOOP_INDEX;

						#endif


					}
				#pragma unroll_loop_end

				${e}

				#pragma unroll_loop_start
					for ( int i = 0; i < 10; i ++ ) {

						#if UNROLLED_LOOP_INDEX < LAYER_COUNT

							v_layer_uv_UNROLLED_LOOP_INDEX = layer_uv_UNROLLED_LOOP_INDEX;

						#endif

					}
				#pragma unroll_loop_end

			`), e.fragmentShader = e.fragmentShader.replace(/void main\(/, (e) => `

				#if LAYER_COUNT != 0
					struct LayerInfo {
						vec3 color;
						float opacity;

						int alphaMask;
						int alphaInvert;
					};

					uniform sampler2D layerMaps[ LAYER_COUNT ];
					uniform LayerInfo layerInfo[ LAYER_COUNT ];
				#endif

				#pragma unroll_loop_start
					for ( int i = 0; i < 10; i ++ ) {

						#if UNROLLED_LOOP_INDEX < LAYER_COUNT

							varying vec3 v_layer_uv_UNROLLED_LOOP_INDEX;

						#endif

					}
				#pragma unroll_loop_end

				${e}

			`).replace(/#include <color_fragment>/, (e) => `

				${e}

				#if LAYER_COUNT != 0
				{
					vec4 tint;
					vec3 layerUV;
					float layerOpacity;
					float wOpacity;
					float wDelta;
					#pragma unroll_loop_start
						for ( int i = 0; i < 10; i ++ ) {

							#if UNROLLED_LOOP_INDEX < LAYER_COUNT

								layerUV = v_layer_uv_UNROLLED_LOOP_INDEX;
								tint = texture( layerMaps[ i ], layerUV.xy );

								// discard texture outside 0, 1 on w - offset the stepped value by an epsilon to avoid cases
								// where wDelta is near 0 (eg a flat surface) at the w boundary, resulting in artifacts on some
								// hardware.
								wDelta = max( fwidth( layerUV.z ), 1e-7 );
								wOpacity =
									smoothstep( - wDelta, 0.0, layerUV.z ) *
									smoothstep( 1.0 + wDelta, 1.0, layerUV.z );

								// apply tint & opacity
								tint.rgb *= layerInfo[ i ].color;
								tint.rgba *= layerInfo[ i ].opacity * wOpacity;

								// invert the alpha
								if ( layerInfo[ i ].alphaInvert > 0 ) {

									tint.a = 1.0 - tint.a;

								}

								// apply the alpha across all existing layers if alpha mask is true
								if ( layerInfo[ i ].alphaMask > 0 ) {

									diffuseColor.a *= tint.a;

								} else {

									tint.rgb *= tint.a;
									diffuseColor = tint + diffuseColor * ( 1.0 - tint.a );

								}

							#endif

						}
					#pragma unroll_loop_end
				}
				#endif
			`);
	}, n;
}
//#endregion
//#region src/three/plugins/utilities/GeometryClipper.js
var z = 0, mt = [
	"a",
	"b",
	"c"
], B = /* @__PURE__ */ new je(), ht = /* @__PURE__ */ new je(), gt = /* @__PURE__ */ new je(), _t = /* @__PURE__ */ new je(), vt = class {
	constructor() {
		this.attributeList = null, this.splitOperations = [], this.trianglePool = new yt();
	}
	forEachSplitPermutation(e) {
		let { splitOperations: t } = this, n = (r = 0) => {
			if (r >= t.length) {
				e();
				return;
			}
			t[r].keepPositive = !0, n(r + 1), t[r].keepPositive = !1, n(r + 1);
		};
		n();
	}
	addSplitOperation(e, t = !0) {
		this.splitOperations.push({
			callback: e,
			keepPositive: t
		});
	}
	clearSplitOperations() {
		this.splitOperations.length = 0;
	}
	clipObject(e) {
		let t = e.clone(), n = [];
		return t.traverse((e) => {
			e.isMesh && (e.geometry = this.clip(e).geometry, (e.geometry.index ? e.geometry.index.count / 3 : e.attributes.position.count / 3) == 0 && n.push(e));
		}), n.forEach((e) => {
			e.removeFromParent();
		}), t;
	}
	clip(e, t = null) {
		let n = this.getClippedData(e, t);
		return this.constructMesh(n.attributes, n.index, e);
	}
	getClippedData(e, t = null, n = {}) {
		let { trianglePool: r, splitOperations: i, attributeList: a } = this, o = e.geometry, s = o.attributes.position, c = o.index, l = 0, u = {};
		n.index = n.index || [], n.vertexIsClipped = n.vertexIsClipped || [], n.attributes = n.attributes || {};
		for (let e in o.attributes) a !== null && (a instanceof Function && !a(e) || Array.isArray(a) && !a.includes(e)) || (n.attributes[e] = []);
		let d = 0, f = c ? c.count : s.count;
		t !== null && (d = t.start, f = t.count);
		for (let t = d, n = d + f; t < n; t += 3) {
			let n = t + 0, a = t + 1, s = t + 2;
			c && (n = c.getX(n), a = c.getX(a), s = c.getX(s));
			let l = r.get();
			l.initFromIndices(n, a, s);
			let u = [l];
			for (let t = 0; t < i.length; t++) {
				let { keepPositive: n, callback: r } = i[t], a = [];
				for (let t = 0; t < u.length; t++) {
					let i = u[t], { indices: s, barycoord: c } = i;
					i.clipValues.a = r(o, s.a, s.b, s.c, c.a, e.matrixWorld), i.clipValues.b = r(o, s.a, s.b, s.c, c.b, e.matrixWorld), i.clipValues.c = r(o, s.a, s.b, s.c, c.c, e.matrixWorld), this.splitTriangle(i, !n, a);
				}
				u = a;
			}
			for (let e = 0, t = u.length; e < t; e++) {
				let t = u[e];
				p(t, o);
			}
			r.reset();
		}
		return n;
		function p(e, t) {
			for (let r = 0; r < 3; r++) {
				let i = e.getVertexHash(r, t);
				i in u || (u[i] = l, l++, e.getVertexData(r, t, n.attributes), n.vertexIsClipped.push(e.clipValues[mt[r]] === z));
				let a = u[i];
				n.index.push(a);
			}
		}
	}
	constructMesh(e, t, n) {
		let r = n.geometry, i = new S(), a = e.position.length / 3 > 65535 ? new Uint32Array(t) : new Uint16Array(t);
		i.setIndex(new x(a, 1, !1));
		for (let t in e) {
			let n = r.getAttribute(t), a = new x(new n.array.constructor(e[t]), n.itemSize, n.normalized);
			a.gpuType = n.gpuType, i.setAttribute(t, a);
		}
		let o = new N(i, n.material.clone());
		return o.position.copy(n.position), o.quaternion.copy(n.quaternion), o.scale.copy(n.scale), o;
	}
	splitTriangle(e, t, n) {
		let { trianglePool: r } = this, i = [], a = [], o = [];
		for (let t = 0; t < 3; t++) {
			let n = mt[t], r = mt[(t + 1) % 3], s = e.clipValues[n], c = e.clipValues[r];
			(s < z != c < z || s === z) && (i.push(t), a.push([n, r]), s === c ? o.push(0) : o.push(j.mapLinear(z, s, c, 0, 1)));
		}
		if (i.length !== 2) Math.min(e.clipValues.a, e.clipValues.b, e.clipValues.c) < z === t && n.push(e);
		else if (i.length === 2) {
			let s = r.get().initFromTriangle(e), c = r.get().initFromTriangle(e), l = r.get().initFromTriangle(e);
			(i[0] + 1) % 3 === i[1] ? (s.lerpVertexFromEdge(e, a[0][0], a[0][1], o[0], "a"), s.copyVertex(e, a[0][1], "b"), s.lerpVertexFromEdge(e, a[1][0], a[1][1], o[1], "c"), s.clipValues.a = z, s.clipValues.c = z, c.lerpVertexFromEdge(e, a[0][0], a[0][1], o[0], "a"), c.copyVertex(e, a[1][1], "b"), c.copyVertex(e, a[0][0], "c"), c.clipValues.a = z, l.lerpVertexFromEdge(e, a[0][0], a[0][1], o[0], "a"), l.lerpVertexFromEdge(e, a[1][0], a[1][1], o[1], "b"), l.copyVertex(e, a[1][1], "c"), l.clipValues.a = z, l.clipValues.b = z) : (s.lerpVertexFromEdge(e, a[0][0], a[0][1], o[0], "a"), s.lerpVertexFromEdge(e, a[1][0], a[1][1], o[1], "b"), s.copyVertex(e, a[0][0], "c"), s.clipValues.a = z, s.clipValues.b = z, c.lerpVertexFromEdge(e, a[0][0], a[0][1], o[0], "a"), c.copyVertex(e, a[0][1], "b"), c.lerpVertexFromEdge(e, a[1][0], a[1][1], o[1], "c"), c.clipValues.a = z, c.clipValues.c = z, l.copyVertex(e, a[0][1], "a"), l.copyVertex(e, a[1][0], "b"), l.lerpVertexFromEdge(e, a[1][0], a[1][1], o[1], "c"), l.clipValues.c = z);
			let u, d;
			u = Math.min(s.clipValues.a, s.clipValues.b, s.clipValues.c), d = u < z, d === t && n.push(s), u = Math.min(c.clipValues.a, c.clipValues.b, c.clipValues.c), d = u < z, d === t && n.push(c), u = Math.min(l.clipValues.a, l.clipValues.b, l.clipValues.c), d = u < z, d === t && n.push(l);
		}
	}
}, yt = class {
	constructor() {
		this.pool = [], this.index = 0;
	}
	get() {
		if (this.index >= this.pool.length) {
			let e = new bt();
			this.pool.push(e);
		}
		let e = this.pool[this.index];
		return this.index++, e;
	}
	reset() {
		this.index = 0;
	}
}, bt = class {
	constructor() {
		this.indices = {
			a: -1,
			b: -1,
			c: -1
		}, this.clipValues = {
			a: -1,
			b: -1,
			c: -1
		}, this.barycoord = new ke();
	}
	getVertexHash(e, t) {
		let { barycoord: n, indices: r } = this, i = n[mt[e]];
		if (i.x === 1) return r[mt[0]];
		if (i.y === 1) return r[mt[1]];
		if (i.z === 1) return r[mt[2]];
		{
			let { attributes: e } = t, n = "";
			for (let t in e) {
				let a = e[t];
				switch (xt(a, r.a, r.b, r.c, i, B), (t === "normal" || t === "tangent" || t === "bitangent") && B.normalize(), a.itemSize) {
					case 4:
						n += St(B.x, B.y, B.z, B.w);
						break;
					case 3:
						n += St(B.x, B.y, B.z);
						break;
					case 2:
						n += St(B.x, B.y);
						break;
					case 1:
						n += St(B.x);
						break;
				}
				n += "|";
			}
			return n;
		}
	}
	getVertexData(e, t, n) {
		let { barycoord: r, indices: i } = this, a = r[mt[e]], { attributes: o } = t;
		for (let e in o) {
			if (!n[e]) continue;
			let t = o[e], r = n[e];
			switch (xt(t, i.a, i.b, i.c, a, B), (e === "normal" || e === "tangent" || e === "bitangent") && B.normalize(), t.itemSize) {
				case 4:
					r.push(B.x, B.y, B.z, B.w);
					break;
				case 3:
					r.push(B.x, B.y, B.z);
					break;
				case 2:
					r.push(B.x, B.y);
					break;
				case 1:
					r.push(B.x);
					break;
			}
		}
	}
	initFromTriangle(e) {
		return this.initFromIndices(e.indices.a, e.indices.b, e.indices.c);
	}
	initFromIndices(e, t, n) {
		return this.indices.a = e, this.indices.b = t, this.indices.c = n, this.clipValues.a = -1, this.clipValues.b = -1, this.clipValues.c = -1, this.barycoord.a.set(1, 0, 0), this.barycoord.b.set(0, 1, 0), this.barycoord.c.set(0, 0, 1), this;
	}
	lerpVertexFromEdge(e, t, n, r, i) {
		this.clipValues[i] = j.lerp(e.clipValues[t], e.clipValues[n], r), this.barycoord[i].lerpVectors(e.barycoord[t], e.barycoord[n], r);
	}
	copyVertex(e, t, n) {
		this.clipValues[n] = e.clipValues[t], this.barycoord[n].copy(e.barycoord[t]);
	}
};
function xt(e, t, n, r, i, a) {
	switch (ht.fromBufferAttribute(e, t), gt.fromBufferAttribute(e, n), _t.fromBufferAttribute(e, r), a.set(0, 0, 0, 0).addScaledVector(ht, i.x).addScaledVector(gt, i.y).addScaledVector(_t, i.z), e.itemSize) {
		case 3:
			B.w = 0;
			break;
		case 2:
			B.w = 0, B.z = 0;
			break;
		case 1:
			B.w = 0, B.z = 0, B.y = 0;
			break;
	}
	return a;
}
function St(...e) {
	let t = "";
	for (let n = 0, r = e.length; n < r; n++) t += ~~(e[n] * 1e5 + .5), n !== r - 1 && (t += "_");
	return t;
}
//#endregion
//#region src/three/plugins/images/sources/WMTSImageSource.js
var Ct = class extends it {
	constructor(e = {}) {
		let { layer: t = null, tileMatrixSet: n = "default", style: r = "default", url: i = null, format: a = "image/jpeg", dimensions: o = null, tileMatrixLabels: s = null, tileMatrices: c = null, projection: l = null, levels: u = 20, tileDimension: d = 256, contentBoundingBox: f = null, ...p } = e;
		super(p), this.layer = t, this.tileMatrixSet = n, this.style = r, this.url = i, this.format = a, this.dimensions = o, this.tileMatrixLabels = s, this.tileMatrices = c, this.projection = l, this.levels = u, this.tileDimension = d, this.contentBoundingBox = f, this._useKvp = !1;
	}
	_detectRequestMode(e) {
		return !/\{/.test(e);
	}
	init() {
		let { tiling: e, tileDimension: t, levels: n, dimensions: r, contentBoundingBox: i, tileMatrices: a, style: o, tileMatrixSet: s } = this, { url: c } = this, l = this.projection || "EPSG:3857";
		if (e.flipY = !0, e.setProjection(new L(l)), i === null ? e.setContentBounds(...e.projection.getBounds()) : e.setContentBounds(i[0], i[1], i[2], i[3]), Array.isArray(a) ? a.forEach((n, r) => {
			let i = n.tileWidth || t, a = n.tileHeight || t;
			e.setLevel(r, {
				tilePixelWidth: i,
				tilePixelHeight: a,
				tileCountX: n.matrixWidth,
				tileCountY: n.matrixHeight,
				tileBounds: n.tileBounds || n.bounds
			});
		}) : e.generateLevels(n, e.projection.tileCountX, e.projection.tileCountY, {
			tilePixelWidth: t,
			tilePixelHeight: t
		}), this._useKvp = this._detectRequestMode(c), !this._useKvp && (c = c.replace(/{\s*TileMatrixSet\s*}/gi, s).replace(/{\s*Style\s*}/gi, o), r)) for (let e in r) c = c.replace(RegExp(`{\\s*${e}\\s*}`, "gi"), r[e]);
		return this.url = c, Promise.resolve();
	}
	getUrl(e, t, n) {
		let { tileMatrices: r, tileMatrixLabels: i } = this, a;
		return a = r !== null && r.length > 0 ? r[n].identifier : i ? i[n] : n.toString(), this._useKvp ? this._buildKvpUrl(e, t, a) : this._buildRestfulUrl(e, t, a);
	}
	_buildRestfulUrl(e, t, n) {
		return this.url.replace(/{\s*TileMatrix\s*}/gi, n).replace(/{\s*TileCol\s*}/gi, e).replace(/{\s*TileRow\s*}/gi, t);
	}
	_buildKvpUrl(e, t, n) {
		let { dimensions: r, format: i } = this, a = this.url, o = new URLSearchParams({
			SERVICE: "WMTS",
			VERSION: "1.0.0",
			REQUEST: "GetTile",
			LAYER: this.layer,
			STYLE: this.style,
			TILEMATRIXSET: this.tileMatrixSet,
			TILEMATRIX: n,
			TILEROW: t,
			TILECOL: e,
			FORMAT: i
		});
		if (r) for (let e in r) o.set(e, r[e]);
		return a + (a.includes("?") ? "&" : "?") + o.toString();
	}
}, wt = class {
	constructor() {
		this.canvas = null, this.context = null, this.range = [
			0,
			0,
			1,
			1
		];
	}
	setTarget(e, t) {
		this.canvas = e.image, this.context = e.image.getContext("2d"), this.range = [...t];
	}
	draw(e, t) {
		let { canvas: n, range: r, context: i } = this, { width: a, height: o } = n, { image: s } = e, c = Math.round(j.mapLinear(t[0], r[0], r[2], 0, a)), l = Math.round(j.mapLinear(t[1], r[1], r[3], 0, o)), u = Math.round(j.mapLinear(t[2], r[0], r[2], 0, a)), d = Math.round(j.mapLinear(t[3], r[1], r[3], 0, o)), f = u - c, p = d - l;
		s instanceof ImageBitmap ? (i.save(), i.translate(c, o - l), i.scale(1, -1), i.drawImage(s, 0, 0, f, p), i.restore()) : i.drawImage(s, c, o - l, f, -p);
	}
	clear() {
		let { context: e, canvas: t } = this;
		e.clearRect(0, 0, t.width, t.height);
	}
}, Tt = 1e-10;
function Et(e, t, n = 0) {
	if (e.length !== t.length) return !1;
	for (let r = 0, i = e.length; r < i; r++) if (Math.abs(e[r] - t[r]) > n) return !1;
	return !0;
}
var Dt = class extends rt {
	hasContent(...e) {
		return !0;
	}
}, Ot = class extends Dt {
	constructor(e) {
		super(), this.tiledImageSource = e, this.tileComposer = new wt(), this.resolution = 256;
	}
	hasContent(e, t, n, r, i) {
		let a = this.tiledImageSource.tiling, o = 0;
		return R([
			e,
			t,
			n,
			r
		], i, a, () => {
			o++;
		}), o !== 0;
	}
	async fetchItem([e, t, n, r, i], a) {
		let { tiledImageSource: o, tileComposer: s } = this, c = [
			e,
			t,
			n,
			r
		], l = o.tiling;
		await this._markImages(c, i, !1), a?.throwIfAborted();
		let u = null;
		if (R(c, i, l, (e, t, n) => {
			Et(l.getTileBounds(e, t, n, !0, !1), c, Tt) && (u = [
				e,
				t,
				n
			]);
		}), u !== null) {
			let [e, t, n] = u;
			return o.get(e, t, n).clone();
		}
		let d = document.createElement("canvas");
		d.width = this.resolution, d.height = this.resolution;
		let f = new C(d);
		return f.colorSpace = Se, f.generateMipmaps = !1, s.setTarget(f, c), s.clear(16777215, 0), R(c, i, l, (e, t, n) => {
			let r = l.getTileBounds(e, t, n, !0, !1), i = o.get(e, t, n);
			s.draw(i, r);
		}), f;
	}
	disposeItem(e, [t, n, r, i, a]) {
		e && e.dispose(), this._markImages([
			t,
			n,
			r,
			i
		], a, !0);
	}
	dispose() {
		super.dispose(), this.tiledImageSource.dispose();
	}
	_markImages(e, t, n = !1) {
		let r = this.tiledImageSource, i = r.tiling, a = [];
		R(e, t, i, (e, t, i) => {
			n ? r.release(e, t, i) : a.push(r.lock(e, t, i));
		});
		let o = a.filter((e) => e instanceof Promise);
		return o.length === 0 ? null : Promise.all(o);
	}
}, kt = Object.freeze({
	fill: "#cccccc",
	stroke: "transparent",
	strokeWidth: 1,
	radius: 2,
	order: 0,
	visible: !0
}), At = class {
	static get DEFAULT_STYLE() {
		return kt;
	}
	get fill() {
		return this._ctx.fillStyle;
	}
	set fill(e) {
		this._ctx.fillStyle = e;
	}
	get stroke() {
		return this._ctx.strokeStyle;
	}
	set stroke(e) {
		this._ctx.strokeStyle = e;
	}
	get strokeWidth() {
		return this._ctx.lineWidth;
	}
	set strokeWidth(e) {
		this._ctx.lineWidth = e;
	}
	constructor(e = {}) {
		let { getX: t = (e) => e.x, getY: n = (e) => e.y, flipY: r = !1, tileExtent: i = null } = e;
		this.getX = t, this.getY = n, this.flipY = r, this.tileExtent = i, this.radius = kt.radius, this.visible = !0, this._invScale = 1, this._ctx = null;
	}
	setFrame(e, t, n) {
		e.restore();
		let [r, i, a, o] = t, [s, c, l, u] = n, { width: d, height: f } = e.canvas, { flipY: p, tileExtent: m } = this, h = m ?? a - r, g = m ?? o - i, _ = Math.round(d * (r - s) / (l - s)), v = Math.round(d * (a - s) / (l - s)), y = Math.round(f * (u - o) / (u - c)), b = Math.round(f * (u - i) / (u - c)), x = (v - _) / h, S = (p ? -1 : 1) * (b - y) / g, C = m ? 0 : r, w = m ? 0 : p ? o : i, T = _ - C * x, E = y - w * S;
		e.save(), e.setTransform(x, 0, 0, S, T, E), e.beginPath(), e.rect(C, m ? 0 : i, h, g), e.clip(), e.clearRect(C, m ? 0 : i, h, g), this._ctx = e, this._invScale = 1 / x;
	}
	setStyle(e) {
		let { _invScale: t } = this;
		this.fill = e?.fill ?? kt.fill, this.stroke = e?.stroke ?? kt.stroke, this.strokeWidth = (e?.strokeWidth ?? kt.strokeWidth) * t, this.radius = (e?.radius ?? kt.radius) * t, this.visible = e ? e?.visible ?? kt.visible : !1;
	}
	_renderPoints(e, t = 1) {
		let { _ctx: n, radius: r, getX: i, getY: a, visible: o } = this;
		if (o) {
			for (let o of e) for (let e of o) {
				let o = i(e), s = a(e);
				n.beginPath(), n.ellipse(o, s, r / t, r, 0, 0, Math.PI * 2), n.fill();
			}
			n.stroke();
		}
	}
	_renderLines(e) {
		let { _ctx: t, getX: n, getY: r, visible: i } = this;
		if (i) {
			if (e instanceof Path2D) {
				t.stroke(e);
				return;
			}
			t.beginPath();
			for (let i of e) for (let e = 0; e < i.length; e++) e === 0 ? t.moveTo(n(i[e]), r(i[e])) : t.lineTo(n(i[e]), r(i[e]));
			t.stroke();
		}
	}
	_renderPolygons(e) {
		let { _ctx: t, getX: n, getY: r, visible: i } = this;
		if (i) {
			if (e instanceof Path2D) {
				t.fill(e, "evenodd"), t.stroke(e);
				return;
			}
			t.beginPath();
			for (let i of e) {
				for (let e = 0; e < i.length; e++) e === 0 ? t.moveTo(n(i[e]), r(i[e])) : t.lineTo(n(i[e]), r(i[e]));
				t.closePath();
			}
			t.fill("evenodd"), t.stroke();
		}
	}
}, jt = new Set([
	"Point",
	"MultiPoint",
	"LineString",
	"MultiLineString",
	"Polygon",
	"MultiPolygon"
]), Mt = /* @__PURE__ */ new I(), Nt = /* @__PURE__ */ new I();
function Pt(e, t, n) {
	let r = .01;
	e.getCartographicToPosition(t, n, 0, Mt), e.getCartographicToPosition(t + r, n, 0, Nt);
	let i = Mt.distanceTo(Nt);
	return e.getCartographicToPosition(t, n + r, 0, Nt), Mt.distanceTo(Nt) / i;
}
var Ft = class extends Dt {
	constructor({ geojson: e = null, url: t = null, resolution: n = 256, pointRadius: r = 6, strokeStyle: i = "white", strokeWidth: a = 2, fillStyle: o = "rgba( 255, 255, 255, 0.5 )", getStyle: s = ((e, t) => ({
		fill: t.fillStyle || this.fillStyle,
		stroke: t.strokeStyle || this.strokeStyle,
		strokeWidth: t.strokeWidth || this.strokeWidth,
		radius: t.pointRadius || this.pointRadius
	})), ...c } = {}) {
		super(c), this.geojson = e, this.url = t, this.resolution = n, this.pointRadius = r, this.strokeStyle = i, this.strokeWidth = a, this.fillStyle = o, this.getStyle = s, this.features = null, this.featureBounds = /* @__PURE__ */ new Map(), this.contentBounds = null, this.projection = new L(), this.fetchData = (...e) => fetch(...e), this._canvasRenderer = new At({
			flipY: !0,
			getX: (e) => e[0],
			getY: (e) => e[1]
		});
	}
	async init() {
		let { geojson: e, url: t } = this;
		if (!e && t) {
			let e = await this.fetchData(t);
			this.geojson = await e.json();
		}
		this._updateCache(!0);
	}
	hasContent(e, t, n, r) {
		let { projection: i } = this, a = [
			i.convertNormalizedToLongitude(e) * j.RAD2DEG,
			i.convertNormalizedToLatitude(t) * j.RAD2DEG,
			i.convertNormalizedToLongitude(n) * j.RAD2DEG,
			i.convertNormalizedToLatitude(r) * j.RAD2DEG
		];
		return this._boundsIntersectBounds(a, this.contentBounds);
	}
	fetchItem(e, t) {
		let n = document.createElement("canvas"), r = new C(n);
		return r.colorSpace = Se, r.generateMipmaps = !1, this._drawToCanvas(n, e), r.needsUpdate = !0, r;
	}
	disposeItem(e) {
		e && e.dispose();
	}
	redraw(...e) {
		let t = this.get(...e);
		t && (this._drawToCanvas(t.image, e), t.needsUpdate = !0);
	}
	_updateCache(e = !1) {
		let { geojson: t, featureBounds: n } = this;
		if (!t || this.features && !e) return;
		n.clear();
		let r = Infinity, i = Infinity, a = -Infinity, o = -Infinity;
		this.features = this._featuresFromGeoJSON(t);
		for (let e of this.features) {
			let t = this._getFeatureBounds(e);
			n.set(e, t);
			let [s, c, l, u] = t;
			r = Math.min(r, s), i = Math.min(i, c), a = Math.max(a, l), o = Math.max(o, u);
		}
		this.contentBounds = [
			r,
			i,
			a,
			o
		];
	}
	_drawToCanvas(e, t) {
		this._updateCache();
		let [n, r, i, a] = t, { projection: o, resolution: s, features: c, _canvasRenderer: l } = this;
		e.width = s, e.height = s;
		let u = o.convertNormalizedToLongitude(n), d = o.convertNormalizedToLatitude(r), f = o.convertNormalizedToLongitude(i), p = o.convertNormalizedToLatitude(a), m = [
			u * j.RAD2DEG,
			d * j.RAD2DEG,
			f * j.RAD2DEG,
			p * j.RAD2DEG
		], h = e.getContext("2d");
		l.setFrame(h, m, m);
		for (let e of c) this._featureIntersectsTile(e, m) && this._drawFeatureOnCanvas(e, m, s);
	}
	_featureIntersectsTile(e, t) {
		let n = this.featureBounds.get(e);
		return n ? this._boundsIntersectBounds(n, t) : !1;
	}
	_boundsIntersectBounds(e, t) {
		let [n, r, i, a] = e, [o, s, c, l] = t;
		return !(i < o || n > c || a < s || r > l);
	}
	_getFeatureBounds(e) {
		let { geometry: t } = e;
		if (!t) return null;
		let { type: n, coordinates: r } = t, i = Infinity, a = Infinity, o = -Infinity, s = -Infinity, c = (e, t) => {
			i = Math.min(i, e), o = Math.max(o, e), a = Math.min(a, t), s = Math.max(s, t);
		};
		return n === "Point" ? c(r[0], r[1]) : n === "MultiPoint" || n === "LineString" ? r.forEach((e) => c(e[0], e[1])) : n === "MultiLineString" || n === "Polygon" ? r.forEach((e) => e.forEach((e) => c(e[0], e[1]))) : n === "MultiPolygon" && r.forEach((e) => e.forEach((e) => e.forEach((e) => c(e[0], e[1])))), [
			i,
			a,
			o,
			s
		];
	}
	_featuresFromGeoJSON(e) {
		let t = e.type;
		return t === "FeatureCollection" ? e.features : t === "Feature" ? [e] : t === "GeometryCollection" ? e.geometries.map((e) => ({
			type: "Feature",
			geometry: e,
			properties: {}
		})) : jt.has(t) ? [{
			type: "Feature",
			geometry: e,
			properties: {}
		}] : [];
	}
	_drawFeatureOnCanvas(e, t, n) {
		let { geometry: r = null, properties: i = {} } = e;
		if (!r) return;
		let [, a, , o] = t, { _canvasRenderer: s } = this, l = this.getStyle(e, i);
		s.setStyle(l);
		let u = r.type;
		if (u === "Point" || u === "MultiPoint") {
			s.radius = l.radius * (o - a) / n;
			let e = u === "Point" ? [r.coordinates] : r.coordinates;
			for (let t of e) {
				let e = Pt(c, t[1] * j.DEG2RAD, t[0] * j.DEG2RAD), n = [t];
				s._renderPoints([n], e);
			}
		} else u === "LineString" ? s._renderLines([r.coordinates]) : u === "MultiLineString" ? s._renderLines(r.coordinates) : u === "Polygon" ? s._renderPolygons(r.coordinates) : u === "MultiPolygon" && r.coordinates.forEach((e) => s._renderPolygons(e));
	}
}, It = class extends it {
	constructor(e = {}) {
		let { url: t = null, layer: n = null, styles: r = null, contentBoundingBox: i = null, version: a = "1.3.0", crs: o = "EPSG:4326", format: s = "image/png", transparent: c = !1, levels: l = 18, tileDimension: u = 256, ...d } = e;
		super(d), this.url = t, this.layer = n, this.crs = o, this.format = s, this.tileDimension = u, this.styles = r, this.version = a, this.levels = l, this.transparent = c, this.contentBoundingBox = i;
	}
	init() {
		let { tiling: e, levels: t, tileDimension: n, contentBoundingBox: r } = this;
		return e.setProjection(new L(this.crs)), e.flipY = !0, e.generateLevels(t, e.projection.tileCountX, e.projection.tileCountY, {
			tilePixelWidth: n,
			tilePixelHeight: n
		}), r === null ? e.setContentBounds(...e.projection.getBounds()) : e.setContentBounds(...r), Promise.resolve();
	}
	normalizedToMercatorX(e) {
		return j.mapLinear(e, 0, 1, -20037508.342789244, 20037508.342789244);
	}
	normalizedToMercatorY(e) {
		return j.mapLinear(e, 0, 1, -20037508.342789244, 20037508.342789244);
	}
	getUrl(e, t, n) {
		let { tiling: r, layer: i, crs: a, format: o, tileDimension: s, styles: c, version: l, transparent: u } = this, d = l === "1.1.1" ? "SRS" : "CRS", f;
		if (a === "EPSG:3857") {
			let i = r.getTileBounds(e, t, n, !0, !1);
			f = [
				this.normalizedToMercatorX(i[0]),
				this.normalizedToMercatorY(i[1]),
				this.normalizedToMercatorX(i[2]),
				this.normalizedToMercatorY(i[3])
			];
		} else {
			let [i, o, s, c] = r.getTileBounds(e, t, n, !1, !1).map((e) => e * j.RAD2DEG);
			f = a === "EPSG:4326" ? l === "1.1.1" ? [
				i,
				o,
				s,
				c
			] : [
				o,
				i,
				c,
				s
			] : [
				i,
				o,
				s,
				c
			];
		}
		let p = new URLSearchParams({
			SERVICE: "WMS",
			REQUEST: "GetMap",
			VERSION: l,
			LAYERS: i,
			[d]: a,
			BBOX: f.join(","),
			WIDTH: s,
			HEIGHT: s,
			FORMAT: o,
			TRANSPARENT: u ? "TRUE" : "FALSE"
		});
		return c != null && p.set("STYLES", c), new URL("?" + p.toString(), this.url).toString();
	}
}, Lt = class extends it {
	constructor(e = {}) {
		let { url: t = null, ...n } = e;
		super(n), this.url = t, this.format = null, this.stem = null;
	}
	getUrl(e, t, n) {
		return `${this.stem}_files/${n}/${e}_${t}.${this.format}`;
	}
	init() {
		let { url: e } = this;
		return this.fetchData(e, this.fetchOptions).then((e) => e.text()).then((t) => {
			let n = new DOMParser().parseFromString(t, "text/xml");
			if (n.querySelector("DisplayRects") || n.querySelector("Collection")) throw Error("DeepZoomImagesPlugin: DisplayRect and Collection DZI files not supported.");
			let r = n.querySelector("Image"), i = r.querySelector("Size"), a = parseInt(i.getAttribute("Width")), o = parseInt(i.getAttribute("Height")), s = parseInt(r.getAttribute("TileSize")), c = parseInt(r.getAttribute("Overlap")), l = r.getAttribute("Format");
			this.format = l, this.stem = e.split(/\.[^.]+$/g)[0];
			let { tiling: u } = this, d = Math.ceil(Math.log2(Math.max(a, o))) + 1;
			u.flipY = !0, u.pixelOverlap = c, u.generateLevels(d, 1, 1, {
				tilePixelWidth: s,
				tilePixelHeight: s,
				pixelWidth: a,
				pixelHeight: o
			});
		});
	}
}, Rt = /* @__PURE__ */ new M(), zt = /* @__PURE__ */ new I(), Bt = /* @__PURE__ */ new I(), Vt = /* @__PURE__ */ new I(), V = /* @__PURE__ */ new I(), Ht = /* @__PURE__ */ new v(), Ut = Symbol("SPLIT_TILE_DATA"), Wt = Symbol("SPLIT_HASH"), Gt = Symbol("ORIGINAL_REFINE"), Kt = /* @__PURE__ */ new t();
Kt.maxJobs = 10, Kt.priorityCallback = (e, t) => {
	let n = e.tile, r = t.tile, i = n.internal.renderer, a = r.internal.renderer, s = i.visibleTiles.has(n);
	return s === a.visibleTiles.has(r) ? o(n, r) : s ? 1 : -1;
};
var qt = class {
	get enableTileSplitting() {
		return this._enableTileSplitting;
	}
	set enableTileSplitting(e) {
		this._enableTileSplitting !== e && (this._enableTileSplitting = e, this._markNeedsUpdate());
	}
	constructor(e = {}) {
		let { overlays: t = [], resolution: n = 256, enableTileSplitting: r = !0 } = e;
		this.name = "IMAGE_OVERLAY_PLUGIN", this.priority = -15, this.resolution = n, this._enableTileSplitting = r, this.overlays = [], this.needsUpdate = !1, this.tiles = null, this.tileComposer = null, this.tileControllers = /* @__PURE__ */ new Map(), this.overlayInfo = /* @__PURE__ */ new Map(), this.meshParams = /* @__PURE__ */ new WeakMap(), this.pendingTiles = /* @__PURE__ */ new Map(), this.processedTiles = /* @__PURE__ */ new Set(), this.processQueue = null, this._onUpdateAfter = null, this._onTileDownloadStart = null, this._onTileVisibilityChange = null, this._virtualChildResetId = 0, this._bytesUsed = /* @__PURE__ */ new WeakMap(), t.forEach((e) => {
			this.addOverlay(e);
		});
	}
	init(e) {
		let t = new wt();
		this.tiles = e, this.tileComposer = t, this.processQueue = Kt, e.forEachLoadedModel((e, t) => {
			this._processTileModel(e, t, !0);
		}), this._onUpdateAfter = async () => {
			let t = !1;
			if (this.overlayInfo.forEach((e, n) => {
				if (!!n.frame != !!e.frame || n.frame && e.frame && !e.frame.equals(n.frame)) {
					let r = e.order;
					this.deleteOverlay(n), this.addOverlay(n, r), t = !0;
				}
			}), t) {
				let { processQueue: t } = this, n = t.maxJobs, r = 0;
				t.items.forEach((t) => {
					e.visibleTiles.has(t.tile) && r++;
				}), t.maxJobs = r + t.currJobs, t.tryRunJobs(), t.maxJobs = n, this.needsUpdate = !0;
			}
			if (this.needsUpdate) {
				this.needsUpdate = !1;
				let { overlays: t, overlayInfo: n } = this;
				t.sort((e, t) => n.get(e).order - n.get(t).order), this.processedTiles.forEach((e) => {
					this._updateLayers(e);
				}), this.resetVirtualChildren(!this.enableTileSplitting), e.recalculateBytesUsed(), e.dispatchEvent({ type: "needs-render" });
			}
		}, this._onTileDownloadStart = ({ tile: e, url: t }) => {
			!/\.json$/i.test(t) && !/\.subtree/i.test(t) && (this.processedTiles.add(e), this._initTileOverlayInfo(e));
		}, this._onTileVisibilityChange = ({ tile: e, visible: t }) => {
			this.overlayInfo.forEach(({ tileInfo: n }, r) => {
				if (n.has(e)) {
					let { range: i } = n.get(e);
					r.setRegionVisible(i, t, e);
				}
			});
		}, e.addEventListener("update-after", this._onUpdateAfter), e.addEventListener("tile-download-start", this._onTileDownloadStart), e.addEventListener("tile-visibility-change", this._onTileVisibilityChange), this.overlays.forEach((e) => {
			this._initOverlay(e);
		});
	}
	_removeVirtualChildren(e) {
		if (!(Gt in e)) return;
		let { tiles: t } = this, { virtualChildCount: n } = e.internal, r = e.children.length, i = r - n;
		for (let n = i; n < r; n++) {
			let r = e.children[n];
			t.processNodeQueue.remove(r), t.lruCache.remove(r), r.parent = null;
		}
		e.children.length -= n, e.internal.virtualChildCount = 0, e.refine = e[Gt], delete e[Gt], delete e[Wt];
	}
	disposeTile(e) {
		let { overlayInfo: t, tileControllers: n, processQueue: r, pendingTiles: i, processedTiles: a } = this;
		a.delete(e), this._removeVirtualChildren(e), n.has(e) && (n.get(e).abort(), n.delete(e), i.delete(e)), t.forEach((({ tileInfo: t }, n) => {
			if (t.has(e)) {
				let { meshInfo: r, range: i } = t.get(e);
				i !== null && n.releaseTexture(i), t.delete(e), r.clear();
			}
		})), r.removeByFilter((t) => t.tile === e);
	}
	calculateBytesUsed(e) {
		let { overlayInfo: t } = this, n = this._bytesUsed, r = null;
		return t.forEach(({ tileInfo: t }, n) => {
			if (t.has(e)) {
				let { target: n } = t.get(e);
				r ||= 0, r += u(n);
			}
		}), r === null ? n.has(e) ? n.get(e) : 0 : (n.set(e, r), r);
	}
	processTileModel(e, t) {
		return this._processTileModel(e, t);
	}
	async _processTileModel(e, t, n = !1) {
		let { tileControllers: r, processedTiles: i, pendingTiles: a } = this;
		r.set(t, new AbortController()), n || a.set(t, e), i.add(t), this._wrapMaterials(e), this._initTileOverlayInfo(t), await this._initTileSceneOverlayInfo(e, t), this.expandVirtualChildren(e, t), this._updateLayers(t), a.delete(t);
	}
	dispose() {
		let { tiles: e } = this;
		[...this.overlays].forEach((e) => {
			this.deleteOverlay(e);
		}), this.processedTiles.forEach((e) => {
			this._updateLayers(e), this.disposeTile(e);
		}), e.removeEventListener("update-after", this._onUpdateAfter), e.removeEventListener("tile-download-start", this._onTileDownloadStart), e.removeEventListener("tile-visibility-change", this._onTileVisibilityChange), this.resetVirtualChildren(!0);
	}
	getAttributions(e) {
		this.overlays.forEach((t) => {
			t.opacity > 0 && t.getAttributions(e);
		});
	}
	parseToMesh(e, t, n, r) {
		if (n === "image_overlay_tile_split") return t[Ut];
	}
	async resetVirtualChildren(e = !1) {
		this._virtualChildResetId++;
		let t = this._virtualChildResetId;
		if (await Promise.all(this.overlays.map((e) => e.whenReady())), t !== this._virtualChildResetId) return;
		let { tiles: n } = this, r = [];
		this.processedTiles.forEach((e) => {
			Wt in e && r.push(e);
		}), r.sort((e, t) => t.internal.depth - e.internal.depth), r.forEach((t) => {
			let n = t.engineData.scene.clone();
			n.updateMatrixWorld(), (e || t[Wt] !== this._getSplitVectors(n, t).hash) && this._removeVirtualChildren(t);
		}), e || n.forEachLoadedModel((e, t) => {
			this.expandVirtualChildren(e, t);
		});
	}
	_getSplitVectors(e, t, n = Bt) {
		let { tiles: r, overlayInfo: i } = this, a = new v();
		a.setFromObject(e), a.getCenter(n);
		let o = [], s = [];
		i.forEach(({ tileInfo: e }, i) => {
			let a = e.get(t);
			if (a && a.target && i.shouldSplit(a.range)) {
				i.frame ? V.set(0, 0, 1).transformDirection(i.frame) : (r.ellipsoid.getPositionToNormal(n, V), V.length() < 1e-6 && V.set(1, 0, 0));
				let e = `${V.x.toFixed(3)},${V.y.toFixed(3)},${V.z.toFixed(3)}_`;
				s.includes(e) || s.push(e);
				let t = zt.set(0, 0, 1);
				Math.abs(V.dot(t)) > .9999 && t.set(1, 0, 0);
				let a = new I().crossVectors(V, t).normalize(), c = new I().crossVectors(V, a).normalize();
				o.push(a, c);
			}
		});
		let c = [];
		for (; o.length !== 0;) {
			let e = o.pop().clone(), t = e.clone();
			for (let n = 0; n < o.length; n++) {
				let r = o[n], i = e.dot(r);
				Math.abs(i) > Math.cos(Math.PI / 8) && (t.addScaledVector(r, Math.sign(i)), e.copy(t).normalize(), o.splice(n, 1), n--);
			}
			c.push(t.normalize());
		}
		return {
			directions: c,
			hash: s.join("")
		};
	}
	async expandVirtualChildren(e, t) {
		let { refine: n } = t, r = n === "REPLACE" && t.children.length === 0 || n === "ADD", i = t.internal.virtualChildCount !== 0;
		if (this.enableTileSplitting === !1 || !r || i) return;
		let a = e.clone();
		a.updateMatrixWorld();
		let { directions: o, hash: s } = this._getSplitVectors(a, t, Bt);
		if (o.length === 0) return;
		t[Wt] = s;
		let c = new vt();
		c.attributeList = (e) => !/^layer_uv_\d+/.test(e), o.map((e) => {
			c.addSplitOperation((t, n, r, i, a, o) => (ke.getInterpolatedAttribute(t.attributes.position, n, r, i, a, zt), zt.applyMatrix4(o).sub(Bt).dot(e)));
		});
		let l = [];
		c.forEachSplitPermutation(() => {
			let e = c.clipObject(a);
			e.matrix.premultiply(t.engineData.transformInverse).decompose(e.position, e.quaternion, e.scale);
			let n = [];
			if (e.traverse((e) => {
				if (e.isMesh) {
					let t = e.material.clone();
					e.material = t;
					for (let e in t) {
						let n = t[e];
						if (n && n.isTexture && n.source.data instanceof ImageBitmap) {
							let r = document.createElement("canvas");
							r.width = n.image.width, r.height = n.image.height;
							let i = r.getContext("2d");
							i.scale(1, -1), i.drawImage(n.source.data, 0, 0, r.width, -r.height);
							let a = new C(r);
							a.mapping = n.mapping, a.wrapS = n.wrapS, a.wrapT = n.wrapT, a.minFilter = n.minFilter, a.magFilter = n.magFilter, a.format = n.format, a.type = n.type, a.anisotropy = n.anisotropy, a.colorSpace = n.colorSpace, a.generateMipmaps = n.generateMipmaps, t[e] = a;
						}
					}
					n.push(e);
				}
			}), n.length === 0) return;
			let r = {};
			if (t.boundingVolume.region && (r.region = lt(n, this.tiles.ellipsoid).region), t.boundingVolume.box || t.boundingVolume.sphere) {
				Ht.setFromObject(e, !0).getCenter(Vt);
				let t = 0;
				e.traverse((e) => {
					let n = e.geometry;
					if (n) {
						let r = n.attributes.position;
						for (let n = 0, i = r.count; n < i; n++) {
							let i = zt.fromBufferAttribute(r, n).applyMatrix4(e.matrixWorld).distanceToSquared(Vt);
							t = Math.max(t, i);
						}
					}
				}), r.sphere = [...Vt, Math.sqrt(t)];
			}
			l.push({
				internal: { isVirtual: !0 },
				refine: "REPLACE",
				geometricError: t.geometricError * .5,
				boundingVolume: r,
				content: { uri: "./child.image_overlay_tile_split" },
				children: [],
				[Ut]: e
			});
		}), t[Gt] = t.refine, t.refine = "REPLACE", t.children.push(...l), t.internal.virtualChildCount += l.length;
	}
	fetchData(e, t) {
		if (/image_overlay_tile_split/.test(e)) return /* @__PURE__ */ new ArrayBuffer();
	}
	addOverlay(e, t = null) {
		let { tiles: n, overlays: r, overlayInfo: i } = this;
		t === null && (t = r.reduce((e, t) => Math.max(e, t.order + 1), 0));
		let a = new AbortController();
		r.push(e), i.set(e, {
			order: t,
			uniforms: {},
			tileInfo: /* @__PURE__ */ new Map(),
			controller: a,
			frame: e.frame ? e.frame.clone() : null
		}), n !== null && this._initOverlay(e);
	}
	setOverlayOrder(e, t) {
		this.overlays.indexOf(e) !== -1 && (this.overlayInfo.get(e).order = t, this._markNeedsUpdate());
	}
	deleteOverlay(e) {
		let { overlays: t, overlayInfo: n, processQueue: r, processedTiles: i, tiles: a } = this, o = t.indexOf(e);
		if (o !== -1) {
			let { tileInfo: s, controller: c } = n.get(e);
			i.forEach((t) => {
				if (!s.has(t)) return;
				let { meshInfo: n, range: r } = s.get(t);
				r !== null && (a.visibleTiles.has(t) && e.setRegionVisible(r, !1), e.releaseTexture(r)), s.delete(t), n.clear();
			}), s.clear(), n.delete(e), c.abort(), r.removeByFilter((t) => t.overlay === e && i.has(t.tile)), t.splice(o, 1), i.forEach((e) => {
				this._updateLayers(e);
			}), this._markNeedsUpdate();
		}
	}
	_initOverlay(e) {
		let { processedTiles: t } = this;
		e.init().then(() => {
			e.setResolution(this.resolution);
		});
		let n = [];
		t.forEach(async (t) => {
			let r = t.engineData.scene;
			this._initTileOverlayInfo(t, e);
			let i = this._initTileSceneOverlayInfo(r, t, e);
			n.push(i), await i, this._updateLayers(t);
		}), Promise.all(n).then(() => {
			this._markNeedsUpdate();
		});
	}
	_wrapMaterials(e) {
		e.traverse((e) => {
			if (e.material) {
				let t = pt(e.material, e.material.onBeforeCompile);
				this.meshParams.set(e, t);
			}
		});
	}
	_initTileOverlayInfo(e, t = this.overlays) {
		if (Array.isArray(t)) {
			t.forEach((t) => this._initTileOverlayInfo(e, t));
			return;
		}
		let { overlayInfo: n } = this;
		if (n.get(t).tileInfo.has(e)) return;
		let r = {
			range: null,
			target: null,
			meshInfo: /* @__PURE__ */ new Map(),
			failed: !1
		};
		if (n.get(t).tileInfo.set(e, r), t.isReady && !t.isPlanarProjection && e.boundingVolume.region) {
			let [n, i, a, o] = e.boundingVolume.region, s = [
				n,
				i,
				a,
				o
			];
			s = t.projection.clampToBounds(s), s = t.projection.toNormalizedRange(s), r.range = s, t.lockTextureSafe(s);
		}
	}
	async _initTileSceneOverlayInfo(e, t, n = this.overlays) {
		if (Array.isArray(n)) return Promise.all(n.map((n) => this._initTileSceneOverlayInfo(e, t, n)));
		let { tiles: r, overlayInfo: i, tileControllers: a } = this, { ellipsoid: o } = r, { controller: s, tileInfo: c } = i.get(n), l = a.get(t);
		if (n.isReady || await n.whenReady(), s.signal.aborted || l.signal.aborted) return;
		let u = [];
		e.updateMatrixWorld(), e.traverse((e) => {
			e.isMesh && u.push(e);
		});
		let { aspectRatio: d, projection: f } = n, p = c.get(t), m, h, g;
		if (n.isPlanarProjection) {
			Rt.makeScale(1 / d, 1, 1).multiply(n.frame), e.parent !== null && Rt.multiply(r.group.matrixWorldInverse);
			let t;
			({range: m, uvs: h, heightRange: t} = dt(u, Rt)), g = !(t[0] > 1 || t[1] < 0);
		} else Rt.identity(), e.parent !== null && Rt.copy(r.group.matrixWorldInverse), {range: m, uvs: h} = lt(u, o, Rt, f, p.range), g = !0;
		p.range === null && (p.range = m, n.lockTextureSafe(m)), r.visibleTiles.has(t) && n.setRegionVisible(p.range, !0), g && n.hasContent(m) && await this._fetchTileOverlayTexture(t, n, p), u.forEach((e, t) => {
			let n = new x(new Float32Array(h[t]), 3);
			p.meshInfo.set(e, { attribute: n });
		});
	}
	async _fetchTileOverlayTexture(e, t, n) {
		let { tiles: r, overlayInfo: i, tileControllers: a, processQueue: o } = this, { controller: s } = i.get(t), c = a.get(e), { range: l } = n;
		n.target = await o.add({
			tile: e,
			overlay: t
		}, async () => {
			if (s.signal.aborted || c.signal.aborted) return null;
			let e = await t.getTexture(l);
			return s.signal.aborted || c.signal.aborted ? null : e;
		}).catch((i) => i.name === "AbortError" ? null : (n.failed = !0, r.dispatchEvent({
			type: "load-error",
			tile: e,
			overlay: t,
			error: i,
			url: null
		}), null));
	}
	resetFailedOverlays() {
		let { processedTiles: e, overlayInfo: t, overlays: n } = this, r = [];
		e.forEach((e) => {
			n.forEach((n) => {
				let { tileInfo: i } = t.get(n), a = i.get(e);
				a.failed && (a.failed = !1, n.releaseTexture(a.range), r.push({
					tile: e,
					overlay: n,
					info: a
				}));
			});
		}), requestAnimationFrame(() => {
			r.forEach(({ tile: e, overlay: t, info: n }) => {
				t.lockTextureSafe(n.range), this._fetchTileOverlayTexture(e, t, n).then(() => {
					this._updateLayers(e);
				}).catch((e) => {
					if (e.name !== "AbortError") throw e;
				});
			});
		});
	}
	_updateLayers(e) {
		let { overlayInfo: t, overlays: n, tileControllers: r, meshParams: i } = this, a = r.get(e);
		if (this.tiles.recalculateBytesUsed(e), !(!a || a.signal.aborted)) {
			if (n.length === 0) {
				let t = e.engineData && e.engineData.scene;
				t && t.traverse((e) => {
					if (e.material && i.has(e)) {
						let t = i.get(e);
						t.layerMaps.length = 0, t.layerInfo.length = 0, e.material.defines.LAYER_COUNT = 0, e.material.needsUpdate = !0;
					}
				});
				return;
			}
			n.forEach((r, a) => {
				let { tileInfo: o } = t.get(r), { meshInfo: s, target: c } = o.get(e);
				s.forEach(({ attribute: e }, t) => {
					let { geometry: o, material: s } = t, l = i.get(t), u = `layer_uv_${a}`;
					o.getAttribute(u) !== e && (o.setAttribute(u, e), o.dispose()), l.layerMaps.length = n.length, l.layerInfo.length = n.length, l.layerMaps.value[a] = c === null ? null : c, l.layerInfo.value[a] = r, s.defines[`LAYER_${a}_EXISTS`] = Number(c !== null), s.defines[`LAYER_${a}_ALPHA_INVERT`] = Number(r.alphaInvert), s.defines[`LAYER_${a}_ALPHA_MASK`] = Number(r.alphaMask), s.defines.LAYER_COUNT = n.length, s.needsUpdate = !0;
				});
			});
		}
	}
	_markNeedsUpdate() {
		this.needsUpdate === !1 && (this.needsUpdate = !0, this.tiles !== null && this.tiles.dispatchEvent({ type: "needs-update" }));
	}
}, Jt = class {
	get isPlanarProjection() {
		return !!this.frame;
	}
	get downloadQueue() {
		return this._downloadQueue;
	}
	set downloadQueue(e) {
		if (e instanceof t) {
			console.warn("ImageOverlay: \"downloadQueue\" is no longer valid as a PriorityQueue. Use a DownloadPriorityQueue, instead.");
			return;
		}
		this._downloadQueue = e;
	}
	constructor(e = {}) {
		let { opacity: t = 1, color: n = 16777215, frame: r = null, preprocessURL: i = null, alphaMask: o = !1, alphaInvert: s = !1 } = e;
		this.preprocessURL = i, this.opacity = t, this.color = new w(n), this.frame = r === null ? null : r.clone(), this.alphaMask = o, this.alphaInvert = s, this.downloadQueue = a, this._whenReady = null, this.isReady = !1, this.isInitialized = !1, this._visibleRegionCounts = /* @__PURE__ */ new Map();
	}
	init() {
		return this.isInitialized || (this.isInitialized = !0, this._whenReady = this._init().then(() => this.isReady = !0)), this._whenReady;
	}
	whenReady() {
		return this._whenReady;
	}
	_init() {
		return Promise.resolve();
	}
	fetch(e, t = {}) {
		this.preprocessURL && (e = this.preprocessURL(e));
		let n = { priority: -performance.now() };
		return this.downloadQueue.add(e, n, () => fetch(e, t), t.signal);
	}
	getAttributions(e) {}
	hasContent(e, t = null) {
		return !1;
	}
	async getTexture(e, t = null) {
		return null;
	}
	async lockTexture(e, t = null) {
		return null;
	}
	lockTextureSafe(e) {
		let t = this.lockTexture(e);
		return t instanceof Promise && t.catch((e) => {
			if (e.name !== "AbortError") throw e;
		}), t;
	}
	releaseTexture(e, t = null) {}
	shouldSplit(e, t = null) {
		return !1;
	}
	setResolution(e) {}
	setRegionVisible(e, t) {
		let { _visibleRegionCounts: n } = this, r = e.join("_"), i = n.get(r);
		if (i || (i = {
			range: [...e],
			count: 0
		}, n.set(r, i)), i.count += t ? 1 : -1, i.count < 0) throw Error();
		i.count === 0 && n.delete(r);
	}
}, Yt = class extends Jt {
	get tiling() {
		return this.imageSource.tiling;
	}
	get projection() {
		return this.tiling.projection;
	}
	get aspectRatio() {
		return this.tiling && this.isReady ? this.tiling.aspectRatio : 1;
	}
	get fetchOptions() {
		return this.imageSource.fetchOptions;
	}
	set fetchOptions(e) {
		this.imageSource.fetchOptions = e;
	}
	constructor(e = {}) {
		let { imageSource: t = null, ...n } = e;
		super(n), this.imageSource = t, this.regionImageSource = null;
	}
	_init() {
		return this._initImageSource().then(() => {
			this.imageSource.fetchData = (...e) => this.fetch(...e), this.regionImageSource = new Ot(this.imageSource);
		});
	}
	_initImageSource() {
		return this.imageSource.init();
	}
	calculateLevel(e, t = null) {
		let [n, r, i, a] = e, o = i - n, s = a - r;
		t === null && (t = this.regionImageSource.resolution);
		let c = 0, l = this.tiling.maxLevel;
		for (; c < l; c++) {
			let e = t / o, n = t / s, r = this.tiling.getLevel(c);
			if (r == null) continue;
			let { pixelWidth: i, pixelHeight: a } = r;
			if (i >= e || a >= n) break;
		}
		return c;
	}
	hasContent(e, t = this.calculateLevel(e)) {
		return this.regionImageSource.hasContent(...e, t);
	}
	getTexture(e, t = this.calculateLevel(e)) {
		return this.regionImageSource.get(...e, t);
	}
	lockTexture(e, t = this.calculateLevel(e)) {
		return this.regionImageSource.lock(...e, t);
	}
	releaseTexture(e, t = this.calculateLevel(e)) {
		this.regionImageSource.release(...e, t);
	}
	shouldSplit(e, t = this.calculateLevel(e)) {
		return this.tiling.maxLevel > t;
	}
	setResolution(e) {
		this.regionImageSource.resolution = e;
	}
}, Xt = class extends Yt {
	constructor(e = {}) {
		super(e), this.imageSource = new at(e);
	}
}, Zt = class extends Yt {
	constructor(e) {
		super(e), this.imageSource = new Lt(e);
	}
}, Qt = class extends Jt {
	get projection() {
		return this.imageSource.projection;
	}
	get aspectRatio() {
		return 2;
	}
	get pointRadius() {
		return this.imageSource.pointRadius;
	}
	set pointRadius(e) {
		this.imageSource.pointRadius = e;
	}
	get strokeStyle() {
		return this.imageSource.strokeStyle;
	}
	set strokeStyle(e) {
		this.imageSource.strokeStyle = e;
	}
	get strokeWidth() {
		return this.imageSource.strokeWidth;
	}
	set strokeWidth(e) {
		this.imageSource.strokeWidth = e;
	}
	get fillStyle() {
		return this.imageSource.fillStyle;
	}
	set fillStyle(e) {
		this.imageSource.fillStyle = e;
	}
	get geojson() {
		return this.imageSource.geojson;
	}
	set geojson(e) {
		this.imageSource.geojson = e;
	}
	constructor(e = {}) {
		super(e), this.imageSource = new Ft(e), this._redrawQueue = new t(), this._redrawQueue.maxJobs = 4, this._redrawQueue.priorityCallback = () => 0;
	}
	_init() {
		return this.imageSource.init();
	}
	hasContent(e) {
		return this.imageSource.hasContent(...e);
	}
	getTexture(e) {
		return this.imageSource.get(...e);
	}
	lockTexture(e) {
		return this.imageSource.lock(...e);
	}
	releaseTexture(e) {
		this.imageSource.release(...e);
	}
	setResolution(e) {
		this.imageSource.resolution = e;
	}
	shouldSplit(e) {
		return !0;
	}
	setRegionVisible(e, t) {
		if (super.setRegionVisible(e, t), t) {
			let { _redrawQueue: t } = this, n = e.join("_");
			t.has(n) && t.flush(n);
		}
	}
	redraw() {
		let { imageSource: e, _redrawQueue: t, _visibleRegionCounts: n } = this;
		for (let { range: t } of n.values()) e.redraw(...t);
		e.forEachItem((r, i) => {
			let a = i.join("_");
			!n.has(a) && !t.has(a) && t.add(a, () => {
				e.redraw(...i);
			});
		});
	}
}, $t = class extends Yt {
	constructor(e = {}) {
		super(e), this.imageSource = new It(e);
	}
}, en = class extends Yt {
	constructor(e = {}) {
		super(e), this.imageSource = new Ct(e);
	}
}, tn = class extends Yt {
	constructor(e = {}) {
		super(e), this.imageSource = new st(e);
	}
}, nn = class extends Yt {
	constructor(e = {}) {
		super(e);
		let { apiToken: t, autoRefreshToken: n, assetId: r } = e;
		this.options = e, this.assetId = r, this.auth = new m({
			apiToken: t,
			autoRefreshToken: n
		}), this.auth.authURL = `https://api.cesium.com/v1/assets/${r}/endpoint`, this._attributions = [], this.externalType = !1;
	}
	_initImageSource() {
		return this.auth.refreshToken().then(async (e) => {
			if (this._attributions = e.attributions.map((e) => ({
				value: e.html,
				type: "html",
				collapsible: e.collapsible
			})), e.type !== "IMAGERY") throw Error("CesiumIonOverlay: Only IMAGERY is supported as overlay type.");
			switch (this.externalType = !!e.externalType, e.externalType) {
				case "GOOGLE_2D_MAPS": {
					let { url: t, session: n, key: r, tileWidth: i } = e.options, a = `${t}/v1/2dtiles/{z}/{x}/{y}?session=${n}&key=${r}`;
					this.imageSource = new at({
						...this.options,
						url: a,
						tileDimension: i,
						levels: 22
					});
					break;
				}
				case "BING": {
					let { url: t, mapStyle: n, key: r } = e.options, i = `${t}/REST/v1/Imagery/Metadata/${n}?incl=ImageryProviders&key=${r}&uriScheme=https`, a = (await fetch(i).then((e) => e.json())).resourceSets[0].resources[0];
					this.imageSource = new ot({
						...this.options,
						url: a.imageUrl,
						subdomains: a.imageUrlSubdomains,
						tileDimension: a.tileWidth,
						levels: a.zoomMax
					});
					break;
				}
				default: this.imageSource = new st({
					...this.options,
					url: e.url
				});
			}
			return this.imageSource.fetchData = (...e) => this.fetch(...e), this.imageSource.init();
		});
	}
	fetch(e, t = {}) {
		if (this.externalType) return super.fetch(e, t);
		this.preprocessURL && (e = this.preprocessURL(e));
		let n = { priority: -performance.now() };
		return this.downloadQueue.add(e, n, () => this.auth.fetch(e, t), t.signal);
	}
	getAttributions(e) {
		e.push(...this._attributions);
	}
}, rn = class extends Yt {
	constructor(e = {}) {
		super(e);
		let { apiToken: t, sessionOptions: n, autoRefreshToken: r, logoUrl: i } = e;
		this.logoUrl = i, this.auth = new p({
			apiToken: t,
			sessionOptions: n,
			autoRefreshToken: r
		}), this.imageSource = new at(), this.imageSource.fetchData = (...e) => this.fetch(...e), this._logoAttribution = {
			value: "",
			type: "image",
			collapsible: !1
		};
	}
	_initImageSource() {
		return this.auth.refreshToken().then((e) => (this.imageSource.tileDimension = e.tileWidth, this.imageSource.url = "https://tile.googleapis.com/v1/2dtiles/{z}/{x}/{y}", this.imageSource.init()));
	}
	fetch(e, t = {}) {
		this.preprocessURL && (e = this.preprocessURL(e));
		let n = { priority: -performance.now() };
		return this.downloadQueue.add(e, n, () => this.auth.fetch(e, t), t.signal);
	}
	getAttributions(e) {
		this.logoUrl && (this._logoAttribution.value = this.logoUrl, e.push(this._logoAttribution));
	}
}, an = /* @__PURE__ */ new I(), on = /* @__PURE__ */ new ke(), H = /* @__PURE__ */ new I(), sn = /* @__PURE__ */ new I(), cn = class extends h {
	constructor(e = D) {
		super(), this.manager = e, this.ellipsoid = new l(), this.skirtLength = 1e3, this.smoothSkirtNormals = !0, this.generateNormals = !0, this.solid = !1, this.minLat = -Math.PI / 2, this.maxLat = Math.PI / 2, this.minLon = -Math.PI, this.maxLon = Math.PI;
	}
	parse(e) {
		let { ellipsoid: t, solid: n, skirtLength: r, smoothSkirtNormals: i, generateNormals: a, minLat: o, maxLat: s, minLon: c, maxLon: l } = this, { header: u, indices: d, vertexData: f, edgeIndices: p, extensions: m } = super.parse(e), h = new S(), g = new de(), _ = new N(h, g);
		_.position.set(...u.center);
		let v = "octvertexnormals" in m, y = v || a, b = f.u.length, C = [], w = [], T = [], D = [], O = 0, k = 0;
		for (let e = 0; e < b; e++) ee(e, H), te(H.x, H.y, H.z, sn), w.push(H.x, H.y), C.push(...sn);
		for (let e = 0, t = d.length; e < t; e++) T.push(d[e]);
		if (y) if (v) {
			let e = m.octvertexnormals.normals;
			for (let t = 0, n = e.length; t < n; t++) D.push(e[t]);
		} else {
			let e = new S(), t = d.length > 21845 ? new Uint32Array(d) : new Uint16Array(d);
			e.setIndex(new x(t, 1, !1)), e.setAttribute("position", new x(new Float32Array(C), 3, !1)), e.computeVertexNormals();
			let n = e.getAttribute("normal").array;
			m.octvertexnormals = { normals: n };
			for (let e = 0, t = n.length; e < t; e++) D.push(n[e]);
		}
		if (h.addGroup(O, d.length, k), O += d.length, k++, n) {
			let e = C.length / 3;
			for (let e = 0; e < b; e++) ee(e, H), te(H.x, H.y, H.z, sn, -r), w.push(H.x, H.y), C.push(...sn);
			for (let t = d.length - 1; t >= 0; t--) T.push(d[t] + e);
			if (y) {
				let e = m.octvertexnormals.normals;
				for (let t = 0, n = e.length; t < n; t++) D.push(-e[t]);
			}
			h.addGroup(O, d.length, k), O += d.length, k++;
		}
		if (r > 0) {
			let { westIndices: e, eastIndices: t, southIndices: n, northIndices: r } = p, i, a = ne(e);
			i = C.length / 3, w.push(...a.uv), C.push(...a.positions);
			for (let e = 0, t = a.indices.length; e < t; e++) T.push(a.indices[e] + i);
			let o = ne(t);
			i = C.length / 3, w.push(...o.uv), C.push(...o.positions);
			for (let e = 0, t = o.indices.length; e < t; e++) T.push(o.indices[e] + i);
			let s = ne(n);
			i = C.length / 3, w.push(...s.uv), C.push(...s.positions);
			for (let e = 0, t = s.indices.length; e < t; e++) T.push(s.indices[e] + i);
			let c = ne(r);
			i = C.length / 3, w.push(...c.uv), C.push(...c.positions);
			for (let e = 0, t = c.indices.length; e < t; e++) T.push(c.indices[e] + i);
			y && (D.push(...a.normals), D.push(...o.normals), D.push(...s.normals), D.push(...c.normals)), h.addGroup(O, d.length, k), O += d.length, k++;
		}
		for (let e = 0, t = C.length; e < t; e += 3) C[e + 0] -= u.center[0], C[e + 1] -= u.center[1], C[e + 2] -= u.center[2];
		let A = C.length / 3 > 65535 ? new Uint32Array(T) : new Uint16Array(T);
		if (h.setIndex(new x(A, 1, !1)), h.setAttribute("position", new x(new Float32Array(C), 3, !1)), h.setAttribute("uv", new x(new Float32Array(w), 2, !1)), y && h.setAttribute("normal", new x(new Float32Array(D), 3, !1)), "watermask" in m) {
			let { mask: e, size: t } = m.watermask, n = new Uint8Array(2 * t * t);
			for (let t = 0, r = e.length; t < r; t++) {
				let r = e[t] === 255 ? 0 : 255;
				n[2 * t + 0] = r, n[2 * t + 1] = r;
			}
			let r = new E(n, t, t, ve, Ae);
			r.flipY = !0, r.minFilter = se, r.magFilter = oe, r.needsUpdate = !0, g.roughnessMap = r;
		}
		return _.userData.minHeight = u.minHeight, _.userData.maxHeight = u.maxHeight, "metadata" in m && (_.userData.metadata = m.metadata.json), _;
		function ee(e, t) {
			return t.x = f.u[e], t.y = f.v[e], t.z = f.height[e], t;
		}
		function te(e, n, r, i, a = 0) {
			let d = j.lerp(u.minHeight, u.maxHeight, r), f = j.lerp(c, l, e), p = j.lerp(o, s, n);
			return t.getCartographicToPosition(p, f, d + a, i), i;
		}
		function ne(e) {
			let t = [], n = [], a = [], o = [], s = [];
			for (let i = 0, s = e.length; i < s; i++) ee(e[i], H), t.push(H.x, H.y), a.push(H.x, H.y), te(H.x, H.y, H.z, sn), n.push(...sn), te(H.x, H.y, H.z, sn, -r), o.push(...sn);
			let c = e.length - 1;
			for (let t = 0; t < c; t++) {
				let n = t, r = t + 1, i = t + e.length, a = t + e.length + 1;
				s.push(n, i, r), s.push(r, i, a);
			}
			let l = null;
			if (y) {
				let t = (n.length + o.length) / 3;
				if (i) {
					l = Array(t * 3);
					let n = m.octvertexnormals.normals, r = l.length / 2;
					for (let i = 0, a = t / 2; i < a; i++) {
						let t = e[i], a = 3 * i, o = n[3 * t + 0], s = n[3 * t + 1], c = n[3 * t + 2];
						l[a + 0] = o, l[a + 1] = s, l[a + 2] = c, l[r + a + 0] = o, l[r + a + 1] = s, l[r + a + 2] = c;
					}
				} else {
					l = [], on.a.fromArray(n, 0), on.b.fromArray(o, 0), on.c.fromArray(n, 3), on.getNormal(an);
					for (let e = 0; e < t; e++) l.push(...an);
				}
			}
			return {
				uv: [...t, ...a],
				positions: [...n, ...o],
				indices: s,
				normals: l
			};
		}
	}
}, ln = {}, un = /* @__PURE__ */ new I(), dn = /* @__PURE__ */ new I(), fn = /* @__PURE__ */ new I(), pn = /* @__PURE__ */ new I(), mn = /* @__PURE__ */ new I(), U = /* @__PURE__ */ new I(), hn = /* @__PURE__ */ new I(), W = /* @__PURE__ */ new F(), gn = /* @__PURE__ */ new F(), _n = /* @__PURE__ */ new F(), vn = class extends vt {
	constructor() {
		super(), this.ellipsoid = new l(), this.skirtLength = 1e3, this.smoothSkirtNormals = !0, this.solid = !1, this.minLat = -Math.PI / 2, this.maxLat = Math.PI / 2, this.minLon = -Math.PI, this.maxLon = Math.PI, this.attributeList = [
			"position",
			"normal",
			"uv"
		];
	}
	clipToQuadrant(e, t, n) {
		let { solid: r, skirtLength: i, ellipsoid: a, smoothSkirtNormals: o } = this;
		this.clearSplitOperations(), this.addSplitOperation(yn("x"), !t), this.addSplitOperation(yn("y"), !n);
		let s, c, l = e.geometry.groups[0], u = this.getClippedData(e, l);
		if (this.adjustVertices(u, e.position, 0), r) {
			s = {
				index: u.index.slice().reverse(),
				attributes: {}
			};
			for (let e in u.attributes) s.attributes[e] = u.attributes[e].slice();
			let t = s.attributes.normal;
			if (t) for (let e = 0; e < t.length; e += 3) t[e + 0] *= -1, t[e + 1] *= -1, t[e + 2] *= -1;
			this.adjustVertices(s, e.position, -i);
		}
		if (i > 0) {
			c = {
				index: [],
				attributes: {
					position: [],
					normal: [],
					uv: []
				}
			};
			let t = 0, n = {}, r = (e, r, i) => {
				let a = St(...e, ...i, ...r);
				a in n || (n[a] = t, t++, c.attributes.position.push(...e), c.attributes.normal.push(...i), c.attributes.uv.push(...r)), c.index.push(n[a]);
			}, s = u.index, l = u.attributes.uv, d = u.attributes.position, f = u.attributes.normal, p = u.index.length / 3;
			for (let t = 0; t < p; t++) {
				let n = 3 * t;
				for (let t = 0; t < 3; t++) {
					let c = (t + 1) % 3, u = s[n + t], p = s[n + c];
					if (W.fromArray(l, u * 2), gn.fromArray(l, p * 2), W.x === gn.x && (W.x === 0 || W.x === .5 || W.x === 1) || W.y === gn.y && (W.y === 0 || W.y === .5 || W.y === 1)) {
						dn.fromArray(d, u * 3), fn.fromArray(d, p * 3);
						let t = dn, n = fn, s = pn.copy(dn), c = mn.copy(fn);
						U.copy(s).add(e.position), a.getPositionToNormal(U, U), s.addScaledVector(U, -i), U.copy(c).add(e.position), a.getPositionToNormal(U, U), c.addScaledVector(U, -i), o && f ? (U.fromArray(f, u * 3), hn.fromArray(f, p * 3)) : (U.subVectors(t, n), hn.subVectors(t, s).cross(U).normalize(), U.copy(hn)), r(n, gn, hn), r(t, W, U), r(s, W, U), r(n, gn, hn), r(s, W, U), r(c, gn, hn);
					}
				}
			}
		}
		let d = u.index.length, f = u;
		if (s) {
			let { index: e, attributes: t } = s, n = f.attributes.position.length / 3;
			for (let t = 0, r = e.length; t < r; t++) f.index.push(e[t] + n);
			for (let e in u.attributes) f.attributes[e].push(...t[e]);
		}
		if (c) {
			let { index: e, attributes: t } = c, n = f.attributes.position.length / 3;
			for (let t = 0, r = e.length; t < r; t++) f.index.push(e[t] + n);
			for (let e in u.attributes) f.attributes[e].push(...t[e]);
		}
		let p = t ? 0 : -.5, m = n ? 0 : -.5, h = f.attributes.uv;
		for (let e = 0, t = h.length; e < t; e += 2) h[e] = (h[e] + p) * 2, h[e + 1] = (h[e + 1] + m) * 2;
		let g = this.constructMesh(f.attributes, f.index, e);
		g.userData.minHeight = e.userData.minHeight, g.userData.maxHeight = e.userData.maxHeight;
		let _ = 0, v = 0;
		return g.geometry.addGroup(v, d, _), v += d, _++, s && (g.geometry.addGroup(v, s.index.length, _), v += s.index.length, _++), c && (g.geometry.addGroup(v, c.index.length, _), v += c.index.length, _++), g;
	}
	adjustVertices(e, t, n) {
		let { ellipsoid: r, minLat: i, maxLat: a, minLon: o, maxLon: s } = this, { attributes: c, vertexIsClipped: l } = e, u = c.position, d = c.uv, f = u.length / 3;
		for (let e = 0; e < f; e++) {
			let c = W.fromArray(d, e * 2);
			l && l[e] && (Math.abs(c.x - .5) < 1e-10 && (c.x = .5), Math.abs(c.y - .5) < 1e-10 && (c.y = .5), W.toArray(d, e * 2));
			let f = j.lerp(i, a, c.y), p = j.lerp(o, s, c.x), m = un.fromArray(u, e * 3).add(t);
			r.getPositionToCartographic(m, ln), r.getCartographicToPosition(f, p, ln.height + n, m), m.sub(t), m.toArray(u, e * 3);
		}
	}
};
function yn(e) {
	return (t, n, r, i, a) => {
		let o = t.attributes.uv;
		return W.fromBufferAttribute(o, n), gn.fromBufferAttribute(o, r), _n.fromBufferAttribute(o, i), W[e] * a.x + gn[e] * a.y + _n[e] * a.z - .5;
	};
}
//#endregion
//#region src/three/plugins/QuantizedMeshPlugin.js
var bn = Symbol("TILE_X"), xn = Symbol("TILE_Y"), Sn = Symbol("TILE_LEVEL"), Cn = Symbol("TILE_AVAILABLE"), wn = Symbol("TILE_SPLIT_SOURCE_SCENE"), Tn = 1e4, En = /* @__PURE__ */ new I();
function Dn(e, t, n, r) {
	if (e && t < e.length) {
		let i = e[t];
		for (let e = 0, t = i.length; e < t; e++) {
			let { startX: t, startY: a, endX: o, endY: s } = i[e];
			if (n >= t && n <= o && r >= a && r <= s) return !0;
		}
	}
	return !1;
}
function On(e) {
	let { available: t = null, maxzoom: n = null } = e;
	return n === null ? t.length - 1 : n;
}
function kn(e) {
	let { metadataAvailability: t = -1 } = e;
	return t;
}
function An(e, t) {
	let n = e[Sn], r = kn(t);
	return n < On(t) && r !== -1 && n % r === 0;
}
function jn(e, t, n, r, i) {
	return i.tiles[0].replace(/{\s*z\s*}/g, n).replace(/{\s*x\s*}/g, e).replace(/{\s*y\s*}/g, t).replace(/{\s*version\s*}/g, r);
}
var Mn = class {
	constructor(e = {}) {
		let { useRecommendedSettings: t = !0, skirtLength: n = null, smoothSkirtNormals: r = !0, generateNormals: i = !0, solid: a = !1 } = e;
		this.name = "QUANTIZED_MESH_PLUGIN", this.priority = -1e3, this.tiles = null, this.layer = null, this.useRecommendedSettings = t, this.skirtLength = n, this.smoothSkirtNormals = r, this.solid = a, this.generateNormals = i, this.attribution = null, this.tiling = new He(), this.projection = new L();
	}
	init(e) {
		e.fetchOptions.headers = e.fetchOptions.headers || {}, e.fetchOptions.headers.Accept = "application/vnd.quantized-mesh,application/octet-stream;q=0.9", this.useRecommendedSettings && (e.errorTarget = 2), this.tiles = e;
	}
	loadRootTileset() {
		let { tiles: e } = this, t = new URL("layer.json", new URL(e.rootURL, location.href));
		return e.invokeAllPlugins((e) => t = e.preprocessURL ? e.preprocessURL(t, null) : t), e.invokeOnePlugin((e) => e.fetchData && e.fetchData(t, this.tiles.fetchOptions)).then((e) => e.json()).then((e) => {
			this.layer = e;
			let { projection: t = "EPSG:4326", extensions: n = [], attribution: r = "", available: i = null } = e, { tiling: a, tiles: o, projection: s } = this;
			r && (this.attribution = {
				value: r,
				type: "string",
				collapsible: !0
			}), n.length > 0 && (o.fetchOptions.headers.Accept += `;extensions=${n.join("-")}`), s.setScheme(t);
			let { tileCountX: c, tileCountY: l } = s;
			a.setProjection(s), a.generateLevels(On(e) + 1, c, l);
			let u = [];
			for (let e = 0; e < c; e++) {
				let t = this.createChild(0, e, 0, i);
				t && u.push(t);
			}
			let d = {
				asset: { version: "1.1" },
				geometricError: Infinity,
				root: {
					refine: "REPLACE",
					geometricError: Infinity,
					boundingVolume: { region: [
						...this.tiling.getContentBounds(),
						-1e4,
						Tn
					] },
					children: u,
					[Cn]: i,
					[Sn]: -1
				}
			}, f = o.rootURL;
			return o.invokeAllPlugins((e) => f = e.preprocessURL ? e.preprocessURL(f, null) : f), o.preprocessTileset(d, f), d;
		});
	}
	parseToMesh(e, t, n, r) {
		let { skirtLength: i, solid: a, smoothSkirtNormals: o, generateNormals: s, tiles: c } = this, l = c.ellipsoid, u;
		if (n === "quantized_tile_split") {
			let e = new URL(r).searchParams, n = e.get("left") === "true", s = e.get("bottom") === "true", c = new vn();
			c.ellipsoid.copy(l), c.solid = a, c.smoothSkirtNormals = o, c.skirtLength = i === null ? t.geometricError : i;
			let [d, f, p, m] = t.parent.boundingVolume.region;
			c.minLat = f, c.maxLat = m, c.minLon = d, c.maxLon = p;
			let h = t.parent.engineData.scene || t.parent[wn];
			u = c.clipToQuadrant(h, n, s);
		} else if (n === "terrain") {
			let n = new cn(c.manager);
			n.ellipsoid.copy(l), n.solid = a, n.smoothSkirtNormals = o, n.generateNormals = s, n.skirtLength = i === null ? t.geometricError : i;
			let [r, d, f, p] = t.boundingVolume.region;
			n.minLat = d, n.maxLat = p, n.minLon = r, n.maxLon = f, u = n.parse(e);
		} else return;
		let { minHeight: d, maxHeight: f, metadata: p } = u.userData;
		return t.boundingVolume.region[4] = d, t.boundingVolume.region[5] = f, t.engineData.boundingVolume.setRegionData(l, ...t.boundingVolume.region), p && ("geometricerror" in p && (t.geometricError = p.geometricerror), An(t, this.layer) && "available" in p && t.children.length === 0 && (t[Cn] = [...Array(t[Sn] + 1).fill(null), ...p.available])), t[wn] = u, this.expandChildren(t), u;
	}
	getAttributions(e) {
		this.attribution && e.push(this.attribution);
	}
	createChild(e, t, n, r) {
		let { tiles: i, layer: a, tiling: o, projection: s } = this, c = i.ellipsoid, l = r === null && e === 0 || Dn(r, e, t, n), u = jn(t, n, e, 1, a), d = [
			...o.getTileBounds(t, n, e),
			-1e4,
			Tn
		], [, f, , p, , m] = d, h = f > 0 == p > 0 ? Math.min(Math.abs(f), Math.abs(p)) : 0;
		c.getCartographicToPosition(h, 0, m, En), En.z = 0;
		let g = s.tileCountX, _ = Math.max(...c.radius) * 2 * Math.PI * .25 / (65 * g) / 2 ** e, v = {
			[Cn]: null,
			[Sn]: e,
			[bn]: t,
			[xn]: n,
			refine: "REPLACE",
			geometricError: _,
			boundingVolume: { region: d },
			content: l ? { uri: u } : null,
			children: []
		};
		return An(v, a) || (v[Cn] = r), v;
	}
	expandChildren(e) {
		let t = e[Sn], n = e[bn], r = e[xn], i = e[Cn];
		if (t >= this.tiling.maxLevel) return;
		let a = !1;
		for (let o = 0; o < 2; o++) for (let s = 0; s < 2; s++) {
			let c = this.createChild(t + 1, 2 * n + o, 2 * r + s, i);
			c.content === null ? (c.content = { uri: `tile.quantized_tile_split?bottom=${s === 0}&left=${o === 0}` }, c.internal = { isVirtual: !0 }, e.internal.virtualChildCount++, e.children.push(c)) : (e.children.push(c), a = !0);
		}
		a || (e.children.length -= e.internal.virtualChildCount, e.internal.virtualChildCount = 0);
	}
	fetchData(e, t) {
		if (/quantized_tile_split/.test(e)) return /* @__PURE__ */ new ArrayBuffer();
	}
	disposeTile(e) {
		let { tiles: t, layer: n } = this;
		if (delete e[wn], An(e, n) && (e[Cn] = null), Cn in e) {
			let { virtualChildCount: n } = e.internal, r = e.children.length, i = r - n;
			for (let n = i; n < r; n++) t.processNodeQueue.remove(e.children[n]);
			e.children.length = 0, e.internal.virtualChildCount = 0;
		}
	}
}, Nn = class extends f {
	constructor(e = {}) {
		super({
			assetTypeHandler: (e, t, n) => {
				if (e === "TERRAIN" && t.getPluginByName("QUANTIZED_MESH_PLUGIN") === null) t.registerPlugin(new Mn({ useRecommendedSettings: this.useRecommendedSettings }));
				else if (e === "IMAGERY" && t.getPluginByName("GENERATED_SURFACE_PLUGIN") === null) {
					let e = new tn({ url: t.rootURL });
					t.registerPlugin(new et({
						shape: "ellipsoid",
						overlay: e
					}));
				} else console.warn(`CesiumIonAuthPlugin: Cesium Ion asset type "${e}" unhandled.`);
			},
			...e
		});
	}
}, Pn = /* @__PURE__ */ new M(), Fn = class {
	constructor() {
		this.name = "UPDATE_ON_CHANGE_PLUGIN", this.tiles = null, this.needsUpdate = !1, this.cameraMatrices = /* @__PURE__ */ new Map();
	}
	init(e) {
		this.tiles = e, this._needsUpdateCallback = () => {
			this.needsUpdate = !0;
		}, this._onCameraAdd = ({ camera: e }) => {
			this.needsUpdate = !0, this.cameraMatrices.set(e, new M());
		}, this._onCameraDelete = ({ camera: e }) => {
			this.needsUpdate = !0, this.cameraMatrices.delete(e);
		}, e.addEventListener("needs-update", this._needsUpdateCallback), e.addEventListener("add-camera", this._onCameraAdd), e.addEventListener("delete-camera", this._onCameraDelete), e.addEventListener("camera-resolution-change", this._needsUpdateCallback), e.cameras.forEach((e) => {
			this._onCameraAdd({ camera: e });
		});
	}
	doTilesNeedUpdate() {
		let e = this.tiles, t = !1;
		this.cameraMatrices.forEach((n, r) => {
			Pn.copy(e.group.matrixWorld).premultiply(r.matrixWorldInverse).premultiply(r.projectionMatrixInverse), t ||= !Pn.equals(n), n.copy(Pn);
		});
		let n = this.needsUpdate;
		return this.needsUpdate = !1, n || t;
	}
	preprocessNode() {
		this.needsUpdate = !0;
	}
	dispose() {
		let e = this.tiles;
		e.removeEventListener("camera-resolution-change", this._needsUpdateCallback), e.removeEventListener("needs-update", this._needsUpdateCallback), e.removeEventListener("add-camera", this._onCameraAdd), e.removeEventListener("delete-camera", this._onCameraDelete);
	}
}, In = /* @__PURE__ */ new I();
function Ln(e, t) {
	if (e.isInterleavedBufferAttribute || e.array instanceof t) return e;
	let n = t === Int8Array || t === Int16Array || t === Int32Array ? -1 : 0, r = new x(new t(e.count * e.itemSize), e.itemSize, !0), i = e.itemSize, a = e.count;
	for (let t = 0; t < a; t++) for (let a = 0; a < i; a++) {
		let i = j.clamp(e.getComponent(t, a), n, 1);
		r.setComponent(t, a, i);
	}
	return r;
}
function Rn(e, t = Int16Array) {
	let n = e.geometry, r = n.attributes, i = r.position;
	if (i.isInterleavedBufferAttribute || i.array instanceof t) return i;
	let a = new x(new t(i.count * i.itemSize), i.itemSize, !1), o = i.itemSize, s = i.count;
	n.computeBoundingBox();
	let c = n.boundingBox, { min: l, max: u } = c, d = 2 ** (8 * t.BYTES_PER_ELEMENT - 1) - 1, f = -d;
	for (let e = 0; e < s; e++) for (let t = 0; t < o; t++) {
		let n = t === 0 ? "x" : t === 1 ? "y" : "z", r = l[n], o = u[n], s = j.mapLinear(i.getComponent(e, t), r, o, f, d);
		a.setComponent(e, t, s);
	}
	c.getCenter(In).multiply(e.scale).applyQuaternion(e.quaternion), e.position.add(In), e.scale.x *= .5 * (u.x - l.x) / d, e.scale.y *= .5 * (u.y - l.y) / d, e.scale.z *= .5 * (u.z - l.z) / d, r.position = a, e.geometry.boundingBox = null, e.geometry.boundingSphere = null, e.updateMatrixWorld();
}
var zn = class {
	constructor(e) {
		this._options = {
			generateNormals: !1,
			disableMipmaps: !0,
			compressIndex: !0,
			compressNormals: !1,
			compressUvs: !1,
			compressPosition: !1,
			uvType: Int8Array,
			normalType: Int8Array,
			positionType: Int16Array,
			...e
		}, this.name = "TILES_COMPRESSION_PLUGIN", this.priority = -100;
	}
	processTileModel(e, t) {
		let { generateNormals: n, disableMipmaps: r, compressIndex: i, compressUvs: a, compressNormals: o, compressPosition: s, uvType: c, normalType: l, positionType: u } = this._options;
		e.traverse((e) => {
			if (e.material && r) {
				let t = e.material;
				for (let e in t) {
					let n = t[e];
					n && n.isTexture && n.generateMipmaps && (n.generateMipmaps = !1, n.minFilter = oe);
				}
			}
			if (e.geometry) {
				let t = e.geometry, r = t.attributes;
				if (a) {
					let { uv: e, uv1: t, uv2: n, uv3: i } = r;
					e && (r.uv = Ln(e, c)), t && (r.uv1 = Ln(t, c)), n && (r.uv2 = Ln(n, c)), i && (r.uv3 = Ln(i, c));
				}
				if (n && !r.normals && t.computeVertexNormals(), o && r.normals && (r.normals = Ln(r.normals, l)), s && Rn(e, u), i && t.index) {
					let e = r.position.count, n = t.index, i = e > 65535 ? Uint32Array : e > 255 ? Uint16Array : Uint8Array;
					if (!(n.array instanceof i)) {
						let e = new i(t.index.count);
						e.set(n.array);
						let r = new x(e, 1);
						t.setIndex(r);
					}
				}
			}
		});
	}
};
//#endregion
//#region src/three/plugins/gltf/metadata/utilities/ClassPropertyHelpers.js
function G(e, t, n) {
	return e && t in e ? e[t] : n;
}
function Bn(e) {
	return e !== "BOOLEAN" && e !== "STRING" && e !== "ENUM";
}
function Vn(e) {
	return /^FLOAT/.test(e);
}
function Hn(e) {
	return /^VEC/.test(e);
}
function Un(e) {
	return /^MAT/.test(e);
}
function Wn(e, t, n, r = null) {
	return Un(n) || Hn(n) ? r.fromArray(e, t) : e[t];
}
function Gn(e) {
	let { type: t, componentType: n } = e;
	switch (t) {
		case "SCALAR": return n === "INT64" ? 0n : 0;
		case "VEC2": return new F();
		case "VEC3": return new I();
		case "VEC4": return new je();
		case "MAT2": return new ce();
		case "MAT3": return new le();
		case "MAT4": return new M();
		case "BOOLEAN": return !1;
		case "STRING": return "";
		case "ENUM": return 0;
	}
}
function Kn(e, t) {
	if (t == null) return !1;
	switch (e) {
		case "SCALAR": return typeof t == "number" || typeof t == "bigint";
		case "VEC2": return t.isVector2;
		case "VEC3": return t.isVector3;
		case "VEC4": return t.isVector4;
		case "MAT2": return t.isMatrix2;
		case "MAT3": return t.isMatrix3;
		case "MAT4": return t.isMatrix4;
		case "BOOLEAN": return typeof t == "boolean";
		case "STRING": return typeof t == "string";
		case "ENUM": return typeof t == "number" || typeof t == "bigint";
	}
	throw Error("ClassProperty: invalid type.");
}
function qn(e, t = null) {
	switch (e) {
		case "INT8": return Int8Array;
		case "INT16": return Int16Array;
		case "INT32": return Int32Array;
		case "INT64": return BigInt64Array;
		case "UINT8": return Uint8Array;
		case "UINT16": return Uint16Array;
		case "UINT32": return Uint32Array;
		case "UINT64": return BigUint64Array;
		case "FLOAT32": return Float32Array;
		case "FLOAT64": return Float64Array;
	}
	switch (t) {
		case "BOOLEAN": return Uint8Array;
		case "STRING": return Uint8Array;
	}
	throw Error("ClassProperty: invalid type.");
}
function Jn(e, t = null) {
	if (e.array) {
		t = t && Array.isArray(t) ? t : [], t.length = e.count;
		for (let n = 0, r = t.length; n < r; n++) t[n] = Yn(e, t[n]);
	} else t = Yn(e, t);
	return t;
}
function Yn(e, t = null) {
	let n = e.default, r = e.type;
	if (t ||= Gn(e), n === null) {
		switch (r) {
			case "SCALAR": return 0;
			case "VEC2": return t.set(0, 0);
			case "VEC3": return t.set(0, 0, 0);
			case "VEC4": return t.set(0, 0, 0, 0);
			case "MAT2": return t.identity();
			case "MAT3": return t.identity();
			case "MAT4": return t.identity();
			case "BOOLEAN": return !1;
			case "STRING": return "";
			case "ENUM": return "";
		}
		throw Error("ClassProperty: invalid type.");
	} else if (Un(r)) t.fromArray(n);
	else if (Hn(r)) t.fromArray(n);
	else return n;
}
function Xn(e, t) {
	if (e.noData === null) return t;
	let n = e.noData, r = e.type;
	if (Array.isArray(t)) for (let e = 0, n = t.length; e < n; e++) t[e] = i(t[e]);
	else t = i(t);
	return t;
	function i(t) {
		return a(t) && (t = Yn(e, t)), t;
	}
	function a(e) {
		if (Un(r)) {
			let t = e.elements;
			for (let e = 0, r = n.length; e < r; e++) if (n[e] !== t[e]) return !1;
			return !0;
		} else if (Hn(r)) {
			for (let t = 0, r = n.length; t < r; t++) if (n[t] !== e.getComponent(t)) return !1;
			return !0;
		} else return n === e;
	}
}
function Zn(e, t) {
	switch (e) {
		case "INT8": return Math.max(t / 127, -1);
		case "INT16": return Math.max(t, 32767, -1);
		case "INT32": return Math.max(t / 2147483647, -1);
		case "INT64": return Math.max(Number(t) / 0x8000000000000000, -1);
		case "UINT8": return t / 255;
		case "UINT16": return t / 65535;
		case "UINT32": return t / 4294967295;
		case "UINT64": return Number(t) / 0x10000000000000000;
	}
}
function Qn(e, t) {
	let { type: n, componentType: r, scale: i, offset: a, normalized: o } = e;
	if (Array.isArray(t)) for (let e = 0, n = t.length; e < n; e++) t[e] = s(t[e]);
	else t = s(t);
	return t;
	function s(e) {
		return e = Un(n) ? l(e) : Hn(n) ? c(e) : u(e), e;
	}
	function c(e) {
		return e.x = u(e.x), e.y = u(e.y), "z" in e && (e.z = u(e.z)), "w" in e && (e.w = u(e.w)), e;
	}
	function l(e) {
		let t = e.elements;
		for (let e = 0, n = t.length; e < n; e++) t[e] = u(t[e]);
		return e;
	}
	function u(e) {
		return o && (e = Zn(r, e)), (o || Vn(r)) && (e = e * i + a), e;
	}
}
function $n(e, t, n = null) {
	if (e.array) {
		Array.isArray(t) || (t = Array(e.count || 0)), t.length = n === null ? e.count : n;
		for (let n = 0, r = t.length; n < r; n++) Kn(e.type, t[n]) || (t[n] = Gn(e));
	} else Kn(e.type, t) || (t = Gn(e));
	return t;
}
function er(e, t) {
	for (let n in t) n in e || delete t[n];
	for (let n in e) {
		let r = e[n];
		t[n] = $n(r, t[n]);
	}
}
function tr(e) {
	switch (e) {
		case "ENUM": return 1;
		case "SCALAR": return 1;
		case "VEC2": return 2;
		case "VEC3": return 3;
		case "VEC4": return 4;
		case "MAT2": return 4;
		case "MAT3": return 9;
		case "MAT4": return 16;
		case "BOOLEAN": return -1;
		case "STRING": return -1;
		default: return -1;
	}
}
//#endregion
//#region src/three/plugins/gltf/metadata/classes/ClassProperty.js
var nr = class {
	constructor(e, t, n = null) {
		this.name = t.name || null, this.description = t.description || null, this.type = t.type, this.componentType = t.componentType || null, this.enumType = t.enumType || null, this.array = t.array || !1, this.count = t.count || 0, this.normalized = t.normalized || !1, this.offset = t.offset || 0, this.scale = G(t, "scale", 1), this.max = G(t, "max", Infinity), this.min = G(t, "min", -Infinity), this.required = t.required || !1, this.noData = G(t, "noData", null), this.default = G(t, "default", null), this.semantic = G(t, "semantic", null), this.enumSet = null, this.accessorProperty = n, n && (this.offset = G(n, "offset", this.offset), this.scale = G(n, "scale", this.scale), this.max = G(n, "max", this.max), this.min = G(n, "min", this.min)), t.type === "ENUM" && (this.enumSet = e[this.enumType], this.componentType === null && (this.componentType = G(this.enumSet, "valueType", "UINT16")));
	}
	shapeToProperty(e, t = null) {
		return $n(this, e, t);
	}
	resolveDefaultElement(e) {
		return Yn(this, e);
	}
	resolveDefault(e) {
		return Jn(this, e);
	}
	resolveNoData(e) {
		return Xn(this, e);
	}
	resolveEnumsToStrings(e) {
		let t = this.enumSet;
		if (this.type === "ENUM") if (Array.isArray(e)) for (let t = 0, r = e.length; t < r; t++) e[t] = n(e[t]);
		else e = n(e);
		return e;
		function n(e) {
			let n = t.values.find((t) => t.value === e);
			return n === null ? "" : n.name;
		}
	}
	adjustValueScaleOffset(e) {
		return Bn(this.type) ? Qn(this, e) : e;
	}
}, rr = class {
	constructor(e, t = {}, n = {}, r = null) {
		this.definition = e, this.class = t[e.class], this.className = e.class, this.enums = n, this.data = r, this.name = "name" in e ? e.name : null, this.properties = null;
	}
	getPropertyNames() {
		return Object.keys(this.class.properties);
	}
	includesData(e) {
		return !!this.definition.properties[e];
	}
	dispose() {}
	_initProperties(e = nr) {
		let t = {};
		for (let n in this.class.properties) t[n] = new e(this.enums, this.class.properties[n], this.definition.properties[n]);
		this.properties = t;
	}
}, ir = class extends nr {
	constructor(e, t, n = null) {
		super(e, t, n), this.attribute = n?.attribute ?? null;
	}
}, ar = class extends rr {
	constructor(...e) {
		super(...e), this.isPropertyAttributeAccessor = !0, this._initProperties(ir);
	}
	getData(e, t, n = {}) {
		let r = this.properties;
		er(r, n);
		for (let i in r) n[i] = this.getPropertyValue(i, e, t, n[i]);
		return n;
	}
	getPropertyValue(e, t, n, r = null) {
		if (t >= this.count) throw Error("PropertyAttributeAccessor: Requested index is outside the range of the buffer.");
		let i = this.properties[e], a = i.type;
		if (!i) throw Error("PropertyAttributeAccessor: Requested class property does not exist.");
		if (!this.definition.properties[e]) return i.resolveDefault(r);
		r = i.shapeToProperty(r);
		let o = n.getAttribute(i.attribute.toLowerCase());
		if (Un(a)) {
			let e = r.elements;
			for (let n = e.length; 0 < n;) e[0] = o.getComponent(t, 0);
		} else if (Hn(a)) r.fromBufferAttribute(o, t);
		else if (a === "SCALAR" || a === "ENUM") r = o.getX(t);
		else throw Error("StructuredMetadata.PropertyAttributeAccessor: BOOLEAN and STRING types are not supported by property attributes.");
		return r = i.adjustValueScaleOffset(r), r = i.resolveEnumsToStrings(r), r = i.resolveNoData(r), r;
	}
}, or = class extends nr {
	constructor(e, t, n = null) {
		super(e, t, n), this.values = n?.values ?? null, this.valueLength = tr(this.type), this.arrayOffsets = G(n, "arrayOffsets", null), this.stringOffsets = G(n, "stringOffsets", null), this.arrayOffsetType = G(n, "arrayOffsetType", "UINT32"), this.stringOffsetType = G(n, "stringOffsetType", "UINT32");
	}
	getArrayLengthFromId(e, t) {
		let n = this.count;
		if (this.arrayOffsets !== null) {
			let { arrayOffsets: r, arrayOffsetType: i } = this, a = new (qn(i))(e[r]);
			n = a[t + 1] - a[t];
		}
		return n;
	}
	getIndexOffsetFromId(e, t) {
		let n = t;
		if (this.arrayOffsets) {
			let { arrayOffsets: t, arrayOffsetType: r } = this;
			n = new (qn(r))(e[t])[n];
		} else this.array && (n *= this.count);
		return n;
	}
}, sr = class extends rr {
	constructor(...e) {
		super(...e), this.isPropertyTableAccessor = !0, this.count = this.definition.count, this._initProperties(or);
	}
	getData(e, t = {}) {
		let n = this.properties;
		er(n, t);
		for (let r in n) t[r] = this.getPropertyValue(r, e, t[r]);
		return t;
	}
	_readValueAtIndex(e, t, n, r = null) {
		let i = this.properties[e], { componentType: a, type: o } = i, s = this.data, c = s[i.values], l = new (qn(a, o))(c), u = i.getIndexOffsetFromId(s, t);
		if (Bn(o) || o === "ENUM") return Wn(l, (u + n) * i.valueLength, o, r);
		if (o === "STRING") {
			let e = u + n, t = 0;
			if (i.stringOffsets !== null) {
				let { stringOffsets: n, stringOffsetType: r } = i, a = new (qn(r))(s[n]);
				t = a[e + 1] - a[e], e = a[e];
			}
			let a = new Uint8Array(l.buffer, e, t);
			r = new TextDecoder().decode(a);
		} else if (o === "BOOLEAN") {
			let e = u + n, t = Math.floor(e / 8), i = e % 8;
			r = (l[t] >> i & 1) == 1;
		}
		return r;
	}
	getPropertyValue(e, t, n = null) {
		if (t >= this.count) throw Error("PropertyTableAccessor: Requested index is outside the range of the table.");
		let r = this.properties[e];
		if (!r) throw Error("PropertyTableAccessor: Requested property does not exist.");
		if (!this.definition.properties[e]) return r.resolveDefault(n);
		let i = r.array, a = this.data, o = r.getArrayLengthFromId(a, t);
		if (n = r.shapeToProperty(n, o), i) for (let r = 0, i = n.length; r < i; r++) n[r] = this._readValueAtIndex(e, t, r, n[r]);
		else n = this._readValueAtIndex(e, t, 0, n);
		return n = r.adjustValueScaleOffset(n), n = r.resolveEnumsToStrings(n), n = r.resolveNoData(n), n;
	}
}, cr = /* @__PURE__ */ new _(), lr = class {
	constructor() {
		this._renderer = new Pe(), this._target = new Ne(1, 1), this._texTarget = new Ne(), this._quad = new Le(new Ce({
			blending: T,
			blendDst: Fe,
			blendSrc: fe,
			uniforms: {
				map: { value: null },
				pixel: { value: new F() }
			},
			vertexShader: "\n				void main() {\n\n					gl_Position = projectionMatrix * modelViewMatrix * vec4( position, 1.0 );\n\n				}\n			",
			fragmentShader: "\n				uniform sampler2D map;\n				uniform ivec2 pixel;\n\n				void main() {\n\n					gl_FragColor = texelFetch( map, pixel, 0 );\n\n				}\n			"
		}));
	}
	increaseSizeTo(e) {
		this._target.setSize(Math.max(this._target.width, e), 1);
	}
	readDataAsync(e) {
		let { _renderer: t, _target: n } = this;
		return t.readRenderTargetPixelsAsync(n, 0, 0, e.length / 4, 1, e);
	}
	readData(e) {
		let { _renderer: t, _target: n } = this;
		t.readRenderTargetPixels(n, 0, 0, e.length / 4, 1, e);
	}
	renderPixelToTarget(e, t, n) {
		let { _renderer: r, _target: i } = this;
		cr.min.copy(t), cr.max.copy(t), cr.max.x += 1, cr.max.y += 1, r.initRenderTarget(i), r.copyTextureToTexture(e, i.texture, cr, n, 0);
	}
}, ur = /* @__PURE__ */ new class {
	constructor() {
		let e = null;
		Object.getOwnPropertyNames(lr.prototype).forEach((t) => {
			t !== "constructor" && (this[t] = (...n) => (e ||= new lr(), e[t](...n)));
		});
	}
}(), dr = /* @__PURE__ */ new F(), fr = /* @__PURE__ */ new F(), pr = /* @__PURE__ */ new F();
function mr(e, t) {
	return t === 0 ? e.getAttribute("uv") : e.getAttribute(`uv${t}`);
}
function hr(e, t, n = [
	,
	,
	,
]) {
	let r = 3 * t, i = 3 * t + 1, a = 3 * t + 2;
	return e.index && (r = e.index.getX(r), i = e.index.getX(i), a = e.index.getX(a)), n[0] = r, n[1] = i, n[2] = a, n;
}
function gr(e, t, n, r, i) {
	let [a, o, s] = r, c = mr(e, t);
	dr.fromBufferAttribute(c, a), fr.fromBufferAttribute(c, o), pr.fromBufferAttribute(c, s), i.set(0, 0, 0).addScaledVector(dr, n.x).addScaledVector(fr, n.y).addScaledVector(pr, n.z);
}
function _r(e, t, n, r) {
	let i = e.x - Math.floor(e.x), a = e.y - Math.floor(e.y), o = Math.floor(i * t % t), s = Math.floor(a * n % n);
	return r.set(o, s), r;
}
//#endregion
//#region src/three/plugins/gltf/metadata/classes/PropertyTextureAccessor.js
var vr = /* @__PURE__ */ new F(), yr = /* @__PURE__ */ new F(), br = /* @__PURE__ */ new F(), xr = class extends nr {
	constructor(e, t, n = null) {
		super(e, t, n), this.channels = G(n, "channels", [0]), this.index = G(n, "index", null), this.texCoord = G(n, "texCoord", null), this.valueLength = parseInt(this.type.replace(/[^0-9]/g, "")) || 1;
	}
	readDataFromBuffer(e, t, n = null) {
		let r = this.type;
		if (r === "BOOLEAN" || r === "STRING") throw Error("PropertyTextureAccessor: BOOLEAN and STRING types not supported.");
		return Wn(e, t * this.valueLength, r, n);
	}
}, Sr = class extends rr {
	constructor(...e) {
		super(...e), this.isPropertyTextureAccessor = !0, this._asyncRead = !1, this._initProperties(xr);
	}
	getData(e, t, n, r = {}) {
		let i = this.properties;
		er(i, r);
		let a = Object.keys(i), o = a.map((e) => r[e]);
		return this.getPropertyValuesAtTexel(a, e, t, n, o), a.forEach((e, t) => r[e] = o[t]), r;
	}
	async getDataAsync(e, t, n, r = {}) {
		let i = this.properties;
		er(i, r);
		let a = Object.keys(i), o = a.map((e) => r[e]);
		return await this.getPropertyValuesAtTexelAsync(a, e, t, n, o), a.forEach((e, t) => r[e] = o[t]), r;
	}
	getPropertyValuesAtTexelAsync(...e) {
		this._asyncRead = !0;
		let t = this.getPropertyValuesAtTexel(...e);
		return this._asyncRead = !1, t;
	}
	getPropertyValuesAtTexel(e, t, n, r, i = []) {
		for (; i.length < e.length;) i.push(null);
		i.length = e.length, ur.increaseSizeTo(i.length);
		let a = this.data, o = this.definition.properties, s = this.properties, c = hr(r, t);
		for (let t = 0, i = e.length; t < i; t++) {
			let i = e[t];
			if (!o[i]) continue;
			let l = s[i], u = a[l.index];
			gr(r, l.texCoord, n, c, vr), _r(vr, u.image.width, u.image.height, yr), br.set(t, 0), ur.renderPixelToTarget(u, yr, br);
		}
		let l = new Uint8Array(e.length * 4);
		if (this._asyncRead) return ur.readDataAsync(l).then(() => (u.call(this), i));
		return ur.readData(l), u.call(this), i;
		function u() {
			for (let t = 0, n = e.length; t < n; t++) {
				let n = e[t], r = s[n], a = r.type;
				if (i[t] = $n(r, i[t]), !r) throw Error("PropertyTextureAccessor: Requested property does not exist.");
				if (!o[n]) {
					i[t] = r.resolveDefault(i);
					continue;
				}
				let c = r.valueLength * (r.count || 1), u = r.channels.map((e) => l[4 * t + e]), d = r.componentType, f = new (qn(d, a))(c);
				if (new Uint8Array(f.buffer).set(u), r.array) {
					let e = i[t];
					for (let t = 0, n = e.length; t < n; t++) e[t] = r.readDataFromBuffer(f, t, e[t]);
				} else i[t] = r.readDataFromBuffer(f, 0, i[t]);
				i[t] = r.adjustValueScaleOffset(i[t]), i[t] = r.resolveEnumsToStrings(i[t]), i[t] = r.resolveNoData(i[t]);
			}
		}
	}
	dispose() {
		this.data.forEach((e) => {
			e && (e.dispose(), e.image instanceof ImageBitmap && e.image.close());
		});
	}
}, Cr = class {
	constructor(e, t, n, r = null, i = null) {
		let { schema: a, propertyTables: o = [], propertyTextures: s = [], propertyAttributes: c = [] } = e, { enums: l, classes: u } = a, d = o.map((e) => new sr(e, u, l, n)), f = [], p = [];
		r && (r.propertyTextures && (f = r.propertyTextures.map((e) => new Sr(s[e], u, l, t))), r.propertyAttributes && (p = r.propertyAttributes.map((e) => new ar(c[e], u, l)))), this.schema = a, this.tableAccessors = d, this.textureAccessors = f, this.attributeAccessors = p, this.object = i, this.textures = t, this.nodeMetadata = r;
	}
	getPropertyTableData(e, t, n = null) {
		if (!Array.isArray(e)) n ||= {}, n = this.tableAccessors[e].getData(t, n);
		else {
			n ||= [];
			let r = Math.min(e.length, t.length);
			n.length = r;
			for (let i = 0; i < r; i++) {
				let r = this.tableAccessors[e[i]];
				n[i] = r.getData(t[i], n[i]);
			}
		}
		if (Array.isArray(e) !== Array.isArray(n) || Array.isArray(e) !== Array.isArray(t)) throw Error("StructuralMetadata: Scalar and array inputs cannot be mixed.");
		return n;
	}
	getPropertyTableInfo(e = null) {
		if (e === null && (e = this.tableAccessors.map((e, t) => t)), Array.isArray(e)) return e.map((e) => {
			let t = this.tableAccessors[e];
			return {
				name: t.name,
				className: t.definition.class
			};
		});
		{
			let t = this.tableAccessors[e];
			return {
				name: t.name,
				className: t.definition.class
			};
		}
	}
	getPropertyTextureData(e, t, n = []) {
		let r = this.textureAccessors;
		n.length = r.length;
		for (let i = 0; i < r.length; i++) n[i] = r[i].getData(e, t, this.object.geometry, n[i]);
		return n;
	}
	async getPropertyTextureDataAsync(e, t, n = []) {
		let r = this.textureAccessors;
		n.length = r.length;
		let i = [];
		for (let a = 0; a < r.length; a++) {
			let o = r[a].getDataAsync(e, t, this.object.geometry, n[a]).then((e) => {
				n[a] = e;
			});
			i.push(o);
		}
		return await Promise.all(i), n;
	}
	getPropertyTextureInfo() {
		return this.textureAccessors;
	}
	getPropertyAttributeData(e, t = []) {
		let n = this.attributeAccessors;
		t.length = n.length;
		for (let r = 0; r < n.length; r++) t[r] = n[r].getData(e, this.object.geometry, t[r]);
		return t;
	}
	getPropertyAttributeInfo() {
		return this.attributeAccessors.map((e) => ({
			name: e.name,
			className: e.definition.class
		}));
	}
	dispose() {
		this.textureAccessors.forEach((e) => e.dispose()), this.tableAccessors.forEach((e) => e.dispose()), this.attributeAccessors.forEach((e) => e.dispose());
	}
}, wr = "EXT_structural_metadata";
function Tr(e, t = []) {
	let n = e.json.textures?.length || 0, r = Array(n).fill(null);
	return t.forEach(({ properties: t }) => {
		for (let n in t) {
			let { index: i } = t[n];
			r[i] === null && (r[i] = e.loadTexture(i));
		}
	}), Promise.all(r);
}
function Er(e, t = []) {
	let n = e.json.bufferViews?.length || 0, r = Array(n).fill(null);
	return t.forEach(({ properties: t }) => {
		for (let n in t) {
			let { values: i, arrayOffsets: a, stringOffsets: o } = t[n];
			r[i] === null && (r[i] = e.getDependency("bufferView", i)), r[a] === null && (r[a] = e.getDependency("bufferView", a)), r[o] === null && (r[o] = e.getDependency("bufferView", o));
		}
	}), Promise.all(r);
}
var Dr = class {
	constructor(e) {
		this.parser = e, this.name = wr;
	}
	async afterRoot({ scene: e, parser: t }) {
		let n = t.json.extensionsUsed;
		if (!n || !n.includes(wr)) return;
		let r = null, i = t.json.extensions[wr];
		if (i.schemaUri) {
			let { manager: e, path: n, requestHeader: a, crossOrigin: o } = t.options, s = new URL(i.schemaUri, n).toString(), c = new A(e);
			c.setCrossOrigin(o), c.setResponseType("json"), c.setRequestHeader(a), r = c.loadAsync(s).then((e) => {
				i = {
					...i,
					schema: e
				};
			});
		}
		let [a, o] = await Promise.all([
			Tr(t, i.propertyTextures),
			Er(t, i.propertyTables),
			r
		]), s = new Cr(i, a, o);
		e.userData.structuralMetadata = s, e.traverse((e) => {
			if (t.associations.has(e)) {
				let { meshes: n, primitives: r } = t.associations.get(e), c = t.json.meshes[n]?.primitives[r];
				if (c && c.extensions && c.extensions[wr]) {
					let t = c.extensions[wr];
					e.userData.structuralMetadata = new Cr(i, a, o, t, e);
				} else e.userData.structuralMetadata = s;
			}
		});
	}
}, Or = /* @__PURE__ */ new F(), kr = /* @__PURE__ */ new F(), Ar = /* @__PURE__ */ new F();
function jr(e) {
	return e.x > e.y && e.x > e.z ? 0 : e.y > e.z ? 1 : 2;
}
var Mr = class {
	constructor(e, t, n) {
		this.geometry = e, this.textures = t, this.data = n, this._asyncRead = !1, this.featureIds = n.featureIds.map((e) => {
			let { texture: t, ...n } = e, r = {
				label: null,
				propertyTable: null,
				nullFeatureId: null,
				...n
			};
			return t && (r.texture = {
				texCoord: 0,
				channels: [0],
				...t
			}), r;
		});
	}
	getTextures() {
		return this.textures;
	}
	getFeatureInfo() {
		return this.featureIds;
	}
	getFeaturesAsync(...e) {
		this._asyncRead = !0;
		let t = this.getFeatures(...e);
		return this._asyncRead = !1, t;
	}
	getFeatures(e, t) {
		let { geometry: n, textures: r, featureIds: i } = this, a = Array(i.length).fill(null), o = i.length;
		ur.increaseSizeTo(o);
		let s = hr(n, e), c = s[jr(t)];
		for (let e = 0, o = i.length; e < o; e++) {
			let o = i[e], l = "nullFeatureId" in o ? o.nullFeatureId : null;
			if ("texture" in o) {
				let i = r[o.texture.index];
				gr(n, o.texture.texCoord, t, s, Or), _r(Or, i.image.width, i.image.height, kr), Ar.set(e, 0), ur.renderPixelToTarget(r[o.texture.index], kr, Ar);
			} else if ("attribute" in o) {
				let t = n.getAttribute(`_feature_id_${o.attribute}`).getX(c);
				t !== l && (a[e] = t);
			} else {
				let t = c;
				t !== l && (a[e] = t);
			}
		}
		let l = new Uint8Array(o * 4);
		if (this._asyncRead) return ur.readDataAsync(l).then(() => (u(), a));
		return ur.readData(l), u(), a;
		function u() {
			let e = new Uint32Array(1);
			for (let t = 0, n = i.length; t < n; t++) {
				let n = i[t], r = "nullFeatureId" in n ? n.nullFeatureId : null;
				if ("texture" in n) {
					let { channels: i } = n.texture, o = i.map((e) => l[4 * t + e]);
					new Uint8Array(e.buffer).set(o);
					let s = e[0];
					s !== r && (a[t] = s);
				}
			}
		}
	}
	dispose() {
		this.textures.forEach((e) => {
			e && (e.dispose(), e.image instanceof ImageBitmap && e.image.close());
		});
	}
}, Nr = "EXT_mesh_features";
function Pr(e, t, n) {
	e.traverse((e) => {
		if (t.associations.has(e)) {
			let { meshes: r, primitives: i } = t.associations.get(e), a = t.json.meshes[r]?.primitives[i];
			a && a.extensions && a.extensions[Nr] && n(e, a.extensions[Nr]);
		}
	});
}
var Fr = class {
	constructor(e) {
		this.parser = e, this.name = Nr;
	}
	async afterRoot({ scene: e, parser: t }) {
		let n = t.json.extensionsUsed;
		if (!n || !n.includes(Nr)) return;
		let r = t.json.textures?.length || 0, i = Array(r).fill(null);
		Pr(e, t, (e, { featureIds: n }) => {
			n.forEach((e) => {
				if (e.texture && i[e.texture.index] === null) {
					let n = e.texture.index;
					i[n] = t.loadTexture(n);
				}
			});
		});
		let a = await Promise.all(i);
		Pr(e, t, (e, t) => {
			e.userData.meshFeatures = new Mr(e.geometry, a, t);
		});
	}
}, Ir = class {
	constructor() {
		this.name = "CESIUM_RTC";
	}
	afterRoot(e) {
		if (e.parser.json.extensions && e.parser.json.extensions.CESIUM_RTC) {
			let { center: t } = e.parser.json.extensions.CESIUM_RTC;
			t && (e.scene.position.x += t[0], e.scene.position.y += t[1], e.scene.position.z += t[2]);
		}
	}
}, Lr = class {
	constructor(e) {
		e = {
			metadata: !0,
			rtc: !0,
			plugins: [],
			dracoLoader: null,
			ktxLoader: null,
			meshoptDecoder: null,
			autoDispose: !0,
			...e
		}, this.tiles = null, this.metadata = e.metadata, this.rtc = e.rtc, this.plugins = e.plugins, this.dracoLoader = e.dracoLoader, this.ktxLoader = e.ktxLoader, this.meshoptDecoder = e.meshoptDecoder, this._gltfRegex = /\.(gltf|glb)$/g, this._dracoRegex = /\.drc$/g, this._loader = null;
	}
	init(e) {
		let t = new Ie(e.manager);
		this.dracoLoader && (t.setDRACOLoader(this.dracoLoader), e.manager.addHandler(this._dracoRegex, this.dracoLoader)), this.ktxLoader && t.setKTX2Loader(this.ktxLoader), this.meshoptDecoder && t.setMeshoptDecoder(this.meshoptDecoder), this.rtc && t.register(() => new Ir()), this.metadata && (t.register(() => new Dr()), t.register(() => new Fr())), this.plugins.forEach((e) => t.register(e)), e.manager.addHandler(this._gltfRegex, t), this.tiles = e, this._loader = t;
	}
	dispose() {
		this.tiles.manager.removeHandler(this._gltfRegex), this.tiles.manager.removeHandler(this._dracoRegex), this.autoDispose && (this.ktxLoader.dispose(), this.dracoLoader.dispose());
	}
}, Rr = /* @__PURE__ */ new Te(), zr = class {
	constructor(e) {
		e = {
			up: "+z",
			recenter: !0,
			lat: null,
			lon: null,
			height: 0,
			azimuth: 0,
			elevation: 0,
			roll: 0,
			...e
		}, this.tiles = null, this.up = e.up.toLowerCase().replace(/\s+/, ""), this.lat = e.lat, this.lon = e.lon, this.height = e.height, this.azimuth = e.azimuth, this.elevation = e.elevation, this.roll = e.roll, this.recenter = e.recenter, this._callback = null;
	}
	init(e) {
		this.tiles = e, this._callback = () => {
			let { up: t, lat: n, lon: r, height: i, azimuth: a, elevation: o, roll: s, recenter: c } = this;
			if (n !== null && r !== null) this.transformLatLonHeightToOrigin(n, r, i, a, o, s);
			else {
				let { ellipsoid: n } = e, r = Math.min(...n.radius);
				if (e.getBoundingSphere(Rr), Rr.center.length() > r * .5) {
					let e = {};
					n.getPositionToCartographic(Rr.center, e), this.transformLatLonHeightToOrigin(e.lat, e.lon, e.height);
				} else {
					let n = e.group;
					switch (n.rotation.set(0, 0, 0), t) {
						case "x":
						case "+x":
							n.rotation.z = Math.PI / 2;
							break;
						case "-x":
							n.rotation.z = -Math.PI / 2;
							break;
						case "y":
						case "+y": break;
						case "-y":
							n.rotation.z = Math.PI;
							break;
						case "z":
						case "+z":
							n.rotation.x = -Math.PI / 2;
							break;
						case "-z":
							n.rotation.x = Math.PI / 2;
							break;
					}
					e.group.position.copy(Rr.center).applyEuler(n.rotation).multiplyScalar(-1);
				}
			}
			c || e.group.position.setScalar(0), e.removeEventListener("load-root-tileset", this._callback);
		}, e.addEventListener("load-root-tileset", this._callback), e.root && this._callback();
	}
	transformLatLonHeightToOrigin(e, t, n = 0, r = 0, i = 0, a = 0) {
		let { group: o, ellipsoid: s } = this.tiles;
		s.getObjectFrame(e, t, n, r, i, a, o.matrix, 2), o.matrix.invert().decompose(o.position, o.quaternion, o.scale), o.updateMatrixWorld();
	}
	dispose() {
		let { group: e } = this.tiles;
		e.position.setScalar(0), e.quaternion.identity(), e.scale.set(1, 1, 1), this.tiles.removeEventListener("load-root-tileset", this._callback);
	}
}, Br = class {
	set delay(e) {
		this.deferCallbacks.delay = e;
	}
	get delay() {
		return this.deferCallbacks.delay;
	}
	set bytesTarget(e) {
		this.lruCache.minBytesSize = e;
	}
	get bytesTarget() {
		return this.lruCache.minBytesSize;
	}
	get estimatedGpuBytes() {
		return this.lruCache.cachedBytes;
	}
	constructor(e = {}) {
		let { delay: t = 0, bytesTarget: r = 0 } = e;
		this.name = "UNLOAD_TILES_PLUGIN", this.tiles = null, this.lruCache = new n(), this.deferCallbacks = new Vr(), this.delay = t, this.bytesTarget = r;
	}
	init(e) {
		this.tiles = e;
		let { lruCache: t, deferCallbacks: n } = this, r = (t) => {
			let n = t.engineData.scene;
			e.visibleTiles.has(t) || e.invokeOnePlugin((e) => e.unloadTileFromGPU && e.unloadTileFromGPU(n, t));
		};
		this._onUpdateBefore = () => {
			t.unloadPriorityCallback = e.lruCache.unloadPriorityCallback, t.minSize = Infinity, t.maxSize = Infinity, t.maxBytesSize = Infinity, t.unloadPercent = 1, t.autoMarkUnused = !1;
		}, this._onVisibilityChangeCallback = ({ tile: i, scene: a, visible: o }) => {
			o ? (t.add(i, r), t.setMemoryUsage(i, e.calculateBytesUsed(i, a) || 1), e.markTileUsed(i), n.cancel(i)) : n.run(i);
		}, this._onDisposeModel = ({ tile: e }) => {
			t.remove(e), n.cancel(e);
		}, n.callback = (e) => {
			t.markUnused(e), t.scheduleUnload();
		}, e.forEachLoadedModel((t, n) => {
			let r = e.visibleTiles.has(n);
			this._onVisibilityChangeCallback({
				tile: n,
				visible: r
			});
		}), e.addEventListener("tile-visibility-change", this._onVisibilityChangeCallback), e.addEventListener("update-before", this._onUpdateBefore), e.addEventListener("dispose-model", this._onDisposeModel);
	}
	unloadTileFromGPU(e, t) {
		e && e.traverse((e) => {
			if (e.material) {
				let t = e.material;
				t.dispose();
				for (let e in t) {
					let n = t[e];
					n && n.isTexture && n.dispose();
				}
			}
			e.geometry && e.geometry.dispose();
		});
	}
	dispose() {
		let { lruCache: e, tiles: t, deferCallbacks: n } = this;
		t.removeEventListener("tile-visibility-change", this._onVisibilityChangeCallback), t.removeEventListener("update-before", this._onUpdateBefore), t.removeEventListener("dispose-model", this._onDisposeModel), n.cancelAll(), e.minBytesSize = 0, e.minSize = 0, e.maxSize = 0, e.markAllUnused(), e.scheduleUnload();
	}
}, Vr = class {
	constructor(e = () => {}) {
		this.map = /* @__PURE__ */ new Map(), this.callback = e, this.delay = 0;
	}
	run(e) {
		let { map: t, delay: n } = this;
		if (t.has(e)) throw Error("DeferCallbackManager: Callback already initialized.");
		n === 0 ? this.callback(e) : t.set(e, setTimeout(() => {
			this.callback(e), t.delete(e);
		}, n));
	}
	cancel(e) {
		let { map: t } = this;
		t.has(e) && (clearTimeout(t.get(e)), t.delete(e));
	}
	cancelAll() {
		this.map.forEach((e, t) => {
			this.cancel(t);
		});
	}
}, { clamp: Hr } = j, Ur = class {
	constructor() {
		this.duration = 250, this.fadeCount = 0, this._lastTick = -1, this._fadeState = /* @__PURE__ */ new Map(), this.onFadeComplete = null, this.onFadeStart = null, this.onFadeSetComplete = null, this.onFadeSetStart = null;
	}
	deleteObject(e) {
		e && this.completeFade(e);
	}
	guaranteeState(e) {
		let t = this._fadeState;
		return t.has(e) ? !1 : (t.set(e, {
			fadeInTarget: 0,
			fadeOutTarget: 0,
			fadeIn: 0,
			fadeOut: 0
		}), !0);
	}
	completeFade(e) {
		let t = this._fadeState;
		if (!t.has(e)) return;
		let n = t.get(e).fadeOutTarget === 0;
		t.delete(e), this.fadeCount--, this.onFadeComplete && this.onFadeComplete(e, n), this.fadeCount === 0 && this.onFadeSetComplete && this.onFadeSetComplete();
	}
	completeAllFades() {
		this._fadeState.forEach((e, t) => {
			this.completeFade(t);
		});
	}
	forEachObject(e) {
		this._fadeState.forEach((t, n) => {
			e(n, t);
		});
	}
	fadeIn(e) {
		let t = this.guaranteeState(e), n = this._fadeState.get(e);
		n.fadeInTarget = 1, n.fadeOutTarget = 0, n.fadeOut = 0, t && (this.fadeCount++, this.fadeCount === 1 && this.onFadeSetStart && this.onFadeSetStart(), this.onFadeStart && this.onFadeStart(e));
	}
	fadeOut(e) {
		let t = this.guaranteeState(e), n = this._fadeState.get(e);
		n.fadeOutTarget = 1, t && (n.fadeInTarget = 1, n.fadeIn = 1, this.fadeCount++, this.fadeCount === 1 && this.onFadeSetStart && this.onFadeSetStart(), this.onFadeStart && this.onFadeStart(e));
	}
	isFading(e) {
		return this._fadeState.has(e);
	}
	isFadingOut(e) {
		let t = this._fadeState.get(e);
		return t && t.fadeOutTarget === 1;
	}
	update() {
		let e = window.performance.now();
		this._lastTick === -1 && (this._lastTick = e);
		let t = Hr((e - this._lastTick) / this.duration, 0, 1);
		this._lastTick = e, this._fadeState.forEach((e, n) => {
			let { fadeOutTarget: r, fadeInTarget: i } = e, { fadeOut: a, fadeIn: o } = e, s = Math.sign(i - o);
			o = Hr(o + s * t, 0, 1);
			let c = Math.sign(r - a);
			a = Hr(a + c * t, 0, 1), e.fadeIn = o, e.fadeOut = a, ((a === 1 || a === 0) && (o === 1 || o === 0) || a >= o) && this.completeFade(n);
		});
	}
}, Wr = Symbol("FADE_PARAMS");
function Gr(e, t) {
	if (e[Wr]) return e[Wr];
	let n = {
		fadeIn: { value: 0 },
		fadeOut: { value: 0 },
		fadeTexture: { value: null }
	};
	return e[Wr] = n, e.defines = {
		...e.defines || {},
		FEATURE_FADE: 0
	}, e.onBeforeCompile = (e) => {
		t && t(e), e.uniforms = {
			...e.uniforms,
			...n
		}, e.vertexShader = e.vertexShader.replace(/void\s+main\(\)\s+{/, (e) => `
					#ifdef USE_BATCHING_FRAG

					varying float vBatchId;

					#endif

					${e}

						#ifdef USE_BATCHING_FRAG

						// add 0.5 to the value to avoid floating error that may cause flickering
						vBatchId = getIndirectIndex( gl_DrawID ) + 0.5;

						#endif
				`), e.fragmentShader = e.fragmentShader.replace(/void main\(/, (e) => `
				#if FEATURE_FADE

				// adapted from https://www.shadertoy.com/view/Mlt3z8
				float bayerDither2x2( vec2 v ) {

					return mod( 3.0 * v.y + 2.0 * v.x, 4.0 );

				}

				float bayerDither4x4( vec2 v ) {

					vec2 P1 = mod( v, 2.0 );
					vec2 P2 = floor( 0.5 * mod( v, 4.0 ) );
					return 4.0 * bayerDither2x2( P1 ) + bayerDither2x2( P2 );

				}

				// the USE_BATCHING define is not available in fragment shaders
				#ifdef USE_BATCHING_FRAG

				// functions for reading the fade state of a given batch id
				uniform sampler2D fadeTexture;
				varying float vBatchId;
				vec2 getFadeValues( const in float i ) {

					int size = textureSize( fadeTexture, 0 ).x;
					int j = int( i );
					int x = j % size;
					int y = j / size;
					return texelFetch( fadeTexture, ivec2( x, y ), 0 ).rg;

				}

				#else

				uniform float fadeIn;
				uniform float fadeOut;

				#endif

				#endif

				${e}
			`).replace(/#include <dithering_fragment>/, (e) => `

				${e}

				#if FEATURE_FADE

				#ifdef USE_BATCHING_FRAG

				vec2 fadeValues = getFadeValues( vBatchId );
				float fadeIn = fadeValues.r;
				float fadeOut = fadeValues.g;

				#endif

				float bayerValue = bayerDither4x4( floor( mod( gl_FragCoord.xy, 4.0 ) ) );
				float bayerBins = 16.0;
				float dither = ( 0.5 + bayerValue ) / bayerBins;
				if ( dither >= fadeIn ) {

					discard;

				}

				if ( dither < fadeOut ) {

					discard;

				}

				#endif

			`);
	}, n;
}
//#endregion
//#region src/three/plugins/fade/FadeMaterialManager.js
var Kr = class {
	constructor() {
		this._fadeParams = /* @__PURE__ */ new WeakMap(), this.fading = 0;
	}
	setFade(e, t, n) {
		if (!e) return;
		let r = this._fadeParams;
		e.traverse((e) => {
			let i = e.material;
			if (i && r.has(i)) {
				let e = r.get(i);
				e.fadeIn.value = t, e.fadeOut.value = n;
				let a = Number(!(t === 0 || t === 1) || !(n === 0 || n === 1));
				i.defines.FEATURE_FADE !== a && (this.fading += a === 1 ? 1 : -1, i.defines.FEATURE_FADE = a, i.needsUpdate = !0);
			}
		});
	}
	prepareScene(e) {
		e.traverse((e) => {
			e.material && this.prepareMaterial(e.material);
		});
	}
	deleteScene(e) {
		if (!e) return;
		this.setFade(e, 1, 0);
		let t = this._fadeParams;
		e.traverse((e) => {
			let n = e.material;
			n && t.delete(n);
		});
	}
	prepareMaterial(e) {
		let t = this._fadeParams;
		t.has(e) || t.set(e, Gr(e, e.onBeforeCompile));
	}
}, qr = class {
	constructor(e, t = new P()) {
		this.other = e, this.material = t, this.visible = !0, this.parent = null, this._instanceInfo = [], this._visibilityChanged = !0;
		let n = new Proxy(this, {
			get(t, r) {
				if (r in t) return t[r];
				{
					let i = e[r];
					return i instanceof Function ? (...e) => (t.syncInstances(), i.call(n, ...e)) : e[r];
				}
			},
			set(t, n, r) {
				return n in t ? t[n] = r : e[n] = r, !0;
			},
			deleteProperty(t, n) {
				return n in t ? delete t[n] : delete e[n];
			}
		});
		return n;
	}
	syncInstances() {
		let e = this._instanceInfo, t = this.other._instanceInfo;
		for (; t.length > e.length;) {
			let n = e.length;
			e.push(new Proxy({ visible: !1 }, {
				get(e, r) {
					return r in e ? e[r] : t[n][r];
				},
				set(e, r, i) {
					return r in e ? e[r] = i : t[n][r] = i, !0;
				}
			}));
		}
	}
}, Jr = class extends qr {
	constructor(...e) {
		super(...e);
		let t = this.material, n = Gr(t, t.onBeforeCompile);
		t.defines.FEATURE_FADE = 1, t.defines.USE_BATCHING_FRAG = 1, t.needsUpdate = !0, this.fadeTexture = null, this._fadeParams = n;
	}
	setFadeAt(e, t, n) {
		this._initFadeTexture(), this.fadeTexture.setValueAt(e, t * 255, n * 255);
	}
	_initFadeTexture() {
		let e = Math.sqrt(this._maxInstanceCount);
		e = Math.ceil(e);
		let t = e * e * 2, n = this.fadeTexture;
		if (!n || n.image.data.length !== t) {
			let r = new Yr(new Uint8Array(t), e, e, ve, Ae);
			if (n) {
				n.dispose();
				let e = n.image.data, t = this.fadeTexture.image.data, r = Math.min(e.length, t.length);
				t.set(new e.constructor(e.buffer, 0, r));
			}
			this.fadeTexture = r, this._fadeParams.fadeTexture.value = r, r.needsUpdate = !0;
		}
	}
	dispose() {
		this.fadeTexture && this.fadeTexture.dispose();
	}
}, Yr = class extends E {
	setValueAt(e, ...t) {
		let { data: n, width: r, height: i } = this.image, a = Math.floor(n.length / (r * i)), o = !1;
		for (let r = 0; r < a; r++) {
			let i = e * a + r, s = n[i], c = t[r] || 0;
			s !== c && (n[i] = c, o = !0);
		}
		o && (this.needsUpdate = !0);
	}
}, Xr = Symbol("HAS_POPPED_IN");
function Zr(e) {
	let t = e;
	for (; t;) {
		if (t.traversal.wasSetActive) return t.traversal.wasInFrustum;
		t = t.parent;
	}
	return !1;
}
var Qr = /* @__PURE__ */ new I(), $r = /* @__PURE__ */ new I(), ei = /* @__PURE__ */ new ge(), ti = /* @__PURE__ */ new ge(), ni = /* @__PURE__ */ new I();
function ri() {
	let e = this._fadeManager, t = this._fadeMaterialManager, n = this._fadingBefore, r = this._prevCameraTransforms, { tiles: i, maximumFadeOutTiles: a, batchedMesh: o } = this, { cameras: s } = i;
	e.update();
	let c = e.fadeCount;
	if (n !== 0 && c !== 0 && (i.dispatchEvent({ type: "fade-change" }), i.dispatchEvent({ type: "needs-render" })), a < this._fadingOutCount) {
		let t = !0;
		s.forEach((e) => {
			if (!r.has(e)) return;
			let n = e.matrixWorld, i = r.get(e);
			n.decompose($r, ti, ni), i.decompose(Qr, ei, ni);
			let a = ti.angleTo(ei), o = $r.distanceTo(Qr);
			t &&= a > .25 || o > .1;
		}), t && e.completeAllFades();
	}
	if (s.forEach((e) => {
		r.get(e).copy(e.matrixWorld);
	}), e.forEachObject((e, { fadeIn: n, fadeOut: r }) => {
		let a = e.engineData.scene;
		i.markTileUsed(e), a && t.setFade(a, n, r), this.forEachBatchIds(e, (e, t, i) => {
			t.setFadeAt(e, n, r), t.setVisibleAt(e, !0), i.batchedMesh.setVisibleAt(e, !1);
		});
	}), o) {
		let e = i.getPluginByName("BATCHED_TILES_PLUGIN").batchedMesh.material;
		o.material.map = e.map;
	}
}
var ii = class {
	get fadeDuration() {
		return this._fadeManager.duration;
	}
	set fadeDuration(e) {
		this._fadeManager.duration = Number(e);
	}
	get fadingTiles() {
		return this._fadeManager.fadeCount;
	}
	constructor(e) {
		e = {
			maximumFadeOutTiles: 50,
			fadeRootTiles: !1,
			fadeDuration: 250,
			...e
		}, this.name = "FADE_TILES_PLUGIN", this.priority = -2, this.tiles = null, this.batchedMesh = null, this._quickFadeTiles = /* @__PURE__ */ new Set(), this._fadeManager = new Ur(), this._fadeMaterialManager = new Kr(), this._prevCameraTransforms = null, this._fadingOutCount = 0, this.maximumFadeOutTiles = e.maximumFadeOutTiles, this.fadeRootTiles = e.fadeRootTiles, this.fadeDuration = e.fadeDuration;
	}
	init(e) {
		this._onLoadModel = ({ scene: e }) => {
			this._fadeMaterialManager.prepareScene(e);
		}, this._onDisposeModel = ({ tile: e, scene: t }) => {
			this.tiles.visibleTiles.has(e) && this._quickFadeTiles.add(e.parent), this._fadeManager.deleteObject(e), this._fadeMaterialManager.deleteScene(t);
		}, this._onAddCamera = ({ camera: e }) => {
			this._prevCameraTransforms.set(e, new M());
		}, this._onDeleteCamera = ({ camera: e }) => {
			this._prevCameraTransforms.delete(e);
		}, this._onTileVisibilityChange = ({ tile: e }) => {
			this.forEachBatchIds(e, (e, t, n) => {
				t.setFadeAt(e, 0, 0), t.setVisibleAt(e, !1), n.batchedMesh.setVisibleAt(e, !1);
			});
		}, this._onUpdateBefore = () => {
			this._fadingBefore = this._fadeManager.fadeCount;
		}, this._onUpdateAfter = () => {
			ri.call(this);
		}, e.addEventListener("load-model", this._onLoadModel), e.addEventListener("dispose-model", this._onDisposeModel), e.addEventListener("add-camera", this._onAddCamera), e.addEventListener("delete-camera", this._onDeleteCamera), e.addEventListener("update-before", this._onUpdateBefore), e.addEventListener("update-after", this._onUpdateAfter), e.addEventListener("tile-visibility-change", this._onTileVisibilityChange);
		let t = this._fadeManager;
		t.onFadeSetStart = () => {
			e.dispatchEvent({ type: "fade-start" }), e.dispatchEvent({ type: "needs-render" });
		}, t.onFadeSetComplete = () => {
			e.dispatchEvent({ type: "fade-end" }), e.dispatchEvent({ type: "needs-render" });
		}, t.onFadeComplete = (t, n) => {
			this._fadeMaterialManager.setFade(t.engineData.scene, 0, 0), this.forEachBatchIds(t, (e, t, r) => {
				t.setFadeAt(e, 0, 0), t.setVisibleAt(e, !1), r.batchedMesh.setVisibleAt(e, n);
			}), n || (e.invokeOnePlugin((e) => e !== this && e.setTileVisible && e.setTileVisible(t, !1)), this._fadingOutCount--);
		};
		let n = /* @__PURE__ */ new Map();
		e.cameras.forEach((e) => {
			n.set(e, new M());
		}), e.forEachLoadedModel((e, t) => {
			this._onLoadModel({ scene: e });
		}), this.tiles = e, this._fadeManager = t, this._prevCameraTransforms = n;
	}
	initBatchedMesh() {
		let e = this.tiles.getPluginByName("BATCHED_TILES_PLUGIN")?.batchedMesh;
		if (e) {
			if (this.batchedMesh === null) {
				this._onBatchedMeshDispose = () => {
					this.batchedMesh.dispose(), this.batchedMesh.removeFromParent(), this.batchedMesh = null, e.removeEventListener("dispose", this._onBatchedMeshDispose);
				};
				let t = e.material.clone();
				t.onBeforeCompile = e.material.onBeforeCompile, this.batchedMesh = new Jr(e, t), this.tiles.group.add(this.batchedMesh);
			}
		} else this.batchedMesh !== null && (this._onBatchedMeshDispose(), this._onBatchedMeshDispose = null);
	}
	setTileVisible(e, t) {
		let n = this._fadeManager, r = n.isFading(e);
		if (!Zr(e)) return r && n.completeFade(e), !1;
		if (n.isFadingOut(e) && this._fadingOutCount--, t ? e.internal.depthFromRenderedParent === 1 ? ((e[Xr] || this.fadeRootTiles) && this._fadeManager.fadeIn(e), e[Xr] = !0) : this._fadeManager.fadeIn(e) : (this._fadingOutCount++, n.fadeOut(e)), this._quickFadeTiles.has(e) && (this._fadeManager.completeFade(e), this._quickFadeTiles.delete(e)), r) return !0;
		let i = this._fadeManager.isFading(e);
		return !!(!t && i);
	}
	dispose() {
		let e = this.tiles;
		this._fadeManager.completeAllFades(), this.batchedMesh !== null && this._onBatchedMeshDispose(), e.removeEventListener("load-model", this._onLoadModel), e.removeEventListener("dispose-model", this._onDisposeModel), e.removeEventListener("add-camera", this._onAddCamera), e.removeEventListener("delete-camera", this._onDeleteCamera), e.removeEventListener("update-before", this._onUpdateBefore), e.removeEventListener("update-after", this._onUpdateAfter), e.removeEventListener("tile-visibility-change", this._onTileVisibilityChange), e.forEachLoadedModel((e, t) => {
			this._fadeManager.deleteObject(t);
		});
	}
	forEachBatchIds(e, t) {
		if (this.initBatchedMesh(), this.batchedMesh) {
			let n = this.tiles.getPluginByName("BATCHED_TILES_PLUGIN"), r = n.getTileBatchIds(e);
			r && r.forEach((e) => {
				t(e, this.batchedMesh, n);
			});
		}
	}
}, ai = /* @__PURE__ */ new M(), oi = /* @__PURE__ */ new I(), si = /* @__PURE__ */ new I(), ci = class extends g {
	constructor(...e) {
		super(...e), this.resetDistance = 1e4, this._matricesTextureHandle = null, this._lastCameraPos = new M(), this._forceUpdate = !0, this._matrices = [];
	}
	setMatrixAt(e, t) {
		super.setMatrixAt(e, t), this._forceUpdate = !0;
		let n = this._matrices;
		for (; n.length <= e;) n.push(new M());
		n[e].copy(t);
	}
	setInstanceCount(...e) {
		super.setInstanceCount(...e);
		let t = this._matrices;
		for (; t.length > this.instanceCount;) t.pop();
	}
	onBeforeRender(e, t, n, r, i, a) {
		super.onBeforeRender(e, t, n, r, i, a), oi.setFromMatrixPosition(n.matrixWorld), si.setFromMatrixPosition(this._lastCameraPos);
		let o = this._matricesTexture, s = this._modelViewMatricesTexture;
		if ((!s || s.image.width !== o.image.width || s.image.height !== o.image.height) && (s && s.dispose(), s = o.clone(), s.source = new we({
			...s.image,
			data: s.image.data.slice()
		}), this._modelViewMatricesTexture = s), this._forceUpdate || oi.distanceTo(si) > this.resetDistance) {
			let e = this._matrices, t = s.image.data;
			for (let r = 0; r < this.maxInstanceCount; r++) {
				let i = e[r];
				i ? ai.copy(i) : ai.identity(), ai.premultiply(this.matrixWorld).premultiply(n.matrixWorldInverse).toArray(t, r * 16);
			}
			s.needsUpdate = !0, this._lastCameraPos.copy(n.matrixWorld), this._forceUpdate = !1;
		}
		this._matricesTextureHandle = this._matricesTexture, this._matricesTexture = this._modelViewMatricesTexture, this.matrixWorld.copy(this._lastCameraPos);
	}
	onAfterRender() {
		this.updateMatrixWorld(), this._matricesTexture = this._matricesTextureHandle, this._matricesTextureHandle = null;
	}
	onAfterShadow(e, t, n, r, i, a) {
		this.onAfterRender(e, null, r, i, a);
	}
	dispose() {
		super.dispose(), this._modelViewMatricesTexture && this._modelViewMatricesTexture.dispose();
	}
}, K = /* @__PURE__ */ new N(), li = [], ui = class extends ci {
	constructor(...e) {
		super(...e), this.expandPercent = .25, this.maxInstanceExpansionSize = Infinity, this._freeGeometryIds = [];
	}
	findFreeId(e, t, n) {
		let r = !!this.geometry.index, i = Math.max(r ? e.index.count : -1, n), a = Math.max(e.attributes.position.count, t), o = -1, s = Infinity, c = this._freeGeometryIds;
		if (c.forEach((e, t) => {
			let { reservedIndexCount: n, reservedVertexCount: r } = this.getGeometryRangeAt(e);
			if (n >= i && r >= a) {
				let e = i - n + (a - r);
				e < s && (o = t, s = e);
			}
		}), o !== -1) {
			let e = c[o];
			return c.splice(o, 1), e;
		} else return -1;
	}
	addGeometry(e, t, n) {
		let r = !!this.geometry.index;
		n = Math.max(r ? e.index.count : -1, n), t = Math.max(e.attributes.position.count, t);
		let { expandPercent: i, _freeGeometryIds: a } = this, o = this.findFreeId(e, t, n);
		if (o !== -1) this.setGeometryAt(o, e);
		else {
			let r = () => {
				let e = this.unusedVertexCount < t, r = this.unusedIndexCount < n;
				return e || r;
			}, s = e.index, c = e.attributes.position;
			if (t = Math.max(t, c.count), n = Math.max(n, s ? s.count : 0), r() && (a.forEach((e) => this.deleteGeometry(e)), a.length = 0, this.optimize(), r())) {
				let e = this.geometry.index, r = this.geometry.attributes.position, a, o;
				if (e) {
					let t = Math.ceil(i * e.count);
					a = Math.max(t, n, s.count) + e.count;
				} else a = Math.max(this.unusedIndexCount, n);
				if (r) {
					let e = Math.ceil(i * r.count);
					o = Math.max(e, t, c.count) + r.count;
				} else o = Math.max(this.unusedVertexCount, t);
				this.setGeometrySize(o, a);
			}
			o = super.addGeometry(e, t, n);
		}
		return o;
	}
	addInstance(e) {
		if (this.maxInstanceCount === this.instanceCount) {
			let e = Math.ceil(this.maxInstanceCount * (1 + this.expandPercent));
			this.setInstanceCount(Math.min(e, this.maxInstanceExpansionSize));
		}
		return super.addInstance(e);
	}
	deleteInstance(e) {
		let t = this.getGeometryIdAt(e);
		return t !== -1 && this._freeGeometryIds.push(t), super.deleteInstance(e);
	}
	raycastInstance(e, t, n) {
		let r = this.geometry, i = this.getGeometryIdAt(e);
		K.material = this.material, K.geometry.index = r.index, K.geometry.attributes = r.attributes;
		let a = this.getGeometryRangeAt(i);
		K.geometry.setDrawRange(a.start, a.count), K.geometry.boundingBox === null && (K.geometry.boundingBox = new v()), K.geometry.boundingSphere === null && (K.geometry.boundingSphere = new Te()), this.getMatrixAt(e, K.matrixWorld).premultiply(this.matrixWorld), this.getBoundingBoxAt(i, K.geometry.boundingBox), this.getBoundingSphereAt(i, K.geometry.boundingSphere), K.raycast(t, li);
		for (let t = 0, r = li.length; t < r; t++) {
			let r = li[t];
			r.object = this, r.batchId = e, n.push(r);
		}
		li.length = 0;
	}
};
//#endregion
//#region src/three/plugins/batched/utilities.js
function di(e) {
	return e.r === 1 && e.g === 1 && e.b === 1;
}
function fi(e) {
	e.needsUpdate = !0, e.onBeforeCompile = (e) => {
		e.vertexShader = e.vertexShader.replace("#include <common>", "\n				#include <common>\n				varying float texture_index;\n				").replace("#include <uv_vertex>", "\n				#include <uv_vertex>\n				texture_index = getIndirectIndex( gl_DrawID );\n				"), e.fragmentShader = e.fragmentShader.replace("#include <map_pars_fragment>", "\n				#ifdef USE_MAP\n				precision highp sampler2DArray;\n				uniform sampler2DArray map;\n				varying float texture_index;\n				#endif\n				").replace("#include <map_fragment>", "\n				#ifdef USE_MAP\n					diffuseColor *= texture( map, vec3( vMapUv, texture_index ) );\n				#endif\n				");
	};
}
//#endregion
//#region src/three/plugins/batched/BatchedTilesPlugin.js
var pi = new Le(new P()), mi = new E(new Uint8Array([
	255,
	255,
	255,
	255
]), 1, 1);
mi.needsUpdate = !0;
var hi = class {
	constructor(e = {}) {
		if (parseInt(_e) < 170) throw Error("BatchedTilesPlugin: Three.js revision 170 or higher required.");
		e = {
			instanceCount: 500,
			vertexCount: 750,
			indexCount: 2e3,
			expandPercent: .25,
			maxInstanceCount: Infinity,
			discardOriginalContent: !0,
			textureSize: null,
			material: null,
			renderer: null,
			...e
		}, this.name = "BATCHED_TILES_PLUGIN", this.priority = -1;
		let t = e.renderer.getContext();
		this.instanceCount = e.instanceCount, this.vertexCount = e.vertexCount, this.indexCount = e.indexCount, this.material = e.material ? e.material.clone() : null, this.expandPercent = e.expandPercent, this.maxInstanceCount = Math.min(e.maxInstanceCount, t.getParameter(t.MAX_3D_TEXTURE_SIZE)), this.renderer = e.renderer, this.discardOriginalContent = e.discardOriginalContent, this.textureSize = e.textureSize, this.batchedMesh = null, this.arrayTarget = null, this.tiles = null, this._tileToInstanceId = /* @__PURE__ */ new Map();
	}
	init(e) {
		this.tiles = e;
	}
	initTextureArray(e) {
		if (this.arrayTarget !== null || e.material.map === null) return;
		let { instanceCount: t, renderer: n, textureSize: r, batchedMesh: i } = this, a = e.material.map, o = {
			colorSpace: a.colorSpace,
			wrapS: a.wrapS,
			wrapT: a.wrapT,
			wrapR: a.wrapS,
			magFilter: a.magFilter
		}, s = new Me(r || a.image.width, r || a.image.height, t);
		Object.assign(s.texture, o), n.initRenderTarget(s), i.material.map = s.texture, this.arrayTarget = s, this._tileToInstanceId.forEach((e) => {
			e.forEach((e) => {
				this.assignTextureToLayer(mi, e);
			});
		});
	}
	initBatchedMesh(e) {
		if (this.batchedMesh !== null) return;
		let { instanceCount: t, vertexCount: n, indexCount: r, tiles: i } = this, a = this.material ? this.material : new e.material.constructor(), o = new ui(t, t * n, t * r, a);
		o.name = "BatchTilesPlugin", o.frustumCulled = !1, i.group.add(o), o.updateMatrixWorld(), fi(o.material), this.batchedMesh = o;
	}
	setTileVisible(e, t) {
		let n = e.engineData.scene;
		if (t && this.addSceneToBatchedMesh(n, e), this._tileToInstanceId.has(e)) {
			this._tileToInstanceId.get(e).forEach((e) => {
				this.batchedMesh.setVisibleAt(e, t);
			});
			let r = this.tiles;
			return t ? r.visibleTiles.add(e) : r.visibleTiles.delete(e), r.dispatchEvent({
				type: "tile-visibility-change",
				scene: n,
				tile: e,
				visible: t
			}), !0;
		}
		return !1;
	}
	disposeTile(e) {
		this.removeSceneFromBatchedMesh(e);
	}
	unloadTileFromGPU(e, t) {
		return !this.discardOriginalContent && this._tileToInstanceId.has(t) ? (this.removeSceneFromBatchedMesh(t), !0) : !1;
	}
	assignTextureToLayer(e, t) {
		if (!this.arrayTarget) return;
		this.expandArrayTargetIfNeeded();
		let { renderer: n } = this, r = n.getRenderTarget();
		n.setRenderTarget(this.arrayTarget, t), pi.material.map = e, pi.render(n), n.setRenderTarget(r), pi.material.map = null, e.dispose();
	}
	expandArrayTargetIfNeeded() {
		let { batchedMesh: e, arrayTarget: t, renderer: n } = this, r = Math.min(e.maxInstanceCount, this.maxInstanceCount);
		if (r > t.depth) {
			let i = {
				colorSpace: t.texture.colorSpace,
				wrapS: t.texture.wrapS,
				wrapT: t.texture.wrapT,
				generateMipmaps: t.texture.generateMipmaps,
				minFilter: t.texture.minFilter,
				magFilter: t.texture.magFilter
			}, a = new Me(t.width, t.height, r);
			Object.assign(a.texture, i), n.initRenderTarget(a), n.copyTextureToTexture(t.texture, a.texture), t.dispose(), e.material.map = a.texture, this.arrayTarget = a;
		}
	}
	removeSceneFromBatchedMesh(e) {
		if (this._tileToInstanceId.has(e)) {
			let t = this._tileToInstanceId.get(e);
			this._tileToInstanceId.delete(e), t.forEach((e) => {
				this.batchedMesh.deleteInstance(e);
			});
		}
	}
	addSceneToBatchedMesh(e, t) {
		if (this._tileToInstanceId.has(t)) return;
		let n = [];
		e.traverse((e) => {
			e.isMesh && n.push(e);
		});
		let r = !0;
		n.forEach((e) => {
			if (this.batchedMesh && r) {
				let t = e.geometry.attributes, n = this.batchedMesh.geometry.attributes;
				for (let e in n) if (!(e in t)) {
					r = !1;
					return;
				}
			}
		});
		let i = !this.batchedMesh || this.batchedMesh.instanceCount + n.length <= this.maxInstanceCount;
		if (r && i) {
			e.updateMatrixWorld();
			let r = [];
			this._tileToInstanceId.set(t, r), n.forEach((e) => {
				this.initBatchedMesh(e), this.initTextureArray(e);
				let { geometry: t, material: n } = e, { batchedMesh: i, expandPercent: a } = this;
				i.expandPercent = a;
				let o = i.addGeometry(t, this.vertexCount, this.indexCount), s = i.addInstance(o);
				r.push(s), i.setMatrixAt(s, e.matrixWorld), i.setVisibleAt(s, !1), di(n.color) || (n.color.setHSL(Math.random(), .5, .5), i.setColorAt(s, n.color));
				let c = n.map;
				c ? this.assignTextureToLayer(c, s) : this.assignTextureToLayer(mi, s);
			}), this.discardOriginalContent && (t.engineData.textures.forEach((e) => {
				e.image instanceof ImageBitmap && e.image.close();
			}), t.engineData.scene = null, t.engineData.materials = [], t.engineData.geometries = [], t.engineData.textures = []);
		}
	}
	raycastTile(e, t, n, r) {
		return this._tileToInstanceId.has(e) ? (this._tileToInstanceId.get(e).forEach((e) => {
			this.batchedMesh.raycastInstance(e, n, r);
		}), !0) : !1;
	}
	dispose() {
		let { arrayTarget: e, batchedMesh: t } = this;
		e && e.dispose(), t && (t.material.dispose(), t.geometry.dispose(), t.dispose(), t.removeFromParent());
	}
	getTileBatchIds(e) {
		return this._tileToInstanceId.get(e);
	}
}, gi = /* @__PURE__ */ new Te(), _i = /* @__PURE__ */ new I(), vi = /* @__PURE__ */ new M(), yi = /* @__PURE__ */ new M(), bi = /* @__PURE__ */ new be(), xi = /* @__PURE__ */ new P({ side: O }), Si = /* @__PURE__ */ new v(), Ci = 1e5;
function wi(e, t) {
	return e.isBufferGeometry ? (e.boundingSphere === null && e.computeBoundingSphere(), t.copy(e.boundingSphere)) : (Si.setFromObject(e), Si.getBoundingSphere(t), t);
}
var Ti = class {
	constructor() {
		this.name = "TILE_FLATTENING_PLUGIN", this.priority = -100, this.tiles = null, this.shapes = /* @__PURE__ */ new Map(), this.positionsMap = /* @__PURE__ */ new Map(), this.positionsUpdated = /* @__PURE__ */ new Set(), this.needsUpdate = !1;
	}
	init(e) {
		this.tiles = e, this.needsUpdate = !0, this._updateBeforeCallback = () => {
			this.needsUpdate &&= (this._updateTiles(), !1);
		}, this._disposeModelCallback = ({ tile: e }) => {
			this.positionsMap.delete(e), this.positionsUpdated.delete(e);
		}, e.addEventListener("update-before", this._updateBeforeCallback), e.addEventListener("dispose-model", this._disposeModelCallback);
	}
	setTileActive(e, t) {
		t && !this.positionsUpdated.has(e) && this._updateTile(e);
	}
	_updateTile(e) {
		let { positionsUpdated: t, positionsMap: n, shapes: r, tiles: i } = this;
		t.add(e);
		let a = e.engineData.scene;
		if (n.has(e)) {
			let t = n.get(e);
			a.traverse((e) => {
				if (e.geometry) {
					let n = t.get(e.geometry);
					n && (e.geometry.attributes.position.array.set(n), e.geometry.attributes.position.needsUpdate = !0);
				}
			});
		} else {
			let t = /* @__PURE__ */ new Map();
			n.set(e, t), a.traverse((e) => {
				e.geometry && t.set(e.geometry, e.geometry.attributes.position.array.slice());
			});
		}
		a.updateMatrixWorld(!0), a.traverse((e) => {
			let { geometry: t } = e;
			t && (vi.copy(e.matrixWorld), a.parent !== null && vi.premultiply(i.group.matrixWorldInverse), yi.copy(vi).invert(), wi(t, gi).applyMatrix4(vi), r.forEach(({ shape: e, direction: n, sphere: r, thresholdMode: i, threshold: a, flattenRange: o }) => {
				_i.subVectors(gi.center, r.center), _i.addScaledVector(n, -n.dot(_i));
				let s = (gi.radius + r.radius) ** 2;
				if (_i.lengthSq() > s) return;
				let { position: c } = t.attributes, { ray: l } = bi;
				l.direction.copy(n).multiplyScalar(-1);
				for (let t = 0, r = c.count; t < r; t++) {
					l.origin.fromBufferAttribute(c, t).applyMatrix4(vi).addScaledVector(n, Ci), bi.far = Ci;
					let r = bi.intersectObject(e)[0];
					if (r) {
						let e = (Ci - r.distance) / a, n = e >= 1;
						(!n || n && i === "flatten") && (e = Math.min(e, 1), r.point.addScaledVector(l.direction, j.mapLinear(e, 0, 1, -o, 0)), r.point.applyMatrix4(yi), c.setXYZ(t, ...r.point));
					}
				}
			}));
		}), this.tiles.dispatchEvent({ type: "needs-render" });
	}
	_updateTiles() {
		this.positionsUpdated.clear(), this.tiles.activeTiles.forEach((e) => this._updateTile(e));
	}
	hasShape(e) {
		return this.shapes.has(e);
	}
	addShape(e, t = new I(0, 0, -1), n = {}) {
		if (this.hasShape(e)) throw Error("TileFlatteningPlugin: Shape is already used.");
		typeof n == "number" && (console.warn("TileFlatteningPlugin: \"addShape\" function signature has changed. Please use an options object, instead."), n = { threshold: n }), this.needsUpdate = !0;
		let r = e.clone();
		r.updateMatrixWorld(!0), r.traverse((e) => {
			e.material &&= xi;
		});
		let i = wi(r, new Te());
		this.shapes.set(e, {
			shape: r,
			direction: t.clone(),
			sphere: i,
			thresholdMode: "none",
			threshold: Infinity,
			flattenRange: 0,
			...n
		});
	}
	updateShape(e) {
		if (!this.hasShape(e)) throw Error("TileFlatteningPlugin: Shape is not present.");
		let { direction: t, threshold: n, thresholdMode: r, flattenRange: i } = this.shapes.get(e);
		this.deleteShape(e), this.addShape(e, t, {
			threshold: n,
			thresholdMode: r,
			flattenRange: i
		});
	}
	deleteShape(e) {
		return this.needsUpdate = !0, this.shapes.delete(e);
	}
	clearShapes() {
		this.shapes.size !== 0 && (this.needsUpdate = !0, this.shapes.clear());
	}
	dispose() {
		this.tiles.removeEventListener("before-update", this._updateBeforeCallback), this.tiles.removeEventListener("dispose-model", this._disposeModelCallback), this.positionsMap.forEach((e) => {
			e.forEach((e, t) => {
				let { position: n } = t.attributes;
				n.array.set(e), n.needsUpdate = !0;
			});
		});
	}
}, Ei = class {
	constructor(e = {}) {
		let { regions: t = [] } = e;
		this.name = "LOAD_REGION_PLUGIN", this.regions = [], this.tiles = null, t.forEach((e) => this.addRegion(e));
	}
	init(e) {
		this.tiles = e;
	}
	addRegion(e) {
		this.regions.indexOf(e) === -1 && this.regions.push(e);
	}
	removeRegion(e) {
		let t = this.regions.indexOf(e);
		t !== -1 && this.regions.splice(t, 1);
	}
	hasRegion(e) {
		return this.regions.indexOf(e) !== -1;
	}
	clearRegions() {
		this.regions = [];
	}
	calculateTileViewError(e, t) {
		let n = e.engineData.boundingVolume, { regions: r, tiles: i } = this, a = !1, o = null, s = 0, c = Infinity;
		for (let t of r) {
			let r = t.intersectsTile(n, e, i);
			a ||= r, r && (s = Math.max(t.calculateError(e, i), s), c = Math.min(t.calculateDistance(n, e, i), c)), t.mask && (o ||= r);
		}
		return t.inView = a && o !== !1, t.error = s, t.distance = c, t.inView || o !== null;
	}
	dispose() {
		this.regions = [];
	}
}, Di = class {
	constructor(e = {}) {
		let { errorTarget: t = 10, mask: n = !1 } = e;
		this.errorTarget = t, this.mask = n;
	}
	intersectsTile(e, t, n) {
		return !1;
	}
	calculateDistance(e, t, n) {
		return Infinity;
	}
	calculateError(e, t) {
		return e.geometricError - this.errorTarget + t.errorTarget;
	}
}, Oi = class extends Di {
	constructor(e = {}) {
		let { sphere: t = new Te() } = e;
		super(e), this.sphere = t.clone();
	}
	intersectsTile(e) {
		return e.intersectsSphere(this.sphere);
	}
}, ki = class extends Di {
	constructor(e = {}) {
		let { ray: t = new ye() } = e;
		super(e), this.ray = t.clone();
	}
	intersectsTile(e) {
		return e.intersectsRay(this.ray);
	}
}, Ai = class extends Di {
	constructor(e = {}) {
		let { obb: t = new s() } = e;
		super(e), this.obb = t.clone(), this.obb.update();
	}
	intersectsTile(e) {
		return e.intersectsOBB(this.obb);
	}
}, q = /* @__PURE__ */ new I(), ji = [
	"x",
	"y",
	"z"
], Mi = class extends ae {
	constructor(e, t = 16776960, n = 40) {
		let r = new S(), i = [];
		for (let e = 0; e < 3; e++) {
			let t = ji[e], r = ji[(e + 1) % 3];
			q.set(0, 0, 0);
			for (let e = 0; e < n; e++) {
				let a;
				a = 2 * Math.PI * e / (n - 1), q[t] = Math.sin(a), q[r] = Math.cos(a), i.push(q.x, q.y, q.z), a = 2 * Math.PI * (e + 1) / (n - 1), q[t] = Math.sin(a), q[r] = Math.cos(a), i.push(q.x, q.y, q.z);
			}
		}
		r.setAttribute("position", new x(new Float32Array(i), 3)), r.computeBoundingSphere(), super(r, new ie({
			color: t,
			toneMapped: !1
		})), this.sphere = e, this.type = "SphereHelper";
	}
	updateMatrixWorld(e) {
		let t = this.sphere;
		this.position.copy(t.center), this.scale.setScalar(t.radius), super.updateMatrixWorld(e);
	}
}, Ni = /* @__PURE__ */ new I(), Pi = /* @__PURE__ */ new I(), Fi = /* @__PURE__ */ new I(), J = /* @__PURE__ */ new I(), Ii = /* @__PURE__ */ new I(), Li = /* @__PURE__ */ new I(0, 0, 1);
function Ri(e) {
	e = e.toNonIndexed();
	let { groups: t } = e, { position: n, normal: r } = e.attributes, i = [], a = [];
	for (let e of t) {
		let { start: t, count: o } = e;
		for (let e = t, s = t + o; e < s; e++) J.fromBufferAttribute(n, e), Ii.fromBufferAttribute(r, e), a.push(...J), i.push(...Ii);
	}
	let o = new S();
	return o.setAttribute("position", new x(new Float32Array(a), 3)), o.setAttribute("normal", new x(new Float32Array(i), 3)), o;
}
function zi(e, t = 32) {
	let { latStart: n = -Math.PI / 2, latEnd: r = Math.PI / 2, lonStart: i = 0, lonEnd: a = 2 * Math.PI, heightStart: o = 0, heightEnd: s = 0 } = e, c = new b(1, 1, 1, t, t), { normal: l, position: u } = c.attributes;
	for (let t = 0, c = u.count; t < c; t++) {
		Fi.fromBufferAttribute(u, t);
		let c = j.mapLinear(Fi.x, -.5, .5, n, r), d = j.mapLinear(Fi.y, -.5, .5, i, a), f = Fi.z < 0;
		Ni.fromBufferAttribute(l, t), e.getCartographicToPosition(c, d, f ? s : o, Fi), u.setXYZ(t, Fi.x, Fi.y, Fi.z), e.getCartographicToNormal(c, d, Pi), Ni.z === 0 ? (J.crossVectors(Li, Pi), J.lengthSq() < 1e-12 && J.set(1, 0, 0), J.normalize(), Ni.x === 0 ? Pi.copy(J).multiplyScalar(Math.sign(Ni.y)) : Pi.crossVectors(Pi, J).normalize().multiplyScalar(Math.sign(Ni.x))) : Pi.multiplyScalar(f ? 1 : -1), l.setXYZ(t, Pi.x, Pi.y, Pi.z);
	}
	return c;
}
function Bi(e, t = 32) {
	let { latStart: n = -Math.PI / 2, latEnd: r = Math.PI / 2, lonStart: i = 0, lonEnd: a = 2 * Math.PI, heightStart: o = 0, heightEnd: s = 0 } = e, c = [], l = (n, r, i, a, o, s) => {
		for (let l = 0; l < t; l++) {
			let u = l / t, d = (l + 1) / t;
			e.getCartographicToPosition(j.lerp(n, a, u), j.lerp(r, o, u), j.lerp(i, s, u), J), e.getCartographicToPosition(j.lerp(n, a, d), j.lerp(r, o, d), j.lerp(i, s, d), Ii), c.push(J.x, J.y, J.z, Ii.x, Ii.y, Ii.z);
		}
	};
	for (let e of [o, s]) l(n, i, e, n, a, e), l(r, i, e, r, a, e), l(n, i, e, r, i, e), l(n, a, e, r, a, e);
	for (let e of [n, r]) for (let t of [i, a]) l(e, t, o, e, t, s);
	let u = new S();
	return u.setAttribute("position", new x(new Float32Array(c), 3)), u;
}
var Vi = class extends ae {
	constructor(e = new d(), t = 16776960) {
		super(), this.ellipsoidRegion = e, this.material.color.set(t), this.update();
	}
	update() {
		this.geometry.dispose(), this.geometry = Bi(this.ellipsoidRegion);
	}
	dispose() {
		this.geometry.dispose(), this.material.dispose();
	}
}, Hi = class extends N {
	constructor(e = new d(), t = 16776960) {
		super(), this.ellipsoidRegion = e, this.material.color.set(t), this.update();
	}
	update() {
		this.geometry.dispose();
		let e = zi(this.ellipsoidRegion), { lonStart: t, lonEnd: n } = this;
		n - t >= 2 * Math.PI ? (e.groups.splice(2, 2), this.geometry = Ri(e)) : this.geometry = e;
	}
	dispose() {
		this.geometry.dispose(), this.material.dispose();
	}
}, Ui = Symbol("ORIGINAL_MATERIAL"), Wi = Symbol("HAS_RANDOM_COLOR"), Gi = Symbol("HAS_RANDOM_NODE_COLOR"), Ki = Symbol("LOAD_TIME"), qi = Symbol("PARENT_BOUND_REF_COUNT"), Ji = /* @__PURE__ */ new Te(), Yi = () => {}, Xi = {};
function Zi(e) {
	if (!Xi[e]) {
		let t = Math.random(), n = .5 + Math.random() * .5, r = .375 + Math.random() * .25;
		Xi[e] = new w().setHSL(t, n, r);
	}
	return Xi[e];
}
var Qi = 0, $i = 1, ea = 2, ta = 3, na = 4, ra = 5, ia = 6, aa = 7, oa = 8, sa = 9, ca = 10, la = 11, ua = Object.freeze({
	NONE: Qi,
	SCREEN_ERROR: $i,
	GEOMETRIC_ERROR: ea,
	DISTANCE: ta,
	DEPTH: na,
	RELATIVE_DEPTH: ra,
	IS_LEAF: ia,
	RANDOM_COLOR: aa,
	RANDOM_NODE_COLOR: oa,
	CUSTOM_COLOR: sa,
	LOAD_ORDER: ca,
	INDEXED_COLOR: la
}), da = class {
	static get ColorModes() {
		return ua;
	}
	get wireframe() {
		return this._wireframe;
	}
	set wireframe(e) {
		e !== this._wireframe && (this._wireframe = e, this.materialsNeedUpdate = !0);
	}
	get unlit() {
		return this._unlit;
	}
	set unlit(e) {
		e !== this._unlit && (this._unlit = e, this.materialsNeedUpdate = !0);
	}
	get colorMode() {
		return this._colorMode;
	}
	set colorMode(e) {
		e !== this._colorMode && (this._colorMode = e, this.materialsNeedUpdate = !0);
	}
	get boundsColorMode() {
		return this._boundsColorMode;
	}
	set boundsColorMode(e) {
		e !== this._boundsColorMode && (this._boundsColorMode = e, this.materialsNeedUpdate = !0);
	}
	get enabled() {
		return this._enabled;
	}
	set enabled(e) {
		e !== this._enabled && this.tiles !== null && (this._enabled = e, e ? this.init(this.tiles) : this.dispose());
	}
	get displayParentBounds() {
		return this._displayParentBounds;
	}
	set displayParentBounds(e) {
		this._displayParentBounds !== e && (this._displayParentBounds = e, e ? this.tiles.traverse((e) => {
			e.traversal && e.traversal.visible && this._onTileVisibilityChange(e, !0);
		}, null, !1) : this.tiles.traverse((e) => {
			e.traversal && (e[qi] = null, this._onTileVisibilityChange(e, e.traversal.visible));
		}, null, !1));
	}
	constructor(e) {
		e = {
			displayParentBounds: !1,
			displayBoxBounds: !1,
			displaySphereBounds: !1,
			displayRegionBounds: !1,
			colorMode: Qi,
			boundsColorMode: Qi,
			maxDebugDepth: -1,
			maxDebugDistance: -1,
			maxDebugError: -1,
			customColorCallback: null,
			unlit: !1,
			wireframe: !1,
			enabled: !0,
			...e
		}, this.name = "DEBUG_TILES_PLUGIN", this.tiles = null, this._colorMode = null, this._boundsColorMode = null, this._unlit = null, this._wireframe = null, this.materialsNeedUpdate = !1, this.extremeDebugDepth = -1, this.extremeDebugError = -1, this.boxGroup = null, this.sphereGroup = null, this.regionGroup = null, this._enabled = e.enabled, this._displayParentBounds = e.displayParentBounds, this.displayBoxBounds = e.displayBoxBounds, this.displaySphereBounds = e.displaySphereBounds, this.displayRegionBounds = e.displayRegionBounds, this.colorMode = e.colorMode, this.boundsColorMode = e.boundsColorMode, this.maxDebugDepth = e.maxDebugDepth, this.maxDebugDistance = e.maxDebugDistance, this.maxDebugError = e.maxDebugError, this.customColorCallback = e.customColorCallback, this.unlit = e.unlit, this.wireframe = e.wireframe, this.getDebugColor = (e, t) => {
			t.setRGB(e, e, e);
		};
	}
	init(e) {
		if (this.tiles = e, !this.enabled) return;
		let t = e.group;
		this.boxGroup = new re(), this.boxGroup.name = "DebugTilesRenderer.boxGroup", t.add(this.boxGroup), this.boxGroup.updateMatrixWorld(), this.sphereGroup = new re(), this.sphereGroup.name = "DebugTilesRenderer.sphereGroup", t.add(this.sphereGroup), this.sphereGroup.updateMatrixWorld(), this.regionGroup = new re(), this.regionGroup.name = "DebugTilesRenderer.regionGroup", t.add(this.regionGroup), this.regionGroup.updateMatrixWorld(), this._onLoadTilesetCB = () => {
			this._initExtremes();
		}, this._onLoadModelCB = ({ scene: e, tile: t }) => {
			this._onLoadModel(e, t);
		}, this._onDisposeModelCB = ({ tile: e }) => {
			this._onDisposeModel(e);
		}, this._onUpdateAfterCB = () => {
			this.update();
		}, this._onTileVisibilityChangeCB = ({ scene: e, tile: t, visible: n }) => {
			this._onTileVisibilityChange(t, n);
		}, e.addEventListener("load-tileset", this._onLoadTilesetCB), e.addEventListener("load-model", this._onLoadModelCB), e.addEventListener("dispose-model", this._onDisposeModelCB), e.addEventListener("update-after", this._onUpdateAfterCB), e.addEventListener("tile-visibility-change", this._onTileVisibilityChangeCB), this._initExtremes(), e.traverse((e) => {
			e.engineData.scene && this._onLoadModel(e.engineData.scene, e);
		}), e.visibleTiles.forEach((e) => {
			this._onTileVisibilityChange(e, !0);
		});
	}
	getTileFromObject3D(e) {
		let t = null;
		return this.tiles.activeTiles.forEach((n) => {
			if (t) return;
			let r = n.engineData.scene;
			r && r.traverse((r) => {
				r === e && (t = n);
			});
		}), t;
	}
	setEmptyTileVisible(e, t) {
		this._onTileVisibilityChange(e, t);
	}
	_initExtremes() {
		if (!(this.tiles && this.tiles.root)) return;
		let e = -1, t = -1;
		this.tiles.traverse(null, (n, r, i) => {
			e = Math.max(e, i), t = Math.max(t, n.geometricError);
		}, !1), this.extremeDebugDepth = e, this.extremeDebugError = t;
	}
	update() {
		let { tiles: e, colorMode: t, boundsColorMode: n } = this;
		if (!e.root) return;
		this.materialsNeedUpdate &&= (e.forEachLoadedModel((e) => {
			this._updateMaterial(e);
		}), !1), this.boxGroup.visible = this.displayBoxBounds, this.sphereGroup.visible = this.displaySphereBounds, this.regionGroup.visible = this.displayRegionBounds;
		let r = -1;
		r = this.maxDebugDepth === -1 ? this.extremeDebugDepth : this.maxDebugDepth;
		let i = -1;
		i = this.maxDebugError === -1 ? this.extremeDebugError : this.maxDebugError;
		let a = -1;
		this.maxDebugDistance === -1 ? (e.getBoundingSphere(Ji), a = Ji.radius) : a = this.maxDebugDistance;
		let { errorTarget: o, visibleTiles: s } = e, c;
		(t === ca || n === ca) && (c = Array.from(s).sort((e, t) => e[Ki] - t[Ki]));
		let l = (e, t, n, s, l, u) => {
			switch (e !== aa && delete n.material[Wi], e !== oa && delete n.material[Gi], e) {
				case na: {
					let e = t.internal.depth / r;
					this.getDebugColor(e, n.material.color);
					break;
				}
				case ra: {
					let e = t.internal.depthFromRenderedParent / r;
					this.getDebugColor(e, n.material.color);
					break;
				}
				case $i: {
					let e = t.traversal.error / o;
					e > 1 ? n.material.color.setRGB(1, 0, 0) : this.getDebugColor(e, n.material.color);
					break;
				}
				case ea: {
					let e = Math.min(t.geometricError / i, 1);
					this.getDebugColor(e, n.material.color);
					break;
				}
				case ta: {
					let e = Math.min(t.traversal.distanceFromCamera / a, 1);
					this.getDebugColor(e, n.material.color);
					break;
				}
				case ia:
					!t.children || t.children.length === 0 ? this.getDebugColor(1, n.material.color) : this.getDebugColor(0, n.material.color);
					break;
				case oa:
					n.material[Gi] || (n.material.color.setHSL(s, l, u), n.material[Gi] = !0);
					break;
				case aa:
					n.material[Wi] || (n.material.color.setHSL(s, l, u), n.material[Wi] = !0);
					break;
				case sa:
					this.customColorCallback ? this.customColorCallback(t, n) : console.warn("DebugTilesRenderer: customColorCallback not defined");
					break;
				case ca: {
					let e = c.indexOf(t);
					this.getDebugColor(e / (c.length - 1), n.material.color);
					break;
				}
				case la:
					n.material.color.copy(Zi(t.internal.depth)), delete n.material[Wi], delete n.material[Gi];
					break;
			}
		};
		s.forEach((e) => {
			let n = e.engineData.scene, r, i, a;
			t === aa && (r = Math.random(), i = .5 + Math.random() * .5, a = .375 + Math.random() * .25), n.traverse((n) => {
				t === oa && (r = Math.random(), i = .5 + Math.random() * .5, a = .375 + Math.random() * .25), n.material && l(t, e, n, r, i, a);
			});
		});
		let u = n === Qi ? la : n, d = [
			this.boxGroup,
			this.sphereGroup,
			this.regionGroup
		];
		for (let e of d) for (let t of e.children) {
			let e = t.userData.tile, n, r, i;
			u === aa && (n = Math.random(), r = .5 + Math.random() * .5, i = .375 + Math.random() * .25), t.traverse((t) => {
				u === oa && (n = Math.random(), r = .5 + Math.random() * .5, i = .375 + Math.random() * .25), t.material && l(u, e, t, n, r, i);
			});
		}
	}
	_onTileVisibilityChange(e, t) {
		this.displayParentBounds ? r(e, (n) => {
			n[qi] ?? (n[qi] = 0), t ? n[qi]++ : n[qi] > 0 && n[qi]--;
			let r = n === e && t || this.displayParentBounds && n[qi] > 0;
			this._updateBoundHelper(n, r);
		}) : this._updateBoundHelper(e, t);
	}
	_createBoundHelper(e) {
		let t = this.tiles, n = e.engineData, { sphere: r, obb: i, region: a } = n.boundingVolume;
		if (i) {
			let r = new re();
			r.name = "DebugTilesRenderer.boxHelperGroup", r.matrix.copy(i.transform), r.matrixAutoUpdate = !1, r.userData.tile = e, n.boxHelperGroup = r;
			let a = new y(i.box, Zi(e.internal.depth));
			a.raycast = Yi, r.add(a);
			let o = new N(new b(), new P({
				color: Zi(e.internal.depth),
				transparent: !0,
				depthWrite: !1,
				opacity: .05,
				side: O
			}));
			i.box.getSize(o.scale), o.raycast = Yi, r.add(o), t.visibleTiles.has(e) && this.displayBoxBounds && (this.boxGroup.add(r), r.updateMatrixWorld(!0));
		}
		if (r) {
			let i = new Mi(r, Zi(e.internal.depth));
			i.raycast = Yi, i.userData.tile = e;
			let a = new N(new Ee(1), new P({
				color: Zi(e.internal.depth),
				transparent: !0,
				depthWrite: !1,
				opacity: .05,
				side: O
			}));
			a.raycast = Yi, i.add(a), n.sphereHelper = i, t.visibleTiles.has(e) && this.displaySphereBounds && (this.sphereGroup.add(i), i.updateMatrixWorld(!0));
		}
		if (a) {
			let r = new Vi(a, Zi(e.internal.depth));
			r.raycast = Yi, r.userData.tile = e;
			let i = new Hi(a, Zi(e.internal.depth));
			i.material.transparent = !0, i.material.depthWrite = !1, i.material.opacity = .05, i.material.side = O, i.raycast = Yi, r.add(i);
			let o = new Te();
			a.getBoundingSphere(o), r.position.copy(o.center), o.center.multiplyScalar(-1), r.geometry.translate(...o.center), i.geometry.translate(...o.center), n.regionHelper = r, t.visibleTiles.has(e) && this.displayRegionBounds && (this.regionGroup.add(r), r.updateMatrixWorld(!0));
		}
	}
	_updateHelperMaterials(e, t) {
		t.traverse((t) => {
			let { material: n } = t;
			if (!n) return;
			e.traversal.visible || !this.displayParentBounds ? n.opacity = t.isMesh ? .05 : 1 : n.opacity = t.isMesh ? .01 : .2;
			let r = n.transparent;
			n.transparent = n.opacity < 1, n.transparent !== r && (n.needsUpdate = !0);
		});
	}
	_updateBoundHelper(e, t) {
		let n = e.engineData;
		if (!n) return;
		let r = this.sphereGroup, i = this.boxGroup, a = this.regionGroup;
		t && n.boxHelperGroup == null && n.sphereHelper == null && n.regionHelper == null && this._createBoundHelper(e);
		let o = n.boxHelperGroup, s = n.sphereHelper, c = n.regionHelper;
		t ? (o && (i.add(o), o.updateMatrixWorld(!0), this._updateHelperMaterials(e, o)), s && (r.add(s), s.updateMatrixWorld(!0), this._updateHelperMaterials(e, s)), c && (a.add(c), c.updateMatrixWorld(!0), this._updateHelperMaterials(e, c))) : (o && i.remove(o), s && r.remove(s), c && a.remove(c));
	}
	_updateMaterial(e) {
		let { colorMode: t, unlit: n, wireframe: r } = this;
		e.traverse((e) => {
			if (!e.material) return;
			let i = e.material, a = e[Ui];
			if (i !== a && i.dispose(), t !== Qi || n) {
				if (e.isPoints) {
					let t = new he();
					t.size = a.size, t.sizeAttenuation = a.sizeAttenuation, e.material = t;
				} else n ? e.material = new P({ wireframe: r }) : (e.material = new de({ wireframe: r }), e.material.flatShading = !0);
				t === Qi && (e.material.map = a.map, e.material.color.set(a.color));
			} else e.material = a;
		});
	}
	_onLoadModel(e, t) {
		t[Ki] = performance.now(), e.traverse((e) => {
			let t = e.material;
			t && (e[Ui] = t);
		}), this._updateMaterial(e);
	}
	_onDisposeModel(e) {
		let t = e.engineData;
		t?.boxHelperGroup && (t.boxHelperGroup.traverse((e) => {
			e.geometry && (e.geometry.dispose(), e.material.dispose());
		}), delete t.boxHelperGroup), t?.sphereHelper && (t.sphereHelper.traverse((e) => {
			e.geometry && (e.geometry.dispose(), e.material.dispose());
		}), delete t.sphereHelper), t?.regionHelper && (t.regionHelper.traverse((e) => {
			e.geometry && (e.geometry.dispose(), e.material.dispose());
		}), delete t.regionHelper);
	}
	dispose() {
		let e = this.tiles;
		e.removeEventListener("load-tileset", this._onLoadTilesetCB), e.removeEventListener("load-model", this._onLoadModelCB), e.removeEventListener("dispose-model", this._onDisposeModelCB), e.removeEventListener("update-after", this._onUpdateAfterCB), e.removeEventListener("tile-visibility-change", this._onTileVisibilityChangeCB), this.colorMode = Qi, this.boundsColorMode = Qi, this.unlit = !1, e.forEachLoadedModel((e) => {
			this._updateMaterial(e);
		}), e.traverse((e) => {
			this._onDisposeModel(e);
		}, null, !1), this.boxGroup?.removeFromParent(), this.sphereGroup?.removeFromParent(), this.regionGroup?.removeFromParent();
	}
}, fa = 0, pa = 1, ma = 2, ha = 3, ga = 150;
function _a(e, t) {
	return e * 1 | t * 2;
}
function va(e, t, n) {
	return `${e}_${t}_${n}`;
}
var ya = class {
	constructor() {
		this.parent = null, this.x = 0, this.y = 0, this.level = 0, this.children = [
			,
			,
			,
			,
		].fill(null), this.childCount = 0, this.loadingState = fa, this.visible = !1, this.target = 0, this.showTimer = 0, this.hideTimer = 0, this.siblingForced = !1, this.forced = !1, this.prefetch = 0, this._key = null, this._index = null;
	}
	getKey() {
		return this._key === null && (this._key = `${this.x}_${this.y}_${this.level}`), this._key;
	}
	getIndex() {
		return this._index === null && (this._index = _a(this.x % 2, this.y % 2)), this._index;
	}
	addChild(e) {
		let t = e.getIndex();
		if (this.children[t] || e.x >> 1 !== this.x || e.y >> 1 !== this.y || e.level - 1 !== this.level) throw Error();
		e.parent = this, this.children[t] = e, this.childCount++;
	}
	remove() {
		if (this.childCount > 0) throw Error();
		this.parent.childCount--, this.parent.children[this.getIndex()] = null, this.parent = null;
	}
}, ba = /* @__PURE__ */ new Set(), xa = class extends k {
	constructor() {
		super(), this.root = new ya(), this.cache = { [this.root.getKey()]: this.root }, this.contentCache = null, this._lastTime = -1, this.loadSiblings = !0;
	}
	update() {
		let e = performance.now(), t = e - (this._lastTime === -1 ? e : this._lastTime);
		this._lastTime = e;
		let { root: n } = this, r = this;
		i(n), a(n), ba.forEach((e) => this._deleteTile(e)), ba.clear();
		function i(e) {
			let n = e.target > 0 || e.siblingForced, a = e.visible && e.forced;
			n || a ? (e.showTimer += t, e.showTimer = Math.min(e.showTimer, ga), e.showTimer === ga && (e.hideTimer = 0)) : (e.visible || e.showTimer > 0) && (e.hideTimer += t, e.hideTimer = Math.min(e.hideTimer, ga), e.hideTimer === ga && (e.showTimer = 0, e.hideTimer = 0, e.loadingState !== fa && e.prefetch === 0 && (r.contentCache.release(e.x, e.y, e.level), e.loadingState = fa)));
			let o = (n ? e.showTimer === ga : e.showTimer > 0) || a;
			if (!n && !a && e.prefetch === 0 && e.showTimer === 0 && e.loadingState !== fa && (r.contentCache.release(e.x, e.y, e.level), e.loadingState = fa), (o || e.prefetch > 0) && e.loadingState === fa) {
				e.loadingState = pa;
				let { x: t, y: n, level: i } = e, a = r.contentCache.lock(t, n, i);
				a instanceof Promise ? a.then((t) => {
					e.loadingState === pa && (e.loadingState = ma);
				}).catch((t) => {
					e.loadingState === pa && (e.loadingState = t.name === "AbortError" ? fa : ha);
				}) : e.loadingState = a === null ? ha : ma;
			}
			let { children: s } = e;
			if (r.loadSiblings) {
				let t = !1;
				for (let e = 0, n = s.length; e < n; e++) {
					let n = s[e];
					n !== null && n.target > 0 && (t = !0);
				}
				if (t && e.childCount < 4) for (let t = 0; t <= 1; t++) for (let n = 0; n <= 1; n++) r._ensureTile(2 * e.x + n, 2 * e.y + t, e.level + 1);
				for (let e = 0, n = s.length; e < n; e++) {
					let n = s[e];
					n !== null && (n.siblingForced = t);
				}
			} else for (let e = 0, t = s.length; e < t; e++) {
				let t = s[e];
				t !== null && (t.siblingForced = !1);
			}
			for (let e = 0, t = s.length; e < t; e++) {
				let t = s[e];
				t !== null && i(t);
			}
		}
		function a(e, t = !1, n = !0) {
			let i = e.target > 0 || e.siblingForced, o = e.visible && t;
			e.forced = t;
			let s = (i ? e.showTimer === ga : e.showTimer > 0) || o, c = !1;
			(i || o) && (e.loadingState === ma && (n || o) ? (c = !0, t = !1) : s && (t = !0));
			let { children: l } = e, u = !0;
			if (r.loadSiblings) for (let e = 0, t = l.length; e < t; e++) {
				let t = l[e];
				(t === null || t.loadingState !== ma && t.loadingState !== ha) && (u = !1);
			}
			let d = e.visible || i || e.showTimer > 0 || e.prefetch > 0, f = !1;
			for (let e = 0, n = l.length; e < n; e++) {
				let n = l[e];
				if (n !== null) {
					d = a(n, t, u) || d;
					let e = n.target > 0 || n.siblingForced, i = r.loadSiblings && n.loadingState === ha;
					f ||= e && !n.visible && !i;
				}
			}
			if (f && e.loadingState === ma && (c = !0), r.loadSiblings && c && e.childCount === 4) {
				let e = !0, t = !1;
				for (let n = 0, r = l.length; n < r; n++) {
					let r = l[n];
					!r.visible && r.loadingState !== ha && (e = !1), t ||= r.visible;
				}
				e && t && (c = !1);
			}
			return c !== e.visible && (e.visible = c, r.dispatchEvent({
				type: "toggle",
				visible: c,
				x: e.x,
				y: e.y,
				level: e.level
			})), e !== r.root && !d && ba.add(e), d;
		}
	}
	getVisibleTiles() {
		let e = [];
		for (let t in this.cache) {
			let n = this.cache[t];
			n.visible && e.push(n);
		}
		return e;
	}
	setTargetState(e, t, n, r) {
		if (r) {
			let r = this._ensureTile(e, t, n);
			r.target++;
		} else {
			let r = this.cache[va(e, t, n)];
			if (!r || r.target <= 0) throw Error("MVTHierarchy: target ref count went negative — mismatched calls.");
			r.target--;
		}
	}
	setPrefetchState(e, t, n, r) {
		if (r) {
			let r = this._ensureTile(e, t, n);
			r.prefetch++;
		} else {
			let r = this.cache[va(e, t, n)];
			if (!r || r.prefetch <= 0) throw Error("MVTHierarchy: prefetch ref count went negative — mismatched calls.");
			r.prefetch--;
		}
	}
	_deleteTile(e) {
		if (e === this.root) throw Error();
		let { cache: t } = this, { x: n, y: r, level: i } = e, a = va(n, r, i);
		if (!(a in t)) throw Error();
		t[a].remove(), delete t[a];
	}
	_ensureTile(e, t, n) {
		let { cache: r } = this, i = va(e, t, n);
		if (i in r) return r[i];
		let a = new ya();
		a.x = e, a.y = t, a.level = n;
		let o = e >> 1, s = t >> 1, c = n - 1;
		return this._ensureTile(o, s, c).addChild(a), r[a.getKey()] = a, a;
	}
}, Sa = {
	test: () => !1,
	mark: () => !1
}, Ca = 5e3;
function wa(e, t) {
	return e.sortValue === t.sortValue ? e.lodLevel === t.lodLevel ? e.visibleTime !== t.visibleTime && (e.visibleDuration < Ca || t.visibleDuration < Ca) ? e.visibleTime < t.visibleTime ? -1 : 1 : t.screenPos.y === e.screenPos.y ? e.id > t.id ? 1 : -1 : t.screenPos.y - e.screenPos.y : t.lodLevel - e.lodLevel : e.sortValue - t.sortValue;
}
var Ta = class {
	constructor() {
		this.id = "", this.layer = "", this.properties = null, this.lodLevel = 0, this.enabled = !0, this.valid = !0, this.ready = !1, this.horizonCutoff = .1, this.screenPos = new I(), this.sortValue = 0, this.visibleDuration = Infinity, this.visibleTime = Infinity, this.visible = !1;
	}
	updateTransform(e, t, n) {}
	evaluate(e, t) {
		return !1;
	}
	onShown() {}
	onHidden() {}
}, Ea = class extends k {
	get hasPendingWork() {
		return this.working || this.needsUpdate;
	}
	constructor() {
		super(), this.camera = null, this.matrix = new M(), this.maxUpdateTimeMs = .5, this._task = null, this._deadline = 0, this.working = !1, this.resolution = new F(1, 1), this.size = 12, this.cells = new Uint32Array(1), this._totalResolution = new F(), this._lastMatrix = new M(), this._ndcMatrix = new M(), this._invMatrix = new M(), this._cameraLocalPos = new I(), this.buffer = .15, this.items = [], this.visible = /* @__PURE__ */ new Set(), this.prevVisible = /* @__PURE__ */ new Set(), this.added = /* @__PURE__ */ new Set(), this._itemSet = /* @__PURE__ */ new Set(), this._itemsNeedsUpdate = !1, this.needsUpdate = !1, this._id = -1, this.handle = {
			test: (e, t, n) => {
				let { cells: r, _id: i } = this, a = !1;
				return this._cellRange(e, t, n, (e, t, n) => (a = !0, r[n] !== 0 && r[n] !== i)) || !a;
			},
			mark: (e, t, n) => {
				let { cells: r, _id: i } = this;
				return this._cellRange(e, t, n, (e, t, n) => (r[n] = i, !1));
			}
		}, this.sortValueCallback = () => 0;
	}
	_cellRange(e, t, n, r) {
		let { size: i, resolution: a, buffer: o } = this, s = a.width, c = a.height, l = s * o, u = c * o, { width: d, height: f } = this._totalResolution, p = e + l, m = t + u, h = Math.max(0, Math.floor((p - n) / i)), g = Math.max(0, Math.floor((m - n) / i)), _ = Math.min(d - 1, Math.floor((p + n) / i)), v = Math.min(f - 1, Math.floor((m + n) / i)), y = n * n;
		for (let e = g; e <= v; e++) for (let t = h; t <= _; t++) {
			let n = Math.max(t * i, Math.min(p, (t + 1) * i)), a = Math.max(e * i, Math.min(m, (e + 1) * i)), o = p - n, s = m - a;
			if (o * o + s * s <= y && r(t, e, e * d + t) === !0) return !0;
		}
		return !1;
	}
	syncItems() {
		let { items: e, _itemSet: t } = this;
		if (this._itemsNeedsUpdate) {
			this._itemsNeedsUpdate = !1, e.length = t.size;
			let n = 0;
			for (let r of t.values()) e[n] = r, n++;
		}
	}
	_deadlineExpired() {
		return performance.now() >= this._deadline;
	}
	setDeadline(e = this.maxUpdateTimeMs) {
		this._deadline = performance.now() + e;
	}
	update(e = this.maxUpdateTimeMs) {
		this.setDeadline(e), this._task === null && (this._task = this._updateGenerator()), this._task.next();
	}
	flush() {
		this.setDeadline(Infinity), this._task === null && (this._task = this._updateGenerator());
		do
			this._task.next();
		while (this.working);
	}
	updateCameraTransform() {
		let { camera: e, matrix: t, _ndcMatrix: n, _invMatrix: r, _cameraLocalPos: i } = this;
		n.copy(t).premultiply(e.matrixWorldInverse).premultiply(e.projectionMatrix), r.copy(t).invert(), i.setFromMatrixPosition(e.matrixWorld).applyMatrix4(r);
	}
	*_updateGenerator() {
		for (;;) {
			let { resolution: e, size: t, added: n, handle: r, sortValueCallback: i, buffer: a, items: o, _lastMatrix: s, _itemSet: c, _ndcMatrix: l, _cameraLocalPos: u } = this;
			if (this.updateCameraTransform(), s.equals(l) && !this.needsUpdate) {
				yield;
				continue;
			}
			s.copy(l), this.needsUpdate = !1, this.working = !0, this.syncItems(), [this.visible, this.prevVisible] = [this.prevVisible, this.visible];
			let { visible: d, prevVisible: f } = this;
			d.clear(), n.clear(), this._totalResolution.copy(e).multiplyScalar(1 + 2 * a).multiplyScalar(1 / t).ceil();
			let { width: p, height: m } = this._totalResolution;
			this.cells.length === p * m ? this.cells.fill(0) : this.cells = new Uint8Array(p * m);
			for (let t = 0, n = o.length; t < n; t++) {
				let n = o[t];
				n.enabled && (n.updateTransform(l, e, u), n.sortValue = i(n)), this._deadlineExpired() && (yield, this.updateCameraTransform());
			}
			o.sort(wa), this._deadlineExpired() && (yield, this.updateCameraTransform());
			for (let e = 0, t = o.length; e < t; e++) {
				let t = o[e];
				this._id = e + 1, t.enabled && c.has(t) && t.evaluate(r) && (d.add(t), f.has(t) ? (t.visible = !1, f.delete(t)) : (t.visible = !0, n.add(t))), this._deadlineExpired() && (yield, this.updateCameraTransform());
			}
			this.working = !1, (n.size > 0 || f.size > 0) && this.dispatchEvent({
				type: "change",
				added: n,
				removed: f
			}), yield;
		}
	}
	refreshLayout(e) {
		let { resolution: t, _ndcMatrix: n, _cameraLocalPos: r } = this;
		e.updateTransform(n, t, r), e.evaluate(Sa, !0);
	}
	register(e) {
		this._itemSet.add(e), this._itemsNeedsUpdate = !0, this.needsUpdate = !0;
	}
	unregister(e) {
		this._itemSet.delete(e), this._itemsNeedsUpdate = !0, this.needsUpdate = !0;
	}
}, Da = class extends k {
	get camera() {
		return this.manager.camera;
	}
	set camera(e) {
		this.manager.camera = e;
	}
	get matrix() {
		return this.manager.matrix;
	}
	get resolution() {
		return this.manager.resolution;
	}
	get size() {
		return this.manager.size;
	}
	set size(e) {
		this.manager.size = e;
	}
	get cells() {
		return this.manager.cells;
	}
	get working() {
		return this.manager.working;
	}
	get hasPendingWork() {
		return this._showTimers.size > 0 || this._hideTimers.size > 0 || this.manager.hasPendingWork;
	}
	get sortValueCallback() {
		return this.manager.sortValueCallback;
	}
	set sortValueCallback(e) {
		this.manager.sortValueCallback = e;
	}
	get maxUpdateTimeMs() {
		return this.manager.maxUpdateTimeMs;
	}
	set maxUpdateTimeMs(e) {
		this.manager.maxUpdateTimeMs = e;
	}
	get buffer() {
		return this.manager.buffer;
	}
	set buffer(e) {
		this.manager.buffer = e;
	}
	get needsUpdate() {
		return this.manager.needsUpdate;
	}
	set needsUpdate(e) {
		this.manager.needsUpdate = e;
	}
	constructor() {
		super(), this.manager = new Ea(), this.visible = /* @__PURE__ */ new Set(), this.showDelay = .5, this.hideDelay = .5, this._showTimers = /* @__PURE__ */ new Map(), this._hideTimers = /* @__PURE__ */ new Map(), this._lastUpdateTime = -1, this.added = /* @__PURE__ */ new Set(), this.removed = /* @__PURE__ */ new Set(), this.manager.addEventListener("change", ({ added: e, removed: t }) => {
			let { _showTimers: n, _hideTimers: r, visible: i } = this;
			for (let t of e) r.delete(t), i.has(t) || (t.onShown(), n.set(t, 0));
			for (let e of t) n.delete(e) ? e.onHidden() : i.has(e) && r.set(e, 0);
		});
	}
	register(e) {
		return this.manager.register(e);
	}
	unregister(e) {
		this.manager.unregister(e);
	}
	syncItems() {
		this.manager.syncItems();
	}
	flush() {
		this.manager.flush();
	}
	update(...e) {
		let t = performance.now() / 1e3, n = this._lastUpdateTime < 0 ? 0 : Math.min(t - this._lastUpdateTime, .1);
		this._lastUpdateTime = t, this.manager.update(...e);
		let { _showTimers: r, _hideTimers: i, visible: a, added: o, removed: s, showDelay: c, hideDelay: l } = this, u = performance.now();
		for (let [e, t] of r) {
			let i = t + n;
			i >= c ? (r.delete(e), a.add(e), o.add(e), s.delete(e), e.visibleTime = u) : r.set(e, i);
		}
		for (let [e, t] of i) {
			let r = t + n;
			r >= l || !e.valid ? (i.delete(e), a.delete(e), s.add(e), o.delete(e), e.onHidden()) : i.set(e, r);
		}
		for (let e of a.values()) e.visibleDuration = u - e.visibleTime, this.manager.refreshLayout(e), e.valid === !1 && !i.has(e) && (i.set(e, 0), this.manager.needsUpdate = !0);
		(o.size > 0 || s.size > 0) && this.dispatchEvent({
			type: "change",
			added: o,
			removed: s
		});
	}
	finishAnimations() {
		let { _showTimers: e, _hideTimers: t, visible: n, added: r, removed: i } = this, a = performance.now();
		for (let t of e.keys()) n.add(t), r.add(t), i.delete(t), t.visibleTime = a;
		e.clear();
		for (let e of t.keys()) n.delete(e), i.add(e), r.delete(e), e.onHidden();
		t.clear();
	}
	reset() {
		this.added.clear(), this.removed.clear();
	}
}, Oa = 5e5, ka = /* @__PURE__ */ new I(), Aa = /* @__PURE__ */ new I(), ja = [], Ma = class extends Ta {
	get count() {
		return this.lat.length;
	}
	get anchorCount() {
		return this.anchorPositions.length;
	}
	constructor() {
		super(), this.text = "", this.characterWidths = [], this.characterRadius = 0, this.totalTextWidth = 0, this.range = null, this.lat = [], this.lon = [], this.positions = [], this.anchorPositions = [], this.screenPositions = [], this.cumulativeLen = [], this.facingRatios = [], this.cachedMatrix = new M(), this.cachedResolution = new F(), this.needsUpdate = !1;
	}
	evaluate() {
		throw Error();
	}
	updateTransform(e, t, n) {
		let { positions: r, screenPositions: i, cachedMatrix: a, cachedResolution: o, cumulativeLen: s } = this;
		if (!this.needsUpdate && a.equals(e) && o.equals(t)) return;
		for (this.needsUpdate = !1, a.copy(e), o.copy(t); i.length < r.length;) i.push(new I());
		let { facingRatios: c } = this;
		c.length = i.length;
		for (let a = 0, o = i.length; a < o; a++) {
			let o = r[a], s = i[a];
			s.copy(o).applyMatrix4(e), s.x = (s.x * .5 + .5) * t.width, s.y = (-s.y * .5 + .5) * t.height, s.z = j.mapLinear(s.z, -1, 1, 0, 1), n !== null && o.lengthSq() > 0 ? (ka.subVectors(n, o).normalize(), Aa.copy(o).normalize(), c[a] = Aa.dot(ka)) : c[a] = 1;
		}
		s.length = i.length, s[0] = 0;
		for (let e = 1; e < i.length; e++) {
			let t = i[e - 1], n = i[e], r = n.x - t.x, a = n.y - t.y, o = Math.sqrt(r * r + a * a);
			s[e] = s[e - 1] + o;
		}
	}
	updateCharacterWidthCache(e) {
		let { text: t, characterWidths: n, properties: r, layer: i } = this;
		n.length = t.length;
		let a = 0;
		for (let o = 0, s = t.length; o < s; o++) {
			let s = e(t[o], i, r);
			n[o] = s, a += s;
		}
		this.totalTextWidth = a, this.characterRadius = e("M", i, r);
	}
	hasCoverage(e, t) {
		let [n, r, i, a] = this.range;
		return t >= n && t <= i && e >= r && e <= a;
	}
	generateAnchors(e) {
		let { lat: t, lon: n } = this, r = [], i = 0;
		for (let e = 0, a = t.length - 1; e < a; e++) {
			let a = t[e], o = t[e + 1], s = n[e], c = n[e + 1], l = .5 * (a + o), u = o - a, d = (c - s) * Math.cos(l), f = Math.sqrt(u * u + d * d);
			r.push(f), i += f;
		}
		let a = e * .5;
		a > i && (a = i * .5);
		let o = 0, s = 0, c = [];
		for (; a <= i;) {
			for (; s < r.length && o + r[s] < a;) o += r[s], s++;
			if (s >= r.length) break;
			let i = s, l = s + 1, u = r[i], d = u > 0 ? (a - o) / u : 0;
			c.push({
				i0: i,
				i1: l,
				alpha: d,
				ref: null,
				lat: j.lerp(t[i], t[l], d),
				lon: j.lerp(n[i], n[l], d)
			}), a += e;
		}
		this.anchorPositions = c;
	}
};
function Na(e, t, n) {
	n.length = 0;
	for (let r = 0, i = e.length - 1; r < i; r++) {
		let i = e[r], a = e[r + 1];
		n.push(i.x, i.y);
		let o = a.x - i.x, s = a.y - i.y, c = Math.sqrt(o * o + s * s), l = Math.ceil(c / t);
		for (let e = 1; e < l; e++) {
			let t = e / l;
			n.push(j.lerp(i.x, a.x, t), j.lerp(i.y, a.y, t));
		}
	}
	let r = e[e.length - 1];
	return n.push(r.x, r.y), n;
}
function Pa(e, t, n, r, i, a, o, s = []) {
	let c = Oa / o.radius.x, [l, u, d, f] = r, { flipY: p, projection: m } = a, h = e.extent, g = h * .015625, _ = `${t}:${e.properties.name || e.id}`, v = e.loadGeometry();
	for (let r of v) {
		let a = Na(r, g, ja), o = new Ma();
		o.id = _, o.layer = t, o.properties = e.properties, o.lodLevel = n, o.range = i;
		for (let e = 0, t = a.length; e < t; e += 2) {
			let t = j.lerp(l, d, a[e] / h), n = a[e + 1] / h, r = p ? j.lerp(f, u, n) : j.lerp(u, f, n), i = m.convertNormalizedToLongitude(t), s = m.convertNormalizedToLatitude(r);
			o.lon.push(i), o.lat.push(s), o.positions.push(new I());
		}
		o.generateAnchors(c * (i[2] - i[0])), s.push(o);
	}
	return s;
}
//#endregion
//#region src/three/plugins/mvt/SettlingManager.js
var Fa = 1e-10, Ia = 1, La = 16, Ra = /* @__PURE__ */ new be(), za = /* @__PURE__ */ new I(), Ba = [];
function Va(e, t) {
	let { ray: n } = e, { planes: r } = t, i = 0, a = e.far;
	for (let e = 0; e < 6; e++) {
		let t = r[e], o = t.normal.dot(n.direction);
		if (Math.abs(o) < Fa) {
			if (t.distanceToPoint(n.origin) < 0) return !1;
		} else {
			let e = n.distanceToPlane(t);
			if (o > 0) e !== null && e > i && (i = e);
			else {
				if (e === null) return !1;
				e < a && (a = e);
			}
			if (i > a) return !1;
		}
	}
	return !0;
}
var Ha = class {
	get hasPendingWork() {
		return this._queue.size > 0;
	}
	constructor() {
		this.tiles = null, this.occupancy = null, this.camera = null, this.maxSettleTimeMs = 1, this.performSettleRaycast = null, this.elevationSource = null, this._queue = /* @__PURE__ */ new Set(), this._items = /* @__PURE__ */ new Set(), this.needsUpdate = !1, this._task = null, this._deadline = 0;
	}
	register(e) {
		this._items.add(e), this._queue.add(e);
	}
	unregister(e) {
		this._items.delete(e), this._queue.delete(e);
	}
	update(e = this.maxSettleTimeMs) {
		if (this.setDeadline(e), this.needsUpdate) {
			this.needsUpdate = !1;
			for (let e of this._items.values()) this._queue.add(e);
		}
		this._task === null && (this._task = this._settleGenerator()), this._task.next();
	}
	setDeadline(e = this.maxSettleTimeMs) {
		this._deadline = performance.now() + e;
	}
	_deadlineExpired() {
		return performance.now() >= this._deadline;
	}
	_getSettlingRay(e, t, n) {
		let { tiles: r } = this, { origin: i, direction: a } = n.ray;
		r.ellipsoid.getCartographicToPosition(e, t, 1e8, i), r.ellipsoid.getCartographicToPosition(e, t, 0, a), a.sub(i).normalize(), n.far = 2 * 1e8, n.firstHitOnly = !0;
	}
	_settleSample(e, t, n, r) {
		let { tiles: i, performSettleRaycast: a, elevationSource: o } = this;
		if (a === null && o !== null) {
			let a = o.sampleCartographicElevation(e, t);
			i.ellipsoid.getCartographicToPosition(e, t, a === null ? 0 : a, za), za.distanceTo(n) > r && n.copy(za);
			return;
		}
		let { origin: s, direction: c } = Ra.ray;
		this._getSettlingRay(e, t, Ra), s.applyMatrix4(i.group.matrixWorld), c.transformDirection(i.group.matrixWorld);
		let l = !1;
		a === null ? (Ba.length = 0, Ra.intersectObject(i.group, !0, Ba), Ba.length > 0 && (za.copy(Ba[0].point), l = !0)) : l = a(Ra.ray, e, t, za), l ? za.applyMatrix4(i.group.matrixWorldInverse) : i.ellipsoid.getCartographicToPosition(e, t, 0, za), za.distanceTo(n) > r && n.copy(za);
	}
	*_settleGenerator() {
		let e = new M(), t = new te(), n = /* @__PURE__ */ new Set(), r = [
			[],
			[],
			[],
			[]
		];
		for (;;) {
			let { _queue: i, _items: a, tiles: o, camera: s, occupancy: c } = this;
			if (s !== null) {
				e.copy(o.group.matrixWorld).premultiply(s.matrixWorldInverse).premultiply(s.projectionMatrix), t.setFromProjectionMatrix(e);
				for (let e of i) if (!c.visible.has(e)) {
					if (e instanceof Ma) {
						let { anchorPositions: r } = e, { lat: i, lon: a } = r[r.length >> 1];
						if (this._getSettlingRay(i, a, Ra), Va(Ra, t)) {
							n.add(e);
							continue;
						}
					} else this._getSettlingRay(e.lat, e.lon, Ra), Va(Ra, t) && n.add(e);
					this._deadlineExpired() && (yield);
				}
			}
			for (let e of i) {
				let t = n.has(e), i = 0;
				!e.ready && t ? i = 3 : c.visible.has(e) ? i = 2 : t && (i = 1), r[i].push(e), this._deadlineExpired() && (yield);
			}
			for (let e = r.length - 1; e >= 0; e--) {
				let t = r[e];
				for (; t.length > 0;) {
					let e = t.pop();
					if (i.delete(e), a.has(e)) {
						if (!e.enabled) {
							e.ready = !1;
							continue;
						}
						yield* this._settleItem(e), this._deadlineExpired() && (yield);
					}
				}
			}
			n.clear(), r.forEach((e) => e.length = 0), yield;
		}
	}
	*_settleItem(e) {
		let t = Ia * 2 ** (La - e.lodLevel);
		if (e instanceof Ma) {
			let { _items: n } = this, { lat: r, lon: i, positions: a } = e;
			for (let o = 0, s = r.length; o < s; o++) if (this._settleSample(r[o], i[o], a[o], t), this._deadlineExpired() && (yield, !n.has(e))) return;
			e.needsUpdate = !0;
		} else this._settleSample(e.lat, e.lon, e.position, t);
		e.ready = !0;
	}
}, Ua = Math.PI / 4, Wa = 3 / 5, Ga = .8, Y = {
	NONE: 0,
	NOT_READY: 1,
	NO_FIT: 2,
	DEPTH: 3,
	OCCUPANCY: 4,
	SPACING: 5,
	ANGLE: 6,
	FACING: 7
}, Ka = [], qa = [], X = /* @__PURE__ */ new I(), Ja = /* @__PURE__ */ new F(), Ya = /* @__PURE__ */ new F(), Xa = /* @__PURE__ */ new F(), Za = [], Qa = [], $a = 0, eo = class extends Ta {
	get lat() {
		return this.getActiveReference().lat;
	}
	get lon() {
		return this.getActiveReference().lon;
	}
	get ready() {
		return this.getActiveReference().line.ready;
	}
	set ready(e) {}
	get properties() {
		return this.getActiveReference().line.properties;
	}
	set properties(e) {}
	get enabled() {
		return this.getActiveReference().line.enabled;
	}
	set enabled(e) {}
	get text() {
		return this.getActiveReference().line.text;
	}
	constructor(e) {
		super(), this.id = `${e}_${$a++}`, this.displayed = !1, this.referencePaths = [], this._activeReference = null, this._snapped = null, this._flippedTextDir = !1, this.characterPositions = [], this.characterAngles = [], this.rejectionReason = Y.NONE;
	}
	evaluate(e, t = !1) {
		this.rejectionReason = Y.NONE;
		let { text: n } = this;
		if (!n) return !1;
		let { line: r } = this.getActiveReference(), { cumulativeLen: i } = r;
		return !r.ready || i.length < 2 ? (this.rejectionReason = Y.NOT_READY, !1) : (this._flippedTextDir = this._getTextDirection(), Ka.length = n.length, qa.length = n.length, this._layoutCharacters(e, Ka, qa, t), !this.valid && !t ? !1 : (this._placeCharacters(e, Ka, qa), !0));
	}
	_reject(e) {
		this.valid && (this.rejectionReason = e), this.valid = !1;
	}
	_getTextDirection() {
		let { line: e, i0: t, i1: n, alpha: r } = this.getActiveReference(), { cumulativeLen: i, screenPositions: a, totalTextWidth: o } = e, s = j.lerp(i[t], i[n], r), c = o * .5, l = s - c, u = s + c, d = 0, f = 0, p = i.length - 2, m = 1;
		for (let e = 0, t = i.length - 2; e < t; e++) {
			let t = e + 1, n = i[e], r = i[t];
			l >= n && l <= r && (d = e, f = j.mapLinear(l, n, r, 0, 1)), u >= n && u <= r && (p = e, m = j.mapLinear(u, n, r, 0, 1));
		}
		let h = X.lerpVectors(a[d], a[d + 1], f).x;
		return X.lerpVectors(a[p], a[p + 1], m).x < h;
	}
	_layoutCharacters(e, t, n, r = !1) {
		let { line: i, i0: a, i1: o, alpha: s } = this.getActiveReference(), { cumulativeLen: c, screenPositions: l, facingRatios: u, totalTextWidth: d, characterWidths: f, characterRadius: p, text: m } = i, h = j.lerp(c[a], c[o], s), g = this._flippedTextDir;
		this.valid = !0;
		let _ = l.length, v = c[c.length - 1], y = m.length, b = h - d * .5, x = Wa * p, S = 0, C = 0;
		Za.length = 0, Qa.length = 0;
		let w = 0, T = 0, E = 0;
		for (let a = 0; a < y; a++) {
			let o = g ? y - 1 - a : a, s = f[o], m = T + s * .5 - d * .5;
			T += s;
			let D = h + m;
			if ((D < 0 || D > v) && (this._reject(Y.NO_FIT), !r)) break;
			for (; w < _ - 2 && c[w + 1] < D;) {
				w++;
				let e = c[w];
				if (e < b) continue;
				let t = l[w - 1], n = l[w], i = l[w + 1];
				Ya.set(n.x - t.x, n.y - t.y), Xa.set(i.x - n.x, i.y - n.y);
				let a = Math.abs(Math.atan2(Ya.cross(Xa), Ya.dot(Xa)));
				for (Za.push(e), Qa.push(a), S += a; e - Za[C] > x;) S -= Qa[C], C++;
				if (S > Ua && (this._reject(Y.ANGLE), !r)) break;
			}
			if (!this.valid && !r) break;
			let O = w + 1, k = c[O] - c[w], A = k > 0 ? (D - c[w]) / k : 0, ee = l[w], te = l[O];
			if (X.lerpVectors(ee, te, A), X.z < 0 || X.z > 1) {
				if (this._reject(Y.DEPTH), !r) break;
			} else if (j.lerp(u[w], u[O], A) < i.horizonCutoff) {
				if (this._reject(Y.FACING), !r) break;
			} else if (e.test(X.x, X.y, p) && (this._reject(Y.OCCUPANCY), !r)) break;
			if (a > 0) {
				let e = X.x - Ja.x, t = X.y - Ja.y, n = e * e + t * t, i = (s + E) * .5 * Ga;
				if (n < i * i && (this._reject(Y.SPACING), !r)) break;
			}
			E = s, Ja.copy(X), t[o] = w, n[o] = A;
		}
	}
	_placeCharacters(e, t, n) {
		let { characterPositions: r, characterAngles: i, text: a } = this, { line: o } = this.getActiveReference(), { screenPositions: s, positions: c, characterRadius: l } = o, u = this._flippedTextDir, d = a.length;
		for (; r.length < d;) r.push(new I());
		r.length = d, i.length = d;
		for (let a = 0; a < d; a++) {
			let o = t[a], d = n[a], f = s[o], p = s[o + 1];
			e.mark(f.x + (p.x - f.x) * d, f.y + (p.y - f.y) * d, l), r[a].lerpVectors(c[o], c[o + 1], d);
			let m = (p.x - f.x) * (u ? -1 : 1), h = (p.y - f.y) * (u ? -1 : 1);
			i[a] = Math.atan2(h, m);
		}
	}
	updateTransform(e, t, n) {
		this.updateActiveReference(), this.getActiveReference().line.updateTransform(e, t, n);
	}
	isEmpty() {
		return this.referencePaths.length === 0;
	}
	hasLoD(e) {
		return this.referencePaths.find((t) => t.line.lodLevel === e);
	}
	getPosition(e) {
		let { line: t, i0: n, i1: r, alpha: i } = this.getActiveReference();
		return e.lerpVectors(t.positions[n], t.positions[r], i);
	}
	getActiveReference() {
		return this._snapped ?? this._activeReference;
	}
	updateActiveReference() {
		let { referencePaths: e, _activeReference: t, displayed: n } = this, r, i = e[0] ?? null;
		if (r = i && i.line.ready ? i : t && t.line.ready && (e.includes(t) || this.displayed) ? t : i ?? t, r && t && r !== t) if (n) {
			let { lat: e, lon: n } = this._snapped ?? t;
			this._snapped = this._snapToLine(r.line, e, n);
		} else this._snapped = null;
		return this._activeReference = r, r;
	}
	_snapToLine(e, t, n) {
		let { lat: r, lon: i } = e;
		if (r.length < 2) return null;
		let a = Infinity, o = 0, s = 1, c = 0, l = r[0], u = i[0];
		for (let e = 0, d = r.length - 1; e < d; e++) {
			let d = r[e], f = i[e], p = r[e + 1] - d, m = i[e + 1] - f, h = p * p + m * m, g = h > 0 ? j.clamp(((t - d) * p + (n - f) * m) / h, 0, 1) : 0, _ = d + p * g, v = f + m * g, y = t - _, b = n - v, x = y * y + b * b;
			x < a && (a = x, o = e, s = e + 1, c = g, l = _, u = v);
		}
		return {
			line: e,
			i0: o,
			i1: s,
			alpha: c,
			lat: l,
			lon: u
		};
	}
	onShown() {
		this.displayed = !0, this._snapped = null;
	}
	onHidden() {
		this.displayed = !1;
	}
	addLine(e, t) {
		let n = e.anchorPositions[t], { referencePaths: r } = this;
		r.push({
			line: e,
			i0: n.i0,
			i1: n.i1,
			alpha: n.alpha,
			lat: n.lat,
			lon: n.lon
		}), r.sort((e, t) => t.line.lodLevel - e.line.lodLevel), this.updateActiveReference();
	}
	removeLine(e) {
		let { referencePaths: t } = this;
		for (let n = 0; n < t.length; n++) t[n].line === e && (t.splice(n, 1), n--);
		this.updateActiveReference();
	}
}, to = class {
	constructor() {
		this.added = /* @__PURE__ */ new Set(), this.removed = /* @__PURE__ */ new Set(), this._anchorsById = /* @__PURE__ */ new Map(), this._linesById = /* @__PURE__ */ new Map(), this.lines = /* @__PURE__ */ new Set(), this.anchors = /* @__PURE__ */ new Set();
	}
	reset() {
		this.added.clear(), this.removed.clear();
	}
	update() {
		let { _anchorsById: e, removed: t } = this;
		e.forEach((n, r) => {
			n.forEach((e) => {
				e.isEmpty() && (n.delete(e), this.anchors.delete(e), t.add(e));
			}), n.size === 0 && e.delete(r);
		});
	}
	addLines(e) {
		let { _anchorsById: t, _linesById: n, added: r } = this, i = /* @__PURE__ */ new Map();
		e.forEach((e) => {
			i.has(e.id) || i.set(e.id, []), i.get(e.id).push(e);
		}), i.forEach((e, i) => {
			t.has(i) || t.set(i, /* @__PURE__ */ new Set()), n.has(i) || n.set(i, /* @__PURE__ */ new Set());
			let a = e[0], o = t.get(i);
			o.forEach((t) => {
				let n = Infinity, r = null, i = -1;
				!a.hasCoverage(t.lat, t.lon) || t.hasLoD(a.lodLevel) || (e.forEach((e) => {
					e.anchorPositions.forEach((a, o) => {
						if (a.ref === null) {
							let s = t.lat - a.lat, c = t.lon - a.lon, l = s * s + c * c;
							l < n && (n = l, r = e, i = o);
						}
					});
				}), r && (t.addLine(r, i), r.anchorPositions[i].ref = t));
			}), e.forEach((e) => {
				e.anchorPositions.forEach((t, n) => {
					if (t.ref === null) {
						let a = new eo(i);
						a.addLine(e, n), e.hasCoverage(a.lat, a.lon) && (t.ref = a, o.add(a), this.anchors.add(a), r.add(a));
					}
				});
			});
		}), i.forEach((e, t) => {
			let r = n.get(t);
			e.forEach((e) => {
				r.add(e), this.lines.add(e);
			});
		});
	}
	deleteLines(e) {
		e.forEach((e) => this.deleteLine(e));
	}
	deleteLine(e) {
		let { _anchorsById: t, _linesById: n } = this, r = e.id;
		n.get(r).delete(e), this.lines.delete(e), n.get(r).size === 0 && n.delete(r);
		let i = t.get(r);
		i && i.forEach((t) => {
			t.removeLine(e);
		});
	}
}, no = class {
	constructor(e) {
		this.enabled = !1, this.canvas = null, this.occupancyManager = e;
	}
	update() {
		let { occupancyManager: e, enabled: t } = this;
		if (!t) {
			this.dispose();
			return;
		}
		if (this.canvas === null) {
			let e = document.createElement("canvas");
			e.style.cssText = "position:fixed;top:0;left:0;pointer-events:none;opacity:0.5;", document.body.appendChild(e), this.canvas = e;
		}
		if (e.working) return;
		let { canvas: n } = this, { cells: r, size: i, resolution: a, buffer: o } = e, s = window.devicePixelRatio, c = a.width * o, l = a.height * o, u = Math.ceil((a.width + 2 * c) / i), d = Math.ceil((a.height + 2 * l) / i);
		n.width = Math.round(s * (a.width + 2 * c)), n.height = Math.round(s * (a.height + 2 * l)), n.style.width = `${a.width + 2 * c}px`, n.style.height = `${a.height + 2 * l}px`, n.style.left = `${-c}px`, n.style.top = `${-l}px`;
		let f = i * s, p = n.getContext("2d");
		p.clearRect(0, 0, n.width, n.height);
		for (let e = 0; e < d; e++) for (let t = 0; t < u; t++) {
			let n = r[e * u + t] !== 0;
			p.fillStyle = n ? "rgba( 255, 80, 80, 0.6 )" : "rgba( 80, 255, 80, 0.15 )", p.fillRect(t * f + .5, e * f + .5, f - 1, f - 1), p.strokeStyle = n ? "rgba( 255, 80, 80, 1 )" : "rgba( 80, 255, 80, 0.25 )", p.lineWidth = 1, p.strokeRect(t * f + .5, e * f + .5, f - 1, f - 1);
		}
	}
	dispose() {
		this.canvas !== null && (this.canvas.remove(), this.canvas = null);
	}
}, ro = new class {
	constructor() {
		this._cache = {};
	}
	getColor(...e) {
		let t = e.pop(), n = e.join("_"), { _cache: r } = this;
		return n in r || (t.setHSL(Math.random(), 1, .5), r[n] = t.getHex()), t.set(r[n]);
	}
}(), io = {
	NONE: 0,
	ID: 1,
	LEVEL: 2,
	TILE: 3,
	NAME: 4,
	REJECTION: 5
}, ao = {
	[Y.NONE]: 16777215,
	[Y.NOT_READY]: 7829367,
	[Y.NO_FIT]: 2250239,
	[Y.DEPTH]: 4473924,
	[Y.OCCUPANCY]: 65535,
	[Y.SPACING]: 16776960,
	[Y.ANGLE]: 16711680,
	[Y.FACING]: 16711935
}, oo = /* @__PURE__ */ new I(), so = /* @__PURE__ */ new I(), co = /* @__PURE__ */ new w();
function lo() {
	let e = new E(new Uint8Array(1024 * 4), 32, 32);
	for (let t = 0; t < 32; t++) for (let n = 0; n < 32; n++) {
		let r = (t - 16) / 16, i = (n - 16) / 16, a = Math.sqrt(r * r + i * i), o = n * 32 + t;
		e.image.data[4 * o + 0] = 255, e.image.data[4 * o + 1] = 255, e.image.data[4 * o + 2] = 255, e.image.data[4 * o + 3] = a < 1 ? 255 : 0;
	}
	return e.needsUpdate = !0, e;
}
var uo = class {
	get ColorMode() {
		return io;
	}
	constructor(e) {
		this.enabled = !1, this.colorMode = io.NONE, this.displayLines = !0, this.displayAnchors = !0, this.camera = null, this.anchorManager = e, this.group = null, this._lines = null, this._points = null;
	}
	update() {
		let { enabled: e, group: t, camera: n, anchorManager: r, displayAnchors: i, displayLines: a } = this;
		if (!e) {
			this.dispose();
			return;
		}
		if (this._lines === null) {
			let e = new ae();
			e.material.transparent = !0, e.material.depthTest = !1, e.material.depthWrite = !1, e.material.vertexColors = !0, e.frustumCulled = !1, e.raycast = () => {};
			let n = new me();
			n.material.transparent = !0, n.material.depthTest = !1, n.material.depthWrite = !1, n.material.map = lo(), n.material.size = 6, n.material.sizeAttenuation = !1, n.material.vertexColors = !0, n.frustumCulled = !1, n.raycast = () => {}, t.add(e, n), this._lines = e, this._points = n;
		}
		let { _lines: o, _points: s } = this;
		n === null ? oo.set(0, 0, 0) : (oo.setFromMatrixPosition(n.matrixWorld), t.worldToLocal(oo));
		let c = Array.from(r.lines).filter((e) => e instanceof Ma && e.ready), l = 0;
		for (let e of c) l += e.count - 1;
		let u = new x(new Float32Array(l * 2 * 3), 3), d = new x(new Float32Array(l * 2 * 3), 3), f = 0;
		for (let e of c) {
			this._getColor(e, co);
			let t = e.positions;
			for (let e = 0, n = t.length - 1; e < n; e++) u.setXYZ(f + 0, ...so.copy(t[e]).sub(oo)), u.setXYZ(f + 1, ...so.copy(t[e + 1]).sub(oo)), d.setXYZ(f + 0, ...co), d.setXYZ(f + 1, ...co), f += 2;
		}
		let p = Array.from(r.anchors).filter((e) => e.ready), m = new x(new Float32Array(p.length * 3), 3), h = new x(new Float32Array(p.length * 2 * 3), 3);
		f = 0;
		for (let e of p) e.getPosition(so).sub(oo), m.setXYZ(f, ...so), this.colorMode === io.REJECTION ? co.set(ao[e.rejectionReason] ?? 16777215) : this._getColor(e.getActiveReference().line, co), h.setXYZ(f, ...co), f++;
		o.geometry.dispose(), o.geometry.setAttribute("position", u), o.geometry.setAttribute("color", d), o.position.copy(oo), o.updateMatrixWorld(), o.visible = a, s.geometry.dispose(), s.geometry.setAttribute("position", m), s.geometry.setAttribute("color", h), s.position.copy(oo), s.updateMatrixWorld(), s.visible = i;
	}
	dispose() {
		this._lines !== null && (this._lines.removeFromParent(), this._lines.geometry.dispose(), this._lines.material.dispose(), this._lines = null), this._points !== null && (this._points.removeFromParent(), this._points.geometry.dispose(), this._points.material.dispose(), this._points.material.map.dispose(), this._points = null);
	}
	_getColor(e, t) {
		switch (this.colorMode) {
			case io.ID:
				ro.getColor(e.id, t);
				break;
			case io.LEVEL:
				ro.getColor(e.lodLevel, t);
				break;
			case io.NAME:
				ro.getColor(e.properties.name, t);
				break;
			case io.TILE:
				ro.getColor(...e.range, t);
				break;
			default:
				t.set(16777215);
				break;
		}
	}
}, fo = /* @__PURE__ */ new I(), po = /* @__PURE__ */ new I(), mo = class extends Ta {
	constructor() {
		super(), this.position = new I(), this.lat = 0, this.lon = 0, this.radius = 28, this.screenPos = new I(), this._facingRatio = 1;
	}
	updateTransform(e, t, n) {
		let { position: r, screenPos: i } = this;
		i.copy(r).applyMatrix4(e), i.x = (i.x * .5 + .5) * t.width, i.y = (-i.y * .5 + .5) * t.height, i.z = +(i.z < -1 || i.z > 1), n !== null && r.lengthSq() > 0 ? (fo.subVectors(n, r).normalize(), po.copy(r).normalize(), this._facingRatio = po.dot(fo)) : this._facingRatio = 1;
	}
	evaluate(e) {
		let { screenPos: t, radius: n, horizonCutoff: r, _facingRatio: i } = this;
		return !this.ready || t.z !== 0 || i < r || e.test(t.x, t.y, n) ? !1 : (e.mark(t.x, t.y, n), !0);
	}
};
function ho(e, t, n, r, i, a = []) {
	let [o, s, c, l] = r, { projection: u } = i, d = e.extent, f = e.loadGeometry();
	for (let [r] of f) {
		let f = j.lerp(o, c, r.x / d), p = r.y / d, m = i.flipY ? j.lerp(l, s, p) : j.lerp(s, l, p), h = u.convertNormalizedToLongitude(f), g = u.convertNormalizedToLatitude(m), _ = new mo();
		_.id = `${t}:${e.id}`, _.layer = t, _.properties = e.properties, _.lat = g, _.lon = h, _.lodLevel = n, a.push(_);
	}
	return a;
}
//#endregion
//#region src/three/plugins/mvt/debug/HierarchyOverlay.js
var go = {
	NONE: 0,
	LEVEL: 1,
	TILE: 2
}, _o = class {
	get ColorMode() {
		return go;
	}
	constructor() {
		this.enabled = !1, this._wasEnabled = !1, this.hierarchy = null, this.tiles = null, this.tiling = null, this.colorMode = go.NONE, this._regions = {}, this._onToggleCallback = ({ x: e, y: t, level: n, visible: r }) => {
			let i = `${e}_${t}_${n}`;
			if (r) {
				let { ellipsoid: r, group: a } = this.tiles, [o, s, c, l] = this.tiling.getTileBounds(e, t, n, !1, !1), u = new d(...r.radius, s, l, o, c, 600, 700), f = new Vi(u);
				f.material.depthWrite = !1, f.material.depthTest = !1, f.material.transparent = !0;
				let p = new Hi(u);
				p.material.transparent = !0, p.material.opacity = .1, p.material.depthWrite = !1;
				let m = new re();
				m.add(f, p), a.add(m), m.updateMatrixWorld(!0), this._regions[i] = {
					helper: m,
					x: e,
					y: t,
					level: n
				};
			} else {
				let { helper: e } = this._regions[i];
				e.children.forEach((e) => e.dispose()), e.removeFromParent(), delete this._regions[i];
			}
		};
	}
	update() {
		let { enabled: e, hierarchy: t, _regions: n } = this;
		if (e !== this._wasEnabled && (this._wasEnabled = e, e ? (t.getVisibleTiles().forEach((e) => {
			this._onToggleCallback(e);
		}), t.addEventListener("toggle", this._onToggleCallback)) : this.dispose()), e) for (let e in n) {
			let { x: t, y: r, level: i, helper: a } = n[e];
			a.children.forEach((e) => {
				let { color: n } = e.material;
				switch (this.colorMode) {
					case go.NONE:
						n.set(16777215);
						break;
					case go.LEVEL:
						ro.getColor(i, n);
						break;
					case go.TILE:
						ro.getColor(t, r, i, n);
						break;
				}
			});
		}
	}
	dispose() {
		let { hierarchy: e } = this;
		e.getVisibleTiles().forEach((e) => {
			this._onToggleCallback({
				...e,
				visible: !1
			});
		}), e.removeEventListener("toggle", this._onToggleCallback);
	}
}, vo = class {
	constructor() {
		this.added = /* @__PURE__ */ new Set(), this.removed = /* @__PURE__ */ new Set(), this.points = /* @__PURE__ */ new Set(), this._annotationsById = /* @__PURE__ */ new Map();
	}
	add(e) {
		let { _annotationsById: t, points: n, added: r } = this, { id: i } = e;
		if (!t.has(i)) t.set(i, {
			annotation: e,
			ref: 0
		}), n.add(e), r.add(e);
		else {
			let n = t.get(i).annotation;
			e.lodLevel > n.lodLevel && (n.lodLevel = e.lodLevel, n.lat = e.lat, n.lon = e.lon);
		}
		t.get(i).ref++;
	}
	delete(e) {
		let { _annotationsById: t } = this, { id: n } = e, r = t.get(n);
		r.ref--;
	}
	update() {
		let { removed: e, points: t, _annotationsById: n } = this;
		n.forEach((r, i) => {
			r.ref === 0 && (e.add(r.annotation), t.delete(r.annotation), n.delete(i));
		});
	}
	reset() {
		this.added.clear(), this.removed.clear();
	}
}, yo = class extends C {
	get isFull() {
		return this._freeList.length === 0 && this._nextIndex >= this._capacity;
	}
	get capacity() {
		return this._capacity;
	}
	get count() {
		return this._slots.size;
	}
	constructor(e = 32, t = 64) {
		super(null), this.generateMipmaps = !1, this.slotSize = 0, this._columns = -1, this._capacity = -1, this._slots = /* @__PURE__ */ new Map(), this._freeList = [], this._nextIndex = 0, this._capacity = 0, this._columns = 0, this._uvs = /* @__PURE__ */ new Map(), this.resize(e, t), this.colorSpace = Se;
	}
	keys() {
		return this._slots.keys();
	}
	has(e) {
		return this._slots.has(e);
	}
	get(e) {
		let { _slots: t } = this;
		return t.has(e) ? this._indexToSlot(t.get(e)) : null;
	}
	getSlotSize(e) {
		let { slotSize: t, image: n } = this;
		return e.set(t / n.width, t / n.height);
	}
	getUV(e) {
		let { _slots: t, _uvs: n } = this, r = t.get(e);
		return n.get(r);
	}
	drawChar(e, t, n = {}) {
		let { font: r = "", color: i = "white", strokeStyle: a = null, strokeWidth: o = 1 } = n;
		return this._draw(e, (e, n, s, c, l) => {
			let u = n + c / 2, d = s + l / 2, f = this.measureChar(t), p = u - (f.actualBoundingBoxRight + f.actualBoundingBoxLeft) / 2, m = d + l / 4;
			a !== null && (e.font = r, e.lineJoin = "round", e.lineWidth = o * 2, e.strokeStyle = a, e.strokeText(t, p, m)), e.font = r, e.fillStyle = i, e.fillText(t, p, m);
		});
	}
	measureChar(e, t) {
		let { ctx: n } = this;
		return n.font = t, n.measureText(e);
	}
	drawImage(e, t) {
		return this._draw(e, (e, n, r, i, a) => {
			e.drawImage(t, n, r, i, a);
		});
	}
	drawPath(e, t, n = {}) {
		let { fillStyle: r = null, strokeStyle: i = null, lineWidth: a = 1 } = n;
		return this._draw(e, (e, n, o) => {
			e.save(), e.translate(n, o), r !== null && (e.fillStyle = r, e.fill(t)), i !== null && (e.strokeStyle = i, e.lineWidth = a, e.stroke(t)), e.restore();
		});
	}
	drawSVG(e, t, n = {}) {
		let { fillStyle: r = "white", strokeStyle: i = null, strokeWidth: a = 1, iconScale: o = 1 } = n, s = new DOMParser().parseFromString(t, "image/svg+xml").documentElement, c = (s.getAttribute("viewBox") ?? "0 0 15 15").trim().split(/[\s,]+/), l = parseFloat(c[2]), u = parseFloat(c[3]), d = [...s.querySelectorAll("path")].map((e) => e.getAttribute("d")).filter(Boolean).map((e) => new Path2D(e));
		return this._draw(e, (e, t, n, s, c) => {
			let f = s * o, p = c * o, m = Math.min(f / l, p / u), h = t + (s - l * m) / 2, g = n + (c - u * m) / 2;
			if (e.save(), e.translate(h, g), e.scale(m, m), e.lineJoin = "round", e.lineCap = "round", i !== null) {
				e.lineWidth = a / m, e.strokeStyle = i;
				for (let t of d) e.stroke(t);
			}
			if (r !== null) {
				e.fillStyle = r;
				for (let t of d) e.fill(t);
			}
			e.restore();
		});
	}
	release(e) {
		let { _slots: t, _freeList: n } = this;
		if (!t.has(e)) return;
		let r = t.get(e);
		n.push(r), t.delete(e);
	}
	resize(e, t = this.slotSize) {
		let n = this.image, r = this._columns, i = this.slotSize, a = Math.ceil(Math.sqrt(e)), o = document.createElement("canvas");
		o.width = a * t, o.height = a * t;
		let s = o.getContext("2d");
		for (let e of this._slots.values()) {
			let o = e % r * i, c = Math.floor(e / r) * i, l = e % a * t, u = Math.floor(e / a) * t;
			s.drawImage(n, o, c, i, i, l, u, t, t);
		}
		this.dispose(), this.image = o, this.ctx = s, this.slotSize = t, this._columns = a, this._capacity = e;
		for (let e of this._slots.values()) this._updateUV(e);
		this.needsUpdate = !0;
	}
	clear() {
		this._slots.clear(), this._freeList.length = 0, this._nextIndex = 0, this.ctx.clearRect(0, 0, this.image.width, this.image.height), this.needsUpdate = !0;
	}
	_draw(e, t) {
		let { ctx: n, _freeList: r, _capacity: i, _slots: a } = this, o;
		if (a.has(e)) o = a.get(e);
		else {
			if (r.length > 0) o = r.pop();
			else if (this._nextIndex < i) o = this._nextIndex++;
			else throw Error("MVTGlyphAtlasTexture: atlas is full. Call resize() to increase capacity.");
			a.set(e, o);
		}
		let s = this._indexToSlot(o);
		return n.save(), n.beginPath(), n.rect(s.x, s.y, s.w, s.h), n.clip(), n.clearRect(s.x, s.y, s.w, s.h), t(n, s.x, s.y, s.w, s.h), n.restore(), this._updateUV(o), this.needsUpdate = !0, s;
	}
	_indexToSlot(e) {
		let { _columns: t, slotSize: n } = this;
		return {
			x: e % t * n,
			y: Math.floor(e / t) * n,
			w: n,
			h: n
		};
	}
	_updateUV(e) {
		let { slotSize: t, image: n, _uvs: r } = this, { width: i, height: a } = n, o = this._indexToSlot(e);
		r.set(e, {
			x: o.x / i,
			y: (a - o.y) / a,
			w: t / i,
			h: t / a
		});
	}
}, bo = /* @__PURE__ */ new je(), xo = class extends he {
	get glyphAtlas() {
		return this._glyphAtlas;
	}
	set glyphAtlas(e) {
		this._glyphAtlas = e, e !== null && e.getSlotSize(this._glyphCellSize), this._uniforms && (this._uniforms.glyphAtlas.value = e);
	}
	get glyphCellSize() {
		return this._glyphCellSize;
	}
	constructor(e = {}) {
		let { size: t = 25, sizeAttenuation: n = !1, ...r } = e;
		super({
			size: t,
			sizeAttenuation: n,
			...r
		}), this.transparent = !0, this.depthTest = !1, this.depthWrite = !1, this.resolution = new F(), this._glyphCellSize = new F(), this._glyphAtlas = new yo(), this._uniforms = null, this.onBeforeCompile = (e) => {
			e.uniforms.glyphAtlas = { value: this._glyphAtlas }, e.uniforms.glyphCellSize = { value: this._glyphCellSize }, this._uniforms = e.uniforms, e.vertexShader = e.vertexShader.replace("#include <color_pars_vertex>", "\n					#include <color_pars_vertex>\n					attribute vec2 glyphUV;\n					attribute float alpha;\n					attribute float angle;\n					varying vec2 vGlyphUV;\n					varying float vAlpha;\n					varying float vAngle;\n				"), e.vertexShader = e.vertexShader.replace("#include <color_vertex>", "\n					#include <color_vertex>\n					vGlyphUV = glyphUV;\n					vAlpha = alpha;\n					vAngle = angle;\n				"), e.fragmentShader = "\n\n					uniform sampler2D glyphAtlas;\n					uniform vec2 glyphCellSize;\n					uniform float opacity;\n					varying vec2 vGlyphUV;\n					varying float vAlpha;\n					varying float vAngle;\n\n					void main() {\n\n						vec4 diffuseColor = vec4( 0.0 );\n						if ( vGlyphUV.x >= 0.0 ) {\n\n							// rotate the point-sprite lookup around its center so the glyph follows\n							// the path direction; clamp keeps the rotated corners inside the slot\n							vec2 pc = gl_PointCoord - 0.5;\n							float c = cos( vAngle );\n							float s = sin( vAngle );\n							pc = vec2( c * pc.x + s * pc.y, - s * pc.x + c * pc.y ) + 0.5;\n							pc = clamp( pc, 0.0, 1.0 );\n\n							vec4 glyph = texture2D( glyphAtlas, vGlyphUV + pc * glyphCellSize * vec2( 1.0, - 1.0 ) );\n							diffuseColor = glyph;\n\n						}\n\n						diffuseColor.a *= vAlpha * opacity;\n						gl_FragColor = diffuseColor;\n\n						#include <tonemapping_fragment>\n						#include <colorspace_fragment>\n						#include <premultiplied_alpha_fragment>\n\n\n					}\n\n\n			";
		};
	}
	onBeforeRender(e) {
		this._glyphAtlas.getSlotSize(this._glyphCellSize), e.getViewport(bo), this.resolution.set(bo.z, bo.w);
	}
}, So = /* @__PURE__ */ new M(), Z = /* @__PURE__ */ new je(), Co = /* @__PURE__ */ new je(), wo = /* @__PURE__ */ new F(), To = /* @__PURE__ */ new F(), Eo = /* @__PURE__ */ new I(), Do = /* @__PURE__ */ Object.freeze({
	OBSCURED: 0,
	DRAW_THROUGH: 1,
	OVERLAY: 2
}), Oo = class extends re {
	static get DrawMode() {
		return Do;
	}
	get size() {
		return this._opaque.material.size;
	}
	set size(e) {
		this._opaque.material.size = e, this._drawThrough.material.size = e;
	}
	get glyphAtlas() {
		return this._opaque.material.glyphAtlas;
	}
	get drawMode() {
		return this._drawMode;
	}
	set drawMode(e) {
		this._drawMode = e, this._applyDrawMode();
	}
	get geometry() {
		return this._opaque.geometry;
	}
	constructor(e) {
		super(), this.frustumCulled = !1, this.fadeInDuration = .3, this.fadeOutDuration = .3, this.drawThroughOpacity = .5, this._entryMap = /* @__PURE__ */ new Map(), this._orderedEntries = [], this._lastUpdateTime = -1, this._lastCamera = null;
		let t = new S(), n = new me(t, new xo());
		n.frustumCulled = !1, n.renderOrder = 1e3, n.onAfterRender = (e, t, n) => {
			this._lastCamera = n;
		};
		let r = new me(t, new xo());
		r.frustumCulled = !1, r.material.glyphAtlas = n.material.glyphAtlas, r.renderOrder = 1001, r.onAfterRender = (e, t, n) => {
			this._lastCamera = n;
		}, this.add(r, n), this._opaque = n, this._drawThrough = r, this.drawMode = Do.OVERLAY;
	}
	dispose() {
		this.glyphAtlas.dispose(), this.geometry.dispose(), this._opaque.material.dispose(), this._drawThrough.material.dispose();
	}
	update(e, t) {
		let n = performance.now() / 1e3, r = this._lastUpdateTime < 0 ? 0 : Math.min(n - this._lastUpdateTime, .1);
		this._lastUpdateTime = n;
		let { _entryMap: i, _orderedEntries: a, fadeInDuration: o, fadeOutDuration: s } = this;
		for (let t of e) {
			let e = i.get(t.id);
			if (e) e.item = t, e.state === "out" && (e.state = "in");
			else {
				let e = {
					item: t,
					fade: 0,
					state: "in"
				};
				i.set(t.id, e), a.push(e);
			}
		}
		for (let e of t) {
			let t = i.get(e.id);
			t && t.state !== "out" && (t.state = "out");
		}
		let c = !1;
		for (let [e, t] of i) t.state === "in" ? (t.fade = Math.min(1, t.fade + r / o), t.fade >= 1 && (t.state = "visible")) : t.state === "out" && (t.fade = Math.max(0, t.fade - r / s), t.fade <= 0 && (i.delete(e), c = !0));
		c && (this._orderedEntries = a.filter((e) => i.has(e.item.id))), this._recenter(), this._updateGeometry();
	}
	raycast(e, t) {
		let n = e.camera;
		if (!n) return;
		let { geometry: r, matrixWorld: i } = this, { material: a } = this._opaque, { resolution: o } = a, s = r.getAttribute("position");
		if (!s || s.count === 0) return;
		let c = a.size / 2, l = -n.near;
		e.ray.at(1, Co), Co.w = 1, Co.applyMatrix4(n.matrixWorldInverse), Co.applyMatrix4(n.projectionMatrix), Co.multiplyScalar(1 / Co.w), wo.set(Co.x * o.x / 2, Co.y * o.y / 2), So.multiplyMatrices(n.matrixWorldInverse, i);
		for (let a = 0, u = r.drawRange.count; a < u; a++) {
			if (Z.fromBufferAttribute(s, a), Z.w = 1, Z.applyMatrix4(So), Z.z > l || (Z.applyMatrix4(n.projectionMatrix), Z.multiplyScalar(1 / Z.w), Z.z < -1 || Z.z > 1) || (To.set(Z.x * o.x / 2, Z.y * o.y / 2), wo.distanceTo(To) > c)) continue;
			Eo.fromBufferAttribute(s, a).applyMatrix4(i);
			let r = this._orderedEntries[a];
			t.push({
				distance: e.ray.origin.distanceTo(Eo),
				point: Eo.clone(),
				index: a,
				face: null,
				faceIndex: null,
				object: this,
				layer: r?.item.layer ?? null,
				properties: r?.item.properties ?? null
			});
		}
		return !1;
	}
	_applyDrawMode() {
		let { _opaque: e, _drawThrough: t, drawThroughOpacity: n, _drawMode: r } = this;
		switch (r) {
			case Do.OVERLAY:
				e.visible = !0, e.material.depthTest = !1, t.visible = !1;
				break;
			case Do.DRAW_THROUGH:
				e.visible = !0, e.material.depthTest = !0, t.visible = !0, t.material.opacity = n, t.material.depthFunc = ne;
				break;
			case Do.OBSCURED:
			default:
				e.visible = !0, e.material.depthTest = !0, t.visible = !1;
				break;
		}
	}
	_recenter() {
		let { parent: e, _lastCamera: t } = this;
		t || (this.position.set(0, 0, 0), this.updateMatrixWorld(!0)), e ? So.copy(e.matrixWorld).invert() : So.identity(), this.position.setFromMatrixPosition(t.matrixWorld).applyMatrix4(So), this.updateMatrixWorld(!0);
	}
	_updateGeometry() {}
	_resizeGeometry(e) {
		let { geometry: t } = this, n = t.getAttribute("position");
		(!n || n.count < e) && (t.dispose(), t.setAttribute("position", new x(new Float32Array(e * 3), 3)), t.setAttribute("glyphUV", new x(new Float32Array(e * 2), 2)), t.setAttribute("alpha", new x(new Float32Array(e), 1)), t.setAttribute("angle", new x(new Float32Array(e), 1))), t.setDrawRange(0, e);
	}
	_writeGlyph(e, t, n, r, i = 0) {
		let { geometry: a, glyphAtlas: o } = this, s = this.position, { position: c, glyphUV: l, alpha: u, angle: d } = a.attributes;
		if (c.setXYZ(e, t.x - s.x, t.y - s.y, t.z - s.z), n !== null && o.has(n)) {
			let t = o.getUV(n);
			l.setXY(e, t.x, t.y);
		} else l.setXY(e, -1, -1);
		u.setX(e, r), d.setX(e, i);
	}
	_markNeedsUpdate() {
		let { geometry: e } = this;
		e.getAttribute("position").needsUpdate = !0, e.getAttribute("glyphUV").needsUpdate = !0, e.getAttribute("alpha").needsUpdate = !0, e.getAttribute("angle").needsUpdate = !0;
	}
}, ko = class extends Oo {
	constructor(e = {}) {
		let { getKind: t = () => null, fallback: n = null, size: r = 18, glyphSize: i = 18 * window.devicePixelRatio, slotCount: a = 64 } = e;
		super(), this.getKind = t, this.fallback = n, this.size = r, this.glyphAtlas.resize(a, i);
	}
	_updateGeometry() {
		let { _orderedEntries: e, getKind: t, glyphAtlas: n, fallback: r } = this, i = e.length;
		this._resizeGeometry(i);
		for (let a = 0; a < i; a++) {
			let { item: i, fade: o } = e[a], s = t(i.layer, i.properties);
			(s === null || !n.has(s)) && (s = r), this._writeGlyph(a, i.position, s, o);
		}
		this._markNeedsUpdate();
	}
}, Ao = /* @__PURE__ */ new Set(), jo = class extends Oo {
	constructor(e = {}) {
		let { size: t = 16, glyphSize: n = 16 * window.devicePixelRatio, slotCount: r = 64, font: i = null, fontFamily: a = "sans-serif", strokeStyle: o = "black", strokeWidth: s = 0 } = e;
		super();
		let c = Math.round(n * .7);
		this._font = i ?? `400 ${c}px ${a}`, this._advanceCache = /* @__PURE__ */ new Map(), this._strokeStyle = o, this._strokeWidth = s, this.glyphAtlas.resize(r, n), this.size = t;
	}
	reset() {
		this._advanceCache.clear(), this.glyphAtlas.clear();
	}
	measureChar(e) {
		let { _advanceCache: t, glyphAtlas: n, _font: r } = this;
		if (!t.has(e)) {
			let i = this.size / n.slotSize, a = n.measureChar(e, r).width + 2;
			t.set(e, a * i);
		}
		return t.get(e);
	}
	_drawChar(e, t) {
		let { glyphAtlas: n } = this;
		if (n.capacity === n.count) {
			let e = null;
			for (let r of n.keys()) if (!t.has(r)) {
				e = r;
				break;
			}
			e === null ? n.resize(n.capacity * 2) : n.release(e);
		}
		n.drawChar(e, e, {
			font: this._font,
			color: "white",
			strokeStyle: this._strokeStyle,
			strokeWidth: this._strokeWidth
		});
	}
	_updateGeometry() {
		let { _orderedEntries: e, glyphAtlas: t } = this;
		Ao.clear();
		let n = 0;
		for (let t of e) {
			let { text: e, characterPositions: r } = t.item;
			n += r.length;
			for (let t = 0, n = e.length; t < n; t++) Ao.add(e[t]);
		}
		for (let e of Ao) t.has(e) || this._drawChar(e, Ao);
		this._resizeGeometry(n);
		let r = 0;
		for (let t of e) {
			let e = t.item, { fade: n } = t, i = e.characterPositions, a = e.characterAngles, o = e.text;
			for (let e = 0, t = i.length; e < t; e++) this._writeGlyph(r++, i[e], o[e], n, a[e]);
		}
		this._markNeedsUpdate(), Ao.clear();
	}
}, Mo = class {
	get hasPendingWork() {
		return this._queue.size > 0;
	}
	constructor() {
		this.callback = function* () {}, this.maxUpdateTimeMs = 1, this._queue = /* @__PURE__ */ new Map(), this._tasks = /* @__PURE__ */ new Map(), this._deadline = 0, this._isDeadlineComplete = () => performance.now() >= this._deadline;
	}
	add(e, t) {
		this._tasks.delete(e), this._queue.set(e, t);
	}
	delete(e) {
		this._queue.delete(e), this._tasks.delete(e);
	}
	update(e = this.maxUpdateTimeMs) {
		let { _queue: t, _tasks: n, _isDeadlineComplete: r } = this;
		this._deadline = performance.now() + e;
		for (let [e, i] of t) {
			let a = n.get(e);
			if (a || (a = this.callback(i, r), n.set(e, a)), a.next().done && (t.delete(e), n.delete(e)), r()) break;
		}
	}
	clear() {
		this._queue.clear(), this._tasks.clear();
	}
}, No = 4095, Po = /* @__PURE__ */ new M();
function Fo(e) {
	let t = [];
	return e.traverse((e) => {
		e.isMesh && t.push(e);
	}), t;
}
var Io = class {
	set needsUpdate(e) {
		e && this.version++;
	}
	constructor() {
		this.group = new re(), this.performSettleRaycast = null, this.sampleCartographicElevation = null, this.version = 0;
	}
	filterAnnotation(e, t, n) {
		return !1;
	}
	getAnnotationRank(e) {
		return e.properties.rank ?? Infinity;
	}
	measureChar(e, t, n) {
		return 1;
	}
	getText(e) {
		return e.name ?? "";
	}
	isAnnotationEnabled(e, t, n) {
		return !0;
	}
	onPointsUpdate(e, t) {}
	onLabelsUpdate(e, t) {}
	dispose() {}
};
function Lo(e) {
	let t = [], n = [];
	for (let r of e) r instanceof eo ? n.push(r) : t.push(r);
	return {
		points: t,
		labels: n
	};
}
var Ro = class extends Io {
	constructor() {
		super();
		let e = window.devicePixelRatio, t = new ko({ fallback: "default" });
		t.glyphAtlas.drawChar("default", "●", {
			fillStyle: "white",
			strokeStyle: "black",
			strokeWidth: 3 * e,
			font: "30px sans-serif"
		});
		let n = new jo({
			fontFamily: "Arial",
			strokeStyle: "black",
			strokeWidth: 3 * e
		});
		this.group.add(t, n), this.icons = t, this.labels = n;
	}
	filterAnnotation(e, t, n) {
		return !0;
	}
	measureChar(e, t, n) {
		return this.labels.measureChar(e);
	}
	onPointsUpdate(e, t) {
		this.icons.update(e, t);
	}
	onLabelsUpdate(e, t) {
		this.labels.update(e, t);
	}
	dispose() {
		this.icons.dispose(), this.labels.dispose();
	}
}, zo = class {
	get contentCache() {
		return this.overlay.imageSource._contentCache;
	}
	get maxSettleTimeMs() {
		return this.settlingManager.maxSettleTimeMs;
	}
	set maxSettleTimeMs(e) {
		this.settlingManager.maxSettleTimeMs = e;
	}
	get maxOccupancyUpdateTimeMs() {
		return this.occupancy.maxUpdateTimeMs;
	}
	set maxOccupancyUpdateTimeMs(e) {
		this.occupancy.maxUpdateTimeMs = e;
	}
	get maxParseTimeMs() {
		return this.toggleTileQueue.maxUpdateTimeMs;
	}
	set maxParseTimeMs(e) {
		this.toggleTileQueue.maxUpdateTimeMs = e;
	}
	get horizonCutoff() {
		return this._horizonCutoff;
	}
	set horizonCutoff(e) {
		e !== this._horizonCutoff && (this._horizonCutoff = e, this.pointManager.points.forEach((t) => t.horizonCutoff = e), this.anchorManager.lines.forEach((t) => t.horizonCutoff = e), this.occupancy.needsUpdate = !0);
	}
	constructor(e = {}) {
		this.priority = Infinity, this.name = "MVT_ANNOTATIONS_PLUGIN";
		let { overlay: t, camera: n = null, driver: r = new Ro(), resolution: i = 50, horizonCutoff: a = .1, useIdleCallback: o = !0 } = e;
		this.overlay = t, this.camera = n, this.driver = r, this.resolution = i, this._horizonCutoff = a, this.useIdleCallback = o, this._idleCallbackHandle = -1, this._measureChar = (e) => this.driver.measureChar(e), this._filterAnnotation = (e, t, n) => this.driver.filterAnnotation(e, t, n), this._driverVersion = -1, this.hierarchy = new xa(), this.occupancy = new Da(), this.anchorManager = new to(), this.pointManager = new vo(), this.settlingManager = new Ha(), this.tileLoadState = /* @__PURE__ */ new Map(), this.vectorTileInfo = /* @__PURE__ */ new Map(), this.toggleTileQueue = new Mo(), this.debug = {
			occupancy: new no(this.occupancy),
			paths: new uo(this.anchorManager),
			hierarchy: new _o()
		};
	}
	async init(e) {
		this.tiles = e, e.group.add(this.driver.group), this.driver.group.updateMatrixWorld();
		let { overlay: t, occupancy: n, debug: r, hierarchy: i, settlingManager: a, contentCache: o, pointManager: s, anchorManager: c, toggleTileQueue: l } = this;
		r.paths.group = e.group, r.hierarchy.hierarchy = i, r.hierarchy.tiles = e, r.hierarchy.tiling = t.tiling, a.occupancy = n, a.tiles = e, i.contentCache = o, t.init(), t.isReady || await t.whenReady(), this.driver.sortAnnotations && console.warn("MVTAnnotationsDriver: \"sortAnnotations\" has been deprecated. Implement \"getAnnotationRank\" instead."), n.sortValueCallback = (e) => {
			let t = +!n.visible.has(e), r = Math.min(Math.max(Math.floor(this.driver.getAnnotationRank(e)), 0), No);
			return t * 4096 + r;
		}, this._onVisibilityChange = ({ scene: e, tile: t, visible: n }) => {
			a.needsUpdate = !0, this._markVectorTile(t, n);
		}, this._onUpdateAfter = () => {
			let { driver: t, camera: o, _measureChar: u } = this, d = t.version !== this._driverVersion;
			if (this._driverVersion = t.version, d) {
				for (let e of s.points) e.enabled = t.isAnnotationEnabled(e.layer, e.properties, 1);
				for (let e of c.lines) e.enabled = t.isAnnotationEnabled(e.layer, e.properties, 2), e.text = t.getText(e.properties), e.updateCharacterWidthCache(u);
				a.needsUpdate = !0, n.needsUpdate = !0;
			}
			o !== null && (e.getResolution(o, n.resolution), n.matrix.copy(e.group.matrixWorld)), i.update(), l.update(), s.update(), s.added.forEach((e) => {
				n.register(e), a.register(e);
			}), s.removed.forEach((e) => {
				n.unregister(e), a.unregister(e);
			}), s.reset(), c.update(), c.added.forEach((e) => {
				n.register(e);
			}), c.removed.forEach((e) => {
				n.unregister(e);
			}), c.reset(), n.needsUpdate = n.needsUpdate || a.hasPendingWork, a.camera = o, a.performSettleRaycast = t.performSettleRaycast, a.elevationSource = t.sampleCartographicElevation === null ? e.plugins.find((e) => e.sampleCartographicElevation) || null : t, a.update(), n.camera = o, n.update(), d && (n.flush(), n.finishAnimations());
			let f = Lo(n.added), p = Lo(n.removed);
			this.driver.onPointsUpdate(f.points, p.points), this.driver.onLabelsUpdate(f.labels, p.labels), (n.added.size > 0 || n.removed.size > 0) && e.dispatchEvent({ type: "needs-render" }), n.reset(), (n.hasPendingWork || a.hasPendingWork || l.hasPendingWork) && (e.dispatchEvent({ type: "needs-update" }), this.useIdleCallback && this._idleCallbackHandle === -1 && (this._idleCallbackHandle = requestIdleCallback((e) => {
				this._idleCallbackHandle = -1, n.needsUpdate = n.needsUpdate || a.hasPendingWork, l.update(e.timeRemaining() * .9), a.update(e.timeRemaining() * .9), n.update(e.timeRemaining() * .9);
			}))), r.paths.camera = this.camera, r.occupancy.update(), r.paths.update(), r.hierarchy.update();
		}, this._onVectorTileToggle = ({ x: t, y: n, level: r, visible: i }) => {
			e.dispatchEvent({ type: "needs-update" });
			let a = `${t}_${n}_${r}`;
			i === this.vectorTileInfo.has(a) ? l.delete(a) : l.add(a, {
				x: t,
				y: n,
				level: r,
				visible: i
			});
		}, this._onTileDownloadStart = ({ tile: e, url: t }) => {
			!/\.json$/i.test(t) && !/\.subtree/i.test(t) && this._initTileRange(e);
		}, l.callback = function* ({ x: n, y: r, level: i, visible: a }, o) {
			let { contentCache: s, driver: c, vectorTileInfo: l, settlingManager: u, anchorManager: d, pointManager: f, _filterAnnotation: p, _measureChar: m } = this, h = `${n}_${r}_${i}`;
			if (a) {
				let { tiling: a } = t, g = s.get(n, r, i);
				if (!g) {
					l.set(h, { annotations: [] });
					return;
				}
				let _ = [], v = a.getTileBounds(n, r, i, !0, !1), y = a.getTileBounds(n, r, i, !1, !1);
				for (let t in g.layers) {
					let n = g.layers[t];
					for (let r = 0; r < n.length; r++) {
						o() && (yield);
						let s = n.feature(r), { type: c } = s;
						c !== 1 && c !== 2 || p(t, s.properties, c) && (c === 1 ? ho(s, t, i, v, a, _) : Pa(s, t, i, v, y, a, e.ellipsoid, _));
					}
				}
				let b = [];
				for (let e of _) e.horizonCutoff = this._horizonCutoff, e instanceof Ma ? (b.push(e), u.register(e), e.enabled = c.isAnnotationEnabled(e.layer, e.properties, 2), e.text = c.getText(e.properties), e.updateCharacterWidthCache(m)) : (f.add(e), e.enabled = c.isAnnotationEnabled(e.layer, e.properties, 1));
				d.addLines(b), l.set(h, { annotations: _ });
			} else {
				let { annotations: e } = l.get(h);
				l.delete(h);
				let t = [];
				for (let n of e) n instanceof Ma ? (t.push(n), u.unregister(n)) : f.delete(n);
				d.deleteLines(t);
			}
		}.bind(this), i.addEventListener("toggle", this._onVectorTileToggle), e.addEventListener("update-after", this._onUpdateAfter), e.addEventListener("tile-visibility-change", this._onVisibilityChange), e.addEventListener("tile-download-start", this._onTileDownloadStart), e.forEachLoadedModel((t, n) => {
			this.processTileModel(t, n), e.visibleTiles.has(n) && this._markVectorTile(n, !0);
		});
	}
	dispose() {
		let { debug: e, tiles: t, hierarchy: n, driver: r, settlingManager: i, toggleTileQueue: a, tileLoadState: o } = this;
		e.occupancy.dispose(), e.paths.dispose(), t.group.remove(r.group), r.dispose(), n.removeEventListener("toggle", this._onVectorTileToggle), t.removeEventListener("update-after", this._onUpdateAfter), t.removeEventListener("tile-visibility-change", this._onVisibilityChange), t.removeEventListener("tile-download-start", this._onTileDownloadStart), o.forEach((e, n) => {
			t.visibleTiles.has(n) && this._markVectorTile(n, !1), this._prefetchVectorTile(n, !1);
		}), a.clear(), this._idleCallbackHandle !== -1 && (cancelIdleCallback(this._idleCallbackHandle), this._idleCallbackHandle = -1), i.elevationSource = null;
	}
	disposeTile(e) {
		this.tileLoadState.has(e) && (this._prefetchVectorTile(e, !1), this.tileLoadState.delete(e));
	}
	async processTileModel(e, t) {
		let { tiles: n, overlay: r } = this;
		if (this.tileLoadState.has(t)) return;
		r.isReady || await r.whenReady(), Po.identity(), e.parent !== null && Po.copy(n.group.matrixWorldInverse), e.updateMatrixWorld();
		let { range: i } = lt(Fo(e), n.ellipsoid, Po, r.projection);
		this.tileLoadState.set(t, i), this._prefetchVectorTile(t, !0);
	}
	_initTileRange(e) {
		let { overlay: t, tileLoadState: n } = this;
		if (!t.isReady || n.has(e) || !e.boundingVolume.region) return;
		let [r, i, a, o] = e.boundingVolume.region, s = [
			r,
			i,
			a,
			o
		];
		s = t.projection.clampToBounds(s), s = t.projection.toNormalizedRange(s), n.set(e, s), this._prefetchVectorTile(e, !0);
	}
	_prefetchVectorTile(e, t) {
		let n = this.tileLoadState.get(e);
		this._forEachTileInBounds(n, (e, n, r) => {
			this.hierarchy.setPrefetchState(e, n, r, t);
		});
	}
	_markVectorTile(e, t) {
		let n = this.tileLoadState.get(e);
		this._forEachTileInBounds(n, (e, n, r) => {
			this.hierarchy.setTargetState(e, n, r, t);
		});
	}
	_forEachTileInBounds(e, t) {
		let { overlay: n, resolution: r } = this, { tiling: i } = n, a = n.calculateLevel(e, r);
		if (!n.isReady) throw Error("MVTAnnotationsPlugin: overlay is not ready.");
		R(e, a, i, t);
	}
}, Bo = class extends S {
	constructor(e = 1, t = 1, n = 1, r = 1) {
		super();
		let i = n + 1, a = r + 1, o = i * a, s = [];
		for (let e = 0; e < i; e++) s.push(e);
		for (let e = 1; e < a; e++) s.push(e * i + i - 1);
		for (let e = i - 2; e >= 0; e--) s.push((a - 1) * i + e);
		for (let e = a - 2; e >= 1; e--) s.push(e * i);
		let c = s.length, l = o + c, u = new Float32Array(3 * l), d = new Float32Array(3 * l), f = new Float32Array(2 * l);
		for (let o = 0; o < a; o++) for (let a = 0; a < i; a++) {
			let s = o * i + a, c = a / n, l = 1 - o / r;
			u[3 * s + 0] = (c - .5) * e, u[3 * s + 1] = (l - .5) * t, d[3 * s + 2] = 1, f[2 * s + 0] = c, f[2 * s + 1] = l;
		}
		for (let e = 0; e < c; e++) {
			let t = s[e], n = o + e;
			u[3 * n + 0] = u[3 * t + 0], u[3 * n + 1] = u[3 * t + 1], u[3 * n + 2] = u[3 * t + 2], d[3 * n + 2] = 1, f[2 * n + 0] = f[2 * t + 0], f[2 * n + 1] = f[2 * t + 1];
		}
		let p = new Uint32Array(6 * n * r + 6 * c), m = 0;
		for (let e = 0; e < r; e++) for (let t = 0; t < n; t++) {
			let n = e * i + t, r = (e + 1) * i + t, a = (e + 1) * i + t + 1, o = e * i + t + 1;
			p[m++] = n, p[m++] = r, p[m++] = o, p[m++] = r, p[m++] = a, p[m++] = o;
		}
		for (let e = 0; e < c; e++) {
			let t = (e + 1) % c, n = s[e], r = s[t], i = o + e, a = o + t;
			p[m++] = n, p[m++] = r, p[m++] = i, p[m++] = r, p[m++] = a, p[m++] = i;
		}
		this.setIndex(new x(p, 1)), this.setAttribute("position", new x(u, 3)), this.setAttribute("normal", new x(d, 3)), this.setAttribute("uv", new x(f, 2)), this.surfaceVertexCount = o, this.skirtSourceIndices = new Uint32Array(s);
	}
};
//#endregion
//#region src/three/plugins/images/terrain-rgb/GridCache.js
function Vo(e, t, n) {
	let { width: r, height: i } = e;
	t.width = r, t.height = i;
	let a = t.getContext("2d", { willReadFrequently: !0 });
	a.drawImage(e, 0, 0);
	let { data: o } = a.getImageData(0, 0, r, i);
	a.clearRect(0, 0, r, i);
	let s = r + 2, c = i + 2, l = new Float32Array(s * c);
	for (let e = 0; e < i; e++) for (let t = 0; t < r; t++) {
		let i = 4 * (e * r + t);
		l[(e + 1) * s + t + 1] = n(o[i], o[i + 1], o[i + 2]);
	}
	for (let e = 0; e < s; e++) {
		let t = j.clamp(e, 1, s - 2);
		l[e] = l[s + t], l[(c - 1) * s + e] = l[(c - 2) * s + t];
	}
	for (let e = 1; e < c - 1; e++) l[e * s] = l[e * s + 1], l[e * s + s - 1] = l[e * s + s - 2];
	let u = new E(l, s, c, xe, ee);
	return u.minFilter = oe, u.magFilter = oe, u.needsUpdate = !0, u;
}
function Ho(e, t, n, r) {
	let { data: i, width: a, height: o } = e.image, s = t.image.data, c = a - 2, l = o - 2, u = 1, d = a - 2;
	n === -1 ? (u = 0, d = 0) : n === 1 && (u = a - 1, d = a - 1);
	let f = 1, p = o - 2;
	r === -1 ? (f = 0, p = 0) : r === 1 && (f = o - 1, p = o - 1);
	for (let e = f; e <= p; e++) for (let t = u; t <= d; t++) i[e * a + t] = s[(e - r * l) * a + (t - n * c)];
	e.needsUpdate = !0;
}
var Uo = class extends rt {
	constructor(e) {
		super(), this.plugin = e, this.canvas = new OffscreenCanvas(1, 1);
	}
	async fetchItem([e, t, n], r) {
		let { plugin: i } = this, a = await i._source.fetchItem([
			e,
			t,
			n
		], r), o = Vo(a.image, this.canvas, (e, t, n) => i.decodeElevation(e, t, n));
		return i._source.disposeItem(a), this.stitchNeighbors(o, e, t, n), o;
	}
	disposeItem(e) {
		e && e.dispose();
	}
	stitchNeighbors(e, t, n, r) {
		let i = this.plugin._source.tiling, { tileCountX: a } = i.getLevel(r), o = i.flipY ? -1 : 1;
		for (let i = -1; i <= 1; i++) for (let s = -1; s <= 1; s++) {
			if (i === 0 && s === 0) continue;
			let c = (t + i + a) % a, l = n + s * o, u = this.get(c, l, r);
			u && !(u instanceof Promise) && (Ho(e, u, i, s), Ho(u, e, -i, -s));
		}
	}
}, Wo = class extends ue {
	constructor(e) {
		super(e), this.onBeforeCompile = (e) => {
			e.fragmentShader = e.fragmentShader.replace("#include <bumpmap_pars_fragment>", "\n				#ifdef USE_BUMPMAP\n\n					uniform sampler2D bumpMap;\n					uniform float bumpScale;\n\n					// central differences at one texel spacing so the gradient interpolates across texels\n					vec2 dHdxy_fwd() {\n\n						vec2 dSTdx = dFdx( vBumpMapUv );\n						vec2 dSTdy = dFdy( vBumpMapUv );\n\n						vec2 texelSize = 1.0 / vec2( textureSize( bumpMap, 0 ) );\n						vec2 dx = vec2( texelSize.x, 0.0 );\n						vec2 dy = vec2( 0.0, texelSize.y );\n						float gradU = ( texture2D( bumpMap, vBumpMapUv + dx ).x - texture2D( bumpMap, vBumpMapUv - dx ).x ) / ( 2.0 * texelSize.x );\n						float gradV = ( texture2D( bumpMap, vBumpMapUv + dy ).x - texture2D( bumpMap, vBumpMapUv - dy ).x ) / ( 2.0 * texelSize.y );\n\n						float dBx = bumpScale * ( gradU * dSTdx.x + gradV * dSTdx.y );\n						float dBy = bumpScale * ( gradU * dSTdy.x + gradV * dSTdy.y );\n\n						return vec2( dBx, dBy );\n\n					}\n\n					// unnormalized surface derivatives so the gradient resolves to the physical slope\n					vec3 perturbNormalArb( vec3 surf_pos, vec3 surf_norm, vec2 dHdxy, float faceDirection ) {\n\n						vec3 vSigmaX = dFdx( surf_pos.xyz );\n						vec3 vSigmaY = dFdy( surf_pos.xyz );\n						vec3 vN = surf_norm; // normalized\n\n						vec3 R1 = cross( vSigmaY, vN );\n						vec3 R2 = cross( vN, vSigmaX );\n\n						float fDet = dot( vSigmaX, R1 ) * faceDirection;\n\n						vec3 vGrad = sign( fDet ) * ( dHdxy.x * R1 + dHdxy.y * R2 );\n						return normalize( abs( fDet ) * surf_norm - vGrad );\n\n					}\n\n				#endif\n			");
		};
	}
}, Go = class extends P {
	constructor(e) {
		super(e), this.displacementMap = null, this.displacementScale = 1, this.displacementBias = 0, this.onBeforeCompile = (e) => {
			e.uniforms.displacementMap = { value: null }, e.uniforms.displacementScale = { value: 1 }, e.uniforms.displacementBias = { value: 0 }, e.uniforms.displacementMapTransform = { value: new le() }, e.vertexShader = e.vertexShader.replace("#include <uv_pars_vertex>", "\n					#include <uv_pars_vertex>\n					uniform sampler2D displacementMap;\n					uniform float displacementScale;\n					uniform float displacementBias;\n				").replace("#include <begin_vertex>", "\n					#include <begin_vertex>\n					transformed += normalize( normal ) * ( texture2D( displacementMap, uv ).x * displacementScale + displacementBias );\n				");
		};
	}
}, Ko = Symbol("TILE_X"), qo = Symbol("TILE_Y"), Jo = Symbol("TILE_LEVEL"), Yo = Symbol("HEIGHT_GRID"), Xo = Symbol("SOURCE_TILE"), Zo = Symbol("OVERLAY_RANGE"), Qo = Symbol("OVERLAY_LEVEL"), $o = Symbol("HEIGHT_RANGE"), es = 32, ts = -500, ns = 9e3, rs = 2, Q = /* @__PURE__ */ new I(), $ = /* @__PURE__ */ new I(), is = /* @__PURE__ */ new Te(), as = [], os = null;
function ss() {
	return os === null && (os = new N(new Bo(1, 1, es, es), new P()), os.matrixAutoUpdate = !1), os;
}
function cs(e, t) {
	return Math.min(rs * Math.floor(e / rs), t);
}
function ls(e, t) {
	let { width: n, height: r } = e.image, i = n - 2, a = r - 2;
	return [
		(t[0] * i + 1) / n,
		(t[1] * a + 1) / r,
		(t[2] * i + 1) / n,
		(t[3] * a + 1) / r
	];
}
function us(e, t, n) {
	let { data: r, width: i, height: a } = e.image, o = j.clamp(t * i - .5, 0, i - 1), s = j.clamp(n * a - .5, 0, a - 1), c = Math.floor(o), l = Math.floor(s), u = Math.min(c + 1, i - 1), d = Math.min(l + 1, a - 1), f = o - c, p = s - l, m = r[l * i + c] * (1 - f) + r[l * i + u] * f, h = r[d * i + c] * (1 - f) + r[d * i + u] * f;
	return m * (1 - p) + h * p;
}
var ds = class {
	get heightScale() {
		return this._heightScale;
	}
	set heightScale(e) {
		e !== this._heightScale && (this._heightScale = e, this._updateHeightScale());
	}
	constructor(e = {}) {
		let { url: t = null, tileDimension: n = 256, maxZoom: r = 15, heightScale: i = 1, overlay: a = null, applyOverlayTexture: o = !1, unlit: s = !1, shape: c = "ellipsoid", endCaps: l = !0, useRecommendedSettings: u = !0 } = e;
		this.name = "TERRAIN_RGB_MESH_PLUGIN", this.priority = -10, this.tiles = null, this.url = t, this.tileDimension = n, this.maxZoom = r, this.overlay = a, this.applyOverlayTexture = o, this.unlit = s, this.shape = c, this.endCaps = l, this.useRecommendedSettings = u, this.heightScale = i, this._source = null, this._gridCache = new Uo(this), this._tiling = null, this._maxSourceLevel = -1;
	}
	init(e) {
		this.useRecommendedSettings && (e.errorTarget = 1), this.tiles = e;
	}
	async loadRootTileset() {
		this.overlay && await this.overlay.init();
		let { url: e, tileDimension: t, maxZoom: n, overlay: r, applyOverlayTexture: i } = this;
		this._maxSourceLevel = rs * Math.floor(n / rs);
		let a = this._maxSourceLevel + rs - 1;
		return r && i && (a = Math.max(a, r.tiling.maxLevel)), this._source = new at({
			url: e,
			tileDimension: t,
			levels: a + 1
		}), this._source.fetchData = (e, t) => {
			let n = { priority: -performance.now() };
			return this.tiles.downloadQueue.add(e, n, () => fetch(e, t), t.signal);
		}, await this._source.init(), this._tiling = this._source.tiling, this.getTileset();
	}
	async parseToMesh(e, t, n, r, i) {
		if (t[Ko] === void 0) return null;
		let a = t[Ko], o = t[qo], s = t[Jo], c = cs(s, this._maxSourceLevel), l = 2 ** (s - c), u = Math.floor(a / l), d = Math.floor(o / l), f;
		try {
			f = await this._gridCache.lock(u, d, c);
		} catch (e) {
			if (e.name !== "AbortError") throw e;
			return null;
		}
		if (i.aborted) return this._gridCache.release(u, d, c), null;
		t[Yo] = f, t[Xo] = [
			u,
			d,
			c
		];
		let p = this._getSubview(t), m = this._useEllipsoid() ? this._createEllipsoidMesh(t, p) : this._createPlanarMesh(t, p), h = f.clone();
		m.material.displacementMap = h, this.unlit || (m.material.bumpMap = h), t.children.forEach((e) => {
			e[$o] || (e[$o] = t[$o], this._updateBoundingVolume(e));
		});
		let { overlay: g, applyOverlayTexture: _ } = this;
		if (g && _) {
			let e = this._tiling.getTileBounds(a, o, s, !0, !1);
			if (g.hasContent(e, s)) {
				try {
					await g.lockTexture(e, s);
				} catch (e) {
					if (e.name !== "AbortError") throw e;
					return this._releaseGrid(t), null;
				}
				if (t[Zo] = e, t[Qo] = s, i.aborted) return g.releaseTexture(e, s), delete t[Zo], delete t[Qo], this._releaseGrid(t), null;
				let [n, r, c, l] = ls(f, p), u = this._tiling.getTileContentUVBounds(a, o, s), d = (u[2] - u[0]) / (c - n), h = (u[3] - u[1]) / (l - r), _ = g.getTexture(e, s).clone();
				_.offset.set(u[0] - n * d, u[1] - r * h), _.repeat.set(d, h), m.material.map = _, m.material.needsUpdate = !0;
			}
		}
		return m.material.displacementScale = this._heightScale, m.material.bumpScale = this._heightScale, m;
	}
	raycastTile(e, t, n, r) {
		let i = e[Yo];
		return i ? (t.traverse((e) => {
			if (e.isMesh) {
				let t = ss(), a = e.geometry.attributes.position, o = e.geometry.attributes.normal, s = e.geometry.attributes.uv, c = t.geometry.attributes.position;
				for (let e = 0, t = c.count; e < t; e++) {
					let t = us(i, s.getX(e), s.getY(e)) * this._heightScale;
					Q.fromBufferAttribute(a, e), $.fromBufferAttribute(o, e), Q.addScaledVector($, t), c.setXYZ(e, Q.x, Q.y, Q.z);
				}
				t.geometry.computeBoundingSphere(), t.matrixWorld.copy(e.matrixWorld), as.length = 0, t.raycast(n, as), as.forEach((t) => {
					t.object = e, r.push(t);
				});
			}
		}), !0) : !1;
	}
	sampleCartographicElevation(e, t) {
		let n = this._tiling;
		if (n === null || !n.projection.isCartographic) return null;
		let { projection: r } = n, i = r.convertLongitudeToNormalized(t), a = r.convertLatitudeToNormalized(e);
		for (let e = this._maxSourceLevel; e >= 0; e -= rs) {
			let [t, r] = n.getTileAtPoint(i, a, e, !0), o = this._gridCache.get(t, r, e);
			if (o && !(o instanceof Promise)) {
				let [s, c, l, u] = n.getTileBounds(t, r, e, !0), { width: d, height: f } = o.image, p = (i - s) / (l - s), m = (a - c) / (u - c);
				return us(o, (p * (d - 2) + 1) / d, (m * (f - 2) + 1) / f) * this._heightScale;
			}
		}
		return null;
	}
	preprocessNode(e) {
		let t = this._tiling.maxLevel;
		e[Jo] < t && e.parent !== null && this.expandChildren(e);
	}
	disposeTile(e) {
		let t = e[Zo];
		this.overlay && t && (this.overlay.releaseTexture(t, e[Qo]), delete e[Zo], delete e[Qo]), this._releaseGrid(e);
	}
	_releaseGrid(e) {
		let t = e[Xo];
		t && (this._gridCache.release(...t), delete e[Xo], delete e[Yo]);
	}
	dispose() {
		this.tiles.forEachLoadedModel((e, t) => {
			this.disposeTile(t);
		});
	}
	_useEllipsoid() {
		return this._tiling.projection.isCartographic && this.shape === "ellipsoid";
	}
	_getSubview(e) {
		let t = e[Ko], n = e[qo], r = e[Jo], [i, a, o] = e[Xo], s = this._tiling.getTileBounds(t, n, r, !0), c = this._tiling.getTileBounds(i, a, o, !0), l = 1 / (c[2] - c[0]), u = 1 / (c[3] - c[1]);
		return [
			(s[0] - c[0]) * l,
			(s[1] - c[1]) * u,
			(s[2] - c[0]) * l,
			(s[3] - c[1]) * u
		];
	}
	_createEllipsoidMesh(e, t) {
		let { tiles: n, endCaps: r, _tiling: i } = this, { projection: a } = i, o = e[Jo], s = e[Ko], c = e[qo], [, l, , u] = e.boundingVolume.region, [d, f, p, m] = i.getTileBounds(s, c, o, !0, !0), h = e[Yo], [g, _, v, y] = ls(h, t), b = new Bo(1, 1, es, es), x = new N(b, this.unlit ? new Go() : new Wo());
		e.engineData.boundingVolume.getSphere(is), x.position.copy(is.center);
		let { position: S, normal: C, uv: w } = b.attributes, { surfaceVertexCount: T, skirtSourceIndices: E } = b, D = Infinity, O = -Infinity;
		for (let e = 0; e < T; e++) {
			let t = e % 33, i = Math.floor(e / 33), o = t / es, s = 1 - i / es, c = a.convertNormalizedToLongitude(j.mapLinear(o, 0, 1, d, p)), b = a.convertNormalizedToLatitude(j.mapLinear(s, 0, 1, f, m));
			if (a.isMercator && r && (m === 1 && s === 1 && (b = Math.PI / 2), f === 0 && s === 0 && (b = -Math.PI / 2)), a.isMercator && s !== 0 && s !== 1) {
				let e = a.convertNormalizedToLatitude(1), t = 1 / es, n = j.mapLinear(s - t, 0, 1, l, u), r = j.mapLinear(s + t, 0, 1, l, u);
				b > e && n < e && (b = e), b < -e && r > -e && (b = -e);
			}
			let x = j.mapLinear(a.convertLongitudeToNormalized(c), d, p, 0, 1), T = j.mapLinear(a.convertLatitudeToNormalized(b), f, m, 0, 1), E = j.mapLinear(x, 0, 1, g, v), k = j.mapLinear(T, 0, 1, _, y), A = us(h, E, k);
			A < D && (D = A), A > O && (O = A), n.ellipsoid.getCartographicToPosition(b, c, 0, Q).sub(is.center), n.ellipsoid.getCartographicToNormal(b, c, $), S.setXYZ(e, Q.x, Q.y, Q.z), C.setXYZ(e, $.x, $.y, $.z), w.setXY(e, E, k);
		}
		for (let t = 0, n = E.length; t < n; t++) {
			let n = E[t], r = T + t;
			Q.fromBufferAttribute(S, n), $.fromBufferAttribute(C, n), Q.addScaledVector($, -e.geometricError), S.setXYZ(r, Q.x, Q.y, Q.z), C.setXYZ(r, $.x, $.y, $.z), w.setXY(r, w.getX(n), w.getY(n));
		}
		return e[$o] = {
			min: D,
			max: O
		}, this._updateBoundingVolume(e), x;
	}
	_createPlanarMesh(e, t) {
		let n = e.boundingVolume.box, r = n[0], i = n[1], a = n[3], o = n[7], s = e[Yo], [c, l, u, d] = ls(s, t), f = new Bo(2 * a, 2 * o, es, es), p = new N(f, this.unlit ? new Go() : new Wo());
		p.position.set(r, i, 0);
		let { position: m, uv: h } = f.attributes, { surfaceVertexCount: g, skirtSourceIndices: _ } = f, v = Infinity, y = -Infinity;
		for (let e = 0; e < g; e++) {
			let t = j.mapLinear(h.getX(e), 0, 1, c, u), n = j.mapLinear(h.getY(e), 0, 1, l, d), r = us(s, t, n);
			r < v && (v = r), r > y && (y = r), h.setXY(e, t, n);
		}
		for (let t = 0, n = _.length; t < n; t++) {
			let n = _[t];
			m.setZ(g + t, -e.geometricError), h.setXY(g + t, h.getX(n), h.getY(n));
		}
		return e[$o] = {
			min: v,
			max: y
		}, this._updateBoundingVolume(e), p;
	}
	_updateBoundingVolume(e) {
		let t = this._heightScale, n = e[Jo] === -1 ? 0 : e.geometricError, r = e[$o], i, a;
		r ? (i = r.min * t - n, a = r.max * t + n) : (i = ts * t - n, a = ns * t);
		let { boundingVolume: o, engineData: s } = e;
		if (o.region) {
			let e = o.region;
			e[4] = i, e[5] = a, s && s.boundingVolume && s.boundingVolume.setRegionData(this.tiles.ellipsoid, ...e);
		} else {
			let e = o.box;
			e[2] = (i + a) / 2, e[11] = (a - i) / 2, s && s.boundingVolume && s.boundingVolume.setObbData(e, s.transform);
		}
	}
	_updateHeightScale() {
		let { tiles: e } = this;
		e && (e.forEachLoadedModel((e) => {
			e.traverse((e) => {
				e.isMesh && (e.material.displacementScale = this._heightScale, e.material.bumpScale = this._heightScale);
			});
		}), e.traverse((e) => {
			this._updateBoundingVolume(e);
		}, null, !1));
	}
	getTileset() {
		let { tiles: e, _tiling: t } = this, n = t.minLevel, { tileCountX: r, tileCountY: i } = t.getLevel(n), a = [];
		for (let e = 0; e < r; e++) for (let t = 0; t < i; t++) {
			let r = this.createChild(e, t, n);
			r !== null && a.push(r);
		}
		let o = {
			asset: { version: "1.1" },
			geometricError: Infinity,
			root: {
				refine: "REPLACE",
				geometricError: Infinity,
				boundingVolume: this.createBoundingVolume(0, 0, -1),
				children: a,
				[Jo]: -1,
				[Ko]: 0,
				[qo]: 0
			}
		};
		return e.preprocessTileset(o, ""), o;
	}
	getUrl(e, t, n) {
		let r = cs(n, this._maxSourceLevel), i = 2 ** (n - r);
		return this._source.getUrl(Math.floor(e / i), Math.floor(t / i), r);
	}
	fetchData() {
		return /* @__PURE__ */ new ArrayBuffer();
	}
	createBoundingVolume(e, t, n, r = 0) {
		let { _tiling: i, endCaps: a } = this, o = n === -1, s = ts * this.heightScale - r, c = ns * this.heightScale;
		if (this._useEllipsoid()) {
			let r, l;
			return o ? (r = i.getContentBounds(!0), l = i.getContentBounds()) : (r = i.getTileBounds(e, t, n, !0, !0), l = i.getTileBounds(e, t, n, !1, !0)), a && (r[3] === 1 && (l[3] = Math.PI / 2), r[1] === 0 && (l[1] = -Math.PI / 2)), { region: [
				...l,
				s,
				c
			] };
		} else {
			let r;
			r = o ? i.getContentBounds(!0) : i.getTileBounds(e, t, n, !0);
			let [a, l, u, d] = r, f = i.aspectRatio * (u - a) / 2, p = (d - l) / 2;
			return { box: [
				i.aspectRatio * ((a + u) / 2 - .5),
				(l + d) / 2 - .5,
				(s + c) / 2,
				f,
				0,
				0,
				0,
				p,
				0,
				0,
				0,
				(c - s) / 2
			] };
		}
	}
	createChild(e, t, n) {
		let { _tiling: r } = this, { projection: i } = r;
		if (!r.getTileExists(e, t, n)) return null;
		let a;
		if (this._useEllipsoid()) {
			let [o, s, c, l] = r.getTileBounds(e, t, n, !0), { tilePixelWidth: u, tilePixelHeight: d } = r.getLevel(n), f = (c - o) / u, p = (l - s) / d, [, m, h, g] = r.getTileBounds(e, t, n), _ = m > 0 == g > 0 ? Math.min(Math.abs(m), Math.abs(g)) : 0, v = i.convertLatitudeToNormalized(_), y = i.getLongitudeDerivativeAtNormalized(o), b = i.getLatitudeDerivativeAtNormalized(v), [x, S] = Be(this.tiles.ellipsoid, _, h);
			a = Math.max(f * y * x, p * b * S);
		} else {
			let { pixelWidth: e, pixelHeight: t } = r.getLevel(n);
			a = Math.max(r.aspectRatio / e, 1 / t);
		}
		return {
			refine: "REPLACE",
			geometricError: a,
			boundingVolume: this.createBoundingVolume(e, t, n, a),
			content: { uri: this.getUrl(e, t, n) },
			children: [],
			[Ko]: e,
			[qo]: t,
			[Jo]: n
		};
	}
	expandChildren(e) {
		let t = e[Jo], n = e[Ko], r = e[qo], { tileSplitX: i, tileSplitY: a } = this._tiling.getLevel(t);
		for (let o = 0; o < i; o++) for (let s = 0; s < a; s++) {
			let c = this.createChild(i * n + o, a * r + s, t + 1);
			c && e.children.push(c);
		}
	}
	decodeElevation(e, t, n) {
		return -1e4 + (e * 65536 + t * 256 + n) * .1;
	}
}, fs = class extends ds {
	constructor(e = {}) {
		super(e), this.name = "TERRARIUM_MESH_PLUGIN";
	}
	decodeElevation(e, t, n) {
		return e * 256 + t + n / 256 - 32768;
	}
}, ps = null;
function ms() {
	return ps ??= Promise.all([import("@mapbox/vector-tile"), import("pbf")]).then(([{ VectorTile: e }, { default: t }]) => ({
		VectorTile: e,
		Protobuf: t
	}));
}
var hs = {
	earth: {
		fill: "#e2dfda",
		order: 0
	},
	water: {
		fill: "#80deea",
		order: 1
	},
	landcover: {
		fill: "#c4e7d2",
		order: 2
	},
	landuse: {
		fill: "#cfddd5",
		order: 3
	},
	natural: {
		fill: "#e2e0d7",
		order: 4
	},
	buildings: {
		fill: "#cccccc",
		order: 5
	},
	roads: {
		stroke: "#ebebeb",
		order: 6
	},
	transit: {
		stroke: "#a7b1b3",
		order: 7
	},
	boundaries: {
		stroke: "#adadad",
		order: 8
	},
	places: {
		fill: "#5c5c5c",
		order: 9
	},
	pois: {
		fill: "#1a8cbd",
		radius: 3,
		order: 10
	}
}, gs = (e, t) => hs[e] ?? null, _s = class extends rt {
	constructor(e = {}) {
		super();
		let { url: t = null, levels: n = 20, projection: r = "EPSG:3857" } = e;
		this.url = t, this.levels = n, this.projectionId = r, this.tiling = new He(), this.fetchData = (...e) => fetch(...e), this.fetchOptions = {};
	}
	init() {
		let { tiling: e, levels: t, url: n, projectionId: r } = this;
		return e.flipY = !/{\s*reverseY|-\s*y\s*}/g.test(n), e.setProjection(new L(r)), e.setContentBounds(...e.projection.getBounds()), Array.isArray(t) ? t.forEach((t, n) => {
			t !== null && e.setLevel(n, {
				tilePixelWidth: 512,
				tilePixelHeight: 512,
				...t
			});
		}) : e.generateLevels(t, e.projection.tileCountX, e.projection.tileCountY, {
			tilePixelWidth: 512,
			tilePixelHeight: 512
		}), Promise.resolve();
	}
	async fetchItem([e, t, n], r) {
		let i = this.getUrl(e, t, n), a = await (await this.fetchData(i, {
			...this.fetchOptions,
			signal: r
		})).arrayBuffer();
		return this._parseVectorTile(a);
	}
	async _parseVectorTile(e) {
		if (!e || e.byteLength === 0) return null;
		let { VectorTile: t, Protobuf: n } = await ms();
		return new t(new n(e));
	}
	disposeItem() {}
	getUrl(e, t, n) {
		return this.url.replace(/{\s*z\s*}/gi, n).replace(/{\s*x\s*}/gi, e).replace(/{\s*(y|reverseY|-\s*y)\s*}/gi, t);
	}
}, vs = class extends Dt {
	get tiling() {
		return this._contentCache.tiling;
	}
	get fetchData() {
		return this._contentCache.fetchData;
	}
	set fetchData(e) {
		this._contentCache.fetchData = e;
	}
	get fetchOptions() {
		return this._contentCache.fetchOptions;
	}
	set fetchOptions(e) {
		this._contentCache.fetchOptions = e;
	}
	constructor(e = {}) {
		let { resolution: t = 512, getStyle: n = null, contentCache: r, ...i } = e;
		super(), this.resolution = t, this.getStyle = n, this._canvasRenderer = new At({ tileExtent: 4096 }), this._contentCache = r ?? new _s(i);
	}
	init() {
		return this._contentCache.init();
	}
	hasContent(e, t, n, r, i) {
		let a = 0;
		return R([
			e,
			t,
			n,
			r
		], i, this._contentCache.tiling, () => a++), a > 0;
	}
	async fetchItem([e, t, n, r, i], a) {
		let { resolution: o, _contentCache: s } = this, c = document.createElement("canvas");
		c.width = o, c.height = o;
		let l = [
			e,
			t,
			n,
			r
		], u = [];
		R(l, i, s.tiling, (e, t, n) => {
			u.push(s.lock(e, t, n));
		}), await Promise.all(u), a?.throwIfAborted(), this._drawToCanvas(c, l, i);
		let d = new C(c);
		return d.colorSpace = Se, d.generateMipmaps = !1, d.needsUpdate = !0, d;
	}
	disposeItem(e, [t, n, r, i, a]) {
		R([
			t,
			n,
			r,
			i
		], a, this._contentCache.tiling, (e, t, n) => {
			this._contentCache.release(e, t, n);
		}), e && e.dispose();
	}
	redraw(...e) {
		let [t, n, r, i, a] = e, o = this.get(t, n, r, i, a);
		o && (this._drawToCanvas(o.image, [
			t,
			n,
			r,
			i
		], a), o.needsUpdate = !0);
	}
	dispose() {
		super.dispose(), this._contentCache.dispose();
	}
	_drawToCanvas(e, t, n) {
		let { _contentCache: r, _canvasRenderer: i } = this, a = e.getContext("2d");
		R(t, n, r.tiling, (e, n, o) => {
			let s = r.tiling.getTileBounds(e, n, o, !0, !1);
			i.setFrame(a, s, t);
			let c = r.get(e, n, o);
			c && this._renderVectorTile(c);
		});
	}
	_renderVectorTile(e) {
		let { _canvasRenderer: t } = this, n = this.getStyle || gs, r = [...Object.keys(e.layers)].sort((e, t) => {
			let r = n(e, null)?.order ?? At.DEFAULT_STYLE.order, i = n(t, null)?.order ?? At.DEFAULT_STYLE.order;
			return r === i ? e.localeCompare(t) : r - i;
		});
		for (let i of r) {
			let r = e.layers[i];
			for (let e = 0; e < r.length; e++) {
				let a = r.feature(e), { properties: o, type: s } = a, c = n(i, o);
				t.setStyle(c);
				let l = a.loadGeometry();
				s === 1 ? t._renderPoints(l) : s === 2 ? t._renderLines(l) : s === 3 && t._renderPolygons(l);
			}
		}
	}
}, ys = Math.PI / 180, bs = null;
function xs() {
	return bs ??= import("pmtiles").then((e) => e.PMTiles);
}
var Ss = class extends it {
	constructor(e, t) {
		super(), this.instance = e, this.tiling = t;
	}
	async fetchItem([e, t, n], r) {
		let i = await this.instance.getZxy(n, e, t, r);
		return !i || !i.data || i.data.byteLength === 0 ? null : this.processBufferToTexture(i.data);
	}
}, Cs = class extends _s {
	constructor(e = {}) {
		super(e), this.instance = null, this.tileType = 1;
	}
	async init() {
		let { tiling: e } = this, t = await xs();
		this.instance = new t({
			getKey: () => this.url,
			getBytes: async (e, t, n) => {
				n && n.throwIfAborted();
				let { fetchOptions: r, url: i } = this, a = await this.fetchData(i, {
					...r,
					signal: n,
					headers: {
						...r.headers,
						range: `bytes=${e}-${e + t - 1}`
					}
				});
				if (!a.ok) throw Error(`PMTilesImageSource: Bad response code: ${a.status}`);
				if (a.status !== 206) throw Error("PMTilesImageSource: Server does not support HTTP Byte Serving.");
				return {
					data: await a.arrayBuffer(),
					etag: a.headers.get("ETag"),
					cacheControl: a.headers.get("Cache-Control"),
					expires: a.headers.get("Expires")
				};
			}
		});
		let n = await this.instance.getHeader();
		this.tileType = n.tileType;
		let r = new L("EPSG:3857");
		e.flipY = !0, e.setProjection(r), e.setContentBounds(ys * n.minLon, ys * n.minLat, ys * n.maxLon, ys * n.maxLat), e.generateLevels(n.maxZoom + 1, r.tileCountX, r.tileCountY, {
			tilePixelWidth: 512,
			tilePixelHeight: 512,
			minLevel: n.minZoom
		});
	}
	async fetchItem([e, t, n], r) {
		let i = await this.instance.getZxy(n, e, t, r);
		return this._parseVectorTile(i ? i.data : null);
	}
}, ws = class extends Dt {
	get tiling() {
		return this._contentCache.tiling;
	}
	get fetchData() {
		return this._contentCache.fetchData;
	}
	set fetchData(e) {
		this._contentCache.fetchData = e;
	}
	get resolution() {
		return this._resolution;
	}
	set resolution(e) {
		this._resolution = e, this._deferredSource && (this._deferredSource.resolution = e);
	}
	get fetchOptions() {
		return this._contentCache.fetchOptions;
	}
	set fetchOptions(e) {
		this._contentCache.fetchOptions = e;
	}
	constructor(e = {}) {
		super();
		let { resolution: t = 512, getStyle: n = null } = e;
		this._resolution = t, this._getStyle = n, this._contentCache = new Cs(e), this._deferredSource = null, this.isVectorTile = !1;
	}
	async init() {
		await this._contentCache.init();
		let { _contentCache: e } = this;
		if (this.isVectorTile = e.tileType === 1, this.isVectorTile) this._deferredSource = new vs({
			resolution: this._resolution,
			getStyle: this._getStyle,
			contentCache: e
		});
		else {
			let t = new Ss(e.instance, e.tiling);
			this._deferredSource = new Ot(t), this._deferredSource.resolution = this._resolution;
		}
	}
	hasContent(e, t, n, r, i) {
		return this._deferredSource.hasContent(e, t, n, r, i);
	}
	lock(...e) {
		return this._deferredSource.lock(...e);
	}
	release(...e) {
		this._deferredSource.release(...e);
	}
	get(...e) {
		return this._deferredSource.get(...e);
	}
	redraw(...e) {
		this._deferredSource instanceof vs && this._deferredSource.redraw(...e);
	}
	forEachItem(...e) {
		return this._deferredSource.forEachItem(...e);
	}
	dispose() {
		super.dispose(), this._contentCache.dispose(), this._deferredSource && this._deferredSource.dispose();
	}
}, Ts = class extends Jt {
	get tiling() {
		return this.imageSource.tiling;
	}
	get projection() {
		return this.tiling.projection;
	}
	get aspectRatio() {
		return this.tiling && this.isReady ? this.tiling.aspectRatio : 1;
	}
	get fetchOptions() {
		return this.imageSource.fetchOptions;
	}
	set fetchOptions(e) {
		this.imageSource.fetchOptions = e;
	}
	get resolution() {
		return this.imageSource.resolution;
	}
	constructor(e = {}) {
		super(e), this.imageSource = e.imageSource ?? new vs(e), this._redrawQueue = new t(), this._redrawQueue.maxJobs = 4, this._redrawQueue.priorityCallback = () => 0;
	}
	_init() {
		return this.imageSource.fetchData = (...e) => this.fetch(...e), this.imageSource.init();
	}
	calculateLevel(e, t = this.resolution) {
		let [n, r, i, a] = e, o = i - n, s = a - r, c = this.tiling.maxLevel, l = 0;
		for (; l < c; l++) {
			let e = this.tiling.getLevel(l);
			if (e == null) continue;
			let { pixelWidth: n, pixelHeight: r } = e;
			if (n >= t / o || r >= t / s) break;
		}
		return l;
	}
	hasContent(e, t = this.calculateLevel(e)) {
		return this.imageSource.hasContent(...e, t);
	}
	getTexture(e, t = this.calculateLevel(e)) {
		return this.imageSource.get(...e, t);
	}
	lockTexture(e, t = this.calculateLevel(e)) {
		return this.imageSource.lock(...e, t);
	}
	releaseTexture(e, t = this.calculateLevel(e)) {
		this.imageSource.release(...e, t);
	}
	setResolution(e) {
		this.imageSource.resolution = e;
	}
	shouldSplit(e) {
		return !0;
	}
	setRegionVisible(e, t) {
		if (super.setRegionVisible(e, t), t) {
			let { _redrawQueue: t } = this, n = e.join("_") + "_" + this.calculateLevel(e);
			t.has(n) && t.flush(n);
		}
	}
	redraw() {
		let { imageSource: e, _redrawQueue: t, _visibleRegionCounts: n } = this;
		for (let { range: t } of n.values()) e.redraw(...t, this.calculateLevel(t));
		e.forEachItem((r, i) => {
			let a = i.join("_");
			!n.has(a) && !t.has(a) && t.add(a, () => {
				e.redraw(...i);
			});
		});
	}
}, Es = class extends Ts {
	constructor(e = {}) {
		super({
			...e,
			imageSource: new ws(e)
		});
	}
	shouldSplit(e) {
		return this.imageSource.isVectorTile ? !0 : this.tiling.maxLevel > this.calculateLevel(e);
	}
}, Ds = e * Math.PI * 2, Os = /* @__PURE__ */ new L("EPSG:3857");
function ks(e) {
	return /:4326$/i.test(e);
}
function As(e) {
	return /:3857$/i.test(e);
}
function js(e) {
	return e.trim().split(/\s+/).map((e) => parseFloat(e));
}
function Ms(e, t) {
	ks(t) && ([e[1], e[0]] = [e[0], e[1]]);
}
function Ns(e, t) {
	if (As(t)) return e[0] = Os.convertNormalizedToLongitude(.5 + e[0] / Ds), e[1] = Os.convertNormalizedToLatitude(.5 + e[1] / Ds), e[0] *= j.RAD2DEG, e[1] *= j.RAD2DEG, e;
}
function Ps(e) {
	e[0] *= j.DEG2RAD, e[1] *= j.DEG2RAD;
}
var Fs = class extends i {
	parse(e) {
		let t = new TextDecoder("utf-8").decode(new Uint8Array(e)), n = new DOMParser().parseFromString(t, "text/xml"), r = n.querySelector("Contents"), i = Ws(r, "TileMatrixSet").map((e) => Hs(e)), a = Ws(r, "Layer").map((e) => Ls(e)), o = Is(n.querySelector("ServiceIdentification"));
		return a.forEach((e) => {
			e.tileMatrixSets = e.tileMatrixSetLinks.map((e) => i.find((t) => t.identifier === e));
		}), {
			serviceIdentification: o,
			tileMatrixSets: i,
			layers: a
		};
	}
};
function Is(e) {
	return {
		title: e.querySelector("Title").textContent,
		abstract: e.querySelector("Abstract")?.textContent || "",
		serviceType: e.querySelector("ServiceType").textContent,
		serviceTypeVersion: e.querySelector("ServiceTypeVersion").textContent
	};
}
function Ls(e) {
	let t = e.querySelector("Title").textContent, n = e.querySelector("Identifier").textContent, r = e.querySelector("Format").textContent, i = Ws(e, "ResourceURL").map((e) => Rs(e)), a = Ws(e, "TileMatrixSetLink").map((e) => Ws(e, "TileMatrixSet")[0].textContent), o = Ws(e, "Style").map((e) => Vs(e)), s = Ws(e, "Dimension").map((e) => zs(e)), c = Bs(e.querySelector("WGS84BoundingBox"));
	return c ||= Bs(e.querySelector("BoundingBox")), {
		title: t,
		identifier: n,
		format: r,
		dimensions: s,
		tileMatrixSetLinks: a,
		styles: o,
		boundingBox: c,
		resourceUrls: i
	};
}
function Rs(e) {
	return {
		template: e.getAttribute("template"),
		format: e.getAttribute("format"),
		resourceType: e.getAttribute("resourceType")
	};
}
function zs(e) {
	return {
		identifier: e.querySelector("Identifier").textContent,
		uom: e.querySelector("UOM")?.textContent || "",
		defaultValue: e.querySelector("Default").textContent,
		current: e.querySelector("Current")?.textContent === "true",
		values: Ws(e, "Value").map((e) => e.textContent)
	};
}
function Bs(e) {
	if (!e) return null;
	let t = e.nodeName.endsWith("WGS84BoundingBox") ? "urn:ogc:def:crs:CRS::84" : e.getAttribute("crs"), n = js(e.querySelector("LowerCorner").textContent), r = js(e.querySelector("UpperCorner").textContent);
	return Ms(n, t), Ms(r, t), Ns(n, t), Ns(r, t), Ps(n), Ps(r), {
		crs: t,
		lowerCorner: n,
		upperCorner: r,
		bounds: [...n, ...r]
	};
}
function Vs(e) {
	return {
		title: e.querySelector("Title")?.textContent || null,
		identifier: e.querySelector("Identifier").textContent,
		isDefault: e.getAttribute("isDefault") === "true"
	};
}
function Hs(e) {
	let t = e.querySelector("SupportedCRS").textContent, n = e.querySelector("Title")?.textContent || "", r = e.querySelector("Identifier").textContent, i = e.querySelector("Abstract")?.textContent || "", a = [];
	return e.querySelectorAll("TileMatrix").forEach((e, n) => {
		let r = Us(e), i = 28e-5 * r.scaleDenominator, o = r.tileWidth * r.matrixWidth * i, s = r.tileHeight * r.matrixHeight * i, c;
		Ms(r.topLeftCorner, t), c = As(t) ? [r.topLeftCorner[0] + o, r.topLeftCorner[1] - s] : [r.topLeftCorner[0] + 360 * o / Ds, r.topLeftCorner[1] - 360 * s / Ds], Ns(c, t), Ns(r.topLeftCorner, t), Ps(c), Ps(r.topLeftCorner), r.bounds = [...r.topLeftCorner, ...c], [r.bounds[1], r.bounds[3]] = [r.bounds[3], r.bounds[1]], a.push(r);
	}), {
		title: n,
		identifier: r,
		abstract: i,
		supportedCRS: t,
		tileMatrices: a
	};
}
function Us(e) {
	return {
		identifier: e.querySelector("Identifier").textContent,
		tileWidth: parseFloat(e.querySelector("TileWidth").textContent),
		tileHeight: parseFloat(e.querySelector("TileHeight").textContent),
		matrixWidth: parseFloat(e.querySelector("MatrixWidth").textContent),
		matrixHeight: parseFloat(e.querySelector("MatrixHeight").textContent),
		scaleDenominator: parseFloat(e.querySelector("ScaleDenominator").textContent),
		topLeftCorner: js(e.querySelector("TopLeftCorner").textContent),
		bounds: null
	};
}
function Ws(e, t) {
	return [...e.children].filter((e) => e.tagName === t);
}
//#endregion
//#region src/three/plugins/loaders/WMSCapabilitiesLoader.js
var Gs = e * Math.PI * 2, Ks = /* @__PURE__ */ new L("EPSG:3857");
function qs(e) {
	return /:4326$/i.test(e);
}
function Js(e) {
	return /:3857$/i.test(e);
}
function Ys(e, t) {
	return Js(t) && (e[0] = Ks.convertNormalizedToLongitude(.5 + e[0] / (Math.PI * 2 * Gs)), e[1] = Ks.convertNormalizedToLatitude(.5 + e[1] / (Math.PI * 2 * Gs)), e[0] *= j.RAD2DEG, e[1] *= j.RAD2DEG), e;
}
function Xs(e, t, n) {
	let [r, i] = n.split(".").map((e) => parseInt(e)), a = r === 1 && i < 3 || r < 1;
	qs(t) && a && ([e[0], e[1]] = [e[1], e[0]]);
}
function Zs(e) {
	e[0] *= j.DEG2RAD, e[1] *= j.DEG2RAD;
}
function Qs(e, t) {
	if (!e) return null;
	let n = e.getAttribute("CRS") || e.getAttribute("crs") || e.getAttribute("SRS") || "", r = parseFloat(e.getAttribute("minx")), i = parseFloat(e.getAttribute("miny")), a = parseFloat(e.getAttribute("maxx")), o = parseFloat(e.getAttribute("maxy")), s = [r, i], c = [a, o];
	return Xs(s, n, t), Xs(c, n, t), Ys(s, n), Ys(c, n), Zs(s), Zs(c), {
		crs: n,
		bounds: [...s, ...c]
	};
}
function $s(e) {
	let t = parseFloat(e.querySelector("westBoundLongitude").textContent), n = parseFloat(e.querySelector("eastBoundLongitude").textContent), r = parseFloat(e.querySelector("southBoundLatitude").textContent), i = parseFloat(e.querySelector("northBoundLatitude").textContent), a = [t, r], o = [n, i];
	return Zs(a), Zs(o), [...a, ...o];
}
function ec(e) {
	let t = parseFloat(e.getAttribute("minx").textContent), n = parseFloat(e.getAttribute("maxx").textContent), r = parseFloat(e.getAttribute("miny").textContent), i = parseFloat(e.getAttribute("maxy").textContent), a = [t, r], o = [n, i];
	return Zs(a), Zs(o), [...a, ...o];
}
function tc(e) {
	return {
		name: e.querySelector("Name").textContent,
		title: e.querySelector("Title").textContent,
		legends: [...e.querySelectorAll("LegendURL")].map((e) => ({
			width: parseInt(e.getAttribute("width")),
			height: parseInt(e.getAttribute("height")),
			format: e.querySelector("Format").textContent,
			url: ic(e.querySelector("OnlineResource"))
		}))
	};
}
function nc(e, t, n = {}) {
	let { styles: r = [], crs: i = [], contentBoundingBox: a = null, queryable: o = !1, opaque: s = !1 } = n, c = e.querySelector(":scope > Name")?.textContent || null, l = e.querySelector(":scope > Title")?.textContent || "", u = e.querySelector(":scope > Abstract")?.textContent || "", d = [...e.querySelectorAll(":scope > Keyword")].map((e) => e.textContent), f = [...e.querySelectorAll(":scope > BoundingBox")].map((e) => Qs(e, t));
	i = [...i, ...Array.from(e.querySelectorAll("CRS")).map((e) => e.textContent)], r = [...r, ...Array.from(e.querySelectorAll(":scope > Style")).map((e) => tc(e))], e.hasAttribute("queryable") && (o = e.getAttribute("queryable") === "1"), e.hasAttribute("opaque") && (s = e.getAttribute("opaque") === "1"), e.querySelector("EX_GeographicBoundingBox") ? a = $s(e.querySelector("EX_GeographicBoundingBox")) : e.querySelector("LatLonBoundingBox") && (a = ec(e.querySelector("LatLonBoundingBox")));
	let p = Array.from(e.querySelectorAll(":scope > Layer")).map((e) => nc(e, t, {
		styles: r,
		crs: i,
		contentBoundingBox: a,
		queryable: o,
		opaque: s
	}));
	return {
		name: c,
		title: l,
		abstract: u,
		queryable: o,
		opaque: s,
		keywords: d,
		crs: i,
		boundingBoxes: f,
		contentBoundingBox: a,
		styles: r,
		subLayers: p
	};
}
function rc(e) {
	return {
		name: e.querySelector("Name")?.textContent || "",
		title: e.querySelector("Title")?.textContent || "",
		abstract: e.querySelector("Abstract")?.textContent || "",
		keywords: Array.from(e.querySelectorAll("Keyword")).map((e) => e.textContent),
		maxWidth: parseFloat(e.querySelector("MaxWidth")) || null,
		maxHeight: parseFloat(e.querySelector("MaxHeight")) || null,
		layerLimit: parseFloat(e.querySelector("LayerLimit")) || null
	};
}
function ic(e) {
	return e ? (e.getAttribute("xlink:href") || e.getAttributeNS("http://www.w3.org/1999/xlink", "href") || "").trim() : "";
}
function ac(e) {
	let t = Array.from(e.querySelectorAll("Format")).map((e) => e.textContent.trim()), n = Array.from(e.querySelectorAll("DCPType")).map((e) => {
		let t = e.querySelector("HTTP"), n = t.querySelector("Get OnlineResource") || t.querySelector("Get > OnlineResource") || t.querySelector("Get"), r = t.querySelector("Post OnlineResource") || t.querySelector("Post > OnlineResource") || t.querySelector("Post");
		return {
			type: "HTTP",
			get: ic(n),
			post: ic(r)
		};
	});
	return {
		formats: t,
		dcp: n,
		href: n[0].get
	};
}
function oc(e) {
	let t = {};
	return Array.from(e.querySelectorAll(":scope > *")).forEach((e) => {
		let n = e.localName;
		t[n] = ac(e);
	}), t;
}
function sc(e, t = []) {
	return e.forEach((e) => {
		e.name !== null && t.push(e), sc(e.subLayers, t);
	}), t;
}
var cc = class extends i {
	parse(e) {
		let t = new TextDecoder("utf-8").decode(new Uint8Array(e)), n = new DOMParser().parseFromString(t, "text/xml"), r = (n.querySelector("WMS_Capabilities") || n.querySelector("WMT_MS_Capabilities")).getAttribute("version"), i = n.querySelector("Capability"), a = rc(n.querySelector(":scope > Service")), o = oc(i.querySelector(":scope > Request"));
		return {
			version: r,
			service: a,
			layers: sc(Array.from(i.querySelectorAll(":scope > Layer")).map((e) => nc(e, r))),
			request: o
		};
	}
};
//#endregion
export { Dr as A, Jt as B, ii as C, Ir as D, Lr as E, Mn as F, en as G, tn as H, nn as I, Ge as J, Xt as K, Zt as L, zn as M, Fn as N, Fr as O, Nn as P, Qt as R, hi as S, zr as T, Yt as U, qt as V, $t as W, We as X, Ue as Y, Ei as _, fs as a, Oi as b, Io as c, ko as d, Oo as f, Di as g, da as h, Es as i, Cr as j, Mr as k, zo as l, yo as m, Fs as n, ds as o, xo as p, et as q, Ts as r, Ro as s, cc as t, jo as u, Ai as v, Br as w, Ti as x, ki as y, rn as z };

//# sourceMappingURL=plugins-DiPIaVd3.js.map