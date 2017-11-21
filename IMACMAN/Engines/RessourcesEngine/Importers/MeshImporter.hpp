//
//  MeshImporter.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef MeshImporter_hpp
#define MeshImporter_hpp

//Forward declaration
class Asset;

#include "Importer.hpp"

class MeshImporter: public Importer
{
public:
	Asset * getAsset(std::string path);

private:

};

#endif /* MeshImporter_hpp */
