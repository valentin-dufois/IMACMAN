#include "Ghost.hpp"

//SETTERS
void Ghost::setName(std::string name){
	m_name = name;
}

void Ghost::setId(uint id){
	m_id = id;
}

void Ghost::setPosition(glm::vec2 position){
	m_position = position;
}

void Ghost::setIsAlive(bool isAlive){
	m_isAlive = isAlive;
}

void Ghost::setIsAfraid(bool isAfraid){
	m_isAfraid = isAfraid;
}

//GETTERS
std::string Ghost::getName() const{
	return m_name;
}

uint Ghost::getId() const{
	return m_id;
}

glm::vec2 Ghost::getPosition() const{
	return m_position;
}

bool Ghost::getIsAlive() const{
	return m_isAlive;
}

bool Ghost::getIsAfraid() const{
	return m_isAfraid;
}

