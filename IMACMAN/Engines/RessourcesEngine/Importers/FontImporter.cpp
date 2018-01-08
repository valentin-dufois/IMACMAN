//
//  FontImporter.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "FontImporter.hpp"

/**
 Return an asset
 
 @param path Path of the font asset
 @return Pointor on new font asset
 */
Asset * FontImporter::getAsset(std::string path)
{
	FT_Face face;

	if(FT_New_Face(GameObj->ressourcesEngine->getFTLibrary(), path.c_str(), 0, &face))
	{
		throw std::runtime_error("Could not load font " + path);
	}

	return new Font(face);
}

FontImporter::~FontImporter()
{

}
