#include "Fruit.hpp"

//GETTERS
bool Fruit::getEatenState() const {
	return m_eaten;
}

//SETTERS
void Fruit::updateEatenState(bool eaten) {
	m_eaten = eaten;
}
