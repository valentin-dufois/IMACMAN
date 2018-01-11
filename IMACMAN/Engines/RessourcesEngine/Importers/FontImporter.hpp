//
//  FontImporter.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef FontImporter_hpp
#define FontImporter_hpp

//Forward declaration
class Asset;
class Importer;

#include "Importer.hpp"

class FontImporter: public Importer
{
public:
	Asset * getAsset(std::string path);
	~FontImporter();

private:

};

#endif /* FontImporter_hpp */
