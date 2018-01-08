#version 330 core

layout(location = 1) in vec3 aVertexPosition;
layout(location = 2) in vec3 aVertexNormal;
layout(location = 3) in vec4 aVertexColor;
layout(location = 4) in vec2 aVertexUV;

// Matrices uniformes de transformation
uniform mat4 uMVMatrix;
uniform mat4 uMVPMatrix;
uniform mat4 uNormalMatrix;

out vec4 vColor;
//out vec2 vFragPosition;

void main() {
	//Use position as color for now
	vColor = vec4(aVertexPosition.xyz, 1);

	gl_Position = vec4(aVertexPosition, 1) * uMVPMatrix;
}

