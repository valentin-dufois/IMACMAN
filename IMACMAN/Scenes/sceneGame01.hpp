//
//  sceneTest001.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef sceneGame01_hpp
#define sceneGame01_hpp

#include "Scene.hpp"
#include "libraries.hpp"
#include "Engines/RessourcesEngine/RessourcesEngine.hpp"
#include "Engines/RenderEngine/RenderEngine.hpp"
#include "Utils/ShaderProgram.hpp"
#include "Utils/Enums.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/ext.hpp>

class sceneGame01: public Scene
{
public:
	/**
	 Fast-forward method to instanciate, init and in the scene GameObj
	 */
	static void load();

	/**
	 Initialize the scene
	 */
	void init();

	/**
	 Execute all the actions in the scene
	 */
	void execute();

	/**
	 Render the scene on the screen
	 */
	void render();

	std::vector<Mesh *> getItemMesh(std::vector<GItem *> items);
	void renderMeshList(std::vector<Mesh *> meshList);
	glm::vec4 getGhostColor(std::string ghostName);

	/**
	 Destructor, used to properly free all the memory used by the scene
	 */
	~sceneGame01() {}

private:
	rId m_sceneID;
	ShaderProgram * scene_prog;
	Level * m_level;
	Mesh * m_sphere;
	std::vector<Mesh *> m_levelWalls;
	std::vector<Mesh *> m_levelGums;
	std::vector<Mesh *> m_levelSuperGums;
	
};

#endif /* sceneGame01_hpp */
