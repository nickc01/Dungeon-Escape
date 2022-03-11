#include <DungeonEscape/ResourceFont.h> //Contains the ResourceFont class, which is used to load font resources

//Constructs and loads the font into memory
ResourceFont::ResourceFont(std::string file_path)
{
	font_file.open(file_path);

	//Load the font from the resource
	font.loadFromStream(font_file);
}

ResourceFont::ResourceFont(const char* file_path) : ResourceFont(std::string(file_path))
{

}

//Loads a blank ResourceFont
ResourceFont::ResourceFont() {}

//Gets the font that was loaded
const sf::Font& ResourceFont::GetFont() const
{
	return font;
}

//Gets the font that was loaded
sf::Font& ResourceFont::GetFont()
{
	return font;
}
