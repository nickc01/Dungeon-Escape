#pragma once
#include <DungeonEscape/Renderable.h> //Contains the Renderable class for rendering to the game window
#include <DungeonEscape/ResourceFont.h> //Contains the ResourceFont class, which is used to load font resources


class GameText : public Renderable
{
	static ResourceFont mainGameFont; //The main game font resource

	ResourceFont loadedFont;

	smk::Text text; //The text object

public:

	//Constructs a new GameText object
	GameText(const std::string text, Vector2f position, float line_height = 175.0f, Vector2f scale = Vector2f(0.1f,0.1f));

	//Get the text object stored in the GameText object
	smk::Text& GetText();
	//Get the text object stored in the GameText object
	const smk::Text& GetText() const;


	//Renders the GameText object
	virtual void Render(smk::Window& window) override;

};

