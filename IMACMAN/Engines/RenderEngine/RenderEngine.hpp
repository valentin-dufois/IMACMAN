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
#include "../RessourcesEngine/RessourcesEngine.hpp"
//#include "Elements/Elements.hpp"
//#include "Managers/Managers.hpp"

//The engine
class RenderEngine
{
public:
				// Renderer configuration
				bool lights = true;
				bool RenderLights = true;
				bool thirdPersCamera = false;

				static void instanciate();

private:
				//Singleton
				static bool m_instanciated;
				//std::vector<Gluint> m_VAOs;
				RenderEngine();
				~RenderEngine();

				//Lighting
				//TODO: std::vector<DirectionalLight*> m_directionalLights;
				//TODO: std::vector<PointLight*> m_PointLights;

				//Camera
				//TODO: Camera* m_Camera;


        //Scene manipulation
        uint m_scenesLoadedCount;

				//VBO
				//std::vector<Gluint> m_VBOs;

				void setAllVBOs(uint size);
				void pushVBO();
				//vector<Gluint> getAllVBOs();
				//Gluint* getSingleVBO(const uint index);
};

#endif /* RenderEngine_hpp */
