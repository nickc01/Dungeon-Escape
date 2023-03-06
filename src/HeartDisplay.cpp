#include <DungeonEscape/HeartDisplay.h> //Contains the HeartDisplay class for displaying the amount of hearts the player has 

using namespace std; //Prevents me from having to type std everywhere
using namespace smk; //Prevents me from having to type smk everywhere


ResourceTexture HeartDisplay::heartTexture; //The texture resource for the heart display


//Constructs a new heart display
HeartDisplay::HeartDisplay(const Player& player) :
	player(player)
{
	if (!heartTexture.Loaded())
	{
		heartTexture = ResourceTexture{ RES_HEART };
	}

	heartSprite = smk::Sprite(heartTexture.GetTexture());

	//Set the render layer
	SetRenderLayer(100);

	//Enable rendering
	Renderable::EnableRendering();
}

//Renders the heart display to the screen
void HeartDisplay::Render(smk::Window& window)
{
	//Store the old camera view
	auto oldView = window.view();

	//Get the window's size
	auto windowSize = window.dimensions();

	//Set the new view to be 1/3rd the size of the window
	auto newView = View({ 0.0f,0.0f }, Vector2f( windowSize.x / 3u,windowSize.y / 3u ));

	//Set the new view
	window.SetView(newView);

	//Get the center of the new view
	auto center = newView.center();
	//Get the size of the new view
	auto size = newView.size();

	//Compute the rectangle of the view
	auto viewingRect = Rect<int>(center.x - (size.x / 2), center.y + (size.y / 2), size.x, size.y);

	//Get the local bounds of the heart sprite
	//auto spriteBounds = heartSprite.getLocalBounds();

	//Set the starting position of the first heart to be rendered
	auto startPosition = Vector2f(viewingRect.left + viewingRect.width - heartSprite.texture().width(), viewingRect.top - viewingRect.height);

	//Loop over all the lives the player has
	for (int i = 0; i < player.GetHealth(); i++)
	{
		//Set the position of the heart sprite to the starting position
		heartSprite.SetPosition(startPosition);
		//Draw the sprite
		window.Draw(heartSprite);
		//Move the start position to the left for the next sprite
		startPosition = startPosition - Vector2f(heartSprite.texture().width(),0.0f);
	}

	//Set the old view
	window.SetView(oldView);
}
