#ifndef PACGUM_HPP
#define PACGUM_HPP

#include "StaticItem.hpp"

class PacGum: public StaticItem {
private:
	bool m_superGum;

public:
	//CONSTRUCTOR
	PacGum(glm::vec2 position, uint score = 1000, bool superGum = false) :
		StaticItem(position, score, (superGum == false ? PAC_GUM : SUPER_PAC_GUM)),
		m_superGum(superGum)
	{};
	//DESTRUCTOR
	~PacGum() = default;
	
	//GETTERS
	bool getSuperGumState() const;

	//SETTERS

};

#endif /* PACGUM_HPP */
