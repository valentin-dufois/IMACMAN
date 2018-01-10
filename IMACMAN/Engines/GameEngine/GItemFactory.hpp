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

#include "Engines/RessourcesEngine/Elements/Mesh.hpp"
#include "Utils/ShaderProgram.hpp"

class GItemFactory {
public:
    static GItem * createItem(enum ITEM_SYNTAX itemType, glm::vec2 position) {
        GItem * newItem;
        Mesh * mesh = genMeshWithAttributs(position, itemType);

        switch (itemType) {
            case WALL :             newItem = new Wall(mesh, position);                       break;
            case PAC_GUM :          newItem = new PacGum(mesh, position);                     break;
            case SUPER_PAC_GUM :    newItem = new PacGum(mesh, position, 100, true);          break;
            case FRUIT :            newItem = new Fruit(mesh, position);                      break;
            case PACMAN :           newItem = new Pacman(mesh, position);                     break;
            case BLINKY :           newItem = new Ghost(mesh, position, "Blinky", itemType);  break;
            case PINKY :            newItem = new Ghost(mesh, position, "Pinky", itemType);   break;
            case INKY :             newItem = new Ghost(mesh, position, "Inky", itemType);    break;
            case CLYDE :            newItem = new Ghost(mesh, position, "Clyde", itemType);   break;
            case FLOOR:             throw std::runtime_error("floor!");                 break;
            default:                throw std::runtime_error("not an item!");           break;
        }
        return newItem;
    }

    static Mesh * genMeshWithAttributs(glm::vec2 position, enum ITEM_SYNTAX itemType) {
        ShaderProgram * shader = new ShaderProgram("triangle.vs.glsl", "triangle.fs.glsl");
        Mesh * tmpMesh;
        glm::vec4 meshColor;
        float scale = 1.f;
        bool isSphere = true;

        switch(itemType) {
            case ITEM_SYNTAX::WALL:
                isSphere = false;
                meshColor = glm::vec4(0, 185, 161, 1);
                break;
            case ITEM_SYNTAX::PAC_GUM:
                scale = 0.1f;
                meshColor = glm::vec4(255, 255, 0, 1);
                break;
            case ITEM_SYNTAX::SUPER_PAC_GUM:
                scale = 0.2f;
                meshColor = glm::vec4(255, 255, 255, 1);
                break;
            case ITEM_SYNTAX::FRUIT:
                scale = 0.3f;
                meshColor = glm::vec4(255, 0, 0, 1);
                break;
            case ITEM_SYNTAX::PACMAN:
                scale = 0.5f;
                meshColor = glm::vec4(255, 255, 0, 1);
                break;
            case ITEM_SYNTAX::BLINKY:
                scale = 0.5f;
                meshColor = glm::vec4(252, 38, 1, 1);
                break;
            case ITEM_SYNTAX::PINKY:
                scale = 0.5f;
                meshColor = glm::vec4(249, 181, 180, 1);
                break;
            case ITEM_SYNTAX::INKY:
                scale = 0.5f;
                meshColor = glm::vec4(28, 219, 221, 1);
                break;
            case ITEM_SYNTAX::CLYDE:
                scale = 0.5f;
                meshColor = glm::vec4(250, 162, 14, 1);
                break;
            default:
                break;
        }
        
        if (isSphere) {
            tmpMesh = GameObj->ressourcesEngine->genSphere(scale, 24, 24, meshColor);
        } else {
            tmpMesh = GameObj->ressourcesEngine->genCube(scale, meshColor);
        }

        tmpMesh->generate(GRID_M);
        tmpMesh->setProgram(shader);
        tmpMesh->getCursor()->translate(glm::vec3(position.x, position.y, 0));

        return tmpMesh;
    }
};

#endif /* GITEM_FACTORY_HPP */