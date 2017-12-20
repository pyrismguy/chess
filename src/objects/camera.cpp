#include "camera.h"

PerspectiveCamera::PerspectiveCamera(const Transform &transform, const glm::vec3 &forward, const glm::vec3 &up, float fov, float aspect)
        : Camera(transform),
          forward(glm::normalize(forward)), up(glm::normalize(up)), fov(fov), aspect(aspect) {

    right = glm::normalize(glm::cross(forward, up));
    h = tanf(fov);
    w = h * aspect;
}

Ray& PerspectiveCamera::makeRay(const glm::vec2& point) const {
    glm::vec3 direction = forward + point.x * w * right + point.y * h * up;
    Ray* pr = new Ray(transform.getPos(), glm::normalize(direction), RAY_T_MAX);
    return *pr;
}
