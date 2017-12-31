#include "../../main.hpp"
#include "Vertex.hpp"

#ifndef PRIMITIVE_HPP
#define PRIMITIVE_HPP

class Primitive {
public:
    Primitive() = default;

    virtual Vertex* getDataPointer();
    virtual GLsizei getVertexCount();

};

#endif