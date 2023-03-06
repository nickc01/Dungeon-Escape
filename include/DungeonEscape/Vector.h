#pragma once
#include <tuple>
#include <glm/vec2.hpp>

template <typename T>
using Vector2 = glm::vec<2, T>;

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2u = Vector2<unsigned int>;


/*template <typename T>
Vector2<T>& operator+=(Vector2<T>& lhs, const Vector2<T>& rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    return lhs;
}

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return Vector2<T>(lhs.x + rhs.x, lhs.y + rhs.y);
}




template <typename T>
Vector2<T>& operator-=(Vector2<T>& lhs, const Vector2<T>& rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    return lhs;
}

template <typename T>
Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return Vector2<T>(lhs.x - rhs.x, lhs.y - rhs.y);
}


template <typename T>
Vector2<T>& operator*=(Vector2<T>& lhs, const T& rhs)
{
    lhs.x *= rhs;
    lhs.y *= rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, const T& rhs)
{
    return Vector2<T>(lhs.x * rhs, lhs.y * rhs);
}



template <typename T>
Vector2<T>& operator/=(Vector2<T>& lhs, const T& rhs)
{
    lhs.x /= rhs;
    lhs.y /= rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator/(const Vector2<T>& lhs, const T& rhs)
{
    return Vector2<T>(lhs.x / rhs, lhs.y / rhs);
}

template<typename T>
T& getX(Vector2<T>& vector)
{
    return vector.x;
}

template<typename T>
T& getY(Vector2<T>& vector)
{
    return vector.y;
}

template<typename T>
const T& getX(const Vector2<T>& vector)
{
    return vector.x;
}

template<typename T>
const T& getY(const Vector2<T>& vector)
{
    return vector.y;
}*/


/*void test()
{
    Vector2i a;
    Vector2i b;

    a += Vector2i(2, 3);

    auto c = a + Vector2i(1,2);
}*/