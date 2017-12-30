//
//  RessourcesEngine.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "../../main.hpp"

bool RessourcesEngine::m_instanciated = false;

/**
 * Instanciate the engine as a Singleton
 */
void RessourcesEngine::instanciate()
{
	if(m_instanciated)
		return;

	GameObj->ressourcesEngine = new RessourcesEngine();

	m_instanciated = true;
}


RessourcesEngine::RessourcesEngine(): m_ressourcesLoadedCount(0)
{
	//Init FreeType Library
	if(FT_Init_FreeType( &m_FTLibrary ) )
	{
		throw new std::runtime_error("Could not load FreeType.");
	}
}



rId RessourcesEngine::loadAsset(std::string path, ressourceType type)
{
	std::string assetPath = buildPath(path, type);

	//Is this asset already loaded ?
	if(m_loadedPaths.find(assetPath) != m_loadedPaths.end())
		return m_loadedPaths[assetPath];

	//Load the asset
	//check if file is present
	if(!fileExist(assetPath))
		throw std::runtime_error("Error loading " + path + "\nThe file could not be found at " + assetPath + "\n");

	//Get importer for the asset
	Importer * importer = getImporter(type);

	//Import the asset
	Asset * newAsset = importer->getAsset(assetPath);

	//Free the importer
	delete importer;

	//store the asset
	rId newAssetId = m_ressourcesLoadedCount;

	m_assets.insert(std::pair<rId, Asset *>(newAssetId, newAsset));
	m_loadedPaths.insert(std::pair<std::string, rId>(assetPath, newAssetId));

	m_ressourcesLoadedCount++;

	//return the asset ID
	return newAssetId;
}



Asset * RessourcesEngine::getAsset(rId assetID)
{
	//Is this asset already loaded ?
	if(m_assets.find(assetID) == m_assets.end())
		throw std::runtime_error("Error fetching ressource. The ressource #" + std::to_string(assetID) + " does not exist.");

	return m_assets[assetID];
}



Importer * RessourcesEngine::getImporter(ressourceType &type)
{
	switch (type)
	{
		case IMAGE:
			return new ImageImporter();
			break;
		case SHADER:
			return new ShaderImporter();
			break;
		case SOUND:
			return new ImageImporter();
			break;
		case MESH:
			return new ImageImporter();
			break;
		case LEVEL:
			return new ImageImporter();
			break;
		case FONT:
			return new FontImporter();
		break;
	}
}


std::string RessourcesEngine::buildPath(std::string &file, ressourceType &type)
{
	std::string prefix;

	switch (type)
	{
		case IMAGE:
			prefix = "assets/images/";
			break;
		case SHADER:
			prefix = "assets/shaders/";
			break;
		case SOUND:
			prefix = "assets/sounds/";
			break;
		case MESH:
			prefix = "assets/meshs/";
			break;
		case LEVEL:
			prefix = "assets/levels/";
			break;
		case FONT:
			prefix = "assets/fonts/";
			break;
	}

	return prefix + file;
}

bool RessourcesEngine::fileExist(std::string filePath)
{
	std::ifstream file(filePath);

	if(file)
		return true;

	return false;
}
