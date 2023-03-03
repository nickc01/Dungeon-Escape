#pragma once
#include <DungeonEscape/Renderable.h> //Contains the Renderable class for rendering to the game window
#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources
#include <DungeonEscape/Player.h> //Contains the Player class that represents the player

//Used to display how many lives the player has left
class HeartDisplay : public Renderable
{
	static const char* heartTexture; //The texture resource for the heart display

	//The player the heart display is bound to
	const Player& player;

	//The heart display sprite
	Sprite heartSprite;

public:

	//Constructs a new heart display
	HeartDisplay(const Player& player);

	//Renders the heart display to the screen
	virtual void Render(SDL_Renderer* renderer) override;

	//Called whenever the SDL_Renderer gets rebuilt
	virtual void OnRebuild(SDL_Renderer* renderer, SDL_Renderer* old_renderer) override;
};