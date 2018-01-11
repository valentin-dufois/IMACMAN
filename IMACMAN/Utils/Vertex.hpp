#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec4 color;		//Used if Mesh.type = COLORED
	glm::vec2 UV;			//Used if Mesh.type = TEXTURED

	//////////////
	//Constructors

	Vertex() {};

	Vertex(glm::vec3 pos):
		position(pos),
		color(glm::vec4(1, 1, 1, 1)) {};

	Vertex(glm::vec3 pos, glm::vec3 aNormal):
		position(pos),
		normal(aNormal),
		color(glm::vec4(1, 1, 1, 1)) {};

	Vertex(glm::vec3 pos, glm::vec2 aUV):
		position(pos),
		color(glm::vec4(1, 1, 1, 1)),
		UV(aUV) {};

	Vertex(glm::vec3 pos, glm::vec3 aNormal, glm::vec4 aColor):
		position(pos),
		normal(aNormal),
		color(aColor) {};

	Vertex(glm::vec3 pos, glm::vec3 aNormal, glm::vec4 aColor, glm::vec2 aUV):
		position(pos),
		normal(aNormal),
		color(aColor),
		UV(aUV) {};
};

#endif /* VERTEX_HPP */
