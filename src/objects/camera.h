#pragma once

#include <glm/vec3.hpp>
#include <glm/vec2.hpp>

#include "object.h"
#include "../ray.h"

class Camera : public Object {
public:
    Camera(const Transform &t) : Object(t) {}
    virtual ~Camera()=default;

    virtual Ray &makeRay(const glm::vec2& point) const = 0;
};


class PerspectiveCamera : public Camera {
private:
    glm::vec3 forward, up, right;
    float w, h;
    float fov, aspect;

public:
    PerspectiveCamera();
    PerspectiveCamera(const Transform &transform, const glm::vec3& forward, const glm::vec3& up, float fov, float aspect);

    Ray &makeRay(const glm::vec2& point) const override;

    Transform& getTransform() {
        return transform;
    }

    void setAspect(float aspect){
        this->aspect = aspect;
        w = h * this->aspect;
    }

};