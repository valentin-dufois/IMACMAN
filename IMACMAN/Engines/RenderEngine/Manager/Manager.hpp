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
#include "../../../main.hpp"

//The engine
class Manager
{
protected:

public:
  //Constructor
	virtual ~Manager() {}

  //Getters

  //Setters

  //Utils
  virtual void fillVBO() {}
};

#include "GridManager.hpp"
#include "PacmanManager.hpp"
#include "GhostsManager.hpp"

#endif /* Manager_hpp */
