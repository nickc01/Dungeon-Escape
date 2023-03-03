#pragma once

#include <DungeonEscape/Graphics.h> //Contains many essential SFML classes and functions for rendering
#include <string>
//#include <SFML/System.hpp>

//Loads a SFML font from a resource
class ResourceFont
{
	//The resource to load
	smk::FileInputStream font_file;
	smk::Font font; //The loaded font

public:

	//Constructs and loads the font into memory
	ResourceFont(std::string file_path);

	//Constructs and loads the font into memory
	ResourceFont(const char* file_path);
	//Loads a blank ResourceFont
	ResourceFont();

	//Gets the font that was loaded
	const smk::Font& GetFont() const;

	//Gets the font that was loaded
	smk::Font& GetFont();
};

