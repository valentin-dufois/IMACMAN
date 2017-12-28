//
//  Core.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 21/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Core_hpp
#define Core_hpp

#include "../main.hpp"

class Core
{
public:
	/**
	 Init the required components of the app
	 */
	void ignite();

	/**
	 Main loop of the app
	 */
	void main();

private:

	/**
	 Pause the app to respect 60 fps

	 @param start start of the loop
	 @param end end of the loop
	 */
	void tempo(std::chrono::high_resolution_clock::time_point start, std::chrono::high_resolution_clock::time_point end);
};

#endif /* Core_hpp */
