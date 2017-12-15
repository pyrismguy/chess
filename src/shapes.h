#include "vector.h"

class Sphere{
public:
    Point center;
    Vector radius;

    Sphere(const Vector& center, const Point& radius) : center(center), radius(radius) {};
    virtual ~Sphere()= default;

    static float getDistance() const;
};