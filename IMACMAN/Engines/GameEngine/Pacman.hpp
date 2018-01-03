#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <iostream>
#include <glm/glm.hpp>

class Pacman {
public:

	Pacman();
	~Pacman();
	
	//SETTERS
	void setName(std::string name);
	void setId(uint id);
//	void set
	
	//GETTERS
	
	
private:
	std::string m_name;
	uint m_id;
	glm::vec2 m_position;
	bool m_isSuper;	
};

#endif /* PACMAN_HPP */
