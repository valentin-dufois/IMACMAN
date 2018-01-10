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
	DynamicItem(Mesh * mesh, glm::vec2 position, std::string name, uint score, enum ITEM_SYNTAX type, enum DIRECTION dir):
        GItem(mesh, position, score, type),
        m_name(name),
        m_firstPosition(position),
        m_currentDirection(dir)
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
    glm::vec2 getNextPosition(glm::vec3 & translation) {
        glm::vec2 nextPos = this->getPosition();

        switch (m_currentDirection) {
            case DIRECTION::UP:
                nextPos.x += -1.f;
                nextPos.y += 0.f;
                translation = glm::vec3(-1.f, 0.f, 0.f);
                break;
            case DIRECTION::DOWN:
                nextPos.x += 1.f;
                nextPos.y += 0.f;
                translation = glm::vec3(1.f, 0.f, 0.f);
                break;
            case DIRECTION::LEFT:
                nextPos.x += 0.f;
                nextPos.y += -1.f;
                translation = glm::vec3(0.f, -1.f, 0.f);
                break;
            case DIRECTION::RIGHT:
                nextPos.x += 0.f;
                nextPos.y += 1.f;
                translation = glm::vec3(0.f, 1.f, 0.f);
                break;
            default:
                translation = glm::vec3(0.f, 0.f, 0.f);
                break;
        }
        return nextPos;
    }

    glm::vec2 getNextPosition(const enum DIRECTION & nextDirection) {
        glm::vec2 nextPos = this->getPosition();

        switch (nextDirection) {
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
