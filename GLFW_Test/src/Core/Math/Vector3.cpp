#include "Vector3.h"

void Vector3::normalize() {
    float len = magnitude();
    if (len > 0) {
        *this /= len;
    }
}

float Vector3::magnitude() const {
    return std::sqrt(squaredMagnitude());
}

float Vector3::squaredMagnitude() const {
    return (x * x + y * y + z * z);
}

Vector3 Vector3::lerp(const Vector3& vec, float t) const {
    return Vector3(
        MathUtil::Lerp(x, vec.x, t),
        MathUtil::Lerp(y, vec.y, t),
        MathUtil::Lerp(z, vec.z, t)
    );
}

// Adds another vector to the current vector
Vector3& Vector3::operator+=(const Vector3& other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

// Subtracts another vector from the current vector
Vector3& Vector3::operator-=(const Vector3& other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

// Scales the vector by a scalar
Vector3& Vector3::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    return *this;
}

// Divides the vector by a scalar
Vector3& Vector3::operator/=(float scalar) {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero is not possible");
    }
    x /= scalar; 
    y /= scalar;
    z /= scalar;
    return *this;
}

// Adds two vectors and returns the result
Vector3 Vector3::operator+(const Vector3& other) const {
    return Vector3(x + other.x, y + other.y, z + other.z);
}

// Subtracts two vectors and returns the result
Vector3 Vector3::operator-(const Vector3& other) const {
    return Vector3(x - other.x, y - other.y, z - other.z);
}

// Scales the vector by a scalar and returns the result
Vector3 Vector3::operator*(float scalar) const {
    return Vector3(x * scalar, y * scalar, z * scalar);
}

// Divides the vector by a scalar and returns the result
Vector3 Vector3::operator/(float scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero is not possible");
    }
    return Vector3(x / scalar, y / scalar, z / scalar);
}