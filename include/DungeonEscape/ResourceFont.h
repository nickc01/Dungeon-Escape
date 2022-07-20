/*#pragma once

#include <string>

//Loads a SFML font from a resource
class ResourceFont
{
	//The resource to load
	sf::FileInputStream font_file;
	sf::Font font; //The loaded font

public:

	//Constructs and loads the font into memory
	ResourceFont(std::string file_path);

	//Constructs and loads the font into memory
	ResourceFont(const char* file_path);
	//Loads a blank ResourceFont
	ResourceFont();

	//Gets the font that was loaded
	const sf::Font& GetFont() const;

	//Gets the font that was loaded
	sf::Font& GetFont();
};*/

