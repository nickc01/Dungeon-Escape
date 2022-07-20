#include <DungeonEscape/GameText.h> //Contains the GameText class, which is used for rendering text to the screen

const char* GameText::mainGameFontPath{ RES_SQUARES_BOLD }; //The main game font resource

//Constructs a new GameText object
GameText::GameText(const std::string message, Vector2f position, unsigned int characterSize, Vector2f scale, SDL_Renderer* renderer) :
	text(message)
{
	if (mainGameFont == nullptr)
	{
		FC_Font* mainGameFont = FC_CreateFont();
		FC_LoadFont(mainGameFont, renderer, mainGameFontPath, characterSize, FC_MakeColor(255, 255, 255, 255), TTF_STYLE_NORMAL);
	}

	//Set the text's position
	position = position;

	//Enable rendering
	EnableRendering();

	//Set the render layer
	SetRenderLayer(100);

	//Set the text's scale
}

//Get the text object stored in the GameText object
/*Text& GameText::GetText()
{
	return text;
}

//Get the text object stored in the GameText object
const Text& GameText::GetText() const
{
	return text;
}*/

//Renders the GameText object
void GameText::Render(SDL_Renderer* renderer)
{
	//Store the old camera view
	/*auto oldView = window.getView();

	//Store the old text position
	auto oldPosition = text.getPosition();

	//Get the text's scale
	auto scale = text.getScale();

	//Get the local bounds of the text
	auto bounds = text.getLocalBounds();

	//Set the position of the text to be centered
	text.setPosition({-((bounds.width / 2.0f) * scale.x) + oldPosition.x,-((bounds.height / 2.0f) * scale.y) + oldPosition.y});

	//Set the view size to be half the size of the window size
	window.setView(View({ 0.0f,0.0f }, static_cast<Vector2f>(window.getSize()) / 2.0f));

	//Draw the text
	window.draw(text);

	//Set the old view
	window.setView(oldView);

	//Set the text's old position
	text.setPosition(oldPosition);*/

	auto render_pos = position;

	render_pos.x -= Common::CameraPosition.x;
	render_pos.y -= Common::CameraPosition.y;

	auto windowSize = Common::GetWindowDimensions();

	render_pos.x += windowSize.x / 2;
	render_pos.y += windowSize.y / 2;

	FC_Draw(mainGameFont, renderer, position.x, position.y, text.c_str());
}
