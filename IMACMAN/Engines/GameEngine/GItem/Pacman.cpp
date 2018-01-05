#include "Pacman.hpp"

//GETTERS
int Pacman::getLives() const {
	return m_lives;
}

bool Pacman::isSuper() const {
	return m_isSuper;
}

int Pacman::getSuperCounter() const {
	return m_superCounter;
}