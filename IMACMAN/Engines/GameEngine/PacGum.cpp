#include "PacGum.hpp"

//SETTERS
void PacGum::setPosition(glm::vec2 position){
	m_position = position;
}

void PacGum::setAte(bool ate){
	m_ate = ate;
}

//GETTERS
glm::vec2 PacGum::getPosition() const{
	return m_position;
}

bool PacGum::getAte()const{
	return m_ate;
}
