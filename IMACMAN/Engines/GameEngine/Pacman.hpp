#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <iostream>
#include <glm/glm.hpp>

class Pacman {
public:

	Pacman(std::string name, uint id, glm::vec2 position, bool isSuper) : m_name(name), m_id(id), m_position(position), m_isSuper(isSuper){};
	~Pacman();
	
	//SETTERS
	void setName(std::string name);
	void setId(uint id);
	void setPosition(glm::vec2 position);
	void setIsSuper(bool isSuper);
	
	//GETTERS
	std::string getName() const;
	uint getId() const;
	
private:
	std::string m_name;
	uint m_id;
	glm::vec2 m_position;
	bool m_isSuper;	
};

#endif /* PACMAN_HPP */
