#ifndef PACGUM_HPP
#define PACGUM_HPP

#include <iostream>
#include <glm/glm.hpp>

class PacGum {
public:
	
	PacGum(glm::vec2 position) : m_position(position), m_ate(0);
	~PacGum();
	
	//SETTERS
	void setPosition(glm::vec2 position);
	void setAte(bool ate);
	
	//GETTERS
	glm::vec2 getPosition() const;
	bool getAte() const;
	
private:
	glm::vec2 m_position;
	bool m_ate;
};

#endif /* PACGUM_HPP */
