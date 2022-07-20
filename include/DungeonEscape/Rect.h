#pragma once

template<typename T>
struct Rect
{
	T x;
	T y;
	T width;
	T height;

	constexpr Rect(T X, T Y, T W, T H) : x(X), y(Y), width(W), height(H) {}

	constexpr bool operator==(const Rect<T>& other) const
	{
		return x == other.x &&
			y == other.y &&
			width == other.width &&
			height == other.height;
	}
};


using RectF = Rect<float>;
using RectI = Rect<int>;