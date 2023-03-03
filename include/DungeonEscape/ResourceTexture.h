#pragma once

#include <DungeonEscape/Graphics.h> //Contains many essential SFML classes and functions for rendering

#include <string> //Contains std::string
//#include <SFML/System.hpp>

//Loads a SFML Texture from a resource
class ResourceTexture
{
	//The resource to load
	smk::FileInputStream texture_file;

	smk::Texture texture; //The loaded Texture

public:

	//Constructs the Texture into memory
	ResourceTexture(std::string file_path);

	//Constructs the Texture into memory
	ResourceTexture(const char* file_path);
	//Constructs a blank ResourceTexture
	ResourceTexture();

	//Gets the texture that was loaded
	const smk::Texture& GetTexture() const;

	//Gets the texture that was loaded
	smk::Texture& GetTexture();
};

