//
//  ImageImporter.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef ImageImporter_hpp
#define ImageImporter_hpp

#include "Importer.hpp"

class ImageImporter: public Importer
{
public:
	Asset getAsset(std::string path);

private:
	

};

#endif /* ImageImporter_hpp */
