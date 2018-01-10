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
#include "Engines/GameEngine/GameEngine.hpp"
#include "Engines/RessourcesEngine/RessourcesEngine.hpp"
#include "Engines/RenderEngine/RenderEngine.hpp"
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

	void renderMesh(Mesh * mesh);
	void renderMeshList(std::vector<GItem *> meshList);

	/**
	 Destructor, used to properly free all the memory used by the scene
	 */
	~sceneGame01() {}

private:
	rId m_sceneID;
	Grid * m_gridLevel;
	
};

#endif /* sceneGame01_hpp */
