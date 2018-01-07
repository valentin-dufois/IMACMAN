#version 330 core

layout(location = 1) in vec3 aVertexPosition;
layout(location = 4) in vec2 aVertexUV;

//Transform matrix
uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

out vec2 vFragUV;

void main() {
	vFragUV = aVertexUV;

	vec4 vertexPosition = vec4(aVertexPosition, 1);

	gl_Position = uMVPMatrix * vertexPosition;
}
