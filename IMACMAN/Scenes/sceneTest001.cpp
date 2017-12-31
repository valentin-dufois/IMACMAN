//
//  sceneTest001.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "sceneTest001.hpp"

void sceneTest001::load()
{
	Scene * scene = new sceneTest001();
	scene->init();

	GameObj->addScene(scene);
}

void sceneTest001::init()
{
	//////
	//FONT

	//Load and get the font
	rId fontID = GameObj->ressourcesEngine->loadAsset("Neoneon.otf", FONT);
	Font * font = *GameObj->ressourcesEngine->getAsset(fontID);

	//Set font size
	font->setHeight(24.f);

	////////
	//SHADER

	//Generate
	m_fontFace = font->genFontFace();

	m_program = new ShaderProgram("tex2D.vs.glsl", "tex2D.fs.glsl");

	///////////
	//FONT BLOC

	std::vector<Vertex2DUV> vertices;
	vertices.push_back(Vertex2DUV(glm::vec2(-1, -1), glm::vec2(-1, -1)));
	vertices.push_back(Vertex2DUV(glm::vec2( 1, -1), glm::vec2(1, -1)));
	vertices.push_back(Vertex2DUV(glm::vec2( 1,  1), glm::vec2(1, 1)));

	vertices.push_back(Vertex2DUV(glm::vec2(-1, -1), glm::vec2(-1, -1)));
	vertices.push_back(Vertex2DUV(glm::vec2( 1,  1), glm::vec2(1, 1)));
	vertices.push_back(Vertex2DUV(glm::vec2(-1,  1), glm::vec2(-1, 1)));

	//Création d'un VBO
	GLuint vbo;
	glGenBuffers(1, &vbo);

	//Bindind du vbo sur la cible
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	//Puis on envois les données à la CG //3*N pour le nombre de sommets pour N triangles
	glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(Vertex2DUV), vertices.data(), GL_STATIC_DRAW);

	//Débinding du vbo de la cible pour éviter de le remodifier
	glBindBuffer(GL_ARRAY_BUFFER, 0);


	//Création du VAO
	glGenVertexArrays(1, &m_vao);

	//Binding du vao (un seul à la fois)
	glBindVertexArray(m_vao);

	//Dire à OpenGL qu'on utilise le VAO
	const GLuint VERTEX_ATTR_POSITION = 0;
	const GLuint VERTEX_ATTR_UV = 1;
	glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
	glEnableVertexAttribArray(VERTEX_ATTR_UV);

	m_program->use();
	//Indiquer à OpenGL où trouver les sommets
	//Bindind du vbo sur la cible
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	//Spécification du format de l'attribut de sommet position
	glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), 0);
	glVertexAttribPointer(VERTEX_ATTR_UV, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex2DUV), (const GLvoid*)offsetof(Vertex2DUV, uv));
	//Débindind du vbo de la cible pour éviter de le remodifier
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Débindind du vao de la cible pour éviter de le remodifier
	glBindVertexArray(0);

	glUniform1i(glGetUniformLocation(m_program->getProgramID(), "uTexture"), 0);



	glClearColor(1.f, 0.f, 0.f, 1.f);


	std::cout << "loaded" << std::endl;
}

void sceneTest001::execute()
{
	std::cout << "executed" << std::endl;
}

void sceneTest001::render()
{

	//On rebind le vao
	glBindVertexArray(m_vao);
	glBindTexture(GL_TEXTURE_2D, m_fontFace.chars[65].texture);

	glDrawArrays(GL_TRIANGLES, 0, 6);

	//Débindind du vao de la cible pour éviter de le remodifier
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);

	std::cout << (glGetError() == GL_NO_ERROR) << std::endl;

	std::cout << "rendered" << std::endl;
}
