#ifndef PACGUM_HPP
#define PACGUM_HPP

#include "StaticItem.hpp"

class PacGum: public StaticItem {
private:
	bool m_superGum;
	bool m_eaten;

public:
	//CONSTRUCTOR
	PacGum(glm::vec2 position, uint score = 10, bool superGum = false, bool eaten = false) :
		StaticItem(position, score),
		m_superGum(superGum),
		m_eaten(eaten)
	{};
	//DESTRUCTOR
	~PacGum();
	
	//GETTERS
	bool getEatenState() const;
	bool getSuperGumState() const;

	//SETTERS
	void updateEatenState(bool eaten);
};

#endif /* PACGUM_HPP */
