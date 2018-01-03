#ifndef GITEM_HPP
#define GITEM_HPP

#include <iostream>
#include <string>
#include <glm/glm.hpp>

#include "Utils/Enums.hpp"

class GItem {
protected:
	glm::vec2 m_position;
    uint m_score;

public:
    //CONSTRUCTOR
	GItem(glm::vec2 position, uint score):
        m_position(position),
        m_score(score)
    {};
    //DESTRUCTOR
	~GItem();
	
    //GETTERS
    glm::vec2 getPosition() const { return m_position; }
    uint getScore() const { return m_score; }

    //SETTERS
    void setPosition(const glm::vec2 position) { m_position = position; }
    void setScore(const uint score) { m_score = score; }

    //METHODS
};

#endif /* GITEM_HPP */
