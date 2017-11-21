//
//  SoundImporter.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef SoundImporter_hpp
#define SoundImporter_hpp

//Forward declaration
class Asset;

#include "Importer.hpp"

class SoundImporter: public Importer
{
public:
	Asset * getAsset(std::string path);

private:

};

#endif /* SoundImporter_hpp */
