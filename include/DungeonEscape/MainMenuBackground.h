#pragma once
#include <DungeonEscape/Renderable.h> //Contains the Renderable class for rendering to the game window
#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources

//Represents the background of the main menu
class MainMenuBackground : public Renderable
{
	static ResourceTexture menuBackgroundTexture; //The texture resource for the main menu background


	smk::Sprite menuBackgroundSprite; //The sprite for the menu background

public:

	//Renders the menu background to the screen
	virtual void Render(smk::Window& window) override;

	//Constructs a new MainMenuBackground
	MainMenuBackground();

};

