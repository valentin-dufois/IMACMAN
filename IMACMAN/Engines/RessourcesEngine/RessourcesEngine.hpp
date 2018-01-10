//
//  RessourcesEngine.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef RessourcesEngine_hpp
#define RessourcesEngine_hpp

//Create type for ressource IDs
using rId = unsigned short int;

//Ressources types
enum ressourceType
{
	IMAGE,
	SHADER,
	SOUND,
	MESH,
	LEVEL,
	FONT
};

class Importer;

#include "libraries.hpp"
#include "Core/GameObject.hpp"
#include "Importers/Importer.hpp"
#include "Elements/Asset.hpp"

#include <glm/gtc/constants.hpp>

#include <vector>
#include <map>


//The engine
class RessourcesEngine
{
public:
	 /**
	 Instanciate the RessourcesEngine in the gameObj as a Singleton
	 */
	static void instanciate();

	/**
	 Return an ID to an asset.
	 Import the asset if needed. Prevent multiple importation

	 @param path Path to the asset in its type folder
	 @param type Type of the asset
	 @return The asset ressourceID
	 */
	rId loadAsset(std::string path, ressourceType type);

	/**
	 Return an asset
	 This function return nullptr if the asset ID is not found

	 @param assetID ID of the asset
	 @return Pointer to the asset
	 */
	Asset * getAsset(rId assetID);

	/**
	 Return the handle to FreeType

	 @return The FreeType Library
	 */
	inline FT_Library getFTLibrary() const { return m_FTLibrary; };

 	/**
 	 Generate a 3D cube as a mesh

 	 @param size Width of each edge
 	 @return The cube in a Mesh object
 	 */
 	Mesh * genCube(const uint &size, glm::vec4 baseColor = glm::vec4(255, 255, 255, 1));

	/**
	 Generate a Sphere as a mesh

	 @param radius Diameter of the sphere
	 @param precisionLat Smoothness of the sphere
	 @param precisionLong Smoothness of the sphere
	 @return The sphere in a mesh object
	 */
	Mesh * genSphere(const float &radius, const uint &precisionLat, const uint &precisionLong, glm::vec4 baseColor = glm::vec4(255, 255, 255, 1));

private:
	//Singleton
	static bool m_instanciated;
	RessourcesEngine();

	//Assets holders
	std::map<std::string, rId> m_loadedPaths;
	std::map<rId, Asset *> m_assets;
	unsigned int m_ressourcesLoadedCount;

	/**
	 Return the appropriate importer for the given assets type

	 @param type Type of the asset
	 @return The importer for the given type
	 */
	Importer * getImporter(ressourceType &type);

	//Utilities
	/**
	 Build the asset path in its appropriate folder

	 @param file relative path to the asset
	 @param type Asset type
	 @return The full path to the asset
	 */
	std::string buildPath(std::string &file, ressourceType &type);

	/**
	 Tell if the given file exist

	 @param filePath Path to the file
	 @return True if it exists, false otherwise
	 */
	bool fileExist(std::string filePath);

	//FreeType handle
	FT_Library m_FTLibrary;
};


#endif /* RessourcesEngine_hpp */

