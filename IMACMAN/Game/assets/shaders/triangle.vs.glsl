#version 330 core

layout(location = 1) in vec3 aVertexPosition;
layout(location = 2) in vec3 aVertexNormal;
layout(location = 3) in vec4 aVertexColor;
layout(location = 4) in vec4 aVertexUV;

uniform mat4 uMVPMatrix;

out vec4 vColor;
//out vec2 vFragPosition;

void main() {
	//Use position as color for now
	vColor = vec4(aVertexPosition.xyz, 1);

	gl_Position = vec4(aVertexPosition, 1) * uMVPMatrix;
}

