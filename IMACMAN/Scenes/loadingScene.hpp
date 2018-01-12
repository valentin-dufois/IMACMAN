//
//  loadingScene.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 11/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef loadingScene_hpp
#define loadingScene_hpp

#include "Scene.hpp"
#include "Engines/RessourcesEngine/Elements/Asset.hpp"
#include "Utils/Selector/Selector.hpp"

class loadingScene: public Scene
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
	~loadingScene() {};

private:

	//Elements
	Selector m_interface;

	//Ressources
	rId m_background;

	void loadAssets();

	bool m_firstPass = true;
};

#endif /* loadingScene_hpp */
