#pragma once


//#include <SFML/Graphics.hpp> //Contains many essential SFML classes and functions for rendering
#include <DungeonEscape/Graphics.h>
#include <string> //Contains std::string
#include <memory> //Contains std::shared_ptr and std::unique_ptr
#include <DungeonEscape/Direction.h> //Contains the Direction Enum for specifying the direction

#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources

namespace Common
{
	namespace Sprites
	{
		//A list of all common sprites used for both the rooms and the branches

		extern smk::Sprite centerPiece1;
		extern smk::Sprite centerPiece2;

		extern smk::Sprite topJointPiece;
		extern smk::Sprite bottomJointPiece;
		extern smk::Sprite leftJointPiece;
		extern smk::Sprite rightJointPiece;

		extern smk::Sprite topLeftPiece;
		extern smk::Sprite topRightPiece;
		extern smk::Sprite bottomLeftPiece;
		extern smk::Sprite bottomRightPiece;
		extern smk::Sprite topPiece;
		extern smk::Sprite bottomPiece;
		extern smk::Sprite rightPiece;
		extern smk::Sprite leftPiece;

	}

	namespace Textures
	{
		//A list of all common textures used for both the rooms and the branches
		//These are then used by the Common Sprites

		extern ResourceTexture centerPiece1;
		extern ResourceTexture centerPiece2;

		extern ResourceTexture topJointPiece;
		extern ResourceTexture bottomJointPiece;
		extern ResourceTexture leftJointPiece;
		extern ResourceTexture rightJointPiece;

		extern ResourceTexture topLeftPiece;
		extern ResourceTexture topRightPiece;
		extern ResourceTexture bottomLeftPiece;
		extern ResourceTexture bottomRightPiece;
		extern ResourceTexture topPiece;
		extern ResourceTexture bottomPiece;
		extern ResourceTexture rightPiece;
		extern ResourceTexture leftPiece;

	}

	//The main render window the game will take place in
	extern std::shared_ptr<smk::Window> MainWindow;

	//Creates all the common sprites used in the game
	void CreateSprites();

	//Gets a random sprite that can be used as a center tile
	smk::Sprite GetCenterSprite();

	//Gets a joint sprite that can be used as a joint piece pointing in a specified direction
	smk::Sprite GetJointPiece(Direction source, Direction to);
	//Gets a sprite that represents a side wall
	smk::Sprite GetSideSprite(Direction side);

	//Gets a sprite that represents a corner
	smk::Sprite GetCornerSprite(Direction A, Direction B);

	//Checks whether two sprites intersect. Optionally scaling their hitboxes by a scale factor
	bool SpritesIntersect(const smk::Sprite& A, const smk::Sprite& B, Vector2f scaleFactor);
	//Checks whether two sprites intersect
	bool SpritesIntersect(const smk::Sprite& A, const smk::Sprite& B);
	//Checks whether two sprites intersect. Optionally scaling their hitboxes by their texture sizes if set to true
	bool SpritesIntersect(const smk::Sprite& A, const smk::Sprite& B, bool scaleByTextureSize);

	//Refreshes the size of the window. This is normally used when the window gets resized
	void RefreshWindow(std::shared_ptr<smk::Window>& window = Common::MainWindow);
	//Gets the mouse position in world coordinates
	Vector2f GetMouseWorldCoordinates(std::shared_ptr<smk::Window>& window = Common::MainWindow);

	//Centers the camera over a specified point
	void CenterCamera(Vector2f center, std::shared_ptr<smk::Window>& window = Common::MainWindow);

	//Gets a random number between the minRange (inclusive) and the maxRange (exclusive)
	int RandomNumber(int minRange, int maxRange);
}