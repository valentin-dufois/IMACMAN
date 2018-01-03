#ifndef PACMAN_HPP
#define PACMAN_HPP

#include <iostream>
#include <glm/glm.hpp>

class Pacman {
public:
	Pacman(std::string name, uint id, glm::vec2 position, glm::vec2 positionInit, bool isSuper) : m_name(name), m_id(id), m_position(position), m_positionInit(positionInit), m_isSuper(isSuper){};
	~Pacman();
	
	//SETTERS
	void setName(std::string name);
	void setId(uint id);
	void setPosition(glm::vec2 position);
	void setPositionInit(glm::vec2 positionInit);
	void setIsSuper(bool isSuper);
	
	//GETTERS
	std::string getName() const;
	uint getId() const;
	glm::vec2 getPosition() const;
	glm::vec2 getPositionInit() const;
	bool getIsSuper() const;
	
private:
	std::string m_name;
	uint m_id;
	glm::vec2 m_position;
	glm::vec2 m_positionInit;
	bool m_isSuper;	
};

#endif /* PACMAN_HPP */
