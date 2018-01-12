//
//  Level.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Level_hpp
#define Level_hpp

#include "Asset.hpp"
#include <glm/glm.hpp>

class Level : public Asset
{
public:
	//Constructors
	Level(uint width, uint height, std::vector<int> grid):
		Asset(LEVEL),
		m_width(width),
		m_height(height),
		m_levelGrid(grid)
	{}

	//Getters
	uint getWidth() const;
	uint getHeight() const;
	std::vector<int> getLevelGrid() const;

	~Level() {}; 

private:
	//Structural infos

	//level infos
	uint m_width;
	uint m_height;
	std::vector<int> m_levelGrid;
};

#endif /* Level_hpp */
