//
//  primitives.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 09/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "RessourcesEngine.hpp"

Mesh * RessourcesEngine::genCube(const uint &size)
{
	std::vector<Vertex> vertexList;
	float demisize = (float)size / 2.0;

	glm::vec2
	UV(0.f, 0.f);

	glm::vec3
	A(-demisize, -demisize, -demisize),
	B(-demisize, -demisize,  demisize),
	C( demisize, -demisize,  demisize),
	D( demisize, -demisize, -demisize),
	E(-demisize,  demisize, -demisize),
	F(-demisize,  demisize,  demisize),
	G( demisize,  demisize,  demisize),
	H( demisize,  demisize, -demisize),
	normalFront(0, 0, -1),
	normalBack(0, 0, 1),
	normalLeft(-1, 0, 0),
	normalRight(1, 0, 0),
	normalBottom(0, -1, 0),
	normalTop(0, 1, 0);

	glm::vec4
	colorFront(1, 0, 0, 1),
	colorBack(0, 1, 0, 1),
	colorLeft(0, 0, 1, 1),
	colorRight(1, 1, 0, 1),
	colorBottom(0, 1, 1, 1),
	colorTop(1, 0, 1, 1);

	//Front
	vertexList.push_back(Vertex(A, normalFront, colorFront, UV));
	vertexList.push_back(Vertex(C, normalFront, colorFront, UV));
	vertexList.push_back(Vertex(B, normalFront, colorFront, UV));
	vertexList.push_back(Vertex(A, normalFront, colorFront, UV));
	vertexList.push_back(Vertex(D, normalFront, colorFront, UV));
	vertexList.push_back(Vertex(C, normalFront, colorFront, UV));

	//Back
	vertexList.push_back(Vertex(E, normalBack, colorBack, UV));
	vertexList.push_back(Vertex(F, normalBack, colorBack, UV));
	vertexList.push_back(Vertex(H, normalBack, colorBack, UV));
	vertexList.push_back(Vertex(H, normalBack, colorBack, UV));
	vertexList.push_back(Vertex(F, normalBack, colorBack, UV));
	vertexList.push_back(Vertex(G, normalBack, colorBack, UV));

	//Left
	vertexList.push_back(Vertex(A, normalLeft, colorLeft, UV));
	vertexList.push_back(Vertex(B, normalLeft, colorLeft, UV));
	vertexList.push_back(Vertex(E, normalLeft, colorLeft, UV));
	vertexList.push_back(Vertex(E, normalLeft, colorLeft, UV));
	vertexList.push_back(Vertex(B, normalLeft, colorLeft, UV));
	vertexList.push_back(Vertex(F, normalLeft, colorLeft, UV));

	//Right
	vertexList.push_back(Vertex(D, normalRight, colorRight, UV));
	vertexList.push_back(Vertex(H, normalRight, colorRight, UV));
	vertexList.push_back(Vertex(G, normalRight, colorRight, UV));
	vertexList.push_back(Vertex(D, normalRight, colorRight, UV));
	vertexList.push_back(Vertex(G, normalRight, colorRight, UV));
	vertexList.push_back(Vertex(C, normalRight, colorRight, UV));

	//Bottom
	vertexList.push_back(Vertex(A, normalBottom, colorBottom, UV));
	vertexList.push_back(Vertex(E, normalBottom, colorBottom, UV));
	vertexList.push_back(Vertex(H, normalBottom, colorBottom, UV));
	vertexList.push_back(Vertex(A, normalBottom, colorBottom, UV));
	vertexList.push_back(Vertex(H, normalBottom, colorBottom, UV));
	vertexList.push_back(Vertex(D, normalBottom, colorBottom, UV));

	//Top
	vertexList.push_back(Vertex(B, normalTop, colorTop, UV));
	vertexList.push_back(Vertex(G, normalTop, colorTop, UV));
	vertexList.push_back(Vertex(F, normalTop, colorTop, UV));
	vertexList.push_back(Vertex(B, normalTop, colorTop, UV));
	vertexList.push_back(Vertex(C, normalTop, colorTop, UV));
	vertexList.push_back(Vertex(G, normalTop, colorTop, UV));

	return new Mesh(vertexList);
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
	for(GLsizei j = 0; j <= precisionLong; ++j)
	{
		GLfloat cosTheta = cos(-glm::pi<float>() / 2 + j * dTheta);
		GLfloat sinTheta = sin(-glm::pi<float>() / 2 + j * dTheta);

		for(GLsizei i = 0; i <= precisionLat; ++i)
		{
			Vertex vertex;

			vertex.UV.x = i * rcpLat;
			vertex.UV.y = 1.f - j * rcpLong;

			vertex.normal.x = sin(i * dPhi) * cosTheta;
			vertex.normal.y = sinTheta;
			vertex.normal.z = cos(i * dPhi) * cosTheta;


			vertex.color = glm::vec4(vertex.normal, 1);

			vertex.position = radius * vertex.normal;

			data.push_back(vertex);
		}
	}

	// Construit les vertex finaux en regroupant les données en triangles:
	// Pour une longitude donnée, les deux triangles formant une face sont de la forme:
	// (i, i + 1, i + precisionLat + 1), (i, i + precisionLat + 1, i + precisionLat)
	// avec i sur la bande correspondant à la longitude
	for(GLsizei j = 0; j < precisionLong; ++j)
	{
		GLsizei offset = j * (precisionLat + 1);

		for(GLsizei i = 0; i < precisionLat; ++i)
		{
			vertices.push_back(data[offset + i]);
			vertices.push_back(data[offset + (i + 1)]);
			vertices.push_back(data[offset + precisionLat + 1 + (i + 1)]);
			vertices.push_back(data[offset + i]);
			vertices.push_back(data[offset + precisionLat + 1 + (i + 1)]);
			vertices.push_back(data[offset + i + precisionLat + 1]);
		}
	}

	return new Mesh(vertices, true);
}
