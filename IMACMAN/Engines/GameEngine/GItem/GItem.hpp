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
    enum ITEM_SYNTAX m_type;

public:
    //CONSTRUCTOR
	GItem(glm::vec2 position, uint score, enum ITEM_SYNTAX type):
        m_position(position),
        m_score(score),
        m_type(type)
    {};
    //DESTRUCTOR
	~GItem() = default;
	
    //GETTERS
    glm::vec2 getPosition() const { return m_position; }
    uint getScore() const { return m_score; }
    enum ITEM_SYNTAX getItemType() const { return m_type; }

    //SETTERS
    void setPosition(const glm::vec2 position) { m_position = position; }
    void updatePosition(glm::vec2 newPosition, uint gridWidth, uint gridHeight) {
        m_position.x = newPosition.x >= 0 ? ((int)newPosition.x % gridWidth) : ((int)newPosition.x + gridWidth);
        m_position.y = newPosition.y >= 0 ? ((int)newPosition.y % gridHeight) : ((int)newPosition.y + gridHeight);
    }
    void updateScore(const uint points) { m_score += points; }

    //METHODS
};

#endif /* GITEM_HPP */
