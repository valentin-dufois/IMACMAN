#include "Grid.hpp"

//SETTERS
void Grid::setWidth(uint width){
	m_width = width;
}

void Grid::setHeight(uint height){
	m_height = height;
}

void Grid::setgrid(std::vector<int> grid){
	m_grid = grid;
}

void Grid::setWalls(std::vector<Wall> walls){
	m_walls = walls;
}

//GEETERS
uint Grid::getWidth() const{
	return m_width;
}

uint Grid::getHeight() const{
	return m_height;
}

std::vector<int> Grid::getGrid() const{
	return m_grid;
}

std::vector<Wall> Grid::getWalls() const{
	return m_walls;
}
