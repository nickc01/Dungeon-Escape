#pragma once
#include <tuple>

template<typename T>
struct Vector2 : std::tuple<float, float>
{
	constexpr Vector2() : std::tuple<T, T>() {}


	constexpr Vector2(T x, T y) : std::tuple<T, T>(x, y) {}

	constexpr T GetX() const
	{
		return (T)std::get<0>(*this);
	}

	constexpr T GetY() const
	{
		return (T)std::get<1>(*this);
	}

	constexpr void SetX(T value)
	{
		std::get<0>(*this) = value;
	}

	constexpr void SetY(T value)
	{
		std::get<1>(*this) = value;
	}

	constexpr bool operator==(const Vector2<T>& other) const
	{
		return GetX() == other.GetX() && GetY() == other.GetY();
	}

	constexpr Vector2<T>& operator+=(const Vector2<T>& rhs) 
	{
		SetX(GetX() + rhs.GetX());
		SetY(GetY() + rhs.GetY());
		return *this;
	}
};


using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;