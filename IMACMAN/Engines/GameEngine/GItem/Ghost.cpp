#include "Ghost.hpp"

//GETTERS
bool Ghost::isAlive() const {
	return m_isAlive;
}

bool Ghost::isAfraid() const {
	return m_isAfraid;
}

//SETTERS
void Ghost::setIsAlive(bool isAlive) {
	m_isAlive = isAlive;
}

void Ghost::setIsAfraid(bool isAfraid) {
	m_isAfraid = isAfraid;
}

void Ghost::setAfraidCounter(const int time) {
	this->setIsAfraid(true);
	m_afraidCounter += time;
}