//
//  gameOverlay.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 11/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef gameOverlay_hpp
#define gameOverlay_hpp

//Forward declaration
class Font;

#include "Scene.hpp"
#include "Utils/Selector/Selector.hpp"

class gameOverlay: public Scene
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
	~gameOverlay() {};

private:

	//Elements
	Selector m_interface;

	Item * m_liveItem;
	Item * m_scoreItem;
	Item * m_superItem;

	//Ressources
	Font * m_font;

	void loadAssets();
};

#endif /* gameOverlay_hpp */
