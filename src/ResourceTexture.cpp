/*#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources
#include <SDL_image.h>

//using namespace sf; //Prevents me from having to type sf everywhere

//Constructs and Texture the font into memory
ResourceTexture::ResourceTexture(std::string file_path)
{
	//texture_file.open(file_path);

	//Load the texture from the resource memory
	//texture.loadFromStream(texture_file);
}

ResourceTexture::ResourceTexture(const char* file_path) : ResourceTexture(std::string(file_path))
{
	SDL_Surface* test;
}

//Constructs a blank ResourceTexture
ResourceTexture::ResourceTexture() {}

//Gets the texture that was loaded
const SDL_Surface* ResourceTexture::GetTexture() const
{
	if (texture == nullptr)
	{
		texture = IMG_Load()
	}
	return texture;
}

//Gets the texture that was loaded
SDL_Surface* ResourceTexture::GetTexture()
{
	return texture;
}*/
