#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include "object.h"
#include "ray.h"

class Camera : public Object {
public:
    virtual ~Camera()=default;

    virtual Ray& makeRay(const glm::vec2& point) const = 0;
};


class PerspectiveCamera : public Camera {
public:
    glm::vec3 forward, up, right;
    float w, h;
    float fov, aspect;

    PerspectiveCamera();
    PerspectiveCamera(const glm::vec3& position, const glm::vec3& forward, const glm::vec3& up, float fov, float aspect);

    Ray& makeRay(const glm::vec2& point) const;

    inline Transform* getTransform() {
        return &transform;
    }
};