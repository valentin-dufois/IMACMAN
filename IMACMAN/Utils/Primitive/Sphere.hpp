#include "../../main.hpp"

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere {
public:
    //Constructor
    void build(GLfloat radius, GLsizei discLat, GLsizei discLong);

    Sphere(GLfloat radius, GLsizei discLat, GLsizei discLong) {
        build(radius, discLat, discLong);
    }

    //Getters
    Vertex* getDataPointer() {
        return &m_vertices[0];
    }
    GLsizei getVertexCount() {
        return m_vertexCount;
    }

private:
    std::vector<Vertex> m_vertices;
    GLsizei m_vertexCount;
};

#endif