#include <cmath>

class Vector
{
public:
    float x, y, z;

    Vector() : x(0.0f), y(1.0f), z(0.0f) {}
    Vector(float x, float y, float z) : x(x), y(y), z(z) {}

    virtual ~Vector()=default;

    inline float length() const {
        return sqrtf(powf(x,2) + powf(y,2) + powf(z,2));
    }

    inline void operator=(const Vector& other) {
        x = other.x, y = other.y, z = other.z;
    }
    inline void operator *=(const float& other) {
        x *= other, y *= other, z *= other;
    }
    inline void operator /=(const float& other) {
        x /= other, y /= other, z /= other;
    }
    inline Vector operator/(const float& other) const {
        return Vector(x / other, y / other, z / other);
    }
    inline Vector operator*(const float& other) const {
        return Vector(x * other, y * other, z * other);
    }
    inline Vector operator/(const Vector& other) const {
        return Vector(x / other.x, y / other.y, z / other.z);
    }
    inline Vector operator*(const Vector& other) const {
        return Vector(x * other.x, y * other.y, z * other.z);
    }
    inline Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }
    inline Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }
};

typedef Vector Point;