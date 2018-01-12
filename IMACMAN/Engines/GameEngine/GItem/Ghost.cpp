#include "Ghost.hpp"

//SETTERS
void Ghost::setIsAlive(bool isAlive)
{
	m_isAlive = isAlive;
}

void Ghost::setIsAfraid(bool isAfraid)
{
	m_isAfraid = isAfraid;
}

void Ghost::updateDeathCounter(const int time)
{
	m_waitCounter = m_waitCounter + time > 0 ? m_waitCounter + time : 0 ;

	setIsAlive(m_waitCounter == 0);
}
