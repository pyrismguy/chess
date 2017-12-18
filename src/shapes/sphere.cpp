#include "shape.h"
#include <glm/geometric.hpp>

Sphere::Sphere() : center(glm::vec3(0.0f, 0.0f, 0.0f)), radius(1.0f) {

};

float Sphere::getDistance(const glm::vec3 &point) const {
    return glm::length(point - center) - radius;
}

bool Sphere::doesIntersect(const glm::vec3 &point) const {
    return this->getDistance(point) < radius;
}

glm::vec3 &Sphere::getNormal(const glm::vec3 &point) const {
    glm::normalize(point - center);
}