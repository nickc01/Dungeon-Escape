#pragma once
#include <tuple>

template<typename T>
struct Vector2
{
	T x;
	T y;

	constexpr Vector2() {}

	constexpr Vector2(T X, T Y) : x(X), y(Y) {}

	constexpr bool operator==(const Vector2<T>& other) const
	{
		return x == other.x && y == other.y;
	}

	constexpr bool operator!=(const Vector2<T>& other) const
	{
		return x != other.x || y != other.y;
	}

	constexpr Vector2<T>& operator+=(const Vector2<T>& rhs) 
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	constexpr Vector2<T>& operator-=(const Vector2<T>& rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	constexpr Vector2<T> operator+(const Vector2<T>& rhs)
	{
		return Vector2<T>(x + rhs.x, y + rhs.y);
	}

	constexpr Vector2<T> operator-(const Vector2<T>& rhs)
	{
		return Vector2<T>(x - rhs.x, y - rhs.y);
	}

	constexpr Vector2<T> operator*(const T& rhs)
	{
		return Vector2<T>(x * rhs, y * rhs);
	}

	constexpr Vector2<T> operator/(const T& rhs)
	{
		return Vector2<T>(x / rhs, y / rhs);
	}

	constexpr Vector2<T> operator*=(const T& rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	constexpr Vector2<T> operator/=(const T& rhs)
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}

	template<typename OtherT>
	constexpr operator Vector2<OtherT>() const
	{
		return Vector2<OtherT>(static_cast<OtherT>(x), static_cast<OtherT>(y));
	}
};


using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;