import { A as e, L as t, _ as n, d as r, f as i, i as a, k as o, n as s, r as c, t as l } from "./renderer-tyqPdeD-.js";
import { Box3 as u, BufferAttribute as d, BufferGeometry as f, Clock as p, Color as m, DefaultLoadingManager as h, Euler as g, EventDispatcher as _, Frustum as v, Group as y, InstancedMesh as ee, LoadingManager as b, MathUtils as x, Matrix3 as te, Matrix4 as S, Mesh as ne, OrthographicCamera as re, PerspectiveCamera as ie, Plane as ae, PlaneGeometry as oe, Points as se, PointsMaterial as ce, Quaternion as le, Ray as ue, Raycaster as de, ShaderMaterial as fe, Sphere as pe, Spherical as me, TextureUtils as he, Vector2 as C, Vector3 as w } from "three";
import { GLTFLoader as ge } from "three/addons/loaders/GLTFLoader.js";
import { estimateBytesUsed as _e } from "three/addons/utils/BufferGeometryUtils.js";
//#region src/three/renderer/loaders/B3DMLoader.js
var ve = class extends a {
	constructor(e = h) {
		super(), this.manager = e, this.adjustmentTransform = new S();
	}
	parse(e) {
		let t = super.parse(e), n = t.glbBytes.slice().buffer;
		return new Promise((e, r) => {
			let i = this.manager, a = this.fetchOptions, o = i.getHandler("path.gltf") || new ge(i);
			a.credentials === "include" && a.mode === "cors" && o.setCrossOrigin("use-credentials"), "credentials" in a && o.setWithCredentials(a.credentials === "include"), a.headers && o.setRequestHeader(a.headers);
			let s = this.workingPath;
			!/[\\/]$/.test(s) && s.length && (s += "/");
			let c = this.adjustmentTransform;
			o.parse(n, s, (n) => {
				let { batchTable: r, featureTable: i } = t, { scene: a } = n, o = i.getData("RTC_CENTER", 1, "FLOAT", "VEC3");
				o && (a.position.x += o[0], a.position.y += o[1], a.position.z += o[2]), n.scene.updateMatrix(), n.scene.matrix.multiply(c), n.scene.matrix.decompose(n.scene.position, n.scene.quaternion, n.scene.scale), n.batchTable = r, n.featureTable = i, a.batchTable = r, a.featureTable = i, e(n);
			}, r);
		});
	}
};
//#endregion
//#region src/three/renderer/loaders/rgb565torgb.js
function ye(e) {
	let t = e >> 11, n = e >> 5 & 63, r = e & 31;
	return [
		Math.round(t / 31 * 255),
		Math.round(n / 63 * 255),
		Math.round(r / 31 * 255)
	];
}
//#endregion
//#region src/three/renderer/loaders/decodeOctNormal.js
var be = /* @__PURE__ */ new C();
function xe(e, t, n = new w()) {
	be.set(e, t).divideScalar(256).multiplyScalar(2).subScalar(1), n.set(be.x, be.y, 1 - Math.abs(be.x) - Math.abs(be.y));
	let r = x.clamp(-n.z, 0, 1);
	return n.x >= 0 ? n.setX(n.x - r) : n.setX(n.x + r), n.y >= 0 ? n.setY(n.y - r) : n.setY(n.y + r), n.normalize(), n;
}
//#endregion
//#region src/three/renderer/loaders/PNTSLoader.js
var Se = {
	RGB: "color",
	POSITION: "position"
}, Ce = class extends s {
	constructor(e = h) {
		super(), this.manager = e;
	}
	parse(e) {
		return super.parse(e).then(async (e) => {
			let { featureTable: t, batchTable: n } = e, r = new ce(), i = t.header.extensions, a = new w(), o;
			if (i && i["3DTILES_draco_point_compression"]) {
				let { byteOffset: e, byteLength: n, properties: a } = i["3DTILES_draco_point_compression"], s = this.manager.getHandler("draco.drc");
				if (s == null) throw Error("PNTSLoader: dracoLoader not available.");
				let c = {};
				for (let e in a) if (e in Se && e in a) {
					let t = Se[e];
					c[t] = a[e];
				}
				let l = {
					attributeIDs: c,
					attributeTypes: {
						position: "Float32Array",
						color: "Uint8Array"
					},
					useUniqueIDs: !0
				}, u = t.getBuffer(e, n);
				o = await s.decodeGeometry(u, l), o.attributes.color && (r.vertexColors = !0);
			} else {
				let e = t.getData("POINTS_LENGTH"), n = t.getData("POSITION", e, "FLOAT", "VEC3"), i = t.getData("NORMAL", e, "FLOAT", "VEC3"), s = t.getData("NORMAL", e, "UNSIGNED_BYTE", "VEC2"), c = t.getData("RGB", e, "UNSIGNED_BYTE", "VEC3"), l = t.getData("RGBA", e, "UNSIGNED_BYTE", "VEC4"), u = t.getData("RGB565", e, "UNSIGNED_SHORT", "SCALAR"), p = t.getData("CONSTANT_RGBA", e, "UNSIGNED_BYTE", "VEC4"), h = t.getData("POSITION_QUANTIZED", e, "UNSIGNED_SHORT", "VEC3"), g = t.getData("QUANTIZED_VOLUME_SCALE", e, "FLOAT", "VEC3"), _ = t.getData("QUANTIZED_VOLUME_OFFSET", e, "FLOAT", "VEC3");
				if (o = new f(), h) {
					let t = new Float32Array(e * 3);
					for (let n = 0; n < e; n++) for (let e = 0; e < 3; e++) {
						let r = 3 * n + e;
						t[r] = h[r] / 65535 * g[e];
					}
					a.x = _[0], a.y = _[1], a.z = _[2], o.setAttribute("position", new d(t, 3, !1));
				} else o.setAttribute("position", new d(n, 3, !1));
				if (i !== null) o.setAttribute("normal", new d(i, 3, !1));
				else if (s !== null) {
					let t = new Float32Array(e * 3), n = new w();
					for (let r = 0; r < e; r++) {
						let e = s[r * 2], i = s[r * 2 + 1], a = xe(e, i, n);
						t[r * 3] = a.x, t[r * 3 + 1] = a.y, t[r * 3 + 2] = a.z;
					}
					o.setAttribute("normal", new d(t, 3, !1));
				}
				if (l !== null) o.setAttribute("color", new d(l, 4, !0)), r.vertexColors = !0, r.transparent = !0, r.depthWrite = !1;
				else if (c !== null) o.setAttribute("color", new d(c, 3, !0)), r.vertexColors = !0;
				else if (u !== null) {
					let t = new Uint8Array(e * 3);
					for (let n = 0; n < e; n++) {
						let e = ye(u[n]);
						for (let r = 0; r < 3; r++) {
							let i = 3 * n + r;
							t[i] = e[r];
						}
					}
					o.setAttribute("color", new d(t, 3, !0)), r.vertexColors = !0;
				} else if (p !== null) {
					r.color = new m(p[0], p[1], p[2]);
					let e = p[3] / 255;
					e < 1 && (r.opacity = e, r.transparent = !0, r.depthWrite = !1);
				}
			}
			let s = new se(o, r);
			s.position.copy(a), e.scene = s, e.scene.featureTable = t, e.scene.batchTable = n;
			let c = t.getData("RTC_CENTER", 1, "FLOAT", "VEC3");
			return c && (e.scene.position.x += c[0], e.scene.position.y += c[1], e.scene.position.z += c[2]), e;
		});
	}
}, we = /* @__PURE__ */ t({
	latitudeToSphericalPhi: () => je,
	sphericalPhiToLatitude: () => Ae,
	swapToGeoFrame: () => Oe,
	swapToThreeFrame: () => ke,
	toLatLonString: () => Pe
}), Te = /* @__PURE__ */ new me(), Ee = /* @__PURE__ */ new w(), De = {};
function Oe(e) {
	let { x: t, y: n, z: r } = e;
	e.x = r, e.y = t, e.z = n;
}
function ke(e) {
	let { x: t, y: n, z: r } = e;
	e.z = t, e.x = n, e.y = r;
}
function Ae(e) {
	return -(e - Math.PI / 2);
}
function je(e) {
	return -e + Math.PI / 2;
}
function Me(e, t, n = {}) {
	return Te.theta = t, Te.phi = je(e), Ee.setFromSpherical(Te), Te.setFromVector3(Ee), n.lat = Ae(Te.phi), n.lon = Te.theta, n;
}
function Ne(e, t = "E", n = "W") {
	let r = e < 0 ? n : t;
	e = Math.abs(e);
	let i = ~~e, a = (e - i) * 60, o = ~~a;
	return `${i}° ${o}' ${~~((a - o) * 60)}" ${r}`;
}
function Pe(e, t, n = !1) {
	let r = Me(e, t, De), i, a;
	return n ? (i = `${(x.RAD2DEG * r.lat).toFixed(4)}°`, a = `${(x.RAD2DEG * r.lon).toFixed(4)}°`) : (i = Ne(x.RAD2DEG * r.lat, "N", "S"), a = Ne(x.RAD2DEG * r.lon, "E", "W")), `${i} ${a}`;
}
//#endregion
//#region src/three/renderer/math/Ellipsoid.js
var Fe = /* @__PURE__ */ new me(), Ie = /* @__PURE__ */ new w(), T = /* @__PURE__ */ new w(), Le = /* @__PURE__ */ new w(), E = /* @__PURE__ */ new S(), D = /* @__PURE__ */ new S(), Re = /* @__PURE__ */ new pe(), O = /* @__PURE__ */ new g(), ze = /* @__PURE__ */ new w(), Be = /* @__PURE__ */ new w(), Ve = /* @__PURE__ */ new w(), He = /* @__PURE__ */ new w(), Ue = /* @__PURE__ */ new ue(), We = 1e-12, Ge = .1, Ke = 0, qe = 1, Je = 2, Ye = class {
	constructor(e = 1, t = 1, n = 1) {
		this.name = "", this.radius = new w(e, t, n);
	}
	intersectRay(e, t) {
		return E.makeScale(...this.radius).invert(), Re.center.set(0, 0, 0), Re.radius = 1, Ue.copy(e).applyMatrix4(E), Ue.intersectSphere(Re, t) ? (E.makeScale(...this.radius), t.applyMatrix4(E), t) : null;
	}
	getEastNorthUpFrame(e, t, n, r) {
		return n.isMatrix4 && (r = n, n = 0, console.warn("Ellipsoid: The signature for \"getEastNorthUpFrame\" has changed.")), this.getEastNorthUpAxes(e, t, ze, Be, Ve), this.getCartographicToPosition(e, t, n, He), r.makeBasis(ze, Be, Ve).setPosition(He);
	}
	getOrientedEastNorthUpFrame(e, t, n, r, i, a, o) {
		return this.getObjectFrame(e, t, n, r, i, a, o, 0);
	}
	getObjectFrame(e, t, n, r, i, a, o, s = 2) {
		return this.getEastNorthUpFrame(e, t, n, E), O.set(i, a, -r, "ZXY"), o.makeRotationFromEuler(O).premultiply(E), s === 1 ? (O.set(Math.PI / 2, 0, 0, "XYZ"), D.makeRotationFromEuler(O), o.multiply(D)) : s === 2 && (O.set(-Math.PI / 2, 0, Math.PI, "XYZ"), D.makeRotationFromEuler(O), o.multiply(D)), o;
	}
	getCartographicFromObjectFrame(e, t, n = 2) {
		return n === 1 ? (O.set(-Math.PI / 2, 0, 0, "XYZ"), D.makeRotationFromEuler(O).premultiply(e)) : n === 2 ? (O.set(-Math.PI / 2, 0, Math.PI, "XYZ"), D.makeRotationFromEuler(O).premultiply(e)) : D.copy(e), He.setFromMatrixPosition(D), this.getPositionToCartographic(He, t), this.getEastNorthUpFrame(t.lat, t.lon, 0, E).invert(), D.premultiply(E), O.setFromRotationMatrix(D, "ZXY"), t.azimuth = -O.z, t.elevation = O.x, t.roll = O.y, t;
	}
	getEastNorthUpAxes(e, t, n, r, i, a = He) {
		this.getCartographicToPosition(e, t, 0, a), this.getCartographicToNormal(e, t, i), n.set(-a.y, a.x, 0).normalize(), r.crossVectors(i, n).normalize();
	}
	getCartographicToPosition(e, t, n, r) {
		this.getCartographicToNormal(e, t, Ie);
		let i = this.radius;
		T.copy(Ie), T.x *= i.x ** 2, T.y *= i.y ** 2, T.z *= i.z ** 2;
		let a = Math.sqrt(Ie.dot(T));
		return T.divideScalar(a), r.copy(T).addScaledVector(Ie, n);
	}
	getPositionToCartographic(e, t) {
		this.getPositionToSurfacePoint(e, T), this.getPositionToNormal(T, Ie);
		let n = Le.subVectors(e, T);
		return t.lon = Math.atan2(Ie.y, Ie.x), t.lat = Math.asin(Ie.z), t.height = Math.sign(n.dot(e)) * n.length(), t;
	}
	getCartographicToNormal(e, t, n) {
		return Fe.set(1, je(e), t), n.setFromSpherical(Fe).normalize(), Oe(n), n;
	}
	getPositionToNormal(e, t) {
		let n = this.radius;
		return t.copy(e), t.x /= n.x ** 2, t.y /= n.y ** 2, t.z /= n.z ** 2, t.normalize(), t;
	}
	getPositionToSurfacePoint(e, t) {
		let n = this.radius, r = 1 / n.x ** 2, i = 1 / n.y ** 2, a = 1 / n.z ** 2, o = e.x * e.x * r, s = e.y * e.y * i, c = e.z * e.z * a, l = o + s + c, u = Math.sqrt(1 / l), d = T.copy(e).multiplyScalar(u);
		if (l < Ge) return isFinite(u) ? t.copy(d) : null;
		let f = Le.set(d.x * r * 2, d.y * i * 2, d.z * a * 2), p = (1 - u) * e.length() / (.5 * f.length()), m = 0, h, g, _, v, y, ee, b, x, te, S, ne;
		do {
			p -= m, _ = 1 / (1 + p * r), v = 1 / (1 + p * i), y = 1 / (1 + p * a), ee = _ * _, b = v * v, x = y * y, te = ee * _, S = b * v, ne = x * y, h = o * ee + s * b + c * x - 1, g = o * te * r + s * S * i + c * ne * a;
			let e = -2 * g;
			m = h / e;
		} while (Math.abs(h) > We);
		return t.set(e.x * _, e.y * v, e.z * y);
	}
	calculateHorizonDistance(e, t) {
		let n = this.calculateEffectiveRadius(e);
		return Math.sqrt(2 * n * t + t ** 2);
	}
	calculateEffectiveRadius(e) {
		let t = this.radius.x, n = 1 - this.radius.z ** 2 / t ** 2, r = e * x.DEG2RAD, i = Math.sin(r) ** 2;
		return t / Math.sqrt(1 - n * i);
	}
	getPositionElevation(e) {
		this.getPositionToSurfacePoint(e, T);
		let t = Le.subVectors(e, T);
		return Math.sign(t.dot(e)) * t.length();
	}
	closestPointToRayEstimate(e, t) {
		return this.intersectRay(e, t) ? t : (E.makeScale(...this.radius).invert(), Ue.copy(e).applyMatrix4(E), T.set(0, 0, 0), Ue.closestPointToPoint(T, t).normalize(), E.makeScale(...this.radius), t.applyMatrix4(E));
	}
	copy(e) {
		return this.radius.copy(e.radius), this;
	}
	clone() {
		return new this.constructor().copy(this);
	}
}, Xe = new Ye(e, e, o);
Xe.name = "WGS84 Earth";
//#endregion
//#region src/three/renderer/loaders/I3DMLoader.js
var Ze = /* @__PURE__ */ new w(), Qe = /* @__PURE__ */ new w(), $e = /* @__PURE__ */ new w(), et = /* @__PURE__ */ new w(), tt = /* @__PURE__ */ new le(), nt = /* @__PURE__ */ new w(), rt = /* @__PURE__ */ new S(), it = /* @__PURE__ */ new S(), at = /* @__PURE__ */ new w(), ot = /* @__PURE__ */ new S(), st = /* @__PURE__ */ new le(), ct = {};
function lt(e, t, n, r) {
	if (e = e / n * 2 - 1, t = t / n * 2 - 1, r.x = e, r.y = t, r.z = 1 - Math.abs(e) - Math.abs(t), r.z < 0) {
		let e = r.x;
		r.x = (1 - Math.abs(r.y)) * (e >= 0 ? 1 : -1), r.y = (1 - Math.abs(e)) * (r.y >= 0 ? 1 : -1);
	}
	return r.normalize(), r;
}
var ut = class extends c {
	constructor(e = h) {
		super(), this.manager = e, this.adjustmentTransform = new S(), this.ellipsoid = Xe.clone();
	}
	resolveExternalURL(e) {
		return this.manager.resolveURL(super.resolveExternalURL(e));
	}
	parse(e) {
		return super.parse(e).then((e) => {
			let { featureTable: t, batchTable: n } = e, r = e.glbBytes.slice().buffer;
			return new Promise((i, a) => {
				let o = this.fetchOptions, s = this.manager, c = s.getHandler("path.gltf") || new ge(s);
				o.credentials === "include" && o.mode === "cors" && c.setCrossOrigin("use-credentials"), "credentials" in o && c.setWithCredentials(o.credentials === "include"), o.headers && c.setRequestHeader(o.headers);
				let l = e.gltfWorkingPath ?? this.workingPath;
				/[\\/]$/.test(l) || (l += "/");
				let u = this.adjustmentTransform;
				c.parse(r, l, (e) => {
					let r = t.getData("INSTANCES_LENGTH"), a = t.getData("POSITION", r, "FLOAT", "VEC3"), o = t.getData("POSITION_QUANTIZED", r, "UNSIGNED_SHORT", "VEC3"), s = t.getData("QUANTIZED_VOLUME_OFFSET", 1, "FLOAT", "VEC3"), c = t.getData("QUANTIZED_VOLUME_SCALE", 1, "FLOAT", "VEC3"), l = t.getData("NORMAL_UP", r, "FLOAT", "VEC3"), d = t.getData("NORMAL_RIGHT", r, "FLOAT", "VEC3"), f = t.getData("NORMAL_UP_OCT32P", r, "UNSIGNED_SHORT", "VEC2"), p = t.getData("NORMAL_RIGHT_OCT32P", r, "UNSIGNED_SHORT", "VEC2"), m = t.getData("SCALE_NON_UNIFORM", r, "FLOAT", "VEC3"), h = t.getData("SCALE", r, "FLOAT", "SCALAR"), g = t.getData("RTC_CENTER", 1, "FLOAT", "VEC3"), _ = t.getData("EAST_NORTH_UP");
					if (!a && o) {
						a = new Float32Array(r * 3);
						for (let e = 0; e < r; e++) a[e * 3 + 0] = s[0] + o[e * 3 + 0] / 65535 * c[0], a[e * 3 + 1] = s[1] + o[e * 3 + 1] / 65535 * c[1], a[e * 3 + 2] = s[2] + o[e * 3 + 2] / 65535 * c[2];
					}
					let v = new w();
					for (let e = 0; e < r; e++) v.x += a[e * 3 + 0] / r, v.y += a[e * 3 + 1] / r, v.z += a[e * 3 + 2] / r;
					let y = [], b = [];
					e.scene.updateMatrixWorld(), e.scene.traverse((e) => {
						if (e.isMesh) {
							b.push(e);
							let { geometry: t, material: n } = e, i = new ee(t, n, r);
							i.position.copy(v), g && (i.position.x += g[0], i.position.y += g[1], i.position.z += g[2]), y.push(i);
						}
					});
					for (let e = 0; e < r; e++) {
						et.set(a[e * 3 + 0] - v.x, a[e * 3 + 1] - v.y, a[e * 3 + 2] - v.z), tt.identity(), l && d ? (Qe.set(l[e * 3 + 0], l[e * 3 + 1], l[e * 3 + 2]), $e.set(d[e * 3 + 0], d[e * 3 + 1], d[e * 3 + 2]), Ze.crossVectors($e, Qe).normalize(), rt.makeBasis($e, Qe, Ze), tt.setFromRotationMatrix(rt)) : f && p && (lt(f[e * 2 + 0], f[e * 2 + 1], 65535, Qe), lt(p[e * 2 + 0], p[e * 2 + 1], 65535, $e), Ze.crossVectors($e, Qe).normalize(), rt.makeBasis($e, Qe, Ze), tt.setFromRotationMatrix(rt)), nt.set(1, 1, 1), m && nt.set(m[e * 3 + 0], m[e * 3 + 1], m[e * 3 + 2]), h && nt.multiplyScalar(h[e]);
						for (let t = 0, n = y.length; t < n; t++) {
							let n = y[t];
							st.copy(tt), _ && (n.updateMatrixWorld(), at.copy(et).applyMatrix4(n.matrixWorld), this.ellipsoid.getPositionToCartographic(at, ct), this.ellipsoid.getEastNorthUpFrame(ct.lat, ct.lon, ot), st.setFromRotationMatrix(ot)), rt.compose(et, st, nt).multiply(u);
							let r = b[t];
							it.multiplyMatrices(rt, r.matrixWorld), n.setMatrixAt(e, it);
						}
					}
					e.scene.clear(), e.scene.add(...y), e.batchTable = n, e.featureTable = t, e.scene.batchTable = n, e.scene.featureTable = t, i(e);
				}, a);
			});
		});
	}
}, dt = class extends l {
	constructor(e = h) {
		super(), this.manager = e, this.adjustmentTransform = new S(), this.ellipsoid = Xe.clone();
	}
	parse(e) {
		let t = super.parse(e), { manager: n, ellipsoid: r, adjustmentTransform: i } = this, a = [];
		for (let e in t.tiles) {
			let { type: o, buffer: s } = t.tiles[e];
			switch (o) {
				case "b3dm": {
					let e = s.slice(), t = new ve(n);
					t.workingPath = this.workingPath, t.fetchOptions = this.fetchOptions, t.adjustmentTransform.copy(i);
					let r = t.parse(e.buffer);
					a.push(r);
					break;
				}
				case "pnts": {
					let e = s.slice(), t = new Ce(n);
					t.workingPath = this.workingPath, t.fetchOptions = this.fetchOptions;
					let r = t.parse(e.buffer);
					a.push(r);
					break;
				}
				case "i3dm": {
					let e = s.slice(), t = new ut(n);
					t.workingPath = this.workingPath, t.fetchOptions = this.fetchOptions, t.ellipsoid.copy(r), t.adjustmentTransform.copy(i);
					let o = t.parse(e.buffer);
					a.push(o);
					break;
				}
			}
		}
		return Promise.all(a).then((e) => {
			let t = new y();
			return e.forEach((e) => {
				t.add(e.scene);
			}), {
				tiles: e,
				scene: t
			};
		});
	}
}, ft = /* @__PURE__ */ new S(), pt = class extends y {
	constructor(e) {
		super(), this.isTilesGroup = !0, this.name = "TilesRenderer.TilesGroup", this.tilesRenderer = e, this.matrixWorldInverse = new S();
	}
	raycast(e, t) {
		return this.tilesRenderer.raycast(e, t), !1;
	}
	updateMatrixWorld(e) {
		if (this.matrixAutoUpdate && this.updateMatrix(), this.matrixWorldNeedsUpdate || e) {
			this.parent === null ? ft.copy(this.matrix) : ft.multiplyMatrices(this.parent.matrixWorld, this.matrix), this.matrixWorldNeedsUpdate = !1;
			let e = ft.elements, t = this.matrixWorld.elements, n = !1;
			for (let r = 0; r < 16; r++) {
				let i = e[r], a = t[r];
				if (Math.abs(i - a) > 2 ** -52) {
					n = !0;
					break;
				}
			}
			if (n) {
				this.matrixWorld.copy(ft), this.matrixWorldInverse.copy(ft).invert();
				let e = this.children;
				for (let t = 0, n = e.length; t < n; t++) e[t].updateMatrixWorld();
				let { tilesRenderer: t } = this, { activeTiles: n, visibleTiles: r } = t;
				n.forEach((e) => {
					r.has(e) || e.engineData.scene.updateMatrixWorld(!0);
				});
			}
		}
	}
	updateWorldMatrix(e, t) {
		this.parent && e && this.parent.updateWorldMatrix(e, !1), this.updateMatrixWorld(!0);
	}
}, mt = /* @__PURE__ */ new ue();
function ht(e, t, n, r) {
	let { scene: i } = e.engineData;
	n.invokeOnePlugin((n) => n.raycastTile && n.raycastTile(e, i, t, r)) || t.intersectObject(i, !0, r);
}
function gt(e) {
	return "traversal" in e;
}
function _t(e, t, n, r, i = null) {
	if (!gt(t)) return;
	let { group: a, activeTiles: o } = e, { boundingVolume: s } = t.engineData;
	if (i === null && (i = mt, i.copy(n.ray).applyMatrix4(a.matrixWorldInverse)), !t.traversal.used || !s.intersectsRay(i)) return;
	o.has(t) && ht(t, n, e, r);
	let c = t.children;
	for (let t = 0, a = c.length; t < a; t++) _t(e, c[t], n, r, i);
}
//#endregion
//#region src/three/renderer/math/OBB.js
var vt = /* @__PURE__ */ new w(), yt = /* @__PURE__ */ new w(), k = /* @__PURE__ */ new w(), bt = /* @__PURE__ */ new ue(), xt = class {
	constructor(e = new u(), t = new S()) {
		this.box = e.clone(), this.transform = t.clone(), this.inverseTransform = new S(), this.points = Array(8).fill().map(() => new w()), this.planes = [
			,
			,
			,
			,
			,
			,
		].fill().map(() => new ae());
	}
	copy(e) {
		return this.box.copy(e.box), this.transform.copy(e.transform), this.update(), this;
	}
	clone() {
		return new this.constructor().copy(this);
	}
	clampPoint(e, t) {
		return t.copy(e).applyMatrix4(this.inverseTransform).clamp(this.box.min, this.box.max).applyMatrix4(this.transform);
	}
	distanceToPoint(e) {
		return this.clampPoint(e, k).distanceTo(e);
	}
	containsPoint(e) {
		return k.copy(e).applyMatrix4(this.inverseTransform), this.box.containsPoint(k);
	}
	intersectsRay(e) {
		return bt.copy(e).applyMatrix4(this.inverseTransform), bt.intersectsBox(this.box);
	}
	intersectRay(e, t) {
		return bt.copy(e).applyMatrix4(this.inverseTransform), bt.intersectBox(this.box, t) ? (t.applyMatrix4(this.transform), t) : null;
	}
	update() {
		let { points: e, inverseTransform: t, transform: n, box: r } = this;
		t.copy(n).invert();
		let { min: i, max: a } = r, o = 0;
		for (let t = -1; t <= 1; t += 2) for (let r = -1; r <= 1; r += 2) for (let s = -1; s <= 1; s += 2) e[o].set(t < 0 ? i.x : a.x, r < 0 ? i.y : a.y, s < 0 ? i.z : a.z).applyMatrix4(n), o++;
		this.updatePlanes();
	}
	updatePlanes() {
		vt.copy(this.box.min).applyMatrix4(this.transform), yt.copy(this.box.max).applyMatrix4(this.transform), k.set(0, 0, 1).transformDirection(this.transform), this.planes[0].setFromNormalAndCoplanarPoint(k, vt), this.planes[1].setFromNormalAndCoplanarPoint(k, yt).negate(), k.set(0, 1, 0).transformDirection(this.transform), this.planes[2].setFromNormalAndCoplanarPoint(k, vt), this.planes[3].setFromNormalAndCoplanarPoint(k, yt).negate(), k.set(1, 0, 0).transformDirection(this.transform), this.planes[4].setFromNormalAndCoplanarPoint(k, vt), this.planes[5].setFromNormalAndCoplanarPoint(k, yt).negate();
	}
	intersectsSphere(e) {
		return this.clampPoint(e.center, k), k.distanceToSquared(e.center) <= e.radius * e.radius;
	}
	intersectsFrustum(e) {
		return this._intersectsPlaneShape(e.planes, e.points);
	}
	intersectsOBB(e) {
		return this._intersectsPlaneShape(e.planes, e.points);
	}
	_intersectsPlaneShape(e, t) {
		let n = this.points, r = this.planes;
		for (let t = 0; t < 6; t++) {
			let r = e[t], i = -Infinity;
			for (let e = 0; e < 8; e++) {
				let t = n[e], a = r.distanceToPoint(t);
				i = i < a ? a : i;
			}
			if (i < 0) return !1;
		}
		for (let e = 0; e < 6; e++) {
			let n = r[e], i = -Infinity;
			for (let e = 0; e < 8; e++) {
				let r = t[e], a = n.distanceToPoint(r);
				i = i < a ? a : i;
			}
			if (i < 0) return !1;
		}
		return !0;
	}
}, St = Math.PI, Ct = St / 2, wt = /* @__PURE__*/ new w(), Tt = /* @__PURE__*/ new w(), A = /* @__PURE__*/ new w(), j = /* @__PURE__*/ new w(), M = /* @__PURE__*/ new S(), Et = /* @__PURE__*/ new u(), Dt = /* @__PURE__*/ new S();
function Ot(e, t) {
	t.radius = Math.max(t.radius, e.distanceToSquared(t.center));
}
function kt(e) {
	return e.x !== e.y;
}
var At = class extends Ye {
	constructor(e = 1, t = 1, n = 1, r = -Ct, i = Ct, a = 0, o = 2 * St, s = 0, c = 0) {
		super(e, t, n), this.latStart = r, this.latEnd = i, this.lonStart = a, this.lonEnd = o, this.heightStart = s, this.heightEnd = c;
	}
	getBoundingBox(e, t) {
		kt(this.radius) && console.warn("EllipsoidRegion: Triaxial ellipsoids are not supported.");
		let { latStart: n, latEnd: r, lonStart: i, lonEnd: a, heightStart: o, heightEnd: s } = this, c = (n + r) * .5, l = (i + a) * .5, u = n > 0, d = r < 0, f;
		f = u ? n : d ? r : 0;
		let { min: p, max: m } = e;
		p.setScalar(Infinity), m.setScalar(-Infinity), a - i <= St ? (this.getCartographicToNormal(c, l, A), Tt.set(0, 0, 1), wt.crossVectors(Tt, A).normalize(), Tt.crossVectors(A, wt).normalize(), t.makeBasis(wt, Tt, A), M.copy(t).invert(), this.getCartographicToPosition(f, i, s, j).applyMatrix4(M), m.x = Math.abs(j.x), p.x = -m.x, this.getCartographicToPosition(r, i, s, j).applyMatrix4(M), m.y = j.y, this.getCartographicToPosition(r, l, s, j).applyMatrix4(M), m.y = Math.max(j.y, m.y), this.getCartographicToPosition(n, i, s, j).applyMatrix4(M), p.y = j.y, this.getCartographicToPosition(n, l, s, j).applyMatrix4(M), p.y = Math.min(j.y, p.y), this.getCartographicToPosition(c, l, s, j).applyMatrix4(M), m.z = j.z, this.getCartographicToPosition(n, i, o, j).applyMatrix4(M), p.z = j.z, this.getCartographicToPosition(r, i, o, j).applyMatrix4(M), p.z = Math.min(j.z, p.z)) : (this.getCartographicToPosition(f, l, s, A), A.z = 0, A.length() < 1e-10 ? A.set(1, 0, 0) : A.normalize(), Tt.set(0, 0, 1), wt.crossVectors(A, Tt).normalize(), t.makeBasis(wt, Tt, A), M.copy(t).invert(), this.getCartographicToPosition(f, l + Ct, s, j).applyMatrix4(M), m.x = Math.abs(j.x), p.x = -m.x, this.getCartographicToPosition(r, 0, d ? o : s, j).applyMatrix4(M), m.y = j.y, this.getCartographicToPosition(n, 0, u ? o : s, j).applyMatrix4(M), p.y = j.y, this.getCartographicToPosition(f, l, s, j).applyMatrix4(M), m.z = j.z, this.getCartographicToPosition(f, a, s, j).applyMatrix4(M), p.z = j.z), e.getCenter(j), e.min.sub(j).multiplyScalar(1.0000000000001), e.max.sub(j).multiplyScalar(1.0000000000001), j.applyMatrix4(t), t.setPosition(j);
	}
	getBoundingSphere(e) {
		kt(this.radius) && console.warn("EllipsoidRegion: Triaxial ellipsoids are not supported."), this.getBoundingBox(Et, Dt), e.center.setFromMatrixPosition(Dt), e.radius = 0;
		let { latStart: t, latEnd: n, lonStart: r, lonEnd: i, heightStart: a, heightEnd: o } = this, s = (t + n) * .5, c = (r + i) * .5, l = t > 0, u = n < 0, d;
		d = l ? t : u ? n : 0, this.getCartographicToPosition(d, r, o, j), Ot(j, e), this.getCartographicToPosition(n, r, o, j), Ot(j, e), this.getCartographicToPosition(n, c, o, j), Ot(j, e), this.getCartographicToPosition(t, r, o, j), Ot(j, e), this.getCartographicToPosition(t, c, o, j), Ot(j, e), this.getCartographicToPosition(s, c, o, j), Ot(j, e), this.getCartographicToPosition(t, r, a, j), Ot(j, e), i - r > St && (this.getCartographicToPosition(d, c + St, o, j), Ot(j, e)), e.radius = Math.sqrt(e.radius) * 1.0000000000001;
	}
}, N = /* @__PURE__ */ new w(), P = /* @__PURE__ */ new w(), F = /* @__PURE__ */ new w(), jt = /* @__PURE__ */ new w(), Mt = /* @__PURE__ */ new w(), Nt = class {
	constructor() {
		this.sphere = null, this.obb = null, this.region = null, this.regionObb = null;
	}
	intersectsRay(e) {
		let t = this.sphere, n = this.obb || this.regionObb;
		return !(t && !e.intersectsSphere(t) || n && !n.intersectsRay(e));
	}
	intersectRay(e, t = null) {
		let n = this.sphere, r = this.obb || this.regionObb, i = -Infinity, a = -Infinity;
		n && e.intersectSphere(n, jt) && (i = n.containsPoint(e.origin) ? 0 : e.origin.distanceToSquared(jt)), r && r.intersectRay(e, Mt) && (a = r.containsPoint(e.origin) ? 0 : e.origin.distanceToSquared(Mt));
		let o = Math.max(i, a);
		return o === -Infinity ? null : (e.at(Math.sqrt(o), t), t);
	}
	distanceToPoint(e) {
		let t = this.sphere, n = this.obb || this.regionObb, r = -Infinity, i = -Infinity;
		return t && (r = Math.max(t.distanceToPoint(e), 0)), n && (i = n.distanceToPoint(e)), r > i ? r : i;
	}
	intersectsFrustum(e) {
		let t = this.obb || this.regionObb, n = this.sphere;
		return n && !e.intersectsSphere(n) || t && !t.intersectsFrustum(e) ? !1 : !!(n || t);
	}
	intersectsSphere(e) {
		let t = this.obb || this.regionObb, n = this.sphere;
		return n && !n.intersectsSphere(e) || t && !t.intersectsSphere(e) ? !1 : !!(n || t);
	}
	intersectsOBB(e) {
		let t = this.obb || this.regionObb, n = this.sphere;
		return n && !e.intersectsSphere(n) || t && !t.intersectsOBB(e) ? !1 : !!(n || t);
	}
	getOBB(e, t) {
		let n = this.obb || this.regionObb;
		n ? (e.copy(n.box), t.copy(n.transform)) : (this.getAABB(e), t.identity());
	}
	getAABB(e) {
		if (this.sphere) this.sphere.getBoundingBox(e);
		else {
			let t = this.obb || this.regionObb;
			e.copy(t.box).applyMatrix4(t.transform);
		}
	}
	getSphere(e) {
		if (this.sphere) e.copy(this.sphere);
		else if (this.region) this.region.getBoundingSphere(e);
		else {
			let t = this.obb || this.regionObb;
			t.box.getBoundingSphere(e), e.applyMatrix4(t.transform);
		}
	}
	setObbData(e, t) {
		let n = new xt();
		N.set(e[3], e[4], e[5]), P.set(e[6], e[7], e[8]), F.set(e[9], e[10], e[11]);
		let r = N.length(), i = P.length(), a = F.length();
		N.normalize(), P.normalize(), F.normalize(), r === 0 && N.crossVectors(P, F), i === 0 && P.crossVectors(N, F), a === 0 && F.crossVectors(N, P), n.transform.set(N.x, P.x, F.x, e[0], N.y, P.y, F.y, e[1], N.z, P.z, F.z, e[2], 0, 0, 0, 1).premultiply(t), n.box.min.set(-r, -i, -a), n.box.max.set(r, i, a), n.update(), this.obb = n;
	}
	setSphereData(e, t, n, r, i) {
		let a = new pe();
		a.center.set(e, t, n), a.radius = r, a.applyMatrix4(i), this.sphere = a;
	}
	setRegionData(e, t, n, r, i, a, o) {
		let s = new At(...e.radius, n, i, t, r, a, o), c = new xt();
		s.getBoundingBox(c.box, c.transform), c.update(), this.region = s, this.regionObb = c;
	}
}, Pt = /* @__PURE__ */ new te();
function Ft(e, t, n, r) {
	let i = Pt.set(e.normal.x, e.normal.y, e.normal.z, t.normal.x, t.normal.y, t.normal.z, n.normal.x, n.normal.y, n.normal.z);
	return r.set(-e.constant, -t.constant, -n.constant), r.applyMatrix3(i.invert()), r;
}
var It = class extends v {
	constructor() {
		super(), this.points = Array(8).fill().map(() => new w());
	}
	setFromProjectionMatrix(...e) {
		return super.setFromProjectionMatrix(...e), this.calculateFrustumPoints(), this;
	}
	calculateFrustumPoints() {
		let { planes: e, points: t } = this;
		[
			[
				e[0],
				e[3],
				e[4]
			],
			[
				e[1],
				e[3],
				e[4]
			],
			[
				e[0],
				e[2],
				e[4]
			],
			[
				e[1],
				e[2],
				e[4]
			],
			[
				e[0],
				e[3],
				e[5]
			],
			[
				e[1],
				e[3],
				e[5]
			],
			[
				e[0],
				e[2],
				e[5]
			],
			[
				e[1],
				e[2],
				e[5]
			]
		].forEach((e, n) => {
			Ft(e[0], e[1], e[2], t[n]);
		});
	}
}, Lt = /* @__PURE__ */ t({
	estimateBytesUsed: () => Vt,
	getTextureByteLength: () => Bt
}), Rt = 0;
function zt(e, t, n, r) {
	try {
		return he.getByteLength(e, t, n, r);
	} catch {
		return Rt;
	}
}
function Bt(e) {
	if (!e) return 0;
	if (e.isExternalTexture) return e.userData?.byteLength ?? Rt;
	let { format: t, type: n, image: r, mipmaps: i } = e;
	if (e.isCompressedTexture && Array.isArray(i) && i.length > 0) {
		let e = 0;
		for (let r of i) r?.data?.byteLength ? e += r.data.byteLength : e += zt(r.width, r.height, t, n);
		return e;
	}
	if (!r) return Rt;
	let a = zt(r.width, r.height, t, n);
	return a *= e.generateMipmaps ? 4 / 3 : 1, a;
}
function Vt(e) {
	let t = /* @__PURE__ */ new Set(), n = 0;
	return e.traverse((e) => {
		if (e.geometry && !t.has(e.geometry) && (n += _e(e.geometry), t.add(e.geometry)), e.material) {
			let r = e.material;
			for (let e in r) {
				let i = r[e];
				i && i.isTexture && !t.has(i) && (n += Bt(i), t.add(i));
			}
		}
	}), n;
}
//#endregion
//#region src/three/renderer/tiles/TilesRenderer.js
var Ht = Symbol("INITIAL_FRUSTUM_CULLED"), Ut = /* @__PURE__ */ new S(), Wt = /* @__PURE__ */ new w(), Gt = /* @__PURE__ */ new C(), Kt = /* @__PURE__ */ new w(1, 0, 0), qt = /* @__PURE__ */ new w(0, 1, 0), Jt = () => null;
function Yt(e, t) {
	e.traverse((e) => {
		e.frustumCulled = e[Ht] && t;
	});
}
var Xt = class extends n {
	get autoDisableRendererCulling() {
		return this._autoDisableRendererCulling;
	}
	set autoDisableRendererCulling(e) {
		this._autoDisableRendererCulling !== e && (super._autoDisableRendererCulling = e, this.forEachLoadedModel((t) => {
			Yt(t, !e);
		}));
	}
	constructor(...e) {
		super(...e), this.accelerateRaycast = !0, this.group = new pt(this), this.ellipsoid = Xe.clone(), this.cameras = [], this.cameraMap = /* @__PURE__ */ new Map(), this.cameraInfo = [], this._upRotationMatrix = new S(), this._bytesUsed = /* @__PURE__ */ new WeakMap(), this._autoDisableRendererCulling = !0, this.manager = new b(), this._listeners = {};
	}
	addEventListener(e, t) {
		_.prototype.addEventListener.call(this, e, t);
	}
	hasEventListener(e, t) {
		return _.prototype.hasEventListener.call(this, e, t);
	}
	removeEventListener(e, t) {
		_.prototype.removeEventListener.call(this, e, t);
	}
	dispatchEvent(e) {
		_.prototype.dispatchEvent.call(this, e);
	}
	getBoundingBox(e) {
		if (!this.root) return !1;
		let t = this.root.engineData.boundingVolume;
		return t ? (t.getAABB(e), !0) : !1;
	}
	getOrientedBoundingBox(e, t) {
		if (!this.root) return !1;
		let n = this.root.engineData.boundingVolume;
		return n ? (n.getOBB(e, t), !0) : !1;
	}
	getBoundingSphere(e) {
		if (!this.root) return !1;
		let t = this.root.engineData.boundingVolume;
		return t ? (t.getSphere(e), !0) : !1;
	}
	forEachLoadedModel(e) {
		this.traverse((t) => {
			let n = t.engineData && t.engineData.scene;
			n && e(n, t);
		}, null, !1);
	}
	raycast(e, t) {
		if (this.root) if (this.accelerateRaycast) _t(this, this.root, e, t);
		else {
			let n = e.firstHitOnly ? [] : t;
			for (let t of this.activeTiles) {
				let { scene: r } = t.engineData;
				this.invokeOnePlugin((i) => i.raycastTile && i.raycastTile(t, r, e, n)) || e.intersectObject(r, !0, n);
			}
			e.firstHitOnly && n.length > 0 && (n.sort((e, t) => e.distance - t.distance), t.push(n[0]));
		}
	}
	hasCamera(e) {
		return this.cameraMap.has(e);
	}
	setCamera(e) {
		let t = this.cameras, n = this.cameraMap;
		return n.has(e) ? !1 : (n.set(e, new C()), t.push(e), this.dispatchEvent({
			type: "add-camera",
			camera: e
		}), !0);
	}
	setResolution(e, t, n) {
		let r = this.cameraMap;
		if (!r.has(e)) return !1;
		let i = t.isVector2 ? t.x : t, a = t.isVector2 ? t.y : n, o = r.get(e);
		return (o.width !== i || o.height !== a) && (o.set(i, a), this.dispatchEvent({ type: "camera-resolution-change" })), !0;
	}
	getResolution(e, t) {
		let n = this.cameraMap.get(e);
		return n ? t.copy(n) : null;
	}
	setResolutionFromRenderer(e, t) {
		return t.getSize(Gt), this.setResolution(e, Gt.x, Gt.y);
	}
	deleteCamera(e) {
		let t = this.cameras, n = this.cameraMap;
		if (n.has(e)) {
			let r = t.indexOf(e);
			return t.splice(r, 1), n.delete(e), this.dispatchEvent({
				type: "delete-camera",
				camera: e
			}), !0;
		}
		return !1;
	}
	loadRootTileset(...e) {
		return super.loadRootTileset(...e).then((e) => {
			let { asset: t, extensions: n = {} } = e;
			switch ((t && t.gltfUpAxis || "y").toLowerCase()) {
				case "x":
					this._upRotationMatrix.makeRotationAxis(qt, -Math.PI / 2);
					break;
				case "y":
					this._upRotationMatrix.makeRotationAxis(Kt, Math.PI / 2);
					break;
			}
			if ("3DTILES_ellipsoid" in n) {
				let e = n["3DTILES_ellipsoid"], { ellipsoid: t } = this;
				t.name = e.body, e.radii ? t.radius.set(...e.radii) : t.radius.set(1, 1, 1);
			}
			return e;
		});
	}
	prepareForTraversal() {
		let e = this.group, t = this.cameras, n = this.cameraMap, r = this.cameraInfo;
		for (; r.length > t.length;) r.pop();
		for (; r.length < t.length;) r.push({
			frustum: new It(),
			isOrthographic: !1,
			sseDenominator: -1,
			position: new w(),
			invScale: -1,
			pixelSize: 0
		});
		Wt.setFromMatrixScale(e.matrixWorldInverse), Math.abs(Math.max(Wt.x - Wt.y, Wt.x - Wt.z)) > 1e-6 && console.warn("ThreeTilesRenderer : Non uniform scale used for tile which may cause issues when calculating screen space error.");
		for (let i = 0, a = r.length; i < a; i++) {
			let a = t[i], o = r[i], s = o.frustum, c = o.position, l = n.get(a);
			(l.width === 0 || l.height === 0) && console.warn("TilesRenderer: resolution for camera error calculation is not set.");
			let u = a.projectionMatrix.elements;
			if (o.isOrthographic = u[15] === 1, o.isOrthographic) {
				let e = 2 / u[0], t = 2 / u[5];
				o.pixelSize = Math.max(t / l.height, e / l.width);
			} else o.sseDenominator = 2 / u[5] / l.height;
			Ut.copy(e.matrixWorld), Ut.premultiply(a.matrixWorldInverse), Ut.premultiply(a.projectionMatrix), s.setFromProjectionMatrix(Ut, a.coordinateSystem, a.reversedDepth), c.set(0, 0, 0), c.applyMatrix4(a.matrixWorld), c.applyMatrix4(e.matrixWorldInverse);
		}
	}
	update() {
		if (super.update(), this.cameras.length === 0 && this.root) {
			let e = !1;
			this.invokeAllPlugins((t) => e ||= !!(t !== this && t.calculateTileViewError)), e === !1 && console.warn("TilesRenderer: no cameras defined. Cannot update 3d tiles.");
		}
	}
	preprocessNode(e, t, n = null) {
		super.preprocessNode(e, t, n);
		let r = new S();
		if (e.transform) {
			let t = e.transform;
			for (let e = 0; e < 16; e++) r.elements[e] = t[e];
		}
		n && r.premultiply(n.engineData.transform);
		let i = new S().copy(r).invert(), a = new Nt();
		"sphere" in e.boundingVolume && a.setSphereData(...e.boundingVolume.sphere, r), "box" in e.boundingVolume && a.setObbData(e.boundingVolume.box, r), "region" in e.boundingVolume && a.setRegionData(this.ellipsoid, ...e.boundingVolume.region), e.engineData.transform = r, e.engineData.transformInverse = i, e.engineData.boundingVolume = a, e.engineData.geometry = null, e.engineData.materials = null, e.engineData.textures = null, e.toJSON = Jt;
	}
	async parseTile(e, t, n, a, o) {
		let s = t.engineData, c = r(a), l = this.fetchOptions, u = this.manager, d = null, f = s.transform, p = this._upRotationMatrix, m = (i(e) || n).toLowerCase();
		switch (m) {
			case "b3dm": {
				let t = new ve(u);
				t.workingPath = c, t.fetchOptions = l, t.adjustmentTransform.copy(p), d = t.parse(e);
				break;
			}
			case "pnts": {
				let t = new Ce(u);
				t.workingPath = c, t.fetchOptions = l, d = t.parse(e);
				break;
			}
			case "i3dm": {
				let t = new ut(u);
				t.workingPath = c, t.fetchOptions = l, t.adjustmentTransform.copy(p), t.ellipsoid.copy(this.ellipsoid), d = t.parse(e);
				break;
			}
			case "cmpt": {
				let t = new dt(u);
				t.workingPath = c, t.fetchOptions = l, t.adjustmentTransform.copy(p), t.ellipsoid.copy(this.ellipsoid), d = t.parse(e).then((e) => e.scene);
				break;
			}
			case "gltf":
			case "glb": {
				let t = u.getHandler("path.gltf") || u.getHandler("path.glb") || new ge(u);
				t.setWithCredentials(l.credentials === "include"), t.setRequestHeader(l.headers || {}), l.credentials === "include" && l.mode === "cors" && t.setCrossOrigin("use-credentials");
				let n = t.resourcePath || t.path || c;
				!/[\\/]$/.test(n) && n.length && (n += "/"), d = t.parseAsync(e, n).then((e) => {
					e.scene = e.scene || new y();
					let { scene: t } = e;
					return t.updateMatrix(), t.matrix.multiply(p).decompose(t.position, t.quaternion, t.scale), e;
				});
				break;
			}
			default:
				d = this.invokeOnePlugin((r) => r.parseToMesh && r.parseToMesh(e, t, n, a, o));
				break;
		}
		let h = await d;
		if (h === null) throw Error(`TilesRenderer: Content type "${m}" not supported.`);
		let g, _;
		h.isObject3D ? (g = h, _ = null) : (g = h.scene, _ = h), g.updateMatrix(), g.matrix.premultiply(f), g.matrix.decompose(g.position, g.quaternion, g.scale), await this.invokeAllPlugins((e) => e.processTileModel && e.processTileModel(g, t)), g.traverse((e) => {
			e[Ht] = e.frustumCulled, e.userData.tile = t;
		}), Yt(g, !this.autoDisableRendererCulling);
		let v = [], ee = [], b = [];
		if (g.traverse((e) => {
			if (e.geometry && ee.push(e.geometry), e.material) {
				let t = e.material;
				v.push(e.material);
				for (let e in t) {
					let n = t[e];
					n && n.isTexture && b.push(n);
				}
			}
		}), o.aborted) {
			for (let e = 0, t = b.length; e < t; e++) {
				let t = b[e];
				t.image instanceof ImageBitmap && t.image.close(), t.dispose();
			}
			return;
		}
		s.materials = v, s.geometry = ee, s.textures = b, s.scene = g, s.metadata = _;
	}
	disposeTile(e) {
		super.disposeTile(e);
		let t = e.engineData;
		if (t.scene) {
			let e = t.materials, n = t.geometry, r = t.textures, i = t.scene.parent;
			t.scene.traverse((e) => {
				e.userData.meshFeatures && e.userData.meshFeatures.dispose(), e.userData.structuralMetadata && e.userData.structuralMetadata.dispose();
			});
			for (let e = 0, t = n.length; e < t; e++) n[e].dispose();
			for (let t = 0, n = e.length; t < n; t++) e[t].dispose();
			for (let e = 0, t = r.length; e < t; e++) {
				let t = r[e];
				t.image instanceof ImageBitmap && t.image.close(), t.dispose();
			}
			i && i.remove(t.scene), t.scene = null, t.materials = null, t.textures = null, t.geometry = null, t.metadata = null;
		}
	}
	setTileActive(e, t) {
		super.setTileActive(e, t);
		let n = e.engineData.scene;
		n && (t ? (n.parent = this.group, n.updateMatrixWorld(!0)) : n.parent = null);
	}
	setTileVisible(e, t) {
		let n = e.engineData.scene, { activeTiles: r, group: i } = this;
		n && (t ? i.add(n) : (i.remove(n), r.has(e) && (n.parent = i))), super.setTileVisible(e, t);
	}
	calculateBytesUsed(e, t) {
		let n = this._bytesUsed;
		return !n.has(e) && t && n.set(e, Vt(t)), n.get(e) ?? null;
	}
	calculateTileViewError(e, t) {
		let n = e.engineData, r = this.cameras, i = this.cameraInfo, a = n.boundingVolume, o = !1, s = 0, c = Infinity, l = 0, u = Infinity;
		for (let t = 0, n = r.length; t < n; t++) {
			let n = i[t], r, d;
			if (n.isOrthographic) {
				let t = n.pixelSize;
				r = e.geometricError / t, d = Infinity;
			} else {
				let t = n.sseDenominator;
				d = a.distanceToPoint(n.position), r = d === 0 ? Infinity : e.geometricError / (d * t);
			}
			let f = i[t].frustum;
			a.intersectsFrustum(f) && (o = !0, s = Math.max(s, r), c = Math.min(c, d)), l = Math.max(l, r), u = Math.min(u, d);
		}
		o ? (t.inView = !0, t.error = s, t.distanceFromCamera = c) : (t.inView = !1, t.error = l, t.distanceFromCamera = u);
	}
	dispose() {
		super.dispose(), this.group.removeFromParent();
	}
}, Zt = class extends ne {
	constructor() {
		super(new oe(0, 0), new Qt()), this.renderOrder = Infinity;
	}
	onBeforeRender(e) {
		let t = this.material.uniforms;
		e.getSize(t.resolution.value);
	}
	updateMatrixWorld() {
		this.matrixWorld.makeTranslation(this.position);
	}
	dispose() {
		this.geometry.dispose(), this.material.dispose();
	}
}, Qt = class extends fe {
	constructor() {
		super({
			depthWrite: !1,
			depthTest: !1,
			transparent: !0,
			uniforms: {
				resolution: { value: new C() },
				size: { value: 15 },
				thickness: { value: 2 },
				opacity: { value: 1 }
			},
			vertexShader: "\n\n				uniform float size;\n				uniform float thickness;\n				uniform vec2 resolution;\n				varying vec2 vUv;\n\n				void main() {\n\n					vUv = uv;\n\n					float aspect = resolution.x / resolution.y;\n					vec2 offset = uv * 2.0 - vec2( 1.0 );\n					offset.y *= aspect;\n\n					vec4 screenPoint = projectionMatrix * modelViewMatrix * vec4( position, 1.0 );\n					screenPoint.xy += offset * ( size + thickness ) * screenPoint.w / resolution.x;\n\n					gl_Position = screenPoint;\n\n				}\n			",
			fragmentShader: "\n\n				uniform float size;\n				uniform float thickness;\n				uniform float opacity;\n\n				varying vec2 vUv;\n				void main() {\n\n					float ht = 0.5 * thickness;\n					float planeDim = size + thickness;\n					float offset = ( planeDim - ht - 2.0 ) / planeDim;\n					float texelThickness = ht / planeDim;\n\n					vec2 vec = vUv * 2.0 - vec2( 1.0 );\n					float dist = abs( length( vec ) - offset );\n					float fw = fwidth( dist ) * 0.5;\n					float a = smoothstep( texelThickness - fw, texelThickness + fw, dist );\n\n					gl_FragColor = vec4( 1, 1, 1, opacity * ( 1.0 - a ) );\n\n				}\n			"
		});
	}
}, $t = /* @__PURE__ */ new C(), en = /* @__PURE__ */ new C(), tn = class {
	constructor() {
		this.domElement = null, this.buttons = 0, this.pointerType = null, this.pointerOrder = [], this.previousPositions = {}, this.pointerPositions = {}, this.startPositions = {}, this.pointerSetThisFrame = {}, this.hoverPosition = new C(), this.hoverSet = !1;
	}
	reset() {
		this.buttons = 0, this.pointerType = null, this.pointerOrder = [], this.previousPositions = {}, this.pointerPositions = {}, this.startPositions = {}, this.pointerSetThisFrame = {}, this.hoverPosition = new C(), this.hoverSet = !1;
	}
	updateFrame() {
		let { previousPositions: e, pointerPositions: t } = this;
		for (let n in t) e[n].copy(t[n]);
	}
	setHoverEvent(e) {
		(e.pointerType === "mouse" || e.type === "wheel") && (this.getAdjustedPointer(e, this.hoverPosition), this.hoverSet = !0);
	}
	getLatestPoint(e) {
		return this.pointerType === null ? this.hoverSet ? (e.copy(this.hoverPosition), e) : null : (this.getCenterPoint(e), e);
	}
	getAdjustedPointer(e, t) {
		let n = (this.domElement ? this.domElement : e.target).getBoundingClientRect(), r = e.clientX - n.left, i = e.clientY - n.top;
		t.set(r, i);
	}
	addPointer(e) {
		let t = e.pointerId, n = new C();
		this.getAdjustedPointer(e, n), this.pointerOrder.push(t), this.pointerPositions[t] = n, this.previousPositions[t] = n.clone(), this.startPositions[t] = n.clone(), this.getPointerCount() === 1 && (this.pointerType = e.pointerType, this.buttons = e.buttons);
	}
	updatePointer(e) {
		let t = e.pointerId;
		return t in this.pointerPositions ? (this.getAdjustedPointer(e, this.pointerPositions[t]), !0) : !1;
	}
	deletePointer(e) {
		let t = e.pointerId, n = this.pointerOrder;
		n.splice(n.indexOf(t), 1), delete this.pointerPositions[t], delete this.previousPositions[t], delete this.startPositions[t], this.getPointerCount() === 0 && (this.buttons = 0, this.pointerType = null);
	}
	getPointerCount() {
		return this.pointerOrder.length;
	}
	getCenterPoint(e, t = this.pointerPositions) {
		let n = this.pointerOrder;
		if (this.getPointerCount() === 1 || this.getPointerType() === "mouse") {
			let r = n[0];
			return e.copy(t[r]), e;
		} else if (this.getPointerCount() === 2) {
			let n = this.pointerOrder[0], r = this.pointerOrder[1], i = t[n], a = t[r];
			return e.addVectors(i, a).multiplyScalar(.5), e;
		}
		return null;
	}
	getPreviousCenterPoint(e) {
		return this.getCenterPoint(e, this.previousPositions);
	}
	getStartCenterPoint(e) {
		return this.getCenterPoint(e, this.startPositions);
	}
	getMoveDistance() {
		return this.getCenterPoint($t), this.getPreviousCenterPoint(en), $t.sub(en).length();
	}
	getTouchPointerDistance(e = this.pointerPositions) {
		if (this.getPointerCount() <= 1 || this.getPointerType() === "mouse") return 0;
		let { pointerOrder: t } = this, n = t[0], r = t[1], i = e[n], a = e[r];
		return i.distanceTo(a);
	}
	getPreviousTouchPointerDistance() {
		return this.getTouchPointerDistance(this.previousPositions);
	}
	getStartTouchPointerDistance() {
		return this.getTouchPointerDistance(this.startPositions);
	}
	getPointerType() {
		return this.pointerType;
	}
	isPointerTouch() {
		return this.getPointerType() === "touch";
	}
	getPointerButtons() {
		return this.buttons;
	}
	isLeftClicked() {
		return !!(this.buttons & 1);
	}
	isRightClicked() {
		return !!(this.buttons & 2);
	}
}, nn = /* @__PURE__ */ new S();
function rn(e, t, n) {
	return n.makeTranslation(-e.x, -e.y, -e.z), nn.makeRotationFromQuaternion(t), n.premultiply(nn), nn.makeTranslation(e.x, e.y, e.z), n.premultiply(nn), n;
}
function I(e, t, n) {
	n.x = e.x / t.clientWidth * 2 - 1, n.y = -(e.y / t.clientHeight) * 2 + 1, n.isVector3 && (n.z = 0);
}
function L(e, t, n) {
	let { origin: r, direction: i } = e instanceof ue ? e : e.ray;
	r.set(t.x, t.y, -1).unproject(n), i.set(t.x, t.y, 1).unproject(n).sub(r), e.isRay || (e.near = 0, e.far = i.length(), e.camera = n), i.normalize();
}
var an = .05, on = .025, R = /* @__PURE__ */ new S(), sn = /* @__PURE__ */ new S(), z = /* @__PURE__ */ new w(), B = /* @__PURE__ */ new w(), cn = /* @__PURE__ */ new w(), ln = /* @__PURE__ */ new w(), V = /* @__PURE__ */ new w(), H = /* @__PURE__ */ new w(), un = /* @__PURE__ */ new w(), dn = /* @__PURE__ */ new w(), U = /* @__PURE__ */ new le(), fn = /* @__PURE__ */ new ae(), W = /* @__PURE__ */ new w(), pn = /* @__PURE__ */ new w(), mn = /* @__PURE__ */ new w(), hn = /* @__PURE__ */ new le(), G = /* @__PURE__ */ new ue(), gn = /* @__PURE__ */ new w(), _n = /* @__PURE__ */ new C(), K = /* @__PURE__ */ new C(), vn = /* @__PURE__ */ new C(), yn = /* @__PURE__ */ new C(), bn = /* @__PURE__ */ new C(), xn = /* @__PURE__ */ new C(), Sn = { type: "change" }, Cn = { type: "start" }, wn = { type: "end" }, Tn = 300, En = 30, Dn = 5, On = .0025, kn = class extends _ {
	get enabled() {
		return this._enabled;
	}
	set enabled(e) {
		e !== this.enabled && (this._enabled = e, this.resetState(), this.pointerTracker.reset(), this.enabled || (this.dragInertia.set(0, 0, 0), this.rotationInertia.set(0, 0)));
	}
	constructor(e = null, t = null, n = null) {
		super(), this.isEnvironmentControls = !0, this.domElement = null, this.camera = null, this.scene = null, this.tilesRenderer = null, this._enabled = !0, this.cameraRadius = 5, this.rotationSpeed = 1, this.minAltitude = 0, this.maxAltitude = .45 * Math.PI, this.minDistance = 10, this.maxDistance = Infinity, this.minZoom = 0, this.maxZoom = Infinity, this.zoomSpeed = 1, this.adjustHeight = !0, this.enableDamping = !1, this.dampingFactor = .15, this.enableDoubleTapZoom = !0, this.doubleTapZoomScale = 2, this.doubleTapZoomDuration = .25, this.fallbackPlane = new ae(new w(0, 1, 0), 0), this.useFallbackPlane = !0, this.enableFlight = !1, this.flightSpeed = 10, this.flightSpeedMultiplier = 4, this.scaleZoomOrientationAtEdges = !1, this.autoAdjustCameraRotation = !0, this.state = 0, this.pointerTracker = new tn(), this.needsUpdate = !1, this.actionHeightOffset = 0, this.pivotPoint = new w(), this.zoomDirectionSet = !1, this.zoomPointSet = !1, this.zoomDirection = new w(), this.zoomPoint = new w(), this.zoomDelta = 0, this.rotationInertiaPivot = new w(), this.rotationInertia = new C(), this.dragInertia = new w(), this.inertiaTargetDistance = Infinity, this.inertiaStableFrames = 0, this.pivotMesh = new Zt(), this.pivotMesh.raycast = () => {}, this.pivotMesh.scale.setScalar(.25), this.raycaster = new de(), this.raycaster.firstHitOnly = !0, this.up = new w(0, 1, 0), this._lastTime = performance.now(), this._keysDown = /* @__PURE__ */ new Set(), this._detachCallback = null, this._upInitialized = !1, this._lastUsedState = 0, this._zoomPointWasSet = !1, this._doubleTapZoomActive = !1, this._doubleTapZoomElapsed = 0, this._doubleTapPoint = new C(), this._lastTapTime = -Infinity, this._lastTapPoint = new C(), this._tilesOnChangeCallback = () => this.zoomPointSet = !1, n && this.attach(n), t && this.setCamera(t), e && this.setScene(e);
	}
	_getDeltaTime() {
		let e = performance.now(), t = e - this._lastTime;
		return this._lastTime = e, t * .001;
	}
	setScene(e) {
		this.scene = e;
	}
	setCamera(e) {
		this.camera = e, this._upInitialized = !1, this.zoomDirectionSet = !1, this.zoomPointSet = !1, this.needsUpdate = !0, this.raycaster.camera = e, this.resetState();
	}
	attach(e) {
		if (this.domElement) throw Error("EnvironmentControls: Controls already attached to element");
		this.domElement = e, this.pointerTracker.domElement = e, e.style.touchAction = "none", e.hasAttribute("tabindex") || (e.tabIndex = -1);
		let t = (e) => {
			this.enabled && e.preventDefault();
		}, n = (e) => {
			let { camera: t, raycaster: n, domElement: r, up: i, pivotMesh: a, pointerTracker: o, scene: s, pivotPoint: c, enabled: l, enableFlight: u, _keysDown: d } = this;
			if (!this.enabled) return;
			if (e.preventDefault(), r.focus(), o.addPointer(e), this.needsUpdate = !0, this._cancelDoubleTapZoom(), o.isPointerTouch()) {
				if (a.visible = !1, o.getPointerCount() === 0) r.setPointerCapture(e.pointerId);
				else if (o.getPointerCount() > 2) {
					this.resetState();
					return;
				}
			}
			o.getCenterPoint(K), I(K, r, K), L(n, K, t);
			let f = Math.abs(n.ray.direction.dot(i));
			if (f < an || f < on) return;
			let p = d.has("w") || d.has("s") || d.has("a") || d.has("d") || d.has("q") || d.has("e") || d.has("arrowup") || d.has("arrowdown") || d.has("arrowleft") || d.has("arrowright") || d.has("shift");
			if (u && p && !o.isPointerTouch() && (o.isRightClicked() || o.isLeftClicked())) {
				c.copy(t.position), this.setState(5);
				return;
			}
			let m = this._raycast(n);
			m && (o.getPointerCount() === 2 || o.isRightClicked() || o.isLeftClicked() && e.shiftKey ? (c.copy(m.point), a.position.copy(m.point), a.visible = o.isPointerTouch() ? !1 : l, a.updateMatrixWorld(), s.add(a), this.setState(o.isPointerTouch() ? 4 : 2)) : o.isLeftClicked() && (c.copy(m.point), a.position.copy(m.point), a.updateMatrixWorld(), s.add(a), this.setState(1)));
		}, r = !1, i = (e) => {
			let { pointerTracker: t } = this;
			if (!this.enabled) return;
			e.preventDefault();
			let { pivotMesh: n, enabled: i } = this;
			this.zoomDirectionSet = !1, this.zoomPointSet = !1, this.state !== 0 && (this.needsUpdate = !0), t.setHoverEvent(e), t.updatePointer(e) && (t.isPointerTouch() && t.getPointerCount() === 2 && (r || (r = !0, queueMicrotask(() => {
				r = !1, t.getCenterPoint(bn);
				let e = t.getStartTouchPointerDistance(), a = t.getTouchPointerDistance(), o = a - e;
				if (this.state === 0 || this.state === 4) {
					t.getCenterPoint(bn), t.getStartCenterPoint(xn);
					let e = 2 * window.devicePixelRatio, n = bn.distanceTo(xn);
					(Math.abs(o) > e || n > e) && (Math.abs(o) > n ? (this.setState(3), this.zoomDirectionSet = !1) : this.setState(2));
				}
				if (this.state === 3) {
					let e = t.getPreviousTouchPointerDistance();
					this.zoomDelta += a - e, n.visible = !1;
				} else this.state === 2 && (n.visible = i);
			}))), this.dispatchEvent(Sn));
		}, a = (t) => {
			let { pointerTracker: n } = this;
			if (!(!this.enabled || n.getPointerCount() === 0)) {
				if (this.enableDoubleTapZoom && t.button === 0 && n.getPointerCount() === 1 && (n.getCenterPoint(K), n.getStartCenterPoint(bn), K.distanceTo(bn) < Dn * window.devicePixelRatio)) {
					let e = performance.now();
					e - this._lastTapTime < Tn && K.distanceTo(this._lastTapPoint) < En * window.devicePixelRatio ? (this._lastTapTime = -Infinity, this._beginDoubleTapZoom(K)) : (this._lastTapTime = e, this._lastTapPoint.copy(K));
				}
				n.deletePointer(t), n.getPointerType() === "touch" && n.getPointerCount() === 0 && e.releasePointerCapture(t.pointerId), this.resetState(), this.needsUpdate = !0;
			}
		}, o = (e) => {
			if (!this.enabled) return;
			e.preventDefault(), this._cancelDoubleTapZoom();
			let { pointerTracker: t } = this;
			t.setHoverEvent(e), t.updatePointer(e), this.dispatchEvent(Cn);
			let n;
			switch (e.deltaMode) {
				case 2:
					n = e.deltaY * 800;
					break;
				case 1:
					n = e.deltaY * 40;
					break;
				case 0:
					n = e.deltaY;
					break;
			}
			let r = Math.sign(n), i = Math.abs(n);
			this.zoomDelta -= .25 * r * i, this.needsUpdate = !0, this._lastUsedState = 3, this.dispatchEvent(wn);
		}, s = (e) => {
			this.enabled && this.resetState();
		};
		e.addEventListener("contextmenu", t), e.addEventListener("pointerdown", n), e.addEventListener("wheel", o, { passive: !1 });
		let c = e.getRootNode();
		c.addEventListener("pointermove", i), c.addEventListener("pointerup", a), c.addEventListener("pointerleave", s);
		let l = (e) => {
			let { _keysDown: t, state: n } = this;
			t.add(e.key.toLowerCase()), (t.has("w") || t.has("s") || t.has("a") || t.has("d") || t.has("q") || t.has("e") || t.has("arrowup") || t.has("arrowdown") || t.has("arrowleft") || t.has("arrowright")) && n !== 5 && this.resetState();
		}, u = (e) => {
			this._keysDown.delete(e.key.toLowerCase());
		}, d = () => {
			this._keysDown.clear();
		};
		e.addEventListener("keydown", l), window.addEventListener("keyup", u), window.addEventListener("blur", d), this._detachCallback = () => {
			e.removeEventListener("contextmenu", t), e.removeEventListener("pointerdown", n), e.removeEventListener("wheel", o), c.removeEventListener("pointermove", i), c.removeEventListener("pointerup", a), c.removeEventListener("pointerleave", s), e.removeEventListener("keydown", l), window.removeEventListener("keyup", u), window.removeEventListener("blur", d);
		};
	}
	detach() {
		this.domElement = null, this._detachCallback && (this._detachCallback(), this._detachCallback = null, this.pointerTracker.reset());
	}
	getUpDirection(e, t) {
		t.copy(this.up);
	}
	getCameraUpDirection(e) {
		this.getUpDirection(this.camera.position, e);
	}
	getPivotPoint(e) {
		let t = null;
		this._lastUsedState === 3 ? this._zoomPointWasSet && (t = e.copy(this.zoomPoint)) : (this._lastUsedState === 2 || this._lastUsedState === 1) && (t = e.copy(this.pivotPoint));
		let { camera: n, raycaster: r } = this;
		t !== null && (B.copy(t).project(n), (B.x < -1 || B.x > 1 || B.y < -1 || B.y > 1) && (t = null)), L(r, {
			x: 0,
			y: 0
		}, n);
		let i = this._raycast(r);
		return i && (t === null || i.distance < t.distanceTo(r.ray.origin)) && (t = e.copy(i.point)), t;
	}
	resetState() {
		this.state !== 0 && this.dispatchEvent(wn), this.state = 0, this.pivotMesh.removeFromParent(), this.pivotMesh.visible = this.enabled, this.actionHeightOffset = 0, this.pointerTracker.reset();
	}
	setState(e = this.state, t = !0) {
		this.state !== e && (this.state === 0 && t && this.dispatchEvent(Cn), this.pivotMesh.visible = this.enabled, this.dragInertia.set(0, 0, 0), this.rotationInertia.set(0, 0), this.inertiaStableFrames = 0, this.state = e, e !== 0 && e !== 4 && (this._lastUsedState = e));
	}
	update(e = Math.min(this._getDeltaTime(), 64 / 1e3)) {
		if (!this.enabled || !this.camera || e === 0) return;
		let { camera: t, cameraRadius: n, pivotPoint: r, up: i, state: a, adjustHeight: o, autoAdjustCameraRotation: s } = this;
		t.updateMatrixWorld(), this.getCameraUpDirection(W), this._upInitialized || (this._upInitialized = !0, this.up.copy(W)), this.zoomPointSet = !1, this._updateDoubleTapZoom(e);
		let c = this._inertiaNeedsUpdate(), l = this.needsUpdate || c;
		if (this.needsUpdate || c) {
			let n = this.zoomDelta;
			this._updateZoom(), this._updatePosition(e), this._updateRotation(e), a === 1 || a === 2 || a === 5 ? (V.set(0, 0, -1).transformDirection(t.matrixWorld), this.inertiaTargetDistance = B.copy(r).sub(t.position).dot(V)) : a === 0 && this._updateInertia(e), (a !== 0 || n !== 0 || c) && this.dispatchEvent(Sn), this.needsUpdate = !1;
		}
		let u = this._updateFlight(e);
		u && (this.dragInertia.set(0, 0, 0), this.rotationInertia.set(0, 0, 0), this.dispatchEvent(Sn));
		let d = t.isOrthographicCamera ? null : o && !u && this._getPointBelowCamera() || null;
		if (this.getCameraUpDirection(W), this._setFrame(W), (this.state === 1 || this.state === 2 || this.state === 5) && this.actionHeightOffset !== 0) {
			let { actionHeightOffset: e } = this;
			t.position.addScaledVector(i, -e), r.addScaledVector(i, -e), d && (d.distance -= e);
		}
		if (this.actionHeightOffset = 0, d) {
			let e = d.distance;
			if (e < n) {
				let a = n - e;
				t.position.addScaledVector(i, a), r.addScaledVector(i, a), this.actionHeightOffset = a;
			}
		}
		this.pointerTracker.updateFrame(), (l && s || u) && (this.getCameraUpDirection(W), this._alignCameraUp(W, 1), this.getCameraUpDirection(W), this._clampRotation(W));
	}
	adjustCamera(e) {
		let { adjustHeight: t, cameraRadius: n } = this;
		if (e.isPerspectiveCamera) {
			this.getUpDirection(e.position, W);
			let r = t && this._getPointBelowCamera(e.position, W) || null;
			if (r) {
				let t = r.distance;
				t < n && e.position.addScaledVector(W, n - t);
			}
		}
	}
	dispose() {
		this.detach();
	}
	_updateInertia(e) {
		let { rotationInertia: t, pivotPoint: n, dragInertia: r, enableDamping: i, dampingFactor: a, camera: o, cameraRadius: s, minDistance: c, inertiaTargetDistance: l } = this;
		if (!this.enableDamping || this.inertiaStableFrames > 1) {
			r.set(0, 0, 0), t.set(0, 0, 0);
			return;
		}
		let u = 2 ** (-e / a), d = Math.max(o.near, s, c, l), f = 2 / (2 * 1e3) * .25;
		if (t.lengthSq() > 0) {
			L(G, B.set(0, 0, -1), o), G.applyMatrix4(o.matrixWorldInverse), G.direction.normalize(), G.recast(-G.direction.dot(G.origin)).at(d / G.direction.z, B), B.applyMatrix4(o.matrixWorld), L(G, z.set(f, f, -1), o), G.applyMatrix4(o.matrixWorldInverse), G.direction.normalize(), G.recast(-G.direction.dot(G.origin)).at(d / G.direction.z, z), z.applyMatrix4(o.matrixWorld), B.sub(n).normalize(), z.sub(n).normalize();
			let r = B.angleTo(z) / e;
			t.multiplyScalar(u), (t.lengthSq() < r ** 2 || !i) && t.set(0, 0);
		}
		if (r.lengthSq() > 0) {
			L(G, B.set(0, 0, -1), o), G.applyMatrix4(o.matrixWorldInverse), G.direction.normalize(), G.recast(-G.direction.dot(G.origin)).at(d / G.direction.z, B), B.applyMatrix4(o.matrixWorld), L(G, z.set(f, f, -1), o), G.applyMatrix4(o.matrixWorldInverse), G.direction.normalize(), G.recast(-G.direction.dot(G.origin)).at(d / G.direction.z, z), z.applyMatrix4(o.matrixWorld);
			let t = B.distanceTo(z) / e;
			r.multiplyScalar(u), (r.lengthSq() < t ** 2 || !i) && r.set(0, 0, 0);
		}
		t.lengthSq() > 0 && this._applyRotation(t.x * e, t.y * e, n), r.lengthSq() > 0 && (o.position.addScaledVector(r, e), o.updateMatrixWorld());
	}
	_inertiaNeedsUpdate() {
		let { rotationInertia: e, dragInertia: t } = this;
		return e.lengthSq() !== 0 || t.lengthSq() !== 0;
	}
	_getFlightSpeedScale() {
		return 1;
	}
	_updateFlight(e) {
		let { camera: t, enableFlight: n, flightSpeed: r, flightSpeedMultiplier: i, _keysDown: a } = this;
		if (!n || t.isOrthographicCamera) return !1;
		let o = a.has("w") || a.has("arrowup"), s = a.has("s") || a.has("arrowdown"), c = a.has("a") || a.has("arrowleft"), l = a.has("d") || a.has("arrowright"), u = a.has("q"), d = a.has("e"), f = (a.has("shift") ? i : 1) * r * this._getFlightSpeedScale() * e;
		return gn.set(!!l - +!!c, !!u - +!!d, !!s - +!!o), gn.lengthSq() === 0 ? !1 : (gn.normalize().transformDirection(t.matrixWorld), t.position.addScaledVector(gn, f), t.updateMatrixWorld(), !0);
	}
	_updateZoom() {
		let { zoomPoint: e, zoomDirection: t, camera: n, minDistance: r, maxDistance: i, pointerTracker: a, domElement: o, minZoom: s, maxZoom: c, zoomSpeed: l, state: u } = this, d = this.zoomDelta;
		if (this.zoomDelta = 0, !(!a.getLatestPoint(K) || d === 0 && u !== 3)) if (this.rotationInertia.set(0, 0), this.dragInertia.set(0, 0, 0), n.isOrthographicCamera) {
			this._updateZoomDirection();
			let e = this.zoomPointSet || this._updateZoomPoint();
			I(K, o, pn), pn.unproject(n);
			let t = .95 ** (-l * d * .05);
			t > 1 ? c < n.zoom * t && (t = 1) : s > n.zoom * t && (t = 1), n.zoom *= t, n.updateProjectionMatrix(), e && (I(K, o, mn), mn.unproject(n), n.position.sub(mn).add(pn), n.updateMatrixWorld());
		} else {
			this._updateZoomDirection();
			let a = B.copy(t);
			if (this.zoomPointSet || this._updateZoomPoint()) {
				let a = e.distanceTo(n.position);
				if (d < 0) {
					let e = Math.min(0, a - i);
					d = d * a * l * On, d = Math.max(d, e);
				} else {
					let e = Math.max(0, a - r);
					d = d * Math.max(a - r, 0) * l * On, d = Math.min(d, e);
				}
				n.position.addScaledVector(t, d), n.updateMatrixWorld();
			} else {
				let e = this._getPointBelowCamera();
				if (e) {
					let t = e.distance;
					a.set(0, 0, -1).transformDirection(n.matrixWorld), n.position.addScaledVector(a, d * t * .01), n.updateMatrixWorld();
				} else n.position.addScaledVector(t, d), n.updateMatrixWorld();
			}
		}
	}
	_beginDoubleTapZoom(e) {
		let { camera: t, raycaster: n, domElement: r } = this;
		I(e, r, bn), L(n, bn, t);
		let i = this._raycast(n);
		i !== null && (this.zoomPoint.copy(i.point), this.zoomPointSet = !0, this.zoomDirection.copy(n.ray.direction).normalize(), this.zoomDirectionSet = !0, this._doubleTapPoint.copy(e), this._doubleTapZoomActive = !0, this._doubleTapZoomElapsed = 0, this.needsUpdate = !0, this.dispatchEvent(Cn));
	}
	_updateDoubleTapZoom(e) {
		if (!this._doubleTapZoomActive) return;
		let { doubleTapZoomDuration: t, doubleTapZoomScale: n, zoomSpeed: r, pointerTracker: i } = this;
		i.getLatestPoint(K) === null && (i.hoverPosition.copy(this._doubleTapPoint), i.hoverSet = !0);
		let a = Math.log(n) / (On * r), o = (e) => 1 - (1 - x.clamp(e, 0, 1)) ** 3, s = o(this._doubleTapZoomElapsed / t);
		this._doubleTapZoomElapsed += e;
		let c = o(this._doubleTapZoomElapsed / t);
		this.zoomDelta += a * (c - s), this.needsUpdate = !0, this._doubleTapZoomElapsed >= t && (this._doubleTapZoomActive = !1, this.dispatchEvent(wn));
	}
	_cancelDoubleTapZoom() {
		this._doubleTapZoomActive && (this._doubleTapZoomActive = !1, this.dispatchEvent(wn));
	}
	_updateZoomDirection() {
		if (this.zoomDirectionSet) return;
		let { domElement: e, raycaster: t, camera: n, zoomDirection: r, pointerTracker: i } = this;
		i.getLatestPoint(K), I(K, e, pn), L(t, pn, n), r.copy(t.ray.direction).normalize(), this.zoomDirectionSet = !0;
	}
	_updateZoomPoint() {
		let { camera: e, zoomDirectionSet: t, zoomDirection: n, raycaster: r, zoomPoint: i, pointerTracker: a, domElement: o } = this;
		if (this._zoomPointWasSet = !1, !t) return !1;
		e.isOrthographicCamera && a.getLatestPoint(_n) ? (I(_n, o, _n), L(r, _n, e)) : (r.ray.origin.copy(e.position), r.ray.direction.copy(n), r.near = 0, r.far = Infinity);
		let s = this._raycast(r);
		return s ? (i.copy(s.point), this.zoomPointSet = !0, this._zoomPointWasSet = !0, !0) : !1;
	}
	_getPointBelowCamera(e = this.camera.position, t = this.up) {
		let { raycaster: n } = this;
		n.ray.direction.copy(t).multiplyScalar(-1), n.ray.origin.copy(e).addScaledVector(t, 1e5), n.near = 0, n.far = Infinity;
		let r = this._raycast(n);
		return r && (r.distance -= 1e5), r;
	}
	_updatePosition(e) {
		let { raycaster: t, camera: n, pivotPoint: r, up: i, pointerTracker: a, domElement: o, state: s, dragInertia: c } = this;
		if (s === 1) {
			if (a.getCenterPoint(K), I(K, o, K), fn.setFromNormalAndCoplanarPoint(i, r), L(t, K, n), Math.abs(t.ray.direction.dot(i)) < an) {
				let e = Math.acos(an);
				dn.crossVectors(t.ray.direction, i).normalize(), t.ray.direction.copy(i).applyAxisAngle(dn, e).multiplyScalar(-1);
			}
			if (this.getUpDirection(r, W), Math.abs(t.ray.direction.dot(W)) < on) {
				let e = Math.acos(on);
				dn.crossVectors(t.ray.direction, W).normalize(), t.ray.direction.copy(W).applyAxisAngle(dn, e).multiplyScalar(-1);
			}
			t.ray.intersectPlane(fn, B) && (z.subVectors(r, B), n.position.add(z), n.updateMatrixWorld(), z.multiplyScalar(1 / e), a.getMoveDistance() / e < 2 * window.devicePixelRatio ? this.inertiaStableFrames++ : (c.copy(z), this.inertiaStableFrames = 0));
		}
	}
	_updateRotation(e) {
		let { pivotPoint: t, pointerTracker: n, domElement: r, state: i, rotationInertia: a } = this;
		(i === 2 || i === 5) && (i === 5 && t.copy(this.camera.position), n.getCenterPoint(K), n.getPreviousCenterPoint(vn), yn.subVectors(K, vn).multiplyScalar(2 * Math.PI / r.clientHeight), this._applyRotation(yn.x, yn.y, t), yn.multiplyScalar(1 / e), n.getMoveDistance() / e < 2 * window.devicePixelRatio ? this.inertiaStableFrames++ : (a.copy(yn), this.inertiaStableFrames = 0));
	}
	_applyRotation(e, t, n) {
		if (e === 0 && t === 0) return;
		let { camera: r, minAltitude: i, maxAltitude: a, rotationSpeed: o } = this, s = -e * o, c = t * o;
		V.set(0, 0, 1).transformDirection(r.matrixWorld), H.set(1, 0, 0).transformDirection(r.matrixWorld), this.getUpDirection(n, W);
		let l;
		W.dot(V) > .9999999999 ? l = 0 : (B.crossVectors(W, V).normalize(), l = Math.sign(B.dot(H)) * W.angleTo(V)), c > 0 ? (c = Math.min(l - i, c), c = Math.max(0, c)) : (c = Math.max(l - a, c), c = Math.min(0, c)), U.setFromAxisAngle(W, s), rn(n, U, R), r.matrixWorld.premultiply(R), H.set(1, 0, 0).transformDirection(r.matrixWorld), U.setFromAxisAngle(H, -c), rn(n, U, R), r.matrixWorld.premultiply(R), r.matrixWorld.decompose(r.position, r.quaternion, B);
	}
	_setFrame(e) {
		let { up: t, camera: n, zoomPoint: r, zoomDirectionSet: i, zoomPointSet: a, scaleZoomOrientationAtEdges: o } = this;
		if (i && (a || this._updateZoomPoint())) {
			if (U.setFromUnitVectors(t, e), o) {
				this.getUpDirection(r, B);
				let e = Math.max(B.dot(t) - .6, 0) / .4;
				e = x.mapLinear(e, 0, .5, 0, 1), e = Math.min(e, 1), n.isOrthographicCamera && (e *= .1), U.slerp(hn, 1 - e);
			}
			rn(r, U, R), n.updateMatrixWorld(), n.matrixWorld.premultiply(R), n.matrixWorld.decompose(n.position, n.quaternion, B), this.zoomDirectionSet = !1, this._updateZoomDirection();
		}
		t.copy(e), n.updateMatrixWorld();
	}
	_raycast(e) {
		let { scene: t, useFallbackPlane: n, fallbackPlane: r } = this, i = e.intersectObject(t)[0] || null;
		if (i) return i;
		if (n) {
			let t = r;
			if (e.ray.intersectPlane(t, B)) return {
				point: B.clone(),
				distance: e.ray.origin.distanceTo(B)
			};
		}
		return null;
	}
	_alignCameraUp(e, t = 1) {
		let { camera: n, state: r, pivotPoint: i, zoomPoint: a, zoomPointSet: o } = this;
		n.updateMatrixWorld(), V.set(0, 0, -1).transformDirection(n.matrixWorld), H.set(-1, 0, 0).transformDirection(n.matrixWorld);
		let s = x.mapLinear(1 - Math.abs(V.dot(e)), 0, .2, 0, 1);
		s = x.clamp(s, 0, 1), t *= s, un.crossVectors(e, V), un.lerp(H, 1 - t).normalize(), U.setFromUnitVectors(H, un), n.quaternion.premultiply(U);
		let c = null;
		r === 1 || r === 2 || r === 5 ? c = cn.copy(i) : o && (c = cn.copy(a)), c && (sn.copy(n.matrixWorld).invert(), B.copy(c).applyMatrix4(sn), n.updateMatrixWorld(), B.applyMatrix4(n.matrixWorld), ln.subVectors(c, B), n.position.add(ln)), n.updateMatrixWorld();
	}
	_clampRotation(e) {
		let { camera: t, minAltitude: n, maxAltitude: r, state: i, pivotPoint: a, zoomPoint: o, zoomPointSet: s } = this;
		t.updateMatrixWorld(), V.set(0, 0, 1).transformDirection(t.matrixWorld), H.set(1, 0, 0).transformDirection(t.matrixWorld);
		let c;
		e.dot(V) > .9999999999 ? c = 0 : (B.crossVectors(e, V), c = Math.sign(B.dot(H)) * e.angleTo(V));
		let l;
		if (c > r) l = r;
		else if (c < n) l = n;
		else return;
		V.copy(e), U.setFromAxisAngle(H, l), V.applyQuaternion(U).normalize(), B.crossVectors(V, H).normalize(), R.makeBasis(H, B, V), t.quaternion.setFromRotationMatrix(R);
		let u = null;
		i === 1 || i === 2 || i === 5 ? u = cn.copy(a) : s && (u = cn.copy(o)), u && (sn.copy(t.matrixWorld).invert(), B.copy(u).applyMatrix4(sn), t.updateMatrixWorld(), B.applyMatrix4(t.matrixWorld), ln.subVectors(u, B), t.position.add(ln)), t.updateMatrixWorld();
	}
}, An = /* @__PURE__ */ new S(), jn = /* @__PURE__ */ new S(), q = /* @__PURE__ */ new w(), J = /* @__PURE__ */ new w(), Y = /* @__PURE__ */ new w(), X = /* @__PURE__ */ new w(), Mn = /* @__PURE__ */ new w(), Nn = /* @__PURE__ */ new w(), Z = /* @__PURE__ */ new le(), Pn = /* @__PURE__ */ new w(), Fn = /* @__PURE__ */ new w(), Q = /* @__PURE__ */ new ue(), In = /* @__PURE__ */ new Ye(), Ln = /* @__PURE__ */ new C(), Rn = {}, zn = 2550, Bn = class extends kn {
	get ellipsoidFrame() {
		return this.ellipsoidGroup.matrixWorld;
	}
	get ellipsoidFrameInverse() {
		let { ellipsoidGroup: e, ellipsoidFrame: t, _ellipsoidFrameInverse: n } = this;
		return e.matrixWorldInverse ? e.matrixWorldInverse : n.copy(t).invert();
	}
	constructor(e = null, t = null, n = null) {
		super(e, t, n), this.isGlobeControls = !0, this._dragMode = 0, this._rotationMode = 0, this.maxZoom = .01, this.nearMargin = .25, this.farMargin = 0, this.useFallbackPlane = !1, this.autoAdjustCameraRotation = !1, this.globeInertia = new le(), this.globeInertiaFactor = 0, this.ellipsoid = Xe.clone(), this.ellipsoidGroup = new y(), this._ellipsoidFrameInverse = new S();
	}
	setEllipsoid(e, t) {
		this.ellipsoid = e || Xe.clone(), this.ellipsoidGroup = t || new y();
	}
	getPivotPoint(e) {
		let { camera: t, ellipsoidFrame: n, ellipsoidFrameInverse: r, ellipsoid: i } = this;
		return X.set(0, 0, -1).transformDirection(t.matrixWorld), Q.origin.copy(t.position), Q.direction.copy(X), Q.applyMatrix4(r), i.closestPointToRayEstimate(Q, J).applyMatrix4(n), (super.getPivotPoint(e) === null || q.subVectors(e, Q.origin).dot(Q.direction) > q.subVectors(J, Q.origin).dot(Q.direction)) && e.copy(J), e;
	}
	getVectorToCenter(e) {
		let { ellipsoidFrame: t, camera: n } = this;
		return e.setFromMatrixPosition(t).sub(n.position);
	}
	getDistanceToCenter() {
		return this.getVectorToCenter(J).length();
	}
	getUpDirection(e, t) {
		let { ellipsoidFrame: n, ellipsoidFrameInverse: r, ellipsoid: i } = this;
		J.copy(e).applyMatrix4(r), i.getPositionToNormal(J, t), t.transformDirection(n);
	}
	getCameraUpDirection(e) {
		let { ellipsoidFrame: t, ellipsoidFrameInverse: n, ellipsoid: r, camera: i } = this;
		i.isOrthographicCamera ? (this._getVirtualOrthoCameraPosition(J), J.applyMatrix4(n), r.getPositionToNormal(J, e), e.transformDirection(t)) : this.getUpDirection(i.position, e);
	}
	update(e = Math.min(this._getDeltaTime(), 64 / 1e3)) {
		if (!this.enabled || !this.camera || e === 0) return;
		let { camera: t, pivotMesh: n } = this;
		this._isNearControls() ? this.scaleZoomOrientationAtEdges = this.zoomDelta < 0 : (this.state !== 0 && this._dragMode !== 1 && this._rotationMode !== 1 && (n.visible = !1), this.scaleZoomOrientationAtEdges = !1);
		let r = this.needsUpdate || this._inertiaNeedsUpdate();
		super.update(e), this.adjustCamera(t), r && (this._isNearControls() || this.state === 5) && (this.getCameraUpDirection(Nn), this._alignCameraUp(Nn, 1), this.getCameraUpDirection(Nn), this._clampRotation(Nn));
	}
	adjustCamera(e) {
		super.adjustCamera(e);
		let { ellipsoidFrame: t, ellipsoidFrameInverse: n, ellipsoid: r, nearMargin: i, farMargin: a } = this, o = this._getMaxWorldRadius();
		if (e.isPerspectiveCamera) {
			let s = J.setFromMatrixPosition(t).sub(e.position).length(), c = i * o, l = x.clamp((s - o) / c, 0, 1), u = x.lerp(1, 1e3, l);
			e.near = Math.max(u, s - o - c), q.copy(e.position).applyMatrix4(n), r.getPositionToCartographic(q, Rn);
			let d = Math.max(r.getPositionElevation(q), zn);
			e.far = r.calculateHorizonDistance(Rn.lat, d) + .1 + o * a, e.updateProjectionMatrix();
		} else {
			this._getVirtualOrthoCameraPosition(e.position, e), e.updateMatrixWorld(), An.copy(e.matrixWorld).invert(), J.setFromMatrixPosition(t).applyMatrix4(An);
			let n = -J.z;
			e.near = n - o * (1 + i), e.far = n + .1 + o * a, e.position.addScaledVector(X, e.near), e.far -= e.near, e.near = 0, e.updateProjectionMatrix(), e.updateMatrixWorld();
		}
	}
	setState(...e) {
		super.setState(...e), this._dragMode = 0, this._rotationMode = 0;
	}
	_updateInertia(e) {
		super._updateInertia(e);
		let { globeInertia: t, enableDamping: n, dampingFactor: r, camera: i, cameraRadius: a, minDistance: o, inertiaTargetDistance: s, ellipsoidFrame: c } = this;
		if (!this.enableDamping || this.inertiaStableFrames > 1) {
			this.globeInertiaFactor = 0, this.globeInertia.identity();
			return;
		}
		let l = 2 ** (-e / r), u = Math.max(i.near, a, o, s), d = 2 / (2 * 1e3) * .25;
		if (Y.setFromMatrixPosition(c), this.globeInertiaFactor !== 0) {
			L(Q, J.set(0, 0, -1), i), Q.applyMatrix4(i.matrixWorldInverse), Q.direction.normalize(), Q.recast(-Q.direction.dot(Q.origin)).at(u / Q.direction.z, J), J.applyMatrix4(i.matrixWorld), L(Q, q.set(d, d, -1), i), Q.applyMatrix4(i.matrixWorldInverse), Q.direction.normalize(), Q.recast(-Q.direction.dot(Q.origin)).at(u / Q.direction.z, q), q.applyMatrix4(i.matrixWorld), J.sub(Y).normalize(), q.sub(Y).normalize(), this.globeInertiaFactor *= l;
			let r = J.angleTo(q) / e;
			(2 * Math.acos(t.w) * this.globeInertiaFactor < r || !n) && (this.globeInertiaFactor = 0, t.identity());
		}
		this.globeInertiaFactor !== 0 && (t.w === 1 && (t.x !== 0 || t.y !== 0 || t.z !== 0) && (t.w = Math.min(t.w, .999999999)), Y.setFromMatrixPosition(c), Z.identity().slerp(t, this.globeInertiaFactor * e), rn(Y, Z, jn), i.matrixWorld.premultiply(jn), i.matrixWorld.decompose(i.position, i.quaternion, J));
	}
	_inertiaNeedsUpdate() {
		return super._inertiaNeedsUpdate() || this.globeInertiaFactor !== 0;
	}
	_getFlightSpeedScale() {
		let e = this.getDistanceToCenter() - this._getMaxWorldRadius();
		return 2 * Math.max(e, 1e3);
	}
	_updateFlight(e) {
		let { camera: t } = this, n = super._updateFlight(e);
		if (n) {
			let e = this._getMaxPerspectiveDistance(), n = this.getDistanceToCenter();
			if (n > e && (this.getVectorToCenter(J).normalize(), t.position.addScaledVector(J, n - e), t.updateMatrixWorld()), !this._isNearControls()) {
				let t = x.clamp(x.mapLinear(this.getDistanceToCenter(), this._getPerspectiveTransitionDistance(), e, 0, 1), 0, 1);
				this._tiltTowardsCenter(.02 * t), this._alignCameraUpToNorth(.01 * t);
			}
		}
		return n;
	}
	_updatePosition(e) {
		if (this.state === 1) {
			this._dragMode === 0 && (this._dragMode = this._isNearControls() ? 1 : -1);
			let { raycaster: t, camera: n, pivotPoint: r, pointerTracker: i, domElement: a, ellipsoidFrame: o, ellipsoidFrameInverse: s } = this, c = q, l = Mn;
			i.getCenterPoint(Ln), I(Ln, a, Ln), L(t, Ln, n), t.ray.applyMatrix4(s);
			let u = J.copy(r).applyMatrix4(s).length();
			if (In.radius.setScalar(u), !In.intersectRay(t.ray, J)) {
				let { origin: e, direction: n } = t.ray, r = c.copy(e).normalize(), i = l.copy(n).addScaledVector(r, -r.dot(n)).normalize(), a = e.length(), o = u * Math.sqrt(Math.max(1 - (u / a) ** 2, 0));
				J.copy(r).multiplyScalar(u * u / a).addScaledVector(i, o);
			}
			J.applyMatrix4(o), Y.setFromMatrixPosition(o), c.subVectors(r, Y).normalize(), l.subVectors(J, Y).normalize(), Z.setFromUnitVectors(l, c), rn(Y, Z, jn), n.matrixWorld.premultiply(jn), n.matrixWorld.decompose(n.position, n.quaternion, J), i.getMoveDistance() / e < 2 * window.devicePixelRatio ? this.inertiaStableFrames++ : (this.globeInertia.copy(Z), this.globeInertiaFactor = 1 / e, this.inertiaStableFrames = 0);
		}
	}
	_updateRotation(...e) {
		if (this.state === 5) {
			super._updateRotation(...e);
			return;
		}
		this._rotationMode === 1 || this._isNearControls() ? (this._rotationMode = 1, super._updateRotation(...e)) : (this.pivotMesh.visible = !1, this._rotationMode = -1);
	}
	_updateZoom() {
		let { zoomDelta: e, zoomSpeed: t, zoomPoint: n, camera: r, maxZoom: i, state: a } = this;
		if (a !== 3 && e === 0) return;
		this.rotationInertia.set(0, 0), this.dragInertia.set(0, 0, 0), this.globeInertia.identity(), this.globeInertiaFactor = 0;
		let o = x.clamp(x.mapLinear(Math.abs(e), 0, 20, 0, 1), 0, 1);
		if (this._isNearControls() || e > 0) {
			if (this._updateZoomDirection(), e < 0 && (this.zoomPointSet || this._updateZoomPoint())) {
				X.set(0, 0, -1).transformDirection(r.matrixWorld).normalize(), Fn.copy(this.up).multiplyScalar(-1), this.getUpDirection(n, Pn);
				let e = x.clamp(x.mapLinear(-Pn.dot(Fn), 1, .95, 0, 1), 0, 1), t = 1 - X.dot(Fn), i = r.isOrthographicCamera ? .05 : 1, a = x.clamp(o * 3, 0, 1), s = Math.min(e * t * i * a, .1);
				Fn.lerpVectors(X, Fn, s).normalize(), Z.setFromUnitVectors(X, Fn), rn(n, Z, jn), r.matrixWorld.premultiply(jn), r.matrixWorld.decompose(r.position, r.quaternion, Fn), this.zoomDirection.subVectors(n, r.position).normalize();
			}
			super._updateZoom();
		} else if (r.isPerspectiveCamera) {
			let n = this._getPerspectiveTransitionDistance(), r = this._getMaxPerspectiveDistance(), i = x.mapLinear(this.getDistanceToCenter(), n, r, 0, 1);
			this._tiltTowardsCenter(x.lerp(0, .4, i * o)), this._alignCameraUpToNorth(x.lerp(0, .2, i * o));
			let a = e * (this.getDistanceToCenter() - this._getMaxWorldRadius()) * t * On, s = Math.max(a, Math.min(this.getDistanceToCenter() - r, 0));
			this.getVectorToCenter(J).normalize(), this.camera.position.addScaledVector(J, s), this.camera.updateMatrixWorld(), this.zoomDelta = 0;
		} else {
			let e = this._getOrthographicTransitionZoom(), n = this._getMinOrthographicZoom(), a = x.mapLinear(r.zoom, e, n, 0, 1);
			this._tiltTowardsCenter(x.lerp(0, .4, a * o)), this._alignCameraUpToNorth(x.lerp(0, .2, a * o));
			let s = this.zoomDelta, c = .95 ** (-t * s * .05), l = n / r.zoom, u = Math.max(c, Math.min(l, 1));
			r.zoom = Math.min(i, r.zoom * u), r.updateProjectionMatrix(), this.zoomDelta = 0, this.zoomDirectionSet = !1;
		}
	}
	_alignCameraUpToNorth(e) {
		let { ellipsoidFrame: t } = this;
		Nn.set(0, 0, 1).transformDirection(t), this._alignCameraUp(Nn, e);
	}
	_tiltTowardsCenter(e) {
		let { camera: t, ellipsoidFrame: n } = this;
		X.set(0, 0, -1).transformDirection(t.matrixWorld).normalize(), J.setFromMatrixPosition(n).sub(t.position).normalize(), J.lerp(X, 1 - e).normalize(), Z.setFromUnitVectors(X, J), t.quaternion.premultiply(Z), t.updateMatrixWorld();
	}
	_getPerspectiveTransitionDistance() {
		let { camera: e } = this;
		if (!e.isPerspectiveCamera) throw Error();
		let t = this._getMaxWorldRadius(), n = 2 * Math.atan(Math.tan(x.DEG2RAD * e.fov * .5) * e.aspect), r = t / Math.tan(x.DEG2RAD * e.fov * .5), i = t / Math.tan(n * .5);
		return Math.max(r, i);
	}
	_getMaxPerspectiveDistance() {
		let { camera: e } = this;
		if (!e.isPerspectiveCamera) throw Error();
		let t = this._getMaxWorldRadius(), n = 2 * Math.atan(Math.tan(x.DEG2RAD * e.fov * .5) * e.aspect), r = t / Math.tan(x.DEG2RAD * e.fov * .5), i = t / Math.tan(n * .5);
		return 2 * Math.max(r, i);
	}
	_getOrthographicTransitionZoom() {
		let { camera: e } = this;
		if (!e.isOrthographicCamera) throw Error();
		let t = e.top - e.bottom, n = e.right - e.left, r = Math.max(t, n), i = 2 * this._getMaxWorldRadius();
		return 2 * r / i;
	}
	_getMinOrthographicZoom() {
		let { camera: e } = this;
		if (!e.isOrthographicCamera) throw Error();
		let t = e.top - e.bottom, n = e.right - e.left, r = Math.min(t, n), i = 2 * this._getMaxWorldRadius();
		return .7 * r / i;
	}
	_getVirtualOrthoCameraPosition(e, t = this.camera) {
		let { ellipsoidFrame: n, ellipsoidFrameInverse: r, ellipsoid: i } = this;
		if (!t.isOrthographicCamera) throw Error();
		Q.origin.copy(t.position), Q.direction.set(0, 0, -1).transformDirection(t.matrixWorld), Q.applyMatrix4(r), i.closestPointToRayEstimate(Q, q).applyMatrix4(n);
		let a = t.top - t.bottom, o = t.right - t.left, s = Math.max(a, o) / t.zoom;
		X.set(0, 0, -1).transformDirection(t.matrixWorld);
		let c = q.sub(t.position).dot(X);
		e.copy(t.position).addScaledVector(X, c - s * 4);
	}
	_isNearControls() {
		let { camera: e } = this;
		return e.isPerspectiveCamera ? this.getDistanceToCenter() < this._getPerspectiveTransitionDistance() : e.zoom > this._getOrthographicTransitionZoom();
	}
	_raycast(e) {
		let t = super._raycast(e);
		if (t === null) {
			let { ellipsoid: t, ellipsoidFrame: n, ellipsoidFrameInverse: r } = this;
			Q.copy(e.ray).applyMatrix4(r);
			let i = t.intersectRay(Q, J);
			return i === null ? null : (i.applyMatrix4(n), {
				point: i.clone(),
				distance: i.distanceTo(e.ray.origin)
			});
		} else return t;
	}
	_getMaxWorldRadius() {
		let { ellipsoid: e, ellipsoidFrame: t } = this;
		return Math.max(...e.radius) * t.getMaxScaleOnAxis();
	}
}, $ = /* @__PURE__ */ new w(), Vn = /* @__PURE__ */ new w(), Hn = /* @__PURE__ */ new re(), Un = /* @__PURE__ */ new w(), Wn = /* @__PURE__ */ new w(), Gn = /* @__PURE__ */ new w(), Kn = /* @__PURE__ */ new le(), qn = /* @__PURE__ */ new le(), Jn = class extends _ {
	get animating() {
		return this._alpha !== 0 && this._alpha !== 1;
	}
	get alpha() {
		return this._target === 0 ? 1 - this._alpha : this._alpha;
	}
	get camera() {
		return this._alpha === 0 ? this.perspectiveCamera : this._alpha === 1 ? this.orthographicCamera : this.transitionCamera;
	}
	get mode() {
		return this._target === 0 ? "perspective" : "orthographic";
	}
	set mode(e) {
		if (e === this.mode) return;
		let t = this.camera;
		e === "perspective" ? (this._target = 0, this._alpha = 0) : (this._target = 1, this._alpha = 1), this.dispatchEvent({
			type: "camera-change",
			camera: this.camera,
			prevCamera: t
		});
	}
	constructor(e = new ie(), t = new re()) {
		super(), this.perspectiveCamera = e, this.orthographicCamera = t, this.transitionCamera = new ie(), this.orthographicPositionalZoom = !0, this.orthographicOffset = 50, this.fixedPoint = new w(), this.duration = 200, this.autoSync = !0, this.easeFunction = (e) => e, this._target = 0, this._alpha = 0, this._clock = new p();
	}
	toggle() {
		this._target = this._target === 1 ? 0 : 1, this._clock.getDelta(), this.dispatchEvent({ type: "toggle" });
	}
	update(e = Math.min(this._clock.getDelta(), 64 / 1e3)) {
		this.autoSync && this.syncCameras();
		let { perspectiveCamera: t, orthographicCamera: n, transitionCamera: r, camera: i } = this, a = e * 1e3;
		if (this._alpha !== this._target) {
			let e = Math.sign(this._target - this._alpha) * a / this.duration;
			this._alpha = x.clamp(this._alpha + e, 0, 1), this.dispatchEvent({
				type: "change",
				alpha: this.alpha
			});
		}
		let o = i, s = null;
		this._alpha === 0 ? s = t : this._alpha === 1 ? s = n : (s = r, this._updateTransitionCamera()), o !== s && (s === r && this.dispatchEvent({ type: "transition-start" }), this.dispatchEvent({
			type: "camera-change",
			camera: s,
			prevCamera: o
		}), o === r && this.dispatchEvent({ type: "transition-end" }));
	}
	syncCameras() {
		let e = this._getFromCamera(), { perspectiveCamera: t, orthographicCamera: n, transitionCamera: r, fixedPoint: i } = this;
		if ($.set(0, 0, -1).transformDirection(e.matrixWorld).normalize(), e.isPerspectiveCamera) {
			if (this.orthographicPositionalZoom) n.position.copy(t.position).addScaledVector($, -this.orthographicOffset), n.rotation.copy(t.rotation), n.updateMatrixWorld();
			else {
				let e = Vn.subVectors(i, n.position).dot($), r = Vn.subVectors(i, t.position).dot($);
				Vn.copy(t.position).addScaledVector($, r), n.rotation.copy(t.rotation), n.position.copy(Vn).addScaledVector($, -e), n.updateMatrixWorld();
			}
			let e = Math.abs(Vn.subVectors(t.position, i).dot($)), r = 2 * Math.tan(x.DEG2RAD * t.fov * .5) * e;
			n.zoom = (n.top - n.bottom) / r, n.updateProjectionMatrix();
		} else {
			let e = Math.abs(Vn.subVectors(n.position, i).dot($)), r = (n.top - n.bottom) / n.zoom * .5 / Math.tan(x.DEG2RAD * t.fov * .5);
			t.rotation.copy(n.rotation), t.position.copy(n.position).addScaledVector($, e).addScaledVector($, -r), t.updateMatrixWorld(), this.orthographicPositionalZoom && (n.position.copy(t.position).addScaledVector($, -this.orthographicOffset), n.updateMatrixWorld());
		}
		r.position.copy(t.position), r.rotation.copy(t.rotation);
	}
	_getTransitionDirection() {
		return Math.sign(this._target - this._alpha);
	}
	_getToCamera() {
		let e = this._getTransitionDirection();
		return e === 0 ? this._target === 0 ? this.perspectiveCamera : this.orthographicCamera : e > 0 ? this.orthographicCamera : this.perspectiveCamera;
	}
	_getFromCamera() {
		let e = this._getTransitionDirection();
		return e === 0 ? this._target === 0 ? this.perspectiveCamera : this.orthographicCamera : e > 0 ? this.perspectiveCamera : this.orthographicCamera;
	}
	_updateTransitionCamera() {
		let { perspectiveCamera: e, orthographicCamera: t, transitionCamera: n, fixedPoint: r } = this, i = this.easeFunction(this._alpha);
		$.set(0, 0, -1).transformDirection(t.matrixWorld).normalize(), Hn.copy(t), Hn.position.addScaledVector($, t.near), t.far -= t.near, t.near = 0, $.set(0, 0, -1).transformDirection(e.matrixWorld).normalize();
		let a = Math.abs(Vn.subVectors(e.position, r).dot($)), o = 2 * Math.tan(x.DEG2RAD * e.fov * .5) * a, s = qn.slerpQuaternions(e.quaternion, Hn.quaternion, i), c = x.lerp(e.fov, 1, i), l = o * .5 / Math.tan(x.DEG2RAD * c * .5), u = Gn.copy(Hn.position).sub(r).applyQuaternion(Kn.copy(Hn.quaternion).invert()), d = Wn.copy(e.position).sub(r).applyQuaternion(Kn.copy(e.quaternion).invert()), f = Un.lerpVectors(d, u, i);
		f.z -= Math.abs(f.z) - l;
		let p = -(d.z - f.z), m = -(u.z - f.z), h = x.lerp(p + e.near, m + Hn.near, i), g = x.lerp(p + e.far, m + Hn.far, i), _ = Math.max(g, 0) - Math.max(h, 0);
		n.aspect = e.aspect, n.fov = c, n.near = Math.max(h, _ * 1e-5), n.far = g, n.position.copy(f).applyQuaternion(s).add(r), n.quaternion.copy(s), n.updateProjectionMatrix(), n.updateMatrixWorld();
	}
};
//#endregion
export { Ce as _, Lt as a, xt as c, Xe as d, qe as f, we as g, Je as h, Xt as i, dt as l, Ye as m, Bn as n, Bt as o, Ke as p, kn as r, At as s, Jn as t, ut as u, ve as v };

//# sourceMappingURL=renderer-3xKvdklX.js.map