//
//  ShaderImporter.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef ShaderImporter_hpp
#define ShaderImporter_hpp

//Forward declaration
class Asset;

#include "Importer.hpp"

#include <fstream>
#include <vector>
#include <sstream>

class ShaderImporter: public Importer
{
public:
	Asset * getAsset(std::string path);

private:
	GLenum getShaderType(std::string path);
};

#endif /* ShaderImporter_hpp */
