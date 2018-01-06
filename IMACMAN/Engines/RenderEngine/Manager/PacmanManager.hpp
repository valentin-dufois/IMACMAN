//
//  PacmanManager.hpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#ifndef PacmanManager_hpp
#define PacmanManager_hpp

#include "libraries.hpp"

//Forward declaration
class Manager;

//The engine
class PacmanManager: public Manager
{
protected:

public:
  //Constructor
	~PacmanManager() {}

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

#endif /* PacmanManager_hpp */
