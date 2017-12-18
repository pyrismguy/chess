#include "ray.h"

Ray::Ray() : origin(glm::vec3(0.0f, 0.0f, 0.0f)),
        direction(glm::vec3(0.0f, 0.0f, -1.0f)),
        tMax(RAY_T_MAX) {

}

Ray::Ray(Ray &other) : origin(other.origin), direction(other.direction), tMax(other.tMax) {
}

Ray::Ray(const glm::vec3 &origin, const glm::vec3 &direction, float tMax)
        : origin(origin), direction(direction), tMax(tMax) {

}

glm::vec3 Ray::calculate(const float& t) const {
    return origin + direction * t;
}
