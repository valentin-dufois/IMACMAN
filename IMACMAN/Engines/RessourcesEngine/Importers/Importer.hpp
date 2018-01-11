//
//  Importer.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Importer_hpp
#define Importer_hpp

class Asset;

#include "libraries.hpp"
#include "../Elements/Asset.hpp"

class Importer
{
public:
	virtual Asset * getAsset(std::string path) = 0;
	virtual ~Importer() {}
};

#include "ImageImporter.hpp"
#include "SoundImporter.hpp"
#include "MeshImporter.hpp"
#include "LevelImporter.hpp"
#include "ShaderImporter.hpp"
#include "FontImporter.hpp"

#endif /* Importer_hpp */
