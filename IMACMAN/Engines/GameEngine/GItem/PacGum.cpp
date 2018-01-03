#include "PacGum.hpp"

//GETTERS
bool PacGum::getEatenState() const {
	return m_eaten;
}

bool PacGum::getSuperGumState() const {
	return m_superGum;
}

//SETTERS
void PacGum::updateEatenState(bool eaten) {
	m_eaten = eaten;
}
