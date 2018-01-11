//
//  sceneTest003.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 09/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef sceneTest003_hpp
#define sceneTest003_hpp

#include "Scene.hpp"
#include "libraries.hpp"
#include "Engines/RessourcesEngine/RessourcesEngine.hpp"
#include "Engines/RenderEngine/RenderEngine.hpp"
#include "Utils/ShaderProgram.hpp"
#include "Utils/Enums.hpp"
#include "Utils/Selector/Selector.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/ext.hpp>

class sceneTest003: public Scene
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

	/**
	 Destructor, used to properly free all the memory used by the scene
	 */
	~sceneTest003() {}

private:

	Mesh * m_mesh;
	Image * m_tex;
	Font * m_font;

	Selector m_menu;
};

#endif /* sceneTest003_hpp */
