#include <DungeonEscape/DialogBoxSprite.h> //Contains the DialogBoxSprite class, which is used to display a dialog box to the screen
#include <DungeonEscape/Common.h>

using namespace std; //Prevents me from having to type std everywhere

//Loads the resource texture
const char* DialogBoxSprite::dialogBoxTexture{ RES_DIALOGBOX };

//Constructs a new dialog box
DialogBoxSprite::DialogBoxSprite() :
	//Creates the dialog box sprite with the loaded texture
	dialogBoxSprite(dialogBoxTexture)
{
	//Gets the texture rect of the sprite
	//auto textureRect = dialogBoxSprite.GetLocalRect();

	//Set the origin to the middle of the sprite
	//dialogBoxSprite.setOrigin(textureRect.width / 2.0f, textureRect.height / 2.0f);

	//Update the layer the sprite is rendering on
	SetRenderLayer(50);

	//Enable rendering for this object
	Renderable::EnableRendering();
}

//Called when the dialog box is to be rendered
void DialogBoxSprite::Render(SDL_Renderer* renderer)
{
	//Store the old view of the window
	//auto oldView = window.getView();

	//Get the window's current size
	//auto windowSize = window.getSize();

	//Set a new view that is centered at (0,0) and the size to be 1/3 of the window's size
	//auto newView = View({ 0.0f,0.0f }, Vector2f(windowSize.x / 3u, windowSize.y / 3u));

	auto oldCameraPos = Common::CameraPosition;

	Common::CameraPosition = {0,0};

	//Update the windows's view
	//window.setView(newView);

	//Draw the dialog box sprite
	//window.draw(dialogBoxSprite);
	dialogBoxSprite.DrawSprite(renderer);

	//Set the old view
	//window.setView(oldView);

	Common::CameraPosition = oldCameraPos;
}
