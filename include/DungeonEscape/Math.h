#pragma once

#include <array> //Contains std::array, which is a fixed array type
#include <DungeonEscape/Direction.h> //Contains the Direction Enum for specifying the direction
#include <DungeonEscape/Entity.h> //Contains the Entity class
#include <DungeonEscape/Sprite.h>
#include <DungeonEscape/Vector2.h>
#include <math.h>

namespace Math
{
	constexpr double PI = 3.14159265358979323846; //The constant PI

	
	//Linearly interpolates between two numbers
	template<typename NumType, typename TType = NumType>
	NumType Lerp(NumType A, NumType B, TType t)
	{
		return A + ((B - A) * t);
	}

	//Linearly interpolates between two vectors
	template<typename NumType, typename TType = NumType>
	Vector2<NumType> VectorLerp(Vector2<NumType> A, Vector2<NumType> B, TType t)
	{
		return Vector2<NumType>(Lerp(A.x,B.x,t),Lerp(A.y,B.y,t));
	}

	//Gets the distance between two vectors
	template<typename VectorType, typename ReturnType = float>
	ReturnType DistanceBetweenVectors(Vector2<VectorType> A, Vector2<VectorType> B)
	{
		return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
	}

	//Splits the vector into its x and y components
	template<typename VectorType>
	std::array<Vector2<VectorType>, 2> VectorComponents(Vector2<VectorType> vect)
	{
		std::array<Vector2<VectorType>, 2> components{};

		components[0] = { vect.x,0 };
		components[1] = { 0,vect.y };

		return components;
	}

	//Gets the length of the vector
	template<typename VectorType, typename ReturnType = float>
	ReturnType GetVectorLength(Vector2<VectorType> input)
	{
		return sqrt(pow(input.x, 2) + pow(input.y, 2));
	}

	//Normalizes the vector to a specified length
	template<typename VectorType>
	Vector2<VectorType> NormalizeVector(Vector2<VectorType> input, VectorType length = static_cast<VectorType>(1))
	{
		//Represents the constant zero
		constexpr VectorType Zero = static_cast<VectorType>(0);

		//Get the length of the vector
		float VectorLength = GetVectorLength(input);
		//If the length is zero
		if (VectorLength == Zero)
		{
			//Return zero
			return Vector2<VectorType>(Zero,Zero);
		}
		//Normalize the vector, multiply it with the specified length, then return it
		return Vector2<VectorType>((input.x / VectorLength) * length,(input.y / VectorLength) * length);
	}

	//Converts the vector into degrees
	template<typename VectorType, typename ReturnType = float>
	ReturnType VectorToDegrees(Vector2<VectorType> input)
	{
		Vector2<VectorType> normalized = NormalizeVector(input);

		return ((atan2(normalized.y, normalized.x) / PI) * -180.0f) + 90.0f;
	}

	//Takes in a vector, and returns a direction enum that is closest to it
	template<typename VectorType>
	Direction ApproxDirectionOfVector(Vector2<VectorType> input)
	{
		
		//Convert the vector to degrees
		float degrees = VectorToDegrees(input);

		//If the degrees is less than zero
		if (degrees < 0)
		{
			//Add 360 to it
			degrees += 360.0f;
		}

		if (degrees >= 45 && degrees < 135)
		{
			return Direction::Right;
		}
		else if (degrees >= 135 && degrees < 225)
		{
			return Direction::Down;
		}
		else if (degrees >= 225 && degrees < 315)
		{
			return Direction::Left;
		}
		else
		{
			return Direction::Up;
		}
	}

	template<typename T>
	bool RectsIntersect(Rect<T> A, Rect<T> B)
	{
		//Get the left side of rect A
		auto leftA = A.x;
		//Get the right side of rect A
		auto rightA = A.x + A.width;
		//Get the top side of rect A
		auto bottomA = A.y;
		//Get the bottom side of rect A
		auto topA = A.y + A.height;

		//Get the left side of rect B
		auto leftB = B.x;
		//Get the right side of rect B
		auto rightB = B.x + B.width;
		//Get the top side of rect B
		auto bottomB = B.y;
		//Get the bottom side of rect B
		auto topB = B.y + B.height;

		//If the rects intersect
		if (leftA < rightB && rightA > leftB && topA > bottomB && bottomA < topB)
		{
			return true;
		}
		return false;
	}

	//Determines if two sprites interect
	bool SpritesIntersect(const Sprite& A, const Sprite& B);
	//Determines if two entities intersect
	bool EntitiesIntersect(const Entity& A, const Entity& B);
}

