#include <DungeonEscape/ResourceTexture.h> //Contains the ResourceTexture class for loading in texture resources

using namespace sf; //Prevents me from having to type sf everywhere

//Constructs and Texture the font into memory
ResourceTexture::ResourceTexture(std::string file_path)
{
	texture_file.open(file_path);

	//Load the texture from the resource memory
	texture.loadFromStream(texture_file);
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
