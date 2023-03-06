#include <DungeonEscape/MainMenuBackground.h> //Contains the MainMenuBackground class, which displays the background you see on the main menu

ResourceTexture MainMenuBackground::menuBackgroundTexture; //The texture resource for the main menu background

//Renders the menu background to the screen
void MainMenuBackground::Render(smk::Window& window)
{
	//Store the old view
	auto oldView = window.view();

	//Set the new view size to be half the window's size
	window.SetView(smk::View({0.0f,0.0f}, window.dimensions() / 2.0f));

	//Draw the main men
	window.Draw(menuBackgroundSprite);

	//Set the old view
	window.SetView(oldView);
}

//Constructs a new MainMenuBackground
MainMenuBackground::MainMenuBackground()
{
	if (!menuBackgroundTexture.Loaded())
	{
		menuBackgroundTexture = ResourceTexture{ RES_BACKGROUNDTILES };
	}

	//Set the texture to be tiled
	//menuBackgroundTexture.GetTexture().setRepeated(true);

	//Create a new sprite with the background texture
	menuBackgroundSprite = smk::Sprite(menuBackgroundTexture.GetTexture());

	//Get the texture's rect
	//auto textureRect = menuBackgroundSprite.getTextureRect();

	//Multiply the dimensions by 200
	//textureRect.width *= 200;
	//textureRect.height *= 200;

	menuBackgroundSprite.SetScale(200,200);
	//menuBackgroundSprite.

	//Center the sprite's position in the texture
	Vector2f position = Vector2f(-menuBackgroundSprite.texture().width() / 2.0f,-menuBackgroundSprite.texture().height() / 2.0f );

	//Set the sprite's new position
	menuBackgroundSprite.SetPosition(position);

	//Set the new texture rect for the sprite
	//menuBackgroundSprite.setTextureRect(textureRect);

	//Enable rendering
	EnableRendering();
}
