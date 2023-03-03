#include <DungeonEscape/HeartDisplay.h> //Contains the HeartDisplay class for displaying the amount of hearts the player has 
#include <DungeonEscape/Common.h>
#include <DungeonEscape/Vector2.h>

using namespace std; //Prevents me from having to type std everywhere


const char* HeartDisplay::heartTexture{RES_HEART}; //The texture resource for the heart display


//Constructs a new heart display
HeartDisplay::HeartDisplay(const Player& player) :
	player(player),
	heartSprite(heartTexture)
{
	//Set the render layer
	SetRenderLayer(100);

	//Enable rendering
	Renderable::EnableRendering();
}

//Renders the heart display to the screen
void HeartDisplay::Render(SDL_Renderer* renderer)
{

	auto windowSize = Common::GetWindowDimensions();

	auto startPosition = Vector2f(windowSize.x / 2.0f, windowSize.y / 2.0f);

	for (int i = 0; i < player.GetHealth(); i++)
	{
		//Set the position of the heart sprite to the starting position
		heartSprite.position = startPosition;
		//Draw the sprite
		heartSprite.DrawSpriteUI(renderer);
		//Move the start position to the left for the next sprite
		startPosition = startPosition - Vector2f(heartSprite.GetTextureRect().width, 0.0f);
	}
	/*//Store the old camera view
	auto oldView = window.getView();

	//Get the window's size
	auto windowSize = window.getSize();

	//Set the new view to be 1/3rd the size of the window
	auto newView = View({ 0.0f,0.0f }, Vector2f( windowSize.x / 3u,windowSize.y / 3u ));

	//Set the new view
	window.setView(newView);

	//Get the center of the new view
	auto center = newView.getCenter();
	//Get the size of the new view
	auto size = newView.getSize();

	//Compute the rectangle of the view
	auto viewingRect = Rect<int>(center.x - (size.x / 2), center.y + (size.y / 2), size.x, size.y);

	//Get the local bounds of the heart sprite
	auto spriteBounds = heartSprite.getLocalBounds();

	//Set the starting position of the first heart to be rendered
	auto startPosition = Vector2f(viewingRect.left + viewingRect.width - spriteBounds.width,viewingRect.top - viewingRect.height);

	//Loop over all the lives the player has
	for (int i = 0; i < player.GetHealth(); i++)
	{
		//Set the position of the heart sprite to the starting position
		heartSprite.setPosition(startPosition);
		//Draw the sprite
		window.draw(heartSprite);
		//Move the start position to the left for the next sprite
		startPosition = startPosition - Vector2f(spriteBounds.width,0.0f);
	}

	//Set the old view
	window.setView(oldView);*/
}

//Called whenever the SDL_Renderer gets rebuilt
void HeartDisplay::OnRebuild(SDL_Renderer* renderer, SDL_Renderer* old_renderer)
{
	heartSprite.Rebuild(renderer);
}
