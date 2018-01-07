#version 330 core

in vec2 vFragUV;

out vec4 fFragColor;

uniform sampler2D uTexture;

void main()
{
	vec2 UVCoords = vec2(vFragUV.x, 1-vFragUV.y);
	fFragColor = texture(uTexture, vFragUV);
}

