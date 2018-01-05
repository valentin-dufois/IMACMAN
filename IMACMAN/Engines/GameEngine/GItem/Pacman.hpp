#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "DynamicItem.hpp"

class Pacman: public DynamicItem {
private:
	int m_lives;
	bool m_isSuper;
	int m_superCounter;

public:
	//CONSTRUCTOR
	Pacman(glm::vec2 position, std::string name = "player", uint score = 0, enum ITEM_SYNTAX type = PACMAN, int lives = 3, bool isSuper = false):
		DynamicItem(position, name, score, type),
		m_lives(lives),
		m_isSuper(isSuper),
		m_superCounter(0)
	{};
	//DESTRUCTOR
	~Pacman() = default;
	
	//GETTERS
	int getLives() const;
	bool isSuper() const;
	int getSuperCounter() const;

	//SETTERS
	void updateLives(const int live);
	void setIsSuper(const bool isSuper);
	void setSuperCounter(const int time);

	//METHODS
	inline void updateSuperCounter() {
		m_superCounter > 0 ? --m_superCounter : m_isSuper = false;
	}
};

#endif /* PACMAN_HPP */
