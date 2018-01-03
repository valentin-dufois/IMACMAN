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
