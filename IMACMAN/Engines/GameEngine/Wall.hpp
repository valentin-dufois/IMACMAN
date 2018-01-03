#ifndef WALL_HPP
#define WALL_HPP

#include <iostream>
#include <glm/glm.hpp>

class Wall {
public:
	void setPosition(glm::vec2 position);
	
	glm::vec2 getPosition() const;
private:
	glm::vec2 m_position;
};

#endif /* WALL_HPP */
