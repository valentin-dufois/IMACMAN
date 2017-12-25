//
//  RenderEngine.hpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#ifndef RenderEngine_hpp
#define RenderEngine_hpp

//Link to main
#include "../../main.hpp"

//Get engine dependancies
#include "Manager/Manager.hpp"

//Managers types
enum managerType
{
	GRID_MANAGER,
	PACMAN_MANAGER,
	GHOST_MANAGER
};

//The engine
class RenderEngine
{
public:
				// Renderer configuration accessible by all
				bool thirdPersCamera = false;

				//Singleton
				static void instanciate();

private:
				//Singleton
				static bool m_instanciated;

				//Factory
				Manager * getManager(managerType type);

				//Attributs
				GLuint m_gridVBO;
				GLuint m_pacmanVBO;
				std::vector<GLuint> m_ghostsVBO;

				//OpenGL Error
				GLenum error;

				//Constructor
				RenderEngine(GLuint gridVBO = 1, GLuint pacmanVBO = 2, std::vector<GLuint> ghostsVBO = {3, 4, 5, 6});
				~RenderEngine();

				//Utils
				void initVBO(GLenum bufferType, GLuint * index, managerType type, GLuint nbOfVBO = 1);

};

#endif /* RenderEngine_hpp */
