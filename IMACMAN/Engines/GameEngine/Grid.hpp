#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include <vector>
#include "Wall.hpp"

class Grid {
public:
	
	Grid(uint width, uint height, std::vector<int> grid, std::vector<Wall> walls) : m_width(width), m_height(height), m_grid(grid), m_walls(walls){};
	~Grid();
	
	//SETTERS
	void setWidth(uint width);
	void setHeight(uint height);
	void setgrid(std::vector<int> grid);
	void setWalls(std::vector<Wall> walls);
	
	//GETTERS
	uint getWidth() const;
	uint getHeight() const;
	std::vector<int> getGrid() const;
	std::vector<Wall> getWalls() const;
	
private:
	uint m_width;
	uint m_height;
	std::vector<int> m_grid;
	std::vector<Wall> m_walls;
};

#endif /* GRID_HPP */
