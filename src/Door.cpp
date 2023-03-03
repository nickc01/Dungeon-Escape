#include <DungeonEscape/Door.h> //Contains the Door class, which is where the player enters to win the game

Door* Door::currentDoor = nullptr; //A singleton that represents the current door in the world map
const char* Door::doorTexture{ RES_DOOR }; //The door's resource texture

//Constructs a new door
Door::Door(Vector2f doorPosition) :
	//Set the doors sprite to the resource texture
	doorSprite(doorTexture)
{
	//Set the sprite's position
	doorSprite.position = doorPosition;
	//Set it's render layer
	SetRenderLayer(5);
	//Update the singleton
	currentDoor = this;
	//Enable rendering
	EnableRendering();
}


//Gets the singleton that represents the door in the world map
Door* Door::GetDoor()
{
	return currentDoor;
}

//Gets the sprite of the door
const Sprite& Door::GetSprite() const
{
	return doorSprite;
}

Door::~Door()
{
	//If the singleton is set to itself
	if (currentDoor == this)
	{
		//Reset it to null
		currentDoor = nullptr;
	}
}

//Called when the dialog box is to be rendered
void Door::Render(SDL_Renderer* renderer)
{
	//Draw the door sprite
	//window.draw(doorSprite);
	doorSprite.DrawSprite(renderer);
}

//Called whenever the SDL_Renderer gets rebuilt
void Door::OnRebuild(SDL_Renderer* renderer, SDL_Renderer* old_renderer)
{
	doorSprite.Rebuild(renderer);
}
