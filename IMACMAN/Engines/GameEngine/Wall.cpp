#include "Wall.hpp"

void Wall::setPosition(glm::vec2 position){
	m_position = position;
}

glm::vec2 Wall::getPosition() const{
	return m_position;
}
