//
//  RessourcesEngine.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "RessourcesEngine.hpp"

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
		throw std::runtime_error("Could not load FreeType.");
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

Mesh * RessourcesEngine::genCube(const uint &size)
{
	std::vector<Vertex> vertexList;
	uint demisize = size >> 2;

	glm::vec3
		A(-demisize, -demisize, -demisize),
		B(-demisize, -demisize,  demisize),
		C( demisize, -demisize,  demisize),
		D( demisize, -demisize, -demisize),
		E(-demisize, -demisize, -demisize),
		F(-demisize, -demisize,  demisize),
		G( demisize, -demisize,  demisize),
		H( demisize, -demisize, -demisize);

	//Bottom
	vertexList.push_back(Vertex(A));
	vertexList.push_back(Vertex(B));
	vertexList.push_back(Vertex(C));
	vertexList.push_back(Vertex(A));
	vertexList.push_back(Vertex(D));
	vertexList.push_back(Vertex(C));

	//Left
	vertexList.push_back(Vertex(A));
	vertexList.push_back(Vertex(E));
	vertexList.push_back(Vertex(F));
	vertexList.push_back(Vertex(A));
	vertexList.push_back(Vertex(B));
	vertexList.push_back(Vertex(F));

	//Back
	vertexList.push_back(Vertex(B));
	vertexList.push_back(Vertex(C));
	vertexList.push_back(Vertex(E));
	vertexList.push_back(Vertex(C));
	vertexList.push_back(Vertex(F));
	vertexList.push_back(Vertex(G));

	//Right
	vertexList.push_back(Vertex(C));
	vertexList.push_back(Vertex(D));
	vertexList.push_back(Vertex(G));
	vertexList.push_back(Vertex(D));
	vertexList.push_back(Vertex(G));
	vertexList.push_back(Vertex(H));

	//Front
	vertexList.push_back(Vertex(A));
	vertexList.push_back(Vertex(D));
	vertexList.push_back(Vertex(E));
	vertexList.push_back(Vertex(D));
	vertexList.push_back(Vertex(E));
	vertexList.push_back(Vertex(H));

	//Top
	vertexList.push_back(Vertex(E));
	vertexList.push_back(Vertex(F));
	vertexList.push_back(Vertex(G));
	vertexList.push_back(Vertex(E));
	vertexList.push_back(Vertex(G));
	vertexList.push_back(Vertex(H));

	return Mesh(vertexList);
}

Mesh * RessourcesEngine::genSphere(const float &radius, const uint &precisionLat, const uint &precisionLong)
{
	// Equation paramétrique en (r, phi, theta) de la sphère
	// avec r >= 0, -PI / 2 <= theta <= PI / 2, 0 <= phi <= 2PI
	//
	// x(r, phi, theta) = r sin(phi) cos(theta)
	// y(r, phi, theta) = r sin(theta)
	// z(r, phi, theta) = r cos(phi) cos(theta)
	//
	// Discrétisation:
	// dPhi = 2PI / precisionLat, dTheta = PI / precisionLong
	//
	// x(r, i, j) = r * sin(i * dPhi) * cos(-PI / 2 + j * dTheta)
	// y(r, i, j) = r * sin(-PI / 2 + j * dTheta)
	// z(r, i, j) = r * cos(i * dPhi) * cos(-PI / 2 + j * dTheta)

	GLfloat rcpLat = 1.f / precisionLat, rcpLong = 1.f / precisionLong;
	GLfloat dPhi = 2 * glm::pi<float>() * rcpLat, dTheta = glm::pi<float>() * rcpLong;

	std::vector<Vertex> data;
	std::vector<Vertex> vertices;

	// Construit l'ensemble des vertex
	for(GLsizei j = 0; j <= precisionLong; ++j) {
		GLfloat cosTheta = cos(-glm::pi<float>() / 2 + j * dTheta);
		GLfloat sinTheta = sin(-glm::pi<float>() / 2 + j * dTheta);

		for(GLsizei i = 0; i <= precisionLat; ++i) {
			Vertex vertex;

			vertex.UV.x = i * rcpLat;
			vertex.UV.y = 1.f - j * rcpLong;

			vertex.normal.x = sin(i * dPhi) * cosTheta;
			vertex.normal.y = sinTheta;
			vertex.normal.z = cos(i * dPhi) * cosTheta;

			vertex.position = radius * vertex.normal;

			data.push_back(vertex);
		}
	}

	GLuint idx = 0;
	// Construit les vertex finaux en regroupant les données en triangles:
	// Pour une longitude donnée, les deux triangles formant une face sont de la forme:
	// (i, i + 1, i + precisionLat + 1), (i, i + precisionLat + 1, i + precisionLat)
	// avec i sur la bande correspondant à la longitude
	for(GLsizei j = 0; j < precisionLong; ++j) {
		GLsizei offset = j * (precisionLat + 1);
		for(GLsizei i = 0; i < precisionLat; ++i) {
			vertices.push_back(data[offset + i]);
			vertices.push_back(data[offset + (i + 1)]);
			vertices.push_back(data[offset + precisionLat + 1 + (i + 1)]);
			vertices.push_back(data[offset + i]);
			vertices.push_back(data[offset + precisionLat + 1 + (i + 1)]);
			vertices.push_back(data[offset + i + precisionLat + 1]);
		}
	}

	return Mesh(vertices);
}





/////////
//PRIVATE

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
