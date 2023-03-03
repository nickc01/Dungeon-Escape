#pragma once
#include <tuple>

template <typename T>
using Vector2 = std::tuple<T,T>;

using Vector2i = Vector2<int>;
using Vector2f = Vector2<float>;
using Vector2u = Vector2<unsigned int>;


template <typename T>
Vector2<T>& operator+=(Vector2<T>& lhs, const Vector2<T>& rhs)
{
    std::get<0>(lhs) += std::get<0>(rhs);
    std::get<1>(lhs) += std::get<1>(rhs);
    return lhs;
}

template <typename T>
Vector2<T> operator+(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return Vector2<T>(std::get<0>(lhs) + std::get<0>(rhs), std::get<1>(lhs) + std::get<1>(rhs));
}




template <typename T>
Vector2<T>& operator-=(Vector2<T>& lhs, const Vector2<T>& rhs)
{
    std::get<0>(lhs) -= std::get<0>(rhs);
    std::get<1>(lhs) -= std::get<1>(rhs);
    return lhs;
}

template <typename T>
Vector2<T> operator-(const Vector2<T>& lhs, const Vector2<T>& rhs)
{
    return Vector2<T>(std::get<0>(lhs) - std::get<0>(rhs), std::get<1>(lhs) - std::get<1>(rhs));
}


template <typename T>
Vector2<T>& operator*=(Vector2<T>& lhs, const T& rhs)
{
    std::get<0>(lhs) *= rhs;
    std::get<1>(lhs) *= rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator*(const Vector2<T>& lhs, const T& rhs)
{
    return Vector2<T>(std::get<0>(lhs) * rhs, std::get<1>(lhs) * rhs);
}



template <typename T>
Vector2<T>& operator/=(Vector2<T>& lhs, const T& rhs)
{
    std::get<0>(lhs) /= rhs;
    std::get<1>(lhs) /= rhs;
    return lhs;
}

template <typename T>
Vector2<T> operator/(const Vector2<T>& lhs, const T& rhs)
{
    return Vector2<T>(std::get<0>(lhs) / rhs, std::get<1>(lhs) / rhs);
}

template<typename T>
T& getX(Vector2<T>& vector)
{
    return std::get<0>(vector);
}

template<typename T>
T& getY(Vector2<T>& vector)
{
    return std::get<1>(vector);
}

template<typename T>
const T& getX(const Vector2<T>& vector)
{
    return std::get<0>(vector);
}

template<typename T>
const T& getY(const Vector2<T>& vector)
{
    return std::get<1>(vector);
}


/*void test()
{
    Vector2i a;
    Vector2i b;

    a += Vector2i(2, 3);

    auto c = a + Vector2i(1,2);
}*/