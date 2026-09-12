import * as THREE from 'three';
import { uvToWgs84, computeSlopeAngle, DEFAULT_GEO_BOUNDS } from './geoUtils.js';

/**
 * TerrainRaycaster - WebGIS Three.js Raycaster & 3D Pulsing Pin Manager
 * Handles pointerdown intersections, WGS84 coordinate projection, slope analysis,
 * and 3D animated pin drop.
 */
export class TerrainRaycaster {
  constructor(options = {}) {
    const {
      scene,
      camera,
      domElement,
      getTerrainMesh = () => null,
      onInspect = () => {},
      onDeselect = () => {},
      geoBounds = DEFAULT_GEO_BOUNDS
    } = options;

    this.scene = scene;
    this.camera = camera;
    this.domElement = domElement;
    this.getTerrainMesh = getTerrainMesh;
    this.onInspect = onInspect;
    this.onDeselect = onDeselect;
    this.geoBounds = { ...DEFAULT_GEO_BOUNDS, ...geoBounds };

    this.raycaster = new THREE.Raycaster();
    this.pointer = new THREE.Vector2();
    this.pointerDownPos = { x: 0, y: 0, time: 0 };
    this.pinGroup = null;
    this.pulseRings = [];
    this.pulseTime = 0;
    this.isEnabled = true;

    this.initPinGeometry();
    this.bindEvents();
  }

  /**
   * Constructs the 3D Pulsing Cyan Pin assembly
   */
  initPinGeometry() {
    this.pinGroup = new THREE.Group();
    this.pinGroup.name = 'ElevationInspectorPin';
    this.pinGroup.visible = false;

    // 1. Vertical Stem / Tapered Needle (Points tip downwards at contact point)
    const coneHeight = 6.0;
    const coneRadius = 0.9;
    const coneGeo = new THREE.ConeGeometry(coneRadius, coneHeight, 16);
    coneGeo.rotateX(Math.PI); // Tip at bottom
    coneGeo.translate(0, coneHeight / 2, 0);

    const cyanMat = new THREE.MeshStandardMaterial({
      color: 0x06b6d4,
      emissive: 0x00f0ff,
      emissiveIntensity: 0.8,
      roughness: 0.2,
      metalness: 0.8
    });

    const stemMesh = new THREE.Mesh(coneGeo, cyanMat);
    this.pinGroup.add(stemMesh);

    // 2. Spherical Pinhead
    const sphereRadius = 1.3;
    const sphereGeo = new THREE.SphereGeometry(sphereRadius, 20, 20);
    const sphereMat = new THREE.MeshStandardMaterial({
      color: 0x22d3ee,
      emissive: 0x06b6d4,
      emissiveIntensity: 1.2,
      roughness: 0.1,
      metalness: 0.5
    });

    const headMesh = new THREE.Mesh(sphereGeo, sphereMat);
    headMesh.position.y = coneHeight + sphereRadius * 0.7;
    this.pinGroup.add(headMesh);

    // 3. Ground Ripple Pulsing Rings (Concentric wave ripples)
    const ringGeo1 = new THREE.RingGeometry(0.8, 1.2, 32);
    ringGeo1.rotateX(-Math.PI / 2); // Flat on ground
    const ringMat1 = new THREE.MeshBasicMaterial({
      color: 0x00f0ff,
      transparent: true,
      opacity: 0.85,
      side: THREE.DoubleSide,
      depthWrite: false
    });
    const ring1 = new THREE.Mesh(ringGeo1, ringMat1);
    ring1.position.y = 0.05;
    this.pinGroup.add(ring1);

    const ringGeo2 = new THREE.RingGeometry(1.6, 2.0, 32);
    ringGeo2.rotateX(-Math.PI / 2);
    const ringMat2 = new THREE.MeshBasicMaterial({
      color: 0x38bdf8,
      transparent: true,
      opacity: 0.6,
      side: THREE.DoubleSide,
      depthWrite: false
    });
    const ring2 = new THREE.Mesh(ringGeo2, ringMat2);
    ring2.position.y = 0.04;
    this.pinGroup.add(ring2);

    this.pulseRings = [
      { mesh: ring1, baseRadius: 1.0, speed: 2.2, phase: 0.0 },
      { mesh: ring2, baseRadius: 2.0, speed: 2.2, phase: Math.PI }
    ];

    if (this.scene) {
      this.scene.add(this.pinGroup);
    }
  }

