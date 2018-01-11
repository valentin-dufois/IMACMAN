//
//  mainMenu.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 11/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef mainMenu_hpp
#define mainMenu_hpp

#include "Scene.hpp"
#include "Engines/RessourcesEngine/Elements/Asset.hpp"
#include "Utils/Selector/Selector.hpp"

class mainMenu: public Scene
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
	~mainMenu() {};

private:

	//Elements
	Selector m_menu;

	//Ressources
	rId m_mainLogo;
	rId m_startBtnIdle; rId m_startBtnActive;
	rId m_helpBtnIdle;  rId m_helpBtnActive;
	rId m_quitBtnIdle;  rId m_quitBtnActive;
	rId m_background;

	void loadAssets();
};

#endif /* mainMenu_hpp */
