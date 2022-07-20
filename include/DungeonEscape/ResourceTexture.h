#pragma once

//#include <SFML/Graphics.hpp> //Contains many essential SFML classes and functions for rendering

#include <string> //Contains std::string
//#include <SFML/System.hpp>
#include <SDL.h>

//Loads a SFML Texture from a resource
class ResourceTexture
{
	SDL_Surface* texture = nullptr;

	const char* file_path = nullptr;

	//The resource to load
	//sf::FileInputStream texture_file;

	//sf::Texture texture; //The loaded Texture

public:

	//Constructs the Texture into memory
	ResourceTexture(std::string file_path);

	//Constructs the Texture into memory
	ResourceTexture(const char* file_path);
	//Constructs a blank ResourceTexture
	ResourceTexture();

	//Gets the texture that was loaded
	const SDL_Surface* GetTexture() const;

	//Gets the texture that was loaded
	SDL_Surface* GetTexture();
};

