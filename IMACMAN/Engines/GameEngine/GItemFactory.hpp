#ifndef GITEM_FACTORY_HPP
#define GITEM_FACTORY_HPP

#include <iostream>
#include <glm/glm.hpp>

#include "Utils/Enums.hpp"

#include "GItem/GItem.hpp"
#include "GItem/DynamicItem.hpp"
#include "GItem/StaticItem.hpp"
#include "GItem/Pacman.hpp"
#include "GItem/Ghost.hpp"
#include "GItem/PacGum.hpp"
#include "GItem/Fruit.hpp"
#include "GItem/Wall.hpp"
#include "GItem/Floor.hpp"

class GItemFactory {
public:
    static GItem * createItem(enum ITEM_SYNTAX itemType, glm::vec2 position) {
        GItem * newItem;

        switch (itemType) {
            case WALL :             newItem = new Wall(position);                       break;
            case PAC_GUM :          newItem = new PacGum(position);                     break;
            case SUPER_PAC_GUM :    newItem = new PacGum(position, 100, true);          break;
            case FRUIT :            newItem = new Fruit(position);                      break;
            case PACMAN :           newItem = new Pacman(position);                     break;
            case BLINKY :           newItem = new Ghost(position, "Blinky", itemType);  break;
            case PINKY :            newItem = new Ghost(position, "Pinky", itemType);   break;
            case INKY :             newItem = new Ghost(position, "Inky", itemType);    break;
            case CLYDE :            newItem = new Ghost(position, "Clyde", itemType);   break;
            case FLOOR:             throw std::runtime_error("floor!");                 break;
            default:                throw std::runtime_error("not an item!");           break;
        }
        return newItem;
    }
};

#endif /* GITEM_FACTORY_HPP */