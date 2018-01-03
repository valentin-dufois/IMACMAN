#ifndef DYNAMIC_ITEM_HPP
#define DYNAMIC_ITEM_HPP

#include "GItem.hpp"

class DynamicItem: public GItem {
protected:
    std::string m_name;
    glm::vec2 m_positionInitial;
    enum DIRECTION m_currentDirection;

public:
    //CONSTRUCTOR
	DynamicItem(glm::vec2 position, std::string name, uint score):
        GItem(position, score),
        m_name(name),
        m_positionInitial(position),
        m_currentDirection(RIGHT)
    {}
    //DESTRUCTOR
	~DynamicItem();

    //GETTERS
	std::string getName() const { return m_name; }

    //SETTERS
	void setName(std::string name) { m_name = name; }

    //METHODS
    void move() {
        switch (m_currentDirection) {
            case DIRECTION::UP:
                std::cout << "move UP" << std::endl;
                break;
            case DIRECTION::DOWN:
                std::cout << "move DOWN" << std::endl;
                break;
            case DIRECTION::LEFT:
                std::cout << "move LEFT" << std::endl;
                break;
            case DIRECTION::RIGHT:
                std::cout << "move RIGHT" << std::endl;
                break;
            default:
                break;
        }
    }
};

#endif /* DYNAMIC_ITEM_HPP */
