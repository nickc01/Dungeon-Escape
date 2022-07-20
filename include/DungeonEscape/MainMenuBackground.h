#pragma once
#include <DungeonEscape/Renderable.h> //Contains the Renderable class for rendering to the game window
#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources
#include <DungeonEscape/Sprite.h>

//Represents the background of the main menu
class MainMenuBackground : public Renderable
{
	static const char* menuBackgroundTexture; //The texture resource for the main menu background


	Sprite menuBackgroundSprite; //The sprite for the menu background

public:

	//Renders the menu background to the screen
	virtual void Render(SDL_Renderer* renderer) override;

	//Constructs a new MainMenuBackground
	MainMenuBackground();

};

