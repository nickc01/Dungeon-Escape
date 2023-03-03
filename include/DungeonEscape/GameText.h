#pragma once
#include <DungeonEscape/Renderable.h> //Contains the Renderable class for rendering to the game window
#include <DungeonEscape/ResourceFont.h> //Contains the ResourceFont class, which is used to load font resources
#include <SDL_ttf.h>
#include <SDL_FontCache.h>
#include <DungeonEscape/Vector2.h>
#include <DungeonEscape/Common.h>

class GameText : public Renderable
{
	static const char* mainGameFontPath; //The main game font resource

	FC_Font* mainGameFont = nullptr;

	unsigned int characterSize;

	SDL_Renderer* renderer;

	TTF_Font* font;

public:

	std::string text;

	Vector2f position;

	void SetCharacterSize(unsigned int size);
	unsigned int GetCharacterSize() const;

	//Constructs a new GameText object
	GameText(const std::string text, Vector2f position, unsigned int characterSize = 300u, Vector2f scale = Vector2f(0.1f,0.1f), SDL_Renderer* renderer = Common::MainWindowRenderer);

	//Get the text object stored in the GameText object
	/*Text& GetText();
	//Get the text object stored in the GameText object
	const Text& GetText() const;*/


	//Renders the GameText object
	virtual void Render(SDL_Renderer* renderer) override;

	//Called whenever the SDL_Renderer gets rebuilt
	virtual void OnRebuild(SDL_Renderer* renderer, SDL_Renderer* old_renderer) override;

};

