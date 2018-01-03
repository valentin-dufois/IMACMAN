#ifndef GITEM_FACTORY_HPP
#define GITEM_FACTORY_HPP

#include <iostream>
#include <glm/glm.hpp>

#include "Utils/Enums.hpp"

#include "../GItem.hpp"
#include "../Pacman.hpp"
#include "../Ghost.hpp"
#include "../PacGum.hpp"
#include "../Fruit.hpp"
#include "../Wall.hpp"

class GItemFactory {
public:
    static GItem * createItem(enum ITEM_SYNTAX item, glm::vec2 position) {
        Gitem * newItem;

        switch () {
            case WALL :
                newItem = new Wall(position);
                break;
            case PAC_GUM :
                newItem = new PacGum(position);
                break;
            case SUPER_PAC_GUM :
                newItem = new PacGum(Position, true);
                break;
            case FRUIT :
                newItem = new Fruit(Position);
                break;
            case PACMAN :
                newItem = new Pacman(Position);
                break;
            case BLINKY :
                newItem = new Ghost(Position, "Blinky");
                break;
            case PINKY :
                newItem = new Ghost(Position, "Pinky");
                break;
            case INKY :
                newItem = new Ghost(Position, "Inky");
                break;
            case CLYDE :
                newItem = new Ghost(Position, "Clyde");
                break;
            case FLOOR :
            default:
                throw std::runtime_error("not an item!");
                break;
    }
    return newItem;
};

#endif /* GITEM_FACTORY_HPP */