#include <DungeonEscape/MainMenuBackground.h> //Contains the MainMenuBackground class, which displays the background you see on the main menu
#include <DungeonEscape/Common.h>

const char* MainMenuBackground::menuBackgroundTexture{RES_BACKGROUNDTILES}; //The texture resource for the main menu background

constexpr int SCALE_FACTOR = 2;

//Renders the menu background to the screen
void MainMenuBackground::Render(SDL_Renderer* renderer)
{
	auto oldPos = menuBackgroundSprite.position;
	auto spriteSize = menuBackgroundSprite.GetSize();

	auto screenSize = Common::GetWindowDimensions();

	auto width = ((screenSize.x / spriteSize.x) / SCALE_FACTOR) + 1;
	auto height = ((screenSize.y / spriteSize.y) / SCALE_FACTOR) + 1;

	for (int x = -width / 2; x < width / 2; x++)
	{
		for (int y = -height / 2; y < height / 2; y++)
		{
			menuBackgroundSprite.position = Vector2f(oldPos.x + (x * SCALE_FACTOR * spriteSize.x),oldPos.y + (y * SCALE_FACTOR * spriteSize.y));
			menuBackgroundSprite.DrawSprite(renderer);
		}
	}

	menuBackgroundSprite.position = oldPos;
}

//Constructs a new MainMenuBackground
MainMenuBackground::MainMenuBackground()
{
	//Create a new sprite with the background texture
	menuBackgroundSprite = Sprite(menuBackgroundTexture);

	//Set the new texture rect for the sprite
	menuBackgroundSprite.scale *= SCALE_FACTOR;

	//Enable rendering
	EnableRendering();
}
