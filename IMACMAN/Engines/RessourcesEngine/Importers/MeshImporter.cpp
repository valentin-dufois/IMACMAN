//
//  MeshImporter.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "MeshImporter.hpp"

Asset * MeshImporter::getAsset(std::string path)
{
	Assimp::Importer importer;

	const aiScene* scene = importer.ReadFile(path,
											 aiProcess_Triangulate |
											 aiProcess_SortByPType |
											 aiProcess_TransformUVCoords |
											 aiProcess_PreTransformVertices);

	if(!scene->HasMeshes())
		return new Mesh();

	std::vector<Vertex> vertex;

	//Used in the loops
	aiVector3D UV, * vertice, * normal;
	aiColor3D color;
	aiFace * aFace;
	aiMesh * aMesh;
	uint indice;

	//For each mesh in the scene
	for(int i = 0; i < scene->mNumMeshes; ++i)
	{
		//Get mesh
		aMesh = scene->mMeshes[i];

		//Check if not empty
		if(!aMesh->HasFaces())
			continue;

		color = aiColor3D(1.f, 1.f, 1.f);
		scene->mMaterials[aMesh->mMaterialIndex]->Get(AI_MATKEY_COLOR_DIFFUSE,color);

		//For each face in the mesh
		for(int j = 0; j < aMesh->mNumFaces; ++j)
		{
			//Get face
			aFace = &aMesh->mFaces[j];

			//Check if not empty
			if(aFace->mNumIndices == 0)
				continue;

			//For each vertice in the face
			for(int k = 0; k < aFace->mNumIndices; ++k)
			{
				//Get vertice indice in mesh arrays
				indice = aFace->mIndices[k];

				//Retrieve vertice properties
				vertice = &aMesh->mVertices[indice];
				normal = &aMesh->mNormals[indice];

				if(aMesh->HasTextureCoords(0))
					UV = aMesh->mTextureCoords[0][indice];
				else
					UV = aiVector3D(vertice->y, vertice->x, 0);

				//Add vertice as a vertex
				vertex.push_back(Vertex(
										glm::vec3(vertice->x, vertice->y, vertice->z),
										glm::vec3(normal->x,  normal->y,  normal->z),
										glm::vec4(color.r, color.g, color.b, 1),
										glm::vec2(UV.x, UV.y)));
			}
		}
	}

	//Build and return the mesh
	return new Mesh(vertex);
}
