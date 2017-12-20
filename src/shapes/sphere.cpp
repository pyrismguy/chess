#include "shape.h"
#include <glm/geometric.hpp>


Intersection::Intersection(const Intersection &i)
        : ray(i.ray),
          t(i.t),
          pShape(i.pShape)
{

}

Intersection::Intersection(const Ray &ray)
        : ray(ray),
        t(ray.tMax),
        pShape(nullptr)
{

}

Intersection::~Intersection() {

}


bool Intersection::intersected() const {
    return (pShape != nullptr);
}

glm::vec3 Intersection::position() const {
    return ray.calculate(t);
}


bool Sphere::intersect(const glm::vec3 &point) const {
    return this->distance(point) < radius;
}

float Sphere::distance(const glm::vec3 &point) const {
    return glm::length(point - center) - radius;
}

glm::vec3 &Sphere::normal(const glm::vec3 &point) const {
    glm::normalize(point - center);
}