  /**
   * Pointer down event handling to distinguish true click vs camera drag
   */
  bindEvents() {
    if (!this.domElement) return;

    this.onPointerDown = (e) => {
      if (e.button !== 0) return; // Only primary mouse button
      this.pointerDownPos = {
        x: e.clientX,
        y: e.clientY,
        time: performance.now()
      };
    };

    this.onPointerUp = (e) => {
      if (e.button !== 0 || !this.isEnabled) return;

      const dx = Math.abs(e.clientX - this.pointerDownPos.x);
      const dy = Math.abs(e.clientY - this.pointerDownPos.y);
      const dt = performance.now() - this.pointerDownPos.time;

      // Filter out camera drag/rotation (movement threshold < 6px and duration < 500ms)
      if (dx < 6 && dy < 6 && dt < 500) {
        this.performRaycast(e);
      }
    };

    this.domElement.addEventListener('pointerdown', this.onPointerDown);
    this.domElement.addEventListener('pointerup', this.onPointerUp);
  }

  /**
   * Raycast against terrain mesh and calculate inspection metrics
   */
  performRaycast(event) {
    const rect = this.domElement.getBoundingClientRect();
    this.pointer.x = ((event.clientX - rect.left) / rect.width) * 2 - 1;
    this.pointer.y = -((event.clientY - rect.top) / rect.height) * 2 + 1;

    this.raycaster.setFromCamera(this.pointer, this.camera);

    const terrain = this.getTerrainMesh();
    if (!terrain) return null;

    const intersects = this.raycaster.intersectObject(terrain, true);
    if (intersects.length === 0) {
      if (this.onDeselect) {
        this.onDeselect();
      }
      return null;
    }

    const hit = intersects[0];
    const hitPoint = hit.point;

    // 1. Extract Normal & Compute Slope Angle
    let normal = new THREE.Vector3(0, 1, 0);
    if (hit.face && hit.face.normal) {
      normal.copy(hit.face.normal);
      // Transform normal into world space
      if (hit.object) {
        normal.transformDirection(hit.object.matrixWorld);
      }
    }
    const slopeAngle = computeSlopeAngle(normal);

    // 2. Compute UV and Map to WGS84 (minLat, maxLat, minLon, maxLon)
    let u = 0.5;
    let v = 0.5;

    if (hit.uv) {
      u = hit.uv.x;
      v = hit.uv.y;
    } else {
      // Fallback: derive normalized coordinates from bounding box
      const box = new THREE.Box3().setFromObject(terrain);
      const size = box.getSize(new THREE.Vector3());
      if (size.x > 0 && size.z > 0) {
        u = (hitPoint.x - box.min.x) / size.x;
        // Invert Z for geographic North
        v = 1.0 - ((hitPoint.z - box.min.z) / size.z);
      }
    }

    const { lat, lon } = uvToWgs84(u, v, this.geoBounds);

    // 3. Absolute Elevation (m MSL)
    // Scale mesh Y coordinate relative to base elevation
    const elevation = this.geoBounds.baseElevationMsl + (hitPoint.y * this.geoBounds.elevationScale);

    // 4. Eye Altitude & Target Range
    const eyeAltitude = Math.max(this.camera.position.y, 0) * this.geoBounds.elevationScale;
    const targetRange = this.camera.position.distanceTo(hitPoint) * this.geoBounds.elevationScale;

    // 5. Place and show pulsing cyan pin
    this.placePin(hitPoint);

    const inspectionData = {
      latitude: lat,
      longitude: lon,
      elevation: elevation,
      slopeAngle: slopeAngle,
      eyeAltitude: eyeAltitude,
      targetRange: targetRange,
      worldPoint: hitPoint.clone(),
      normal: normal.clone(),
      uv: { u, v },
      timestamp: new Date().toISOString()
    };

    if (this.onInspect) {
      this.onInspect(inspectionData);
    }

    return inspectionData;
  }

  /**
   * Places the 3D pin at target coordinate
   */
  placePin(position) {
    if (!this.pinGroup) return;
    this.pinGroup.position.copy(position);
    this.pinGroup.visible = true;
  }

  /**
   * Hides the inspection pin
   */
  hidePin() {
    if (this.pinGroup) {
      this.pinGroup.visible = false;
    }
  }

  /**
   * Animation update tick called from main Three.js render loop.
   * Animates the pulsing cyan ground ripples.
   */
  update(delta = 0.016) {
    if (!this.pinGroup || !this.pinGroup.visible) return;

    this.pulseTime += delta * 3.0;

    this.pulseRings.forEach((ring, idx) => {
      // Periodic expansion and opacity fade
      const progress = (this.pulseTime + ring.phase) % (Math.PI * 2);
      const normProgress = progress / (Math.PI * 2); // 0 to 1

      const scale = 1.0 + normProgress * 2.2;
      ring.mesh.scale.set(scale, scale, 1);

      if (ring.mesh.material) {
        ring.mesh.material.opacity = Math.max(0, (1.0 - normProgress) * 0.85);
      }
    });
  }

  dispose() {
    if (this.domElement) {
      this.domElement.removeEventListener('pointerdown', this.onPointerDown);
      this.domElement.removeEventListener('pointerup', this.onPointerUp);
    }
    if (this.pinGroup && this.scene) {
      this.scene.remove(this.pinGroup);
    }
  }
}
