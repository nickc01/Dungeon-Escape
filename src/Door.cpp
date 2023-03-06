#include <DungeonEscape/Door.h> //Contains the Door class, which is where the player enters to win the game

Door* Door::currentDoor = nullptr; //A singleton that represents the current door in the world map
ResourceTexture Door::doorTexture; //The door's resource texture

//TODO - FIX THE ABOVE doorTexture code so it doesn't crash

//Constructs a new door
Door::Door(Vector2f doorPosition)
{
	if (!doorTexture.Loaded())
	{
		doorTexture = ResourceTexture{ RES_DOOR };
	}

	//Set the doors sprite to the resource texture
	doorSprite = smk::Sprite(doorTexture.GetTexture());

	//Set the sprite's position
	doorSprite.SetPosition(doorPosition.x,doorPosition.y);
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
const smk::Sprite& Door::GetSprite() const
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
void Door::Render(smk::Window& window)
{
	//Draw the door sprite
	window.Draw(doorSprite);
}
