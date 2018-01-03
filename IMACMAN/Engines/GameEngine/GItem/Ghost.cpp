#include "Ghost.hpp"

//SETTERS
void Ghost::setIsAlive(bool isAlive) {
	m_isAlive = isAlive;
}

void Ghost::setIsAfraid(bool isAfraid) {
	m_isAfraid = isAfraid;
}

//GETTERS
bool Ghost::getIsAlive() const {
	return m_isAlive;
}

bool Ghost::getIsAfraid() const {
	return m_isAfraid;
}

