//
//  RessourcesEngine.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef RessourcesEngine_hpp
#define RessourcesEngine_hpp

//Link to main
#include "../../main.hpp"


//Create type for ressource IDs
using rId = uint;

//Ressources types
enum ressourceType
{
				IMAGE,
				SHADER,
				SOUND,
				MESH,
				LEVEL
};

//Forward declarations
class Asset;

//Get engine dependancies
#include "Elements/Asset.hpp"


//The engine
class RessourcesEngine
{
				
};

#endif /* RessourcesEngine_hpp */

