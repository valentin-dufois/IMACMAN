#ifndef PACMAN_HPP
#define PACMAN_HPP

#include "DynamicItem.hpp"

class Pacman: public DynamicItem
{
public:
	//CONSTRUCTOR
	Pacman(Mesh * mesh, glm::vec2 position, std::string name = "player", uint score = 0, ITEM_SYNTAX type = PACMAN, int lives = 3, bool isSuper = false):
		DynamicItem(mesh, position, name, score, type, DIRECTION::RIGHT),
		m_lives(lives),
		m_isSuper(isSuper),
		m_superCounter(0),
		m_realScore(0)
	{};

	//DESTRUCTOR
	~Pacman() = default;
	
	//GETTERS
	/**
	 Return the number of remaining lives of the pac-man

	 @return Number of lives
	 */
	inline uint getLives() const { return m_lives; };

	/**
	 Tell if the pacman is in super state

	 @return True if in super state, else otherwise
	 */
	inline bool isSuper() const { return m_isSuper; };

	/**
	 Tell the remaining time before end of super state

	 @return remaining time (seconds ?)
	 */
	inline int getSuperCounter() const { return m_superCounter; };

	/**
	 Return the real (?) score of the pac-man

	 @return The score
	 */
	inline int getRealScore() const { return m_realScore; };

	//SETTERS
	/**
	 Add the given amount of life to the pac-man

	 @param addLife Amount to add
	 */
	inline void updateLives(const int addLife) { m_lives += addLife; };

	/**
	 Update pac-man super state satatus
	 */
	inline void updateIsSuper() { m_isSuper = m_superCounter > 0; };

	/**
	 Add the given amount of points to the score

	 @param points Points to add
	 */
	inline void updateRealScore(const int points) { m_realScore += points; };

	/**
	 Add more time to the super state counter

	 @param time Time to add
	 */
	void updateSuperCounter(const int time);

	/**
	 Add points to the pac-man

	 @param points Points to add
	 */
	void updateScores(const int points);

private:
	int m_lives;

	bool m_isSuper;
	int m_superCounter;

	int m_realScore;
};

#endif /* PACMAN_HPP */
