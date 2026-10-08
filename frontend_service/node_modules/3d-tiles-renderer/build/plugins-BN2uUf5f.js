import { c as e, f as t, u as n, x as r } from "./renderer-tyqPdeD-.js";
//#region src/core/plugins/auth/CesiumIonAuth.js
var i = class {
	constructor(e = {}) {
		let { apiToken: t, autoRefreshToken: n = !1 } = e;
		this.apiToken = t, this.autoRefreshToken = n, this.authURL = null, this._tokenRefreshPromise = null, this._bearerToken = null, this._bearerHostname = null;
	}
	async fetch(e, t) {
		await this._tokenRefreshPromise;
		let n = { ...t }, r = this._bearerHostname !== null && new URL(e).host === this._bearerHostname;
		r && (n.headers = {
			...n.headers,
			Authorization: this._bearerToken
		});
		let i = await fetch(e, n);
		return r && i.status >= 400 && i.status <= 499 && this.autoRefreshToken ? (await this.refreshToken(t), n.headers.Authorization = this._bearerToken, fetch(e, n)) : i;
	}
	refreshToken(e) {
		if (this._tokenRefreshPromise === null) {
			let t = new URL(this.authURL);
			t.searchParams.set("access_token", this.apiToken), this._tokenRefreshPromise = fetch(t, e).then((e) => {
				if (!e.ok) throw Error(`CesiumIonAuthPlugin: Failed to load data with error code ${e.status}`);
				return e.json();
			}).then((e) => (e.accessToken && e.url && (this._bearerToken = `Bearer ${e.accessToken}`, this._bearerHostname = new URL(e.url).host), this._tokenRefreshPromise = null, e));
		}
		return this._tokenRefreshPromise;
	}
}, a = "https://tile.googleapis.com/v1/createSession", o = class {
	get isMapTilesSession() {
		return this.authURL === a;
	}
	constructor(e = {}) {
		let { apiToken: t, sessionOptions: n = null, autoRefreshToken: r = !1 } = e;
		this.apiToken = t, this.autoRefreshToken = r, this.authURL = a, this.sessionToken = null, this.sessionOptions = n, this._tokenRefreshPromise = null, this._authHostname = null;
	}
	async fetch(e, t) {
		this.sessionToken === null && this.isMapTilesSession && this.refreshToken(t), await this._tokenRefreshPromise, this._authHostname === null && (this._authHostname = new URL(this.authURL).host);
		let n = new URL(e), r = n.host === this._authHostname;
		r && (n.searchParams.set("key", this.apiToken), this.sessionToken && n.searchParams.set("session", this.sessionToken));
		let i = await fetch(n, t);
		return r && i.status >= 400 && i.status <= 499 && this.autoRefreshToken && (await this.refreshToken(t), this.sessionToken && n.searchParams.set("session", this.sessionToken), i = await fetch(n, t)), this.sessionToken === null && !this.isMapTilesSession ? i.json().then((e) => (this.sessionToken = s(e), e)) : i;
	}
	refreshToken(e) {
		if (this._tokenRefreshPromise === null) {
			let t = new URL(this.authURL);
			t.searchParams.set("key", this.apiToken);
			let n = { ...e };
			this.isMapTilesSession && (n.method = "POST", n.body = JSON.stringify(this.sessionOptions), n.headers = n.headers || {}, n.headers = {
				...n.headers,
				"Content-Type": "application/json"
			}), this._tokenRefreshPromise = fetch(t, n).then((e) => {
				if (!e.ok) throw Error(`GoogleCloudAuth: Failed to load data with error code ${e.status}`);
				return e.json();
			}).then((e) => (this.sessionToken = s(e), this._tokenRefreshPromise = null, e));
		}
		return this._tokenRefreshPromise;
	}
};
function s(e) {
	if ("session" in e) return e.session;
	{
		let t = null, n = e.root;
		return r(n, (e) => {
			if (e.content && e.content.uri) {
				let [, n] = e.content.uri.split("?");
				return t = new URLSearchParams(n).get("session"), !0;
			}
			return !1;
		}), t;
	}
}
//#endregion
//#region src/core/plugins/GoogleAttributionsManager.js
var c = class {
	constructor() {
		this.creditsCount = {};
	}
	_adjustAttributions(e, t) {
		let n = this.creditsCount, r = e.split(/;/g);
		for (let e = 0, i = r.length; e < i; e++) {
			let i = r[e];
			i in n || (n[i] = 0), n[i] += t ? 1 : -1, n[i] <= 0 && delete n[i];
		}
	}
	addAttributions(e) {
		this._adjustAttributions(e, !0);
	}
	removeAttributions(e) {
		this._adjustAttributions(e, !1);
	}
	toString() {
		return Object.entries(this.creditsCount).sort((e, t) => {
			let n = e[1];
			return t[1] - n;
		}).map((e) => e[0]).join("; ");
	}
}, l = "https://tile.googleapis.com/v1/3dtiles/root.json", u = class {
	constructor({ apiToken: e, sessionOptions: t = null, autoRefreshToken: n = !1, logoUrl: r = null, useRecommendedSettings: i = !0 }) {
		this.name = "GOOGLE_CLOUD_AUTH_PLUGIN", this.apiToken = e, this.useRecommendedSettings = i, this.logoUrl = r, this.auth = new o({
			apiToken: e,
			autoRefreshToken: n,
			sessionOptions: t
		}), this.tiles = null, this._visibilityChangeCallback = null, this._attributionsManager = new c(), this._logoAttribution = {
			value: "",
			type: "image",
			collapsible: !1
		}, this._attribution = {
			value: "",
			type: "string",
			collapsible: !0
		};
	}
	init(e) {
		let { useRecommendedSettings: t, auth: n } = this;
		e.resetFailedTiles(), e.rootURL ??= l, n.sessionOptions || (n.authURL = e.rootURL), t && !n.isMapTilesSession && (e.errorTarget = 20), this.tiles = e, this._visibilityChangeCallback = ({ tile: e, visible: t }) => {
			let n = e.engineData.metadata?.asset?.copyright || "";
			t ? this._attributionsManager.addAttributions(n) : this._attributionsManager.removeAttributions(n);
		}, e.addEventListener("tile-visibility-change", this._visibilityChangeCallback);
	}
	getAttributions(e) {
		this.tiles.visibleTiles.size > 0 && (this.logoUrl && (this._logoAttribution.value = this.logoUrl, e.push(this._logoAttribution)), this._attribution.value = this._attributionsManager.toString(), e.push(this._attribution));
	}
	dispose() {
		this.tiles.removeEventListener("tile-visibility-change", this._visibilityChangeCallback);
	}
	async fetchData(e, t) {
		return this.auth.fetch(e, t);
	}
}, d = class {
	get apiToken() {
		return this.auth.apiToken;
	}
	set apiToken(e) {
		this.auth.apiToken = e;
	}
	get autoRefreshToken() {
		return this.auth.autoRefreshToken;
	}
	set autoRefreshToken(e) {
		this.auth.autoRefreshToken = e;
	}
	constructor(e = {}) {
		let { apiToken: t, assetId: n = null, autoRefreshToken: r = !1, useRecommendedSettings: a = !0, assetTypeHandler: o = (e, t, n) => {
			console.warn(`CesiumIonAuthPlugin: Cesium Ion asset type "${e}" unhandled.`);
		} } = e;
		this.name = "CESIUM_ION_AUTH_PLUGIN", this.auth = new i({
			apiToken: t,
			autoRefreshToken: r
		}), this.assetId = n, this.autoRefreshToken = r, this.useRecommendedSettings = a, this.assetTypeHandler = o, this.tiles = null, this._tileSetVersion = -1, this._attributions = [];
	}
	init(e) {
		this.assetId !== null && (e.rootURL = `https://api.cesium.com/v1/assets/${this.assetId}/endpoint`), this.tiles = e, this.auth.authURL = e.rootURL, e.resetFailedTiles();
	}
	loadRootTileset() {
		return this.auth.refreshToken().then((e) => (this._initializeFromAsset(e), this.tiles.invokeOnePlugin((e) => e !== this && e.loadRootTileset && e.loadRootTileset()))).catch((e) => {
			this.tiles.dispatchEvent({
				type: "load-error",
				tile: null,
				error: e,
				url: this.auth.authURL
			});
		});
	}
	preprocessURL(e) {
		return e = new URL(e), /^http/.test(e.protocol) && this._tileSetVersion != -1 && e.searchParams.set("v", this._tileSetVersion), e.toString();
	}
	fetchData(e, t) {
		return this.tiles.getPluginByName("GOOGLE_CLOUD_AUTH_PLUGIN") === null ? this.auth.fetch(e, t) : null;
	}
	getAttributions(e) {
		this.tiles.visibleTiles.size > 0 && e.push(...this._attributions);
	}
	_initializeFromAsset(e) {
		let t = this.tiles;
		if ("externalType" in e) {
			let n = new URL(e.options.url);
			t.rootURL = e.options.url, t.registerPlugin(new u({
				apiToken: n.searchParams.get("key"),
				autoRefreshToken: this.autoRefreshToken,
				useRecommendedSettings: this.useRecommendedSettings
			}));
		} else {
			e.type !== "3DTILES" && this.assetTypeHandler(e.type, t, e), t.rootURL = e.url;
			let n = new URL(e.url);
			n.searchParams.has("v") && this._tileSetVersion === -1 && (this._tileSetVersion = n.searchParams.get("v")), e.attributions && (this._attributions = e.attributions.map((e) => ({
				value: e.html,
				type: "html",
				collapsible: e.collapsible
			})));
		}
	}
};
//#endregion
//#region src/core/plugins/SUBTREELoader.js
function f(e) {
	return e.implicitTilingData.root.implicitTiling.subdivisionScheme === "OCTREE";
}
function p(e) {
	return f(e) ? 8 : 4;
}
function m(e, t) {
	if (!e) return [
		0,
		0,
		0
	];
	let n = e.implicitTilingData.x, r = e.implicitTilingData.y, i = e.implicitTilingData.z;
	return [
		2 * n + t % 2,
		2 * r + Math.floor(t / 2) % 2,
		f(e) ? 2 * i + Math.floor(t / 4) % 2 : 0
	];
}
var h = class {
	constructor(e, t) {
		this.parent = e, this.children = [], this.geometricError = 0, this.boundingVolume = null;
		let [n, r, i] = m(e, t);
		this.implicitTilingData = {
			level: e.implicitTilingData.level + 1,
			root: e.implicitTilingData.root,
			subtreeIdx: t,
			x: n,
			y: r,
			z: i
		};
	}
	static clone(e) {
		return {
			parent: e.parent,
			children: [],
			geometricError: e.geometricError,
			boundingVolume: e.boundingVolume,
			implicitTilingData: { ...e.implicitTilingData }
		};
	}
}, g = class extends e {
	constructor(e) {
		super(), this.tile = e, this.rootTile = e.implicitTilingData.root, this.workingPath = null;
	}
	parseBuffer(e) {
		let r = new DataView(e), i = 0, a = t(r);
		console.assert(a === "subt", "SUBTREELoader: The magic bytes equal \"subt\"."), i += 4;
		let o = r.getUint32(i, !0);
		console.assert(o === 1, "SUBTREELoader: The version listed in the header is \"1\"."), i += 4;
		let s = r.getUint32(i, !0);
		i += 8;
		let c = r.getUint32(i, !0);
		i += 8;
		let l = JSON.parse(n(new Uint8Array(e, i, s)));
		return i += s, {
			version: o,
			subtreeJson: l,
			subtreeByte: e.slice(i, i + c)
		};
	}
	async parse(e) {
		let t = this.parseBuffer(e), n = t.subtreeJson;
		n.contentAvailabilityHeaders = [].concat(n.contentAvailability);
		let r = this.preprocessBuffers(n.buffers), i = this.preprocessBufferViews(n.bufferViews, r);
		this.markActiveBufferViews(n, i);
		let a = await this.requestActiveBuffers(r, t.subtreeByte), o = this.parseActiveBufferViews(i, a);
		this.parseAvailability(t, n, o), this.expandSubtree(this.tile, t);
	}
	markActiveBufferViews(e, t) {
		let n, r = e.tileAvailability;
		isNaN(r.bitstream) ? isNaN(r.bufferView) || (n = t[r.bufferView]) : n = t[r.bitstream], n && (n.isActive = !0, n.bufferHeader.isActive = !0);
		let i = e.contentAvailabilityHeaders;
		for (let e = 0; e < i.length; e++) n = void 0, isNaN(i[e].bitstream) ? isNaN(i[e].bufferView) || (n = t[i[e].bufferView]) : n = t[i[e].bitstream], n && (n.isActive = !0, n.bufferHeader.isActive = !0);
		n = void 0;
		let a = e.childSubtreeAvailability;
		isNaN(a.bitstream) ? isNaN(a.bufferView) || (n = t[a.bufferView]) : n = t[a.bitstream], n && (n.isActive = !0, n.bufferHeader.isActive = !0);
	}
	async requestActiveBuffers(e, t) {
		let n = [];
		for (let r = 0; r < e.length; r++) {
			let i = e[r];
			if (!i.isActive) n.push(Promise.resolve());
			else if (i.isExternal) {
				let e = this.parseImplicitURIBuffer(this.tile, this.rootTile.implicitTiling.subtrees.uri, i.uri), t = fetch(e, this.fetchOptions).then((e) => {
					if (!e.ok) throw Error(`SUBTREELoader: Failed to load external buffer from ${i.uri} with error code ${e.status}.`);
					return e.arrayBuffer();
				}).then((e) => new Uint8Array(e));
				n.push(t);
			} else n.push(Promise.resolve(new Uint8Array(t)));
		}
		let r = await Promise.all(n), i = {};
		for (let e = 0; e < r.length; e++) {
			let t = r[e];
			t && (i[e] = t);
		}
		return i;
	}
	parseActiveBufferViews(e, t) {
		let n = {};
		for (let r = 0; r < e.length; r++) {
			let i = e[r];
			if (!i.isActive) continue;
			let a = i.byteOffset, o = a + i.byteLength;
			n[r] = t[i.buffer].slice(a, o);
		}
		return n;
	}
	preprocessBuffers(e = []) {
		for (let t = 0; t < e.length; t++) {
			let n = e[t];
			n.isActive = !1, n.isExternal = !!n.uri;
		}
		return e;
	}
	preprocessBufferViews(e = [], t) {
		for (let n = 0; n < e.length; n++) {
			let r = e[n];
			r.bufferHeader = t[r.buffer], r.isActive = !1, r.isExternal = r.bufferHeader.isExternal;
		}
		return e;
	}
	parseAvailability(e, t, n) {
		let r = p(this.rootTile), i = this.rootTile.implicitTiling.subtreeLevels, a = (r ** +i - 1) / (r - 1), o = r ** +i;
		e._tileAvailability = this.parseAvailabilityBitstream(t.tileAvailability, n, a), e._contentAvailabilityBitstreams = [];
		for (let r = 0; r < t.contentAvailabilityHeaders.length; r++) {
			let i = this.parseAvailabilityBitstream(t.contentAvailabilityHeaders[r], n, a);
			e._contentAvailabilityBitstreams.push(i);
		}
		e._childSubtreeAvailability = this.parseAvailabilityBitstream(t.childSubtreeAvailability, n, o);
	}
	parseAvailabilityBitstream(e, t, n) {
		if (!isNaN(e.constant)) return {
			constant: !!e.constant,
			lengthBits: n
		};
		let r;
		return isNaN(e.bitstream) ? isNaN(e.bufferView) || (r = t[e.bufferView]) : r = t[e.bitstream], {
			bitstream: r,
			lengthBits: n
		};
	}
	expandSubtree(e, t) {
		let n = h.clone(e);
		for (let r = 0; t && r < t._contentAvailabilityBitstreams.length; r++) if (t && this.getBit(t._contentAvailabilityBitstreams[r], 0)) {
			n.content = { uri: this.parseImplicitURI(e, this.rootTile.content.uri) };
			break;
		}
		e.children.push(n);
		let r = this.transcodeSubtreeTiles(n, t), i = this.listChildSubtrees(t, r);
		for (let e = 0; e < i.length; e++) {
			let t = i[e], n = t.tile, r = this.deriveChildTile(null, n, null, t.childMortonIndex);
			r.content = { uri: this.parseImplicitURI(r, this.rootTile.implicitTiling.subtrees.uri) }, n.children.push(r);
		}
	}
	transcodeSubtreeTiles(e, t) {
		let n = [e], r = [];
		for (let e = 1; e < this.rootTile.implicitTiling.subtreeLevels; e++) {
			let i = p(this.rootTile), a = (i ** +e - 1) / (i - 1), o = i * n.length;
			for (let e = 0; e < o; e++) {
				let o = a + e, s = e >> Math.log2(i), c = n[s];
				if (!this.getBit(t._tileAvailability, o)) {
					r.push(void 0);
					continue;
				}
				let l = this.deriveChildTile(t, c, o, e);
				c.children.push(l), r.push(l);
			}
			n = r, r = [];
		}
		return n;
	}
	deriveChildTile(e, t, n, r) {
		let i = new h(t, r);
		i.boundingVolume = this.getTileBoundingVolume(i), i.geometricError = this.getGeometricError(i);
		for (let t = 0; e && t < e._contentAvailabilityBitstreams.length; t++) if (e && this.getBit(e._contentAvailabilityBitstreams[t], n)) {
			i.content = { uri: this.parseImplicitURI(i, this.rootTile.content.uri) };
			break;
		}
		return i;
	}
	getBit(e, t) {
		if (t < 0 || t >= e.lengthBits) throw Error("Bit index out of bounds.");
		if (e.constant !== void 0) return e.constant;
		let n = t >> 3, r = t % 8;
		return (new Uint8Array(e.bitstream)[n] >> r & 1) == 1;
	}
	getTileBoundingVolume(e) {
		let t = {};
		if (this.rootTile.boundingVolume.region) {
			let n = [...this.rootTile.boundingVolume.region], r = n[0], i = n[2], a = n[1], o = n[3], s = (i - r) / 2 ** e.implicitTilingData.level, c = (o - a) / 2 ** e.implicitTilingData.level;
			n[0] = r + s * e.implicitTilingData.x, n[2] = r + s * (e.implicitTilingData.x + 1), n[1] = a + c * e.implicitTilingData.y, n[3] = a + c * (e.implicitTilingData.y + 1);
			for (let e = 0; e < 4; e++) {
				let t = n[e];
				t < -Math.PI ? n[e] += 2 * Math.PI : t > Math.PI && (n[e] -= 2 * Math.PI);
			}
			if (f(e)) {
				let t = n[4], r = (n[5] - t) / 2 ** e.implicitTilingData.level;
				n[4] = t + r * e.implicitTilingData.z, n[5] = t + r * (e.implicitTilingData.z + 1);
			}
			t.region = n;
		}
		if (this.rootTile.boundingVolume.box) {
			let n = [...this.rootTile.boundingVolume.box], r = 2 ** e.implicitTilingData.level - 1, i = 2 ** -e.implicitTilingData.level, a = f(e) ? 3 : 2;
			for (let t = 0; t < a; t++) {
				n[3 + t * 3 + 0] *= i, n[3 + t * 3 + 1] *= i, n[3 + t * 3 + 2] *= i;
				let a = n[3 + t * 3 + 0], o = n[3 + t * 3 + 1], s = n[3 + t * 3 + 2], c = t === 0 ? e.implicitTilingData.x : t === 1 ? e.implicitTilingData.y : e.implicitTilingData.z;
				n[0] += 2 * a * (-.5 * r + c), n[1] += 2 * o * (-.5 * r + c), n[2] += 2 * s * (-.5 * r + c);
			}
			t.box = n;
		}
		return t;
	}
	getGeometricError(e) {
		return this.rootTile.geometricError / 2 ** e.implicitTilingData.level;
	}
	listChildSubtrees(e, t) {
		let n = [], r = p(this.rootTile);
		for (let i = 0; i < t.length; i++) {
			let a = t[i];
			if (a !== void 0) for (let t = 0; t < r; t++) {
				let o = i * r + t;
				this.getBit(e._childSubtreeAvailability, o) && n.push({
					tile: a,
					childMortonIndex: o
				});
			}
		}
		return n;
	}
	parseImplicitURI(e, t) {
		return t = t.replace("{level}", e.implicitTilingData.level), t = t.replace("{x}", e.implicitTilingData.x), t = t.replace("{y}", e.implicitTilingData.y), t = t.replace("{z}", e.implicitTilingData.z), t;
	}
	parseImplicitURIBuffer(e, t, n) {
		let r = this.parseImplicitURI(e, t), i = new URL(r, this.workingPath + "/");
		return i.pathname = i.pathname.substring(0, i.pathname.lastIndexOf("/")), new URL(i.pathname + "/" + n, this.workingPath + "/").toString();
	}
}, _ = class {
	constructor() {
		this.name = "IMPLICIT_TILING_PLUGIN";
	}
	init(e) {
		this.tiles = e;
	}
	preprocessNode(e, t, n) {
		e.implicitTiling ? (e.internal.hasUnrenderableContent = !0, e.internal.hasRenderableContent = !1, e.implicitTilingData = {
			root: e,
			subtreeIdx: 0,
			x: 0,
			y: 0,
			z: 0,
			level: 0
		}) : /.subtree$/i.test(e.content?.uri) && (e.internal.hasUnrenderableContent = !0, e.internal.hasRenderableContent = !1);
	}
	parseTile(e, t, n) {
		if (/^subtree$/i.test(n)) {
			let n = new g(t);
			return n.workingPath = t.internal.basePath, n.fetchOptions = this.tiles.fetchOptions, n.parse(e);
		}
	}
	preprocessURL(e, t) {
		if (t && t.implicitTiling) {
			let e = t.implicitTiling.subtrees.uri.replace("{level}", t.implicitTilingData.level).replace("{x}", t.implicitTilingData.x).replace("{y}", t.implicitTilingData.y).replace("{z}", t.implicitTilingData.z);
			return new URL(e, t.internal.basePath + "/").toString();
		}
		return e;
	}
	disposeTile(e) {
		/.subtree$/i.test(e.content?.uri) && (e.children.forEach((e) => {
			this.tiles.processNodeQueue.remove(e);
		}), e.children.length = 0);
	}
}, v = class {
	constructor() {
		this.name = "ENFORCE_NONZERO_ERROR", this.priority = -Infinity, this.originalError = /* @__PURE__ */ new Map();
	}
	preprocessNode(e) {
		if (e.geometricError === 0) {
			let t = e.parent, n = 1;
			for (; t !== null;) {
				if (t.geometricError !== 0) {
					e.geometricError = t.geometricError * 2 ** -n;
					break;
				}
				t = t.parent, n++;
			}
		}
	}
};
//#endregion
//#region src/core/plugins/loaders/QuantizedMeshLoaderBase.js
function y(e) {
	return e >> 1 ^ -(e & 1);
}
var b = class extends e {
	constructor(...e) {
		super(...e), this.fetchOptions.header = { Accept: "application/vnd.quantized-mesh,application/octet-stream;q=0.9" };
	}
	loadAsync(...e) {
		let { fetchOptions: t } = this;
		return t.header = t.header || {}, t.header.Accept = "application/vnd.quantized-mesh,application/octet-stream;q=0.9", t.header.Accept += ";extensions=octvertexnormals-watermask-metadata", super.loadAsync(...e);
	}
	parse(e) {
		let t = 0, n = new DataView(e), r = () => {
			let e = n.getFloat64(t, !0);
			return t += 8, e;
		}, i = () => {
			let e = n.getFloat32(t, !0);
			return t += 4, e;
		}, a = () => {
			let e = n.getUint32(t, !0);
			return t += 4, e;
		}, o = () => {
			let e = n.getUint8(t);
			return t += 1, e;
		}, s = (n, r) => {
			let i = new r(e, t, n);
			return t += n * r.BYTES_PER_ELEMENT, i;
		}, c = {
			center: [
				r(),
				r(),
				r()
			],
			minHeight: i(),
			maxHeight: i(),
			sphereCenter: [
				r(),
				r(),
				r()
			],
			sphereRadius: r(),
			horizonOcclusionPoint: [
				r(),
				r(),
				r()
			]
		}, l = a(), u = s(l, Uint16Array), d = s(l, Uint16Array), f = s(l, Uint16Array), p = new Float32Array(l), m = new Float32Array(l), h = new Float32Array(l), g = 0, _ = 0, v = 0, b = 32767;
		for (let e = 0; e < l; ++e) g += y(u[e]), _ += y(d[e]), v += y(f[e]), p[e] = g / b, m[e] = _ / b, h[e] = v / b;
		let S = l > 65536, C = S ? Uint32Array : Uint16Array;
		t = S ? Math.ceil(t / 4) * 4 : Math.ceil(t / 2) * 2;
		let w = s(a() * 3, C), T = 0;
		for (var E = 0; E < w.length; ++E) {
			let e = w[E];
			w[E] = T - e, e === 0 && ++T;
		}
		let D = (e, t) => m[t] - m[e], O = (e, t) => -D(e, t), k = (e, t) => p[e] - p[t], A = (e, t) => -k(e, t), j = s(a(), C);
		j.sort(D);
		let M = s(a(), C);
		M.sort(k);
		let N = s(a(), C);
		N.sort(O);
		let P = s(a(), C);
		P.sort(A);
		let F = {
			westIndices: j,
			southIndices: M,
			eastIndices: N,
			northIndices: P
		}, I = {};
		for (; t < n.byteLength;) {
			let e = o(), t = a();
			if (e === 1) {
				let t = s(l * 2, Uint8Array), n = new Float32Array(l * 3);
				for (let e = 0; e < l; e++) {
					let r = t[2 * e + 0] / 255 * 2 - 1, i = t[2 * e + 1] / 255 * 2 - 1, a = 1 - (Math.abs(r) + Math.abs(i));
					if (a < 0) {
						let e = r;
						r = (1 - Math.abs(i)) * x(e), i = (1 - Math.abs(e)) * x(i);
					}
					let o = Math.sqrt(r * r + i * i + a * a);
					n[3 * e + 0] = r / o, n[3 * e + 1] = i / o, n[3 * e + 2] = a / o;
				}
				I.octvertexnormals = {
					extensionId: e,
					normals: n
				};
			} else if (e === 2) {
				let n = t === 1 ? 1 : 256;
				I.watermask = {
					extensionId: e,
					mask: s(n * n, Uint8Array),
					size: n
				};
			} else if (e === 4) {
				let t = s(a(), Uint8Array), n = new TextDecoder().decode(t);
				I.metadata = {
					extensionId: e,
					json: JSON.parse(n)
				};
			}
		}
		return {
			header: c,
			indices: w,
			vertexData: {
				u: p,
				v: m,
				height: h
			},
			edgeIndices: F,
			extensions: I
		};
	}
};
function x(e) {
	return e < 0 ? -1 : 1;
}
//#endregion
export { u as a, d as i, v as n, o, _ as r, i as s, b as t };

//# sourceMappingURL=plugins-BN2uUf5f.js.map