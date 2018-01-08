//
//  GameObject.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "GameObject.hpp"

#include <iostream>

GameObject * GameObj = nullptr;
bool GameObject::m_instanciated = false;


/**
 Instanciate the singleton GameObject

 @param appPath appPath
 */
void GameObject::instanciate(std::string appPath)
{
	if(m_instanciated) {
		return;
	}
	GameObj = new GameObject(appPath + "/");

	m_instanciated = true;
}


/**
 Remove a scene from the GameObject

 @param scene scene The scene to remove
 */
void GameObject::removeScene(Scene * scene)
{
	for(std::vector<Scene *>::iterator it = m_scenes.begin(); it != m_scenes.end(); ++it) {
		if((*it) == scene) {
			m_scenes.erase(it);
			return;
		}
	}
}

