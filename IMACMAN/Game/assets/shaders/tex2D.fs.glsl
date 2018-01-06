#version 330 core

in vec2 vFragUV;

out vec4 fFragColor;

uniform sampler2D uTexture;

void main()
{
	fFragColor = texture(uTexture, vFragUV);
}

