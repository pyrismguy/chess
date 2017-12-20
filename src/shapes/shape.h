#pragma once
#include <glm/vec3.hpp>

#include "../ray.h"

class Shape {
public:
    virtual bool intersect(const glm::vec3 &point) const = 0;

    /*
     * This "getDistance" function needs to returns the distance from a point to the surface of the shape.
       Do not confuse this with distance from the center of the object.
     */
    virtual float distance(const glm::vec3 &point) const = 0;

    virtual glm::vec3 &normal(const glm::vec3 &point) const = 0;
};

struct Intersection {
    const Ray& ray;
    float t;
    Shape *pShape;

    Intersection();
    Intersection(const Intersection& i);
    Intersection(const Ray& ray);

    virtual ~Intersection();

    Intersection& operator= (const Intersection& i);

    bool intersected() const;
    glm::vec3 position() const;
};

class Sphere : public Shape {
public:
    glm::vec3 center;
    float radius;

    Sphere() : center(glm::vec3(0.0f, 0.0f, 0.0f)), radius(1.0f) {}
    Sphere(const glm::vec3 &center, const float &radius) : center(center), radius(radius) {}
    virtual ~Sphere()= default;

    bool intersect(const glm::vec3 &point) const override;
    float distance(const glm::vec3 &point) const override;

    glm::vec3 &normal(const glm::vec3 &point) const override;
};