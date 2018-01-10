#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "DynamicItem.hpp"

class Pacman: public DynamicItem {
private:
	int m_lives;
	bool m_isSuper;
	int m_superCounter;
	int m_realScore;

public:
	//CONSTRUCTOR
	Pacman(Mesh * mesh, glm::vec2 position, std::string name = "player", uint score = 0, enum ITEM_SYNTAX type = PACMAN, int lives = 3, bool isSuper = false):
		DynamicItem(mesh, position, name, score, type, DIRECTION::RIGHT),
		m_lives(lives),
		m_isSuper(isSuper),
		m_superCounter(0),
		m_realScore(0)
	{};
	//DESTRUCTOR
	~Pacman() = default;
	
	//GETTERS
	inline int getLives() const { return m_lives; }
	inline bool isSuper() const { return m_isSuper; }
	inline int getSuperCounter() const { return m_superCounter; }
	inline int getRealScore() const { return m_realScore; }

	//SETTERS
	inline void updateLives(const int addLife) { m_lives += addLife; }
	inline void updateIsSuper() { m_isSuper = m_superCounter > 0; }
	inline void updateRealScore(const int points) { m_realScore += points; }

	void updateSuperCounter(const int time);
	void updateScores(const int points);
};

#endif /* PACMAN_HPP */
