//
//  GameObject.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "../main.hpp"

GameObject * GameObj = nullptr;
bool GameObject::m_instanciated = false;

void GameObject::instanciate()
{
	if(m_instanciated)
		return;

	GameObj = new GameObject();

	m_instanciated = true;
}

void GameObject::addScene(Scene * scene)
{
	m_scenes.push_back(scene);
}
