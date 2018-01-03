#include "Pacman.hpp"

//SETTERS
void Pacman::setName(std::string name){
	m_name = name;
}

void Pacman::setId(uint id){
	m_id = id;
}

void Pacman::setPosition(glm::vec2 position){
	m_position = position;
}

void Pacman::setPositionInit(glm::vec2 positionInit){
	m_positionInit = positionInit;
}

void Pacman::setIsSuper(bool isSuper){
	m_isSuper = isSuper;
}

//GETTERS
std::string Pacman::getName() const{
	return m_name;
}

uint Pacman::getId() const{
	return m_id;
}

glm::vec2 Pacman::getPosition() const{
	return m_position;
}

glm::vec2 Pacman::getPositionInit() const{
	return m_positionInit;
}

bool Pacman::getIsSuper() const{
	return m_isSuper;
}

