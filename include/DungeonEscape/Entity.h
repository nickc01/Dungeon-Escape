#pragma once

#include <DungeonEscape/Renderable.h> //Contains the Renderable class for rendering to the game window
#include <DungeonEscape/UpdateReceiver.h> //Contains the UpdateReceiver class for receiving update events
#include <DungeonEscape/WorldMap.h> //Contains the WorldMap class
#include <DungeonEscape/Direction.h> //Contains the Direction Enum for specifying the direction
#include <DungeonEscape/Sprite.h>


//Represents any objects that interact with the world map in some way
class Entity : public Renderable, public UpdateReceiver
{
	const WorldMap& map; //The map the entity is located in
	bool collisionEnabled; //Whether the entity collides with the walls or not
	RectF hitbox = RectF(0.0f, 0.0f, 0.0f, 0.0f); //The hitbox of the entity. If it's set to all zeros, then it uses the texture Rect as the default hitbox

	Sprite* sprite = nullptr; //The sprite the entity will be rendering

	//Called when the dialog box is to be rendered
	virtual void Render(SDL_Renderer* renderer) override;

protected:
	//Gets all the world tiles that are nearby the entity
	Array2D<BackgroundTile*> GetTilesAroundEntity() const;

	//The update function that is called each frame
	virtual void Update(double dt) override = 0;
public:

	//Constructs a new entity
	Entity(const WorldMap& map, bool collisionEnabled = true);

	//Constructs a new entity with the specified sprite
	Entity(const WorldMap& map,Sprite* sprite, bool collisionEnabled = true);

	//Gets the currently set sprite
	Sprite* GetSprite();
	//Gets the currently set sprite
	const Sprite* GetSprite() const;
	//Sets the entity's sprite
	void SetSprite(Sprite* sprite);

	//Gets the collision mode of the entity
	bool GetCollisionMode() const;
	//Sets the collision mode of the entity
	void SetCollisionMode(bool enabled);
	//Gets the hitbox of the entity
	RectF GetHitBox() const;
	//Gets the hitbox of the entity in global coordinates
	RectF GetHitBoxGlobalBounds() const;
	//Sets the entity's hitbox
	void SetHitbox(RectF hitbox);

	//Moves the sprite in the specified direction
	void Move(float x, float y);
	//Moves the sprite in the specified direction
	void Move(Vector2f direction);
	//Moves the sprite in the specified direction
	void Move(Direction direction, int scalar);

	//Gets the distance to the nearest wall in the specified direction
	float GetDistanceToWall(Direction direction) const;
	//Gets the distance to the nearest wall in the specified direction, with the applied offset to the sprite
	float GetDistanceToWall(Direction direction, Vector2f offset) const;
	//Gets the distance to the nearest wall in the specified direction, with the specified tiles to take into account
	float GetDistanceToWall(Array2D<BackgroundTile*>& tiles, Direction direction) const;
	//Gets the distance to the nearest wall in the specified direction, with the specified tiles to take into account and with the applied offset to the sprite
	float GetDistanceToWall(Array2D<BackgroundTile*>& tiles, Direction direction, Vector2f offset) const;

	//Determines if the entity is touching a wall or not
	bool IsTouchingWall(Vector2f offset = Vector2f(0, 0)) const;

	//Moves the camera to the specified position.
	//If the lerp amount is less than one, then that determines the percentage on how far the camera should move towards the new position.
	//For example if the lerp is 0.5f or 50%, then the camera will move 50% the distance between the old position and the new position
	static void MoveCameraTo(Vector2f position, float lerpAmount = 1.0f);

	//Gets the world map the entity is living in
	const WorldMap& GetMap() const;

	//The destructor for the entity
	virtual ~Entity();

};

