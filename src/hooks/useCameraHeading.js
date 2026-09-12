'use client';

import { useState, useEffect, useCallback, useRef } from 'react';
import * as THREE from 'three';

/**
 * Smoothly reset the camera azimuth to True North (heading = 0°),
 * preserving active camera distance and tilt pitch relative to controls.target.
 *
 * @param {THREE.Camera} camera
 * @param {import('three/examples/jsm/controls/OrbitControls.js').OrbitControls} controls
 * @param {Function} [onComplete]
 * @param {number} [duration=400]
 */
export function resetCameraToNorth(camera, controls, onComplete, duration = 400) {
  if (!camera || !controls) return;

  const target = controls.target || new THREE.Vector3(0, 0, 0);
  const offset = new THREE.Vector3().subVectors(camera.position, target);

  // Horizontal radius in the X-Z plane
  const horizontalRadius = Math.sqrt(offset.x * offset.x + offset.z * offset.z);
  const currentY = offset.y;

  // Heading 0° (looking towards -Z / North) places the camera at +Z relative to target
  const startPos = camera.position.clone();
  const safeRadius = horizontalRadius > 0.001 ? horizontalRadius : 10;
  const endPos = new THREE.Vector3(
    target.x,
    target.y + currentY,
    target.z + safeRadius
  );

  const startTime = performance.now();

  function step(now) {
    const elapsed = now - startTime;
    const progress = Math.min(1, elapsed / duration);
    // Smooth cubic ease-out curve
    const ease = 1 - Math.pow(1 - progress, 3);

    camera.position.lerpVectors(startPos, endPos, ease);
    controls.update();

    if (progress < 1) {
      requestAnimationFrame(step);
    } else {
      camera.position.copy(endPos);
      controls.update();
      if (typeof onComplete === 'function') {
        onComplete();
      }
    }
  }

  requestAnimationFrame(step);
}

/**
 * Smoothly snap the camera to predetermined WebGIS views:
 * - 'top': 90° plan/overhead view
 * - 'perspective': 3D isometric oblique view
 * - 'front': Elevation view looking North
 * - 'right': Elevation view looking West
 * - 'reset': Default framing
 *
 * @param {THREE.Camera} camera
 * @param {import('three/examples/jsm/controls/OrbitControls.js').OrbitControls} controls
 * @param {'top'|'perspective'|'front'|'right'|'reset'} viewType
 * @param {Function} [onComplete]
 * @param {number} [duration=450]
 */
export function snapCameraView(camera, controls, viewType, onComplete, duration = 450) {
  if (!camera || !controls) return;

  const target = controls.target || new THREE.Vector3(0, 0, 0);
  const distance = Math.max(camera.position.distanceTo(target), 30);
  const startPos = camera.position.clone();
  let endPos = new THREE.Vector3();

  switch (viewType) {
    case 'top':
      // Overhead looking down: slight Z offset prevents gimbal lock on up-vector
      endPos.set(target.x, target.y + distance, target.z + 0.001);
      break;
    case 'perspective':
      // 3D Oblique
      endPos.set(
        target.x + distance * 0.6,
        target.y + distance * 0.5,
        target.z + distance * 0.65
      );
      break;
    case 'front':
      // Looking directly North from South
      endPos.set(target.x, target.y + distance * 0.25, target.z + distance * 0.95);
      break;
    case 'right':
      // Looking directly West from East
      endPos.set(target.x + distance * 0.95, target.y + distance * 0.25, target.z);
      break;
    case 'reset':
    default:
      endPos.set(130, 100, 150);
      break;
  }

  const startTime = performance.now();

  function step(now) {
    const elapsed = now - startTime;
    const progress = Math.min(1, elapsed / duration);
    const ease = 1 - Math.pow(1 - progress, 3);

    camera.position.lerpVectors(startPos, endPos, ease);
    controls.update();

    if (progress < 1) {
      requestAnimationFrame(step);
    } else {
      camera.position.copy(endPos);
      controls.update();
      if (typeof onComplete === 'function') {
        onComplete();
      }
    }
  }

  requestAnimationFrame(step);
}

/**
 * Hook for Real-Time Camera Azimuth Calculation and True North Reset
 *
 * @param {THREE.Camera|null} camera
 * @param {import('three/examples/jsm/controls/OrbitControls.js').OrbitControls|null} controls
 * @returns {{
 *   heading: number,
 *   resetToNorth: () => void,
 *   snapView: (viewType: 'top'|'perspective'|'front'|'right'|'reset') => void,
 *   updateHeading: () => void
 * }}
 */
export function useCameraHeading(camera, controls) {
  const [heading, setHeading] = useState(0);
  const headingRef = useRef(0);

  // Exact azimuth calculation specified:
  // dir = camera.getWorldDirection(dir)
  // rad = Math.atan2(dir.x, -dir.z)
  // deg = (THREE.MathUtils.radToDeg(rad) + 360) % 360
  const updateHeading = useCallback(() => {
    if (!camera) return;

    const dir = new THREE.Vector3();
    camera.getWorldDirection(dir);

    const rad = Math.atan2(dir.x, -dir.z);
    const deg = (THREE.MathUtils.radToDeg(rad) + 360) % 360;
    const rounded = Math.round(deg);

    if (headingRef.current !== rounded) {
      headingRef.current = rounded;
      setHeading(rounded);
    }
  }, [camera]);

  // OrbitControls 'change' event listener
  useEffect(() => {
    if (!controls || !camera) return;

    updateHeading();

    const handleChange = () => {
      updateHeading();
    };

    controls.addEventListener('change', handleChange);

    return () => {
      controls.removeEventListener('change', handleChange);
    };
  }, [controls, camera, updateHeading]);

  // Click-to-Reset to True North
  const resetToNorth = useCallback(() => {
    if (!camera || !controls) return;
    resetCameraToNorth(camera, controls, updateHeading);
  }, [camera, controls, updateHeading]);

  // Snap to cardinal/isometric views
  const snapView = useCallback(
    (viewType) => {
      if (!camera || !controls) return;
      snapCameraView(camera, controls, viewType, updateHeading);
    },
    [camera, controls, updateHeading]
  );

  return {
    heading,
    resetToNorth,
    snapView,
    updateHeading
  };
}

export default useCameraHeading;
