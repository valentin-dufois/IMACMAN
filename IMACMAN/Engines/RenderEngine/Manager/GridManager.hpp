//
//  GridManager.hpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#ifndef GridManager_hpp
#define GridManager_hpp

#include "libraries.hpp"
#include "Engines/GameEngine/Grid.hpp"

//Forward declaration
class Manager;

//The engine
class GridManager: public Manager
{
protected:

public:
  //Constructor
	~GridManager() {}

  //Getters

  //Setters

  //Utils
  void init();
  void render();
  
  void fillVBO(uint nbOfVertex, std::vector<Vertex> * vertices);
  void fillVAO();

  void updateVBO();
  void updateVAO();
};

#endif /* GridManager_hpp */
