#pragma once


//#include <SFML/Graphics.hpp> //Contains many essential SFML classes and functions for rendering
#include <string> //Contains std::string
#include <memory> //Contains std::shared_ptr and std::unique_ptr
#include <DungeonEscape/Direction.h> //Contains the Direction Enum for specifying the direction
#include <DungeonEscape/Sprite.h>
#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources
#include <SDL.h>
#include <DungeonEscape/Vector2.h>

namespace Common
{
	namespace Sprites
	{
		//A list of all common sprites used for both the rooms and the branches

		extern Sprite centerPiece1;
		extern Sprite centerPiece2;

		extern Sprite topJointPiece;
		extern Sprite bottomJointPiece;
		extern Sprite leftJointPiece;
		extern Sprite rightJointPiece;

		extern Sprite topLeftPiece;
		extern Sprite topRightPiece;
		extern Sprite bottomLeftPiece;
		extern Sprite bottomRightPiece;
		extern Sprite topPiece;
		extern Sprite bottomPiece;
		extern Sprite rightPiece;
		extern Sprite leftPiece;

	}

	namespace Textures
	{
		//A list of all common textures used for both the rooms and the branches
		//These are then used by the Common Sprites

		extern const char* centerPiece1;
		extern const char* centerPiece2;

		extern const char* topJointPiece;
		extern const char* bottomJointPiece;
		extern const char* leftJointPiece;
		extern const char* rightJointPiece;

		extern const char* topLeftPiece;
		extern const char* topRightPiece;
		extern const char* bottomLeftPiece;
		extern const char* bottomRightPiece;
		extern const char* topPiece;
		extern const char* bottomPiece;
		extern const char* rightPiece;
		extern const char* leftPiece;

	}

	//The main render window the game will take place in
	extern SDL_Window* MainWindow;
	extern SDL_Surface* MainWindowSurface;
	extern SDL_Renderer* MainWindowRenderer;
	extern Vector2f CameraPosition;

	//Creates all the common sprites used in the game
	void CreateSprites();

	//Gets a random sprite that can be used as a center tile
	Sprite GetCenterSprite();

	//Gets a joint sprite that can be used as a joint piece pointing in a specified direction
	Sprite GetJointPiece(Direction source, Direction to);
	//Gets a sprite that represents a side wall
	Sprite GetSideSprite(Direction side);

	//Gets a sprite that represents a corner
	Sprite GetCornerSprite(Direction A, Direction B);

	//Checks whether two sprites intersect. Optionally scaling their hitboxes by a scale factor
	//bool SpritesIntersect(const Sprite& A, const Sprite& B, std::tuple<float, float> scaleFactor);
	//Checks whether two sprites intersect
	bool SpritesIntersect(const Sprite& A, const Sprite& B);
	//Checks whether two sprites intersect. Optionally scaling their hitboxes by their texture sizes if set to true
	//bool SpritesIntersect(const Sprite& A, const Sprite& B, bool scaleByTextureSize);

	//Refreshes the size of the window. This is normally used when the window gets resized
	void RefreshWindow(SDL_Window* window = Common::MainWindow);
	//Gets the mouse position in world coordinates
	Vector2f GetMouseWorldCoordinates(SDL_Window* window = Common::MainWindow);

	//Centers the camera over a specified point
	void CenterCamera(Vector2f position, SDL_Window* window = Common::MainWindow);

	//Gets a random number between the minRange (inclusive) and the maxRange (exclusive)
	int RandomNumber(int minRange, int maxRange);


	Vector2f GetWindowDimensions();
}