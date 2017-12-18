#pragma once
#include <glm/glm.hpp>

// Minimun distance, in order to prevent self intersection
#define RAY_T_MIN 0.0001f

// 'Infinit'e distance, used as a default value
#define RAY_T_MAX 1.0e30f

class Ray {
public:
    glm::vec3 origin, direction;
    float tMax;

    Ray();
    Ray(Ray &other);
    Ray(const glm::vec3 &origin, const glm::vec3 &direction, float tMax);

    virtual ~Ray()=default;

    /*
     * This function 'calculate' returns the
     * coordinates of a point along the ray at distance 't'.
     */
    glm::vec3 calculate(const float& t) const;

    Ray& operator= (const Ray &other);
};
