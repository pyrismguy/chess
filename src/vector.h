class Vector
{
public:
    float x, y, z;

    Vector() : x(0.0), y(1.0), z(0.0)
    {}
    Vector(float x, float y, float z)
            : x(x), y(y), z(z)
    {}
    virtual ~Vector()=default;

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