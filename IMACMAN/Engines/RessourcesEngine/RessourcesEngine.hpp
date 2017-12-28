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
using rId = unsigned int;

//Ressources types
enum ressourceType
{
				IMAGE,
				SHADER,
				SOUND,
				MESH,
				LEVEL
};

//Get engine dependancies
#include "Importers/Importer.hpp"
#include "Elements/Asset.hpp"


//The engine
class RessourcesEngine
{
public:
				static void instanciate();

				//Assets manipulation
				rId loadAsset(std::string &path, ressourceType type);
				Asset * getAsset(rId assetID);

private:
				//Singleton
				static bool m_instanciated;
				RessourcesEngine();

				//Assets holders
				std::map<std::string, rId> m_loadedPaths;
				std::map<rId, Asset *> m_assets;
				unsigned int m_ressourcesLoadedCount;

				Importer * getImporter(ressourceType &type);

				//Utilities
				std::string buildPath(std::string &file, ressourceType &type);
				bool fileExist(std::string filePath);
};


#endif /* RessourcesEngine_hpp */

