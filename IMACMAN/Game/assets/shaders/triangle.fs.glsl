#version 330

in vec3 vPosition_vs; // Position du sommet transformé dans l'espace View
in vec3 vNormal_vs; // Normale du sommet transformé dans l'espace View
in vec4 vColor_vs; // Couleur

out vec4 fFragColor;

void main() {
    fFragColor = vec4(normalize(vNormal_vs), 1);
}
