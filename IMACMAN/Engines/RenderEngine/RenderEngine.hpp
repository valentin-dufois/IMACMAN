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

//The engine
class RenderEngine
{
public:
				static void instanciate();

private:
				//Singleton
				static bool m_instanciated;
				RenderEngine();

        //Scene manipulation
        uint m_scenesLoadedCount;

				//Utilities

};

#endif /* RenderEngine_hpp */
