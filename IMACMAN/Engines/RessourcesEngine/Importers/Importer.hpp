//
//  Importer.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Importer_hpp
#define Importer_hpp

#include <iostream>

//Forward declaration
class Asset;

class Importer
{
public:
	 virtual Asset * getAsset(std::string path) = 0;
};

#include "ImageImporter.hpp"
#include "SoundImporter.hpp"
#include "MeshImporter.hpp"
#include "LevelImporter.hpp"
#include "ShaderImporter.hpp"

#endif /* Importer_hpp */
