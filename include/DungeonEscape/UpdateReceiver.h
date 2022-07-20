#pragma once

#include <DungeonEscape/ObjectManager.h> //Contains the ObjectManager class, which is used to store a collection of all instantiated objects
#include <vector>

//Allows objects to receive update events
class UpdateReceiver : public ObjectManager<UpdateReceiver>
{
public:
	//Constructs a new update receiver
	UpdateReceiver(bool enabled = false);

	//Whether to enable updating or not
	void EnableUpdating(bool enabled = true);

	//Gets the list of all updatable objects
	static std::vector<UpdateReceiver*>& GetUpdatables();

	//The update loop
	virtual void Update(double dt) = 0;
};

