#version 330 core

layout(location = 0) in vec2 aVertexPosition;
layout(location = 1) in vec2 aVertexUV;

out vec2 vFragUV;

void main() {
    vFragUV = aVertexUV;
    gl_Position = vec4(aVertexPosition, 0, 1);
}
