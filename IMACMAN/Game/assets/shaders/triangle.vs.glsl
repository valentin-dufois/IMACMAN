#version 330 core

layout(location = 1) in vec3 aVertexPosition;
layout(location = 2) in vec3 aVertexNormal;
layout(location = 3) in vec4 aVertexColor;
layout(location = 4) in vec2 aVertexUV;

// Matrices uniformes de transformation
uniform mat4 uMVMatrix;
uniform mat4 uMVPMatrix;
uniform mat4 uNormalMatrix;

// Sorties du shader
out vec3 vPosition_vs;
out vec3 vNormal_vs;
out vec4 vColor_vs;
out vec2 vUV_vs;

void main() {
	// Calcul des coordonnées homogènes
	vec4 vertexPosition = vec4(aVertexPosition, 1);
	vec4 vertexNormal = vec4(aVertexNormal, 0);

	//Calcul des valeurs de sortie
	vPosition_vs = vec3(uMVMatrix * vertexPosition);
	vNormal_vs = vec3(uNormalMatrix * vertexNormal);
	vColor_vs = aVertexColor;
	vUV_vs = aVertexUV;

	gl_Position = uMVPMatrix * vertexPosition;
}

