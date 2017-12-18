#pragma once
#include <glm/vec3.hpp>

class Shape {
public:
    virtual bool doesIntersect(const glm::vec3 &point) const = 0;

    /*
     * This "getDistance" function needs to returns the distance from a point to the surface of the shape.
       Do not confuse this with distance from the center of the object.
     */
    virtual float getDistance(const glm::vec3 &point) const = 0;
};


class Sphere : public Shape {
public:
    glm::vec3 center;
    float radius;

    Sphere();
    Sphere(const glm::vec3 &center, const float &radius) : center(center), radius(radius) {}
    virtual ~Sphere()= default;

    bool doesIntersect(const glm::vec3 &point) const override;
    float getDistance(const glm::vec3 &point) const override;

    glm::vec3& getNormal(const glm::vec3 &point) const;
};