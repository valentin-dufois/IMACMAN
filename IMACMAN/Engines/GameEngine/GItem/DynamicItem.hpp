#ifndef DYNAMIC_ITEM_HPP
#define DYNAMIC_ITEM_HPP

#include "GItem.hpp"

class DynamicItem: public GItem {
protected:
    std::string m_name;
    glm::vec2 m_firstPosition;
    enum DIRECTION m_currentDirection;

public:
    //CONSTRUCTOR
	DynamicItem(glm::vec2 position, std::string name, uint score, enum ITEM_SYNTAX type):
        GItem(position, score, type),
        m_name(name),
        m_firstPosition(position),
        m_currentDirection(RIGHT)
    {}
    //DESTRUCTOR
	~DynamicItem() = default;

    //GETTERS
	std::string getName() const { return m_name; }
    enum DIRECTION getDirection() const { return m_currentDirection; }
    glm::vec2 getFirstPosition() const { return m_firstPosition; }

    //SETTERS
	void setName(std::string name) { m_name = name; }
    void updateDirection(enum DIRECTION direction) { m_currentDirection = direction; }

    //METHODS
    glm::vec2 getNextPosition() {
        glm::vec2 nextPos = this->getPosition();

        switch (m_currentDirection) {
            case DIRECTION::UP:
                nextPos.x += -1.f;
                nextPos.y += 0.f;
                break;
            case DIRECTION::DOWN:
                nextPos.x += 1.f;
                nextPos.y += 0.f;
                break;
            case DIRECTION::LEFT:
                nextPos.x += 0.f;
                nextPos.y += -1.f;
                break;
            case DIRECTION::RIGHT:
                nextPos.x += 0.f;
                nextPos.y += 1.f;
                break;
            default:
                break;
        }
        return nextPos;
    }
};

#endif /* DYNAMIC_ITEM_HPP */
