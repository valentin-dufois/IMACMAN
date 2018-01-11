#version 330

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec4 vColor_vs; // Couleur
in vec2 vUV_vs;

out vec4 fFragColor;

uniform bool uTexturedMesh;
uniform sampler2D uTexture;

void main()
{
	if(uTexturedMesh)
	{
		//texture
		fFragColor = vec4(texture(uTexture, vUV_vs).rgb, .5);

		if (fFragColor.r <= 0.05 && fFragColor.g <= 0.05 && fFragColor.b <= 0.05) {
			discard;
		}

		return;
	}

	//color
	//fFragColor = vec4(normalize(vNormal_vs), 1);
	fFragColor = vColor_vs;
	//fFragColor = vec4(1, 1, 1, 1);
}
