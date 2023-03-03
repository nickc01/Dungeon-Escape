#pragma once
#include <DungeonEscape/Renderable.h> //Contains the Renderable class for rendering to the game window
#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources
#include <DungeonEscape/Sprite.h>

//Represents the exit door that the player needs to get to in order to win
class Door : public Renderable
{
	static Door* currentDoor; //A singleton that represents the current door in the world map
	static const char* doorTexture; //The door's resource texture

	Sprite doorSprite; //The door's sprite

	//Called when the dialog box is to be rendered
	virtual void Render(SDL_Renderer* renderer) override;

	//Called whenever the SDL_Renderer gets rebuilt
	virtual void OnRebuild(SDL_Renderer* renderer, SDL_Renderer* old_renderer) override;

public:

	//Constructs a new door
	Door(Vector2f doorPosition);

	//Gets the singleton that represents the door in the world map
	static Door* GetDoor();

	//Gets the sprite of the door
	const Sprite& GetSprite() const;

	//Deleting these four functions prevents the object from being copied or moved
	Door(const Door&) = delete;
	Door(Door&&) = delete;
	Door& operator=(const Door&) = delete;
	Door& operator=(Door&&) = delete;

	//The destructor for the door
	virtual ~Door();
};

