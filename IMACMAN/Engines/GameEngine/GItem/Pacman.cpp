#include "Pacman.hpp"

//SETTERS
void Pacman::updateSuperCounter(const int time)
{
	m_superCounter = m_superCounter + time > 0 ? m_superCounter + time : 0 ;
	updateIsSuper();
}

void Pacman::updateScores(const int points)
{
	m_realScore += points;

	if ((m_score += points) >= 10000)
	{
		m_score -= 10000;
		++m_lives;
	}
}
