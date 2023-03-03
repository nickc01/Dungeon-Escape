#pragma once

//#include <SFML/Graphics.hpp> //Contains many essential SFML classes and functions for rendering
#include <smk/Sprite.hpp>
#include <DungeonEscape/Vector.h>
#include <memory> //Contains std::shared_ptr and std::unique_ptr

//A sprite that represents a background portion of the worldmap
class BackgroundTile
{
	//The sprite of the background tile
	smk::Sprite sprite;

	//Whether the tile is collidable or not
	bool collidable;

	//Constructs a new background tile with the specified sprite
	BackgroundTile(const smk::Sprite& sprite, bool collidable = false);

	//Constructs a new background tile with the specified sprite and position
	BackgroundTile(const smk::Sprite& sprite, Vector2<int> position, bool collidable = false);

public:

	//Returns whether the sprite is colidable or not
	bool IsCollidable() const;


	//Gets the sprite of the tile
	const smk::Sprite& GetSprite() const;

	//Gets the sprite of the tile
	smk::Sprite& GetSprite();

	//Sets the sprite of the tile
	void SetSprite(const smk::Sprite& sprite);

	//Create a new shared_ptr of a background tile
	static std::shared_ptr<BackgroundTile> Create(const smk::Sprite& sprite, bool collidable = false);

	//Create a new shared_ptr of a background tile
	static std::shared_ptr<BackgroundTile> Create(const smk::Sprite& sprite, Vector2<int> position, bool collidable = false);
};

