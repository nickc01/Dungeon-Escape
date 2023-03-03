#include <DungeonEscape/AnimatedEntity.h> //Contains the AnimatedEntity class for entities that are animated

//Updates the current sprite
void AnimatedEntity::UpdateAnimatedSprite()
{
	//If the currently selected animation group exists in the map
	if (animationGroups.count(currentAnimationGroup) != 0)
	{
		//Get the list of sprites
		auto& vect = animationGroups[currentAnimationGroup];

		//If there are sprites within the list
		if (vect.size() > 0)
		{
			//Update the current sprite
			SetSprite(&vect[spriteInGroup]);
		}
	}
}

//Constructs an animated entity
AnimatedEntity::AnimatedEntity(const WorldMap& map, bool doPingPong, float animationSpeed, bool enableCollision) :
	Entity(map,enableCollision),
	animationSpeed(animationSpeed),
	PingPong(doPingPong)
{

}


//Sets the current animation group to animate with
void AnimatedEntity::SetAnimationGroup(std::string animationGroup)
{
	//If a new animation group is being set
	if (currentAnimationGroup != animationGroup)
	{
		//Reset the ping pong direction
		pingPongDirectionForward = true;
		//Reset the sprite to be the first in the group
		spriteInGroup = 0;
		//Update the current animation group
		currentAnimationGroup = animationGroup;

		//Update the current sprite
		UpdateAnimatedSprite();
	}
}

//Adds an existing sprite to an animation group
void AnimatedEntity::AddSprite(std::string group, smk::Sprite sprite)
{
	//Get the sprite list from the animation group. This creates a new list if it doesn't exist already
	auto& vector = animationGroups[group];

	//Add the sprite to the back of the sprite list
	vector.push_back(sprite);
}


//Constructs a new sprite and adds it to an animation group
void AnimatedEntity::EmplaceSprite(std::string group, smk::Texture& texture, Rect<int> rect,Vector2f scale)
{
	//Get the sprite list from the animation group. This creates a new list if it doesn't exist already
	auto& vector = animationGroups[group];

	//Construct the sprite
	smk::Sprite sprite = smk::Sprite(texture, rect);

	//Set the sprite's scale
	sprite.SetScale(std::get<0>(scale), std::get<1>(scale));

	//Add the sprite to the back of the sprite list
	vector.push_back(sprite);
}


//Runs the specified animation sprite group if one is currently set
void AnimatedEntity::UpdateAnimations(double dt)
{
	//If there are no animation groups specified
	if (animationGroups.count(currentAnimationGroup) == 0)
	{
		//Exit out
		return;
	}

	//Increase the animation timer
	animationTimer += dt;

	//If the timer is greater than the specified animation speed
	if (animationTimer >= animationSpeed)
	{
		//Reset the animation timer
		animationTimer -= animationSpeed;

		//If ping pong mode is enabled
		if (PingPong)
		{
			//If we are animating the sprites forwards
			if (pingPongDirectionForward)
			{
				//Move to the next sprite in the animation
				spriteInGroup++;
				//If the sprite group index went past or is equal to the last index
				if (spriteInGroup >= animationGroups[currentAnimationGroup].size() - 1)
				{
					//Set it to the last index
					spriteInGroup == animationGroups[currentAnimationGroup].size() - 1;
					//Start animating backwards
					pingPongDirectionForward = false;
				}
			}
			//If we are animating backwards
			else
			{
				//Move to the next sprite in the animation
				spriteInGroup--;
				//If the sprite group index is less than or equal to the first index
				if (spriteInGroup <= 0)
				{
					//Set it to the first index
					spriteInGroup = 0;
					//Start animating forwards
					pingPongDirectionForward = true;
				}
			}
		}
		//If ping pong mode is disabled
		else
		{
			//Go to the next sprite
			spriteInGroup++;
			
			//If the sprite group index goes past the last sprite in the animation
			if (spriteInGroup >= animationGroups[currentAnimationGroup].size())
			{
				//Reset it back to the first sprite
				spriteInGroup = 0;
			}
		}
		//Update the current sprite
		UpdateAnimatedSprite();
	}
}
