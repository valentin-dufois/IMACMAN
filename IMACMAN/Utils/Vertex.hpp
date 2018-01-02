#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <iostream>
#include <vector>
#include <glm/glm.hpp>

struct Vertex
{
	glm::vec3 position;
	glm::vec4 color;		//Used if Mesh.type = COLORED
	glm::vec2 UV;			//Used if Mesh.type = TEXTURED

	glm::vec3 normal;

	Vertex() {};
	Vertex(glm::vec3 pos): position(pos) {};
};

#endif /* VERTEX_HPP */