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

//SETTERS
void Pacman::updateLives(const int live) {
	m_lives = live;
}

void Pacman::setIsSuper(const bool isSuper) {
	m_isSuper = isSuper;
}

void Pacman::setSuperCounter(const int time) {
	this->setIsSuper(true);
	m_superCounter += time;
}