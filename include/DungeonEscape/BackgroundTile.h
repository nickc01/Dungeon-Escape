#pragma once

#include <memory> //Contains std::shared_ptr and std::unique_ptr
#include <DungeonEscape/Vector2.h>
#include <DungeonEscape/Sprite.h>
#include <DungeonEscape/Rect.h>

//A sprite that represents a background portion of the worldmap
class BackgroundTile
{
	//The sprite of the background tile
	Sprite sprite;

	//Whether the tile is collidable or not
	bool collidable;

	//Constructs a new background tile with the specified sprite
	BackgroundTile(const Sprite& sprite, bool collidable = false);

	//Constructs a new background tile with the specified sprite and position
	BackgroundTile(const Sprite& sprite, Vector2<int> position, bool collidable = false);

public:

	//Returns whether the sprite is colidable or not
	bool IsCollidable() const;


	//Gets the sprite of the tile
	const Sprite& GetSprite() const;

	//Gets the sprite of the tile
	Sprite& GetSprite();

	//Sets the sprite of the tile
	void SetSprite(const Sprite& sprite);

	//Create a new shared_ptr of a background tile
	static std::shared_ptr<BackgroundTile> Create(const Sprite& sprite, bool collidable = false);

	//Create a new shared_ptr of a background tile
	static std::shared_ptr<BackgroundTile> Create(const Sprite& sprite, Vector2<int> position, bool collidable = false);
};

