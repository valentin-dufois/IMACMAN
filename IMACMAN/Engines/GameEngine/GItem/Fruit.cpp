#include "Fruit.hpp"

//SETTERS
void Fruit::updatePopCounter(const int time) {
	m_popCounter = m_popCounter + time > 0 ? m_popCounter + time : 0 ;
	updateIsEaten();
}
