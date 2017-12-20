//
//  ImageImporter.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef ImageImporter_hpp
#define ImageImporter_hpp

//Forward declaration
class Asset;
class Importer;

#include "../../../main.hpp"
#include <iostream>

class ImageImporter: public Importer
{
public:
	Asset * getAsset(std::string path);
	std::vector<SDL_Color> getColorPixels(SDL_Surface* surface);
	~ImageImporter();
private:

};

#endif /* ImageImporter_hpp */
