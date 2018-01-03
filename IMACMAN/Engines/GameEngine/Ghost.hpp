#ifndef GHOST_HPP
#define GHOST_HPP

#include <iostream>
#include <glm/glm.hpp>

class Ghost {
public:

	Ghost(std::string name, uint id, glm::vec2 position, bool isAlive = 1, bool isAfraid = 0) : m_name(name), m_id(id), m_position(position), m_isAlive(isAlive), m_isAfraid(isAfraid){};
	~Ghost();
	
	//SETTERS
	void setName(std::string name);
	void setId(uint id);
	void setPosition(glm::vec2 position);
	void setIsAlive(bool isAlive);
	void setIsAfraid(bool isAfraid);
	
	//GETTERS
	std::string getName() const;
	uint getId() const;
	glm::vec2 getPosition() const;
	bool getIsAlive() const;
	bool getIsAfraid() const;
	
private:
	std::string m_name;
	uint m_id;
	glm::vec2 m_position;
	bool m_isAlive;
	bool m_isAfraid;
};

#endif /* GHOST_HPP */
