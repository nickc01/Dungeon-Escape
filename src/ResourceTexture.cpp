#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources

using namespace smk; //Prevents me from having to type smk everywhere

//Constructs and Texture the font into memory
ResourceTexture::ResourceTexture(std::string file_path) : texture(file_path), _loaded(true)
{

}

ResourceTexture::ResourceTexture(const char* file_path) : ResourceTexture(std::string(file_path))
{

}

//Constructs a blank ResourceTexture
ResourceTexture::ResourceTexture() {}

//Gets the texture that was loaded
const Texture& ResourceTexture::GetTexture() const
{
	return texture;
}

//Gets the texture that was loaded
Texture& ResourceTexture::GetTexture()
{
	return texture;
}

bool ResourceTexture::Loaded() const
{
	return _loaded;
}
