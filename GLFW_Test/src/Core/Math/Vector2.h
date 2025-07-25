#ifndef VECTOR2_H
#define VECTOR2_H

#include <stdexcept>
#include <cmath>

#include "MathUtils.h"

class Vector2 {
public:
    float x = 0;
    float y = 0;

    Vector2() {}
    Vector2(float x, float y) : x(x), y(y) {}
    
    // Normalizes the vector (sets the length to 1)
    void normalize();
    
    // Returns the magnitude (length) of the vector
    float magnitude() const;
    
    // Returns the squared magnitude (without square root)
    float squaredMagnitude() const;

    // Returns a new vector linearly interpolated between this vector and the given vector
    // using the interpolation factor t (0.0 returns this vector, 1.0 returns the target vector)
    Vector2 lerp(const Vector2& vec, float t) const;

    // Operator overloads for vector operations
    Vector2& operator+=(const Vector2& other);
    Vector2& operator-=(const Vector2& other);
    Vector2& operator*=(float scalar);
    Vector2& operator/=(float scalar);
    
    // Additional operator overloads for convenient operations
    Vector2 operator+(const Vector2& other) const;
    Vector2 operator-(const Vector2& other) const;
    Vector2 operator*(float scalar) const;
    Vector2 operator/(float scalar) const;
};

#endif