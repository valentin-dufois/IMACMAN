#version 330 core

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View

uniform vec3 uKd;
uniform vec3 uKs;
uniform float uShininess;

uniform vec3 uLightDir_vs;
uniform vec3 uLightIntensity;

out vec3 fFragColor;

vec3 blinnPhong() {
	vec3 wi = normalize(uLightDir_vs);
	
	vec3 w0 = normalize(-vPosition_vs);
	
	vec3 halfVector = normalize((w0 + wi) / 2);
	
	float coef_dif = dot(wi, normalize(vNormal_vs));
	if (coef_dif<0) coef_dif = 0.0;
	float coef_shiny = dot(halfVector, normalize(vNormal_vs));
	if (coef_shiny<0) coef_shiny = 0.0;
	
	return uLightIntensity * (uKd * coef_dif) + uKs * pow(coef_shiny, uShininess);
}

void main() {
	fFragColor = blinnPhong();
}
