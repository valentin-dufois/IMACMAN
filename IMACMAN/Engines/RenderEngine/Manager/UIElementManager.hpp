//
//  UIElementManager.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 06/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef UIElementManager_hpp
#define UIElementManager_hpp

#include "libraries.hpp"

//Forward declaration
class Manager;

//The engine
class UIElementManager: public Manager
{
protected:

public:
	//Constructor
	~UIElementManager() {}

	//Getters

	//Setters

	//Utils
	void init();
	void render();

	void fillVBO(std::vector<Vertex> &vertices);
	void fillVAO();

	void updateVBO();
	void updateVAO();
};

#endif /* UIElementManager_hpp */
