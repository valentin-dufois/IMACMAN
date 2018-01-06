//
//  LevelImporter.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef LevelImporter_hpp
#define LevelImporter_hpp

//Forward declaration
class Asset;

#include "Importer.hpp"

class LevelImporter: public Importer
{
public:
	Asset * getAsset(std::string path);
	~LevelImporter();
private:

};

#endif /* LevelImporter_hpp */
