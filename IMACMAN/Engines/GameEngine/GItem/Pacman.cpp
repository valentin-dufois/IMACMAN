#include "Pacman.hpp"

//GETTERS
int Pacman::getLives() const {
	return m_lives;
}

bool Pacman::getIsSuper() const {
	return m_isSuper;
}

//SETTERS
void Pacman::updateLives(const int live) {
	m_lives = live;
}

void Pacman::setIsSuper(const bool isSuper) {
	m_isSuper = isSuper;
}