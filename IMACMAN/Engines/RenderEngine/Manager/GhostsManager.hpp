//
//  GhostsManager.hpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#ifndef GhostsManager_hpp
#define GhostsManager_hpp

#include "libraries.hpp"
#include "Engines/GameEngine/Ghost.hpp"

//Forward declaration
class Manager;

//The engine
class GhostsManager: public Manager
{
protected:

public:
  //Constructor
	~GhostsManager() {}

  //Getters

  //Setters

  //Utils
  void init(Ghost &ghost);
  void render();

  void fillVBO(uint nbOfVertex, std::vector<Vertex> * vertices);
  void fillVAO();

  void updateVBO();
  void updateVAO();
};

#endif /* GhostsManager_hpp */
