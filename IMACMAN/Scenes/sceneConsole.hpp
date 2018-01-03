//
//  sceneTest001.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef sceneConsole_hpp
#define sceneConsole_hpp

#include "Scene.hpp"
#include "libraries.hpp"
#include "Engines/RessourcesEngine/RessourcesEngine.hpp"
#include "Engines/RenderEngine/RenderEngine.hpp"
#include "Utils/ShaderProgram.hpp"

#include <map>

class sceneConsole: public Scene
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
	~sceneConsole() {}

private:
	rId m_sceneID;
	std::map<int, char> m_map = {
		{0, ' '},
		{1, '@'},
		{2, '.'},
		{3, '*'},
		{4, 'F'},
		{5, 'P'},
		{6, 'B'},
		{7, 'Y'},
		{8, 'I'},
		{9, 'C'}
	};

	Level * m_level;
	
};

#endif /* sceneConsole_hpp */
