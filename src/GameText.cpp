#include <DungeonEscape/GameText.h> //Contains the GameText class, which is used for rendering text to the screen

ResourceFont GameText::mainGameFont; //The main game font resource

//std::map<std::

//Constructs a new GameText object
GameText::GameText(const std::string message, Vector2f position, float line_height, Vector2f scale)
	//text(message, mainGameFont.GetFont(), characterSize)
{
	/*if (!mainGameFont.Loaded())
	{
		
	}*/

	loadedFont = ResourceFont{ RES_SQUARES_BOLD, line_height};

	text = smk::Text(loadedFont.GetFont(), message);

	//Set the text's position
	text.SetPosition(position);

	//Enable rendering
	EnableRendering();

	//Set the render layer
	SetRenderLayer(100);

	//Set the text's scale
	text.SetScale(scale);
}

//Get the text object stored in the GameText object
smk::Text& GameText::GetText()
{
	return text;
}

//Get the text object stored in the GameText object
const smk::Text& GameText::GetText() const
{
	return text;
}

//Renders the GameText object
void GameText::Render(smk::Window& window)
{
	//Store the old camera view
	auto oldView = window.view();

	//Store the old text position
	auto oldPosition = text.position();

	//Get the text's scale
	auto scale = text.scale();

	//Get the local bounds of the text
	//auto bounds = text.getLocalBounds();
	auto dimensions = text.ComputeDimensions();

	//Set the position of the text to be centered
	text.SetPosition({-((dimensions.x / 2.0f) * scale.x) + oldPosition.x,-((dimensions.y / 2.0f) * scale.y) + oldPosition.y});

	auto newView = smk::View(oldView);
	newView.SetCenter(0, 0);
	newView.SetSize(window.width() / 2.0,window.height() / 2.0);
	//Set the view size to be half the size of the window size
	window.SetView(newView);

	//Draw the text
	window.Draw(text);

	//Set the old view
	window.SetView(oldView);

	//Set the text's old position
	text.SetPosition(oldPosition);
}
