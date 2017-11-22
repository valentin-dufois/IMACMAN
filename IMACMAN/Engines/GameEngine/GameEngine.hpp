//
//  GameEngine.hpp
//  IMACMAN
//
//  Created by Laurie Greinert on 22/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <iostream>

class GameEngine{
public:
	static void instanciate();
	
private:
	static bool m_instanciated;
	
	GameEngine();
};

#endif /* GameEngine_hpp */
