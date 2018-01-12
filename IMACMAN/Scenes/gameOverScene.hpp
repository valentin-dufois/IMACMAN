//
//  gameOverScene.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 12/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef gameOverScene_hpp
#define gameOverScene_hpp

//Forward declaration
class Font;

#include "Scene.hpp"
#include "Engines/RessourcesEngine/Elements/Asset.hpp"
#include "Utils/Selector/Selector.hpp"

class gameOverScene: public Scene
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
	~gameOverScene();

private:

	//Elements
	Selector m_interface;



	//Ressources
	Font * m_font;

	rId m_background;
	rId m_startBtnIdle; rId m_startBtnActive;
	rId m_quitBtnIdle;  rId m_quitBtnActive;

	void loadAssets();
};

#endif /* gameOverScene_hpp */
