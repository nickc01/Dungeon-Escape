#include <DungeonEscape/DialogBoxSprite.h> //Contains the DialogBoxSprite class, which is used to display a dialog box to the screen

using namespace smk; //Prevents me from having to type smk everywhere
using namespace std; //Prevents me from having to type std everywhere

//Loads the resource texture
ResourceTexture DialogBoxSprite::dialogBoxTexture;

//Constructs a new dialog box
DialogBoxSprite::DialogBoxSprite()
{
	if (!dialogBoxTexture.Loaded())
	{
		dialogBoxTexture = ResourceTexture{ RES_DIALOGBOX };
	}

	//Creates the dialog box sprite with the loaded texture
	dialogBoxSprite = smk::Sprite(dialogBoxTexture.GetTexture());

	//Gets the texture rect of the sprite
	//auto textureRect = dialogBoxSprite.getTextureRect();
	auto textureWidth = dialogBoxSprite.texture().width();
	auto textureHeight = dialogBoxSprite.texture().height();

	//Set the origin to the middle of the sprite
	dialogBoxSprite.SetCenter(textureWidth / 2.0f, textureHeight / 2.0f);

	//Update the layer the sprite is rendering on
	SetRenderLayer(50);

	//Enable rendering for this object
	Renderable::EnableRendering();
}

//Called when the dialog box is to be rendered
void DialogBoxSprite::Render(smk::Window& window)
{
	//Store the old view of the window
	auto oldView = window.view();

	//Get the window's current size
	auto windowSize = Vector2i(window.width(),window.height());

	//Set a new view that is centered at (0,0) and the size to be 1/3 of the window's size
	//auto newView = View({ 0.0f,0.0f }, Vector2f(std::get<0>(windowSize) / 3u, windowSize.y / 3u));
	auto newView = View(oldView);
	newView.SetCenter(0, 0);
	newView.SetSize(windowSize.x / 3, windowSize.y / 3);

	//Update the windows's view
	window.SetView(newView);

	//Draw the dialog box sprite
	window.Draw(dialogBoxSprite);

	//Set the old view
	window.SetView(oldView);
}
