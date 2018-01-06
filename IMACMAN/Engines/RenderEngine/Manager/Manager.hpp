//
//  Manager.hpp
//  IMACMAN
//
//  Created by Gaëlle Calmels on 19/12/2017.
//  Copyright © 2017 Gaëlle Calmels. All rights reserved.
//

#ifndef Manager_hpp
#define Manager_hpp

//Link to main
#include "libraries.hpp"
#include "Utils/Vertex.hpp"
#include "Utils/Enums.hpp"

//The engine
class Manager
{
protected:

public:
  //Constructor
	virtual ~Manager() {}

  //Utils
  virtual void init() {}
  virtual void render() {}

  virtual void fillVBO(std::vector<Vertex> &vertices) {}
  virtual void fillVAO() {}

  virtual void updateVBO() {}
  virtual void updateVAO() {}
};

#include "GridManager.hpp"
#include "PacmanManager.hpp"
#include "GhostsManager.hpp"

#endif /* Manager_hpp */
