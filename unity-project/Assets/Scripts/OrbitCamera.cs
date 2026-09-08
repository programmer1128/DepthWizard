using UnityEngine;

namespace UnityNextViewer
{
    [RequireComponent(typeof(Camera))]
    public class OrbitCamera : MonoBehaviour
    {
        [Header("Target & Distance")]
        public Transform target;
        public float distance = 5.0f;
        public float minDistance = 0.5f;
        public float maxDistance = 50.0f;

        [Header("Speed & Sensitivity")]
        public float xSpeed = 120.0f;
        public float ySpeed = 120.0f;
        public float zoomSpeed = 5.0f;
        public float smoothTime = 0.08f;

        [Header("Limits")]
        public float yMinLimit = -80f;
        public float yMaxLimit = 80f;

        private float currentX = 0.0f;
        private float currentY = 20.0f;
        private float targetX = 0.0f;
        private float targetY = 20.0f;

        private float currentDistance;
        private float targetDistance;

        private Vector3 xVelocity = Vector3.zero;
        private Vector3 currentTargetPos = Vector3.zero;
        private Vector3 targetTargetPos = Vector3.zero;

        private Vector3 lastMousePos;
        private Camera cam;

        private void Awake()
        {
            cam = GetComponent<Camera>();
            currentDistance = distance;
            targetDistance = distance;
            targetX = currentX;
            targetY = currentY;

            if (target != null)
            {
                currentTargetPos = target.position;
                targetTargetPos = target.position;
            }
        }

        private void LateUpdate()
        {
            HandleInput();
            UpdateCameraTransform();
        }

        private void HandleInput()
        {
            // Rotate on Left Click Drag
            if (Input.GetMouseButton(0))
            {
                targetX += Input.GetAxis("Mouse X") * xSpeed * 0.02f;
                targetY -= Input.GetAxis("Mouse Y") * ySpeed * 0.02f;
                targetY = ClampAngle(targetY, yMinLimit, yMaxLimit);
            }

            // Pan on Middle/Right Click Drag
            if (Input.GetMouseButton(1) || Input.GetMouseButton(2))
            {
                float panX = -Input.GetAxis("Mouse X") * (distance * 0.03f);
                float panY = -Input.GetAxis("Mouse Y") * (distance * 0.03f);
                Vector3 right = transform.right * panX;
                Vector3 up = transform.up * panY;
                targetTargetPos += right + up;
            }

            // Zoom on Scroll
            float scroll = Input.GetAxis("Mouse ScrollWheel");
            if (Mathf.Abs(scroll) > 0.001f)
            {
                targetDistance -= scroll * zoomSpeed * (targetDistance * 0.2f);
                targetDistance = Mathf.Clamp(targetDistance, minDistance, maxDistance);
            }
        }

        private void UpdateCameraTransform()
        {
            currentX = Mathf.Lerp(currentX, targetX, Time.deltaTime / smoothTime);
            currentY = Mathf.Lerp(currentY, targetY, Time.deltaTime / smoothTime);
            currentDistance = Mathf.Lerp(currentDistance, targetDistance, Time.deltaTime / smoothTime);
            currentTargetPos = Vector3.Lerp(currentTargetPos, targetTargetPos, Time.deltaTime / smoothTime);

            Quaternion rotation = Quaternion.Euler(currentY, currentX, 0);
            Vector3 position = rotation * new Vector3(0.0f, 0.0f, -currentDistance) + currentTargetPos;

            transform.rotation = rotation;
            transform.position = position;
        }

        public void FrameBounds(Bounds bounds)
        {
            targetTargetPos = bounds.center;
            currentTargetPos = bounds.center;

            float radius = bounds.extents.magnitude;
            if (radius < 0.001f) radius = 1.0f;

            float fov = cam != null ? cam.fieldOfView : 60f;
            float desiredDistance = (radius / Mathf.Sin(fov * 0.5f * Mathf.Deg2Rad)) * 1.25f;

            minDistance = Mathf.Max(0.1f, desiredDistance * 0.1f);
            maxDistance = desiredDistance * 10f;
            targetDistance = desiredDistance;
            currentDistance = desiredDistance;

            targetX = 45f;
            targetY = 20f;
            currentX = 45f;
            currentY = 20f;
        }

        public void ResetView()
        {
            targetX = 45f;
            targetY = 20f;
            targetTargetPos = target != null ? target.position : Vector3.zero;
        }

        private static float ClampAngle(float angle, float min, float max)
        {
            if (angle < -360F) angle += 360F;
            if (angle > 360F) angle -= 360F;
            return Mathf.Clamp(angle, min, max);
        }
    }
}
