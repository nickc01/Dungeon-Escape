#include <DungeonEscape/ResourceFont.h> //Contains the ResourceFont class, which is used to load font resources

//Constructs and loads the font into memory
ResourceFont::ResourceFont(std::string file_path, float line_height) :
	font(file_path, line_height),
	_loaded(true)
{

}

ResourceFont::ResourceFont(const char* file_path, float line_height) : ResourceFont(std::string(file_path, line_height))
{

}

//Loads a blank ResourceFont
ResourceFont::ResourceFont() {}

//Gets the font that was loaded
const smk::Font& ResourceFont::GetFont() const
{
	return font;
}

//Gets the font that was loaded
smk::Font& ResourceFont::GetFont()
{
	return font;
}

bool ResourceFont::Loaded() const
{
	return _loaded;
}
