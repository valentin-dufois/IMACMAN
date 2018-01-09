#include "Grid.hpp"

//GETTERS
std::vector<GItem *> Grid::getGrid() const
{
    return m_gridItems;
}

std::vector<GItem *> Grid::getItem(glm::vec2 position) const
{
    std::vector<GItem *> result;
    std::vector<GItem *>::const_iterator it;

    for (it = m_gridItems.begin(); it < m_gridItems.end(); ++it) {
        if (position.x == (*it)->getPosition().x &&
            position.y == (*it)->getPosition().y) {
                result.push_back(*it);
        }
    }
    
    if(result.size() == 0) {
        throw std::runtime_error("Error: There is no item at this position !\n");
    }

    return result;
}

std::vector<GItem *> Grid::getItemList(enum ITEM_SYNTAX type) const
{
    std::vector<GItem *> result;
    std::vector<GItem *>::const_iterator it;

    for (it = m_gridItems.begin(); it < m_gridItems.end(); ++it) {
        if ((*it)->getItemType() == type) {
            result.push_back(*it);
        }
    }
    
    if(result.size() == 0) {
        throw std::runtime_error("Error: There is no item of this type !\n");
    }

    return result;
}

GItem * Grid::getItem(enum ITEM_SYNTAX type) const {
    std::vector<GItem *>::const_iterator it = std::find_if(
        m_gridItems.begin(),
        m_gridItems.end(),
        [type](const GItem * item) -> bool {
            return item->getItemType() == type;
        }
    );
    
    if(it == m_gridItems.end()) {
        throw std::runtime_error("Error: There is no item with this type!\n");
    }

    return *it;
}

bool Grid::checkItemsExist(std::vector<enum ITEM_SYNTAX> types) const {
    std::vector<enum ITEM_SYNTAX>::const_iterator it;
    bool res = false;

    for (it = types.begin(); it < types.end(); ++it) {
        try {
            this->getItem((*it));
            res = true;
            break;
        } catch (...) {}
    }
    return res;
}

//SETTERS
int Grid::loadGrid(std::vector<int> level)
{
    enum ITEM_SYNTAX type;
    int countGums = 0;

    for (uint i = 0; i < m_height; ++i) {
        for (uint j = 0; j < m_width; ++j) {
            try {
                type = static_cast<ITEM_SYNTAX>(level[i * m_width + j]);
                m_gridItems.push_back(GItemFactory::createItem(type, glm::vec2((float)i, (float)j)));
                if (type == ITEM_SYNTAX::PAC_GUM || type == ITEM_SYNTAX::SUPER_PAC_GUM) {
                    ++countGums;
                }

            } catch(...) {
                continue;
            }
        }
    }
    return countGums;
}

//METHODS
void Grid::moveItems()
{
    std::vector<GItem *>::iterator it;

    for(it = m_gridItems.begin(); it < m_gridItems.end(); ++it) {
        try {
            this->moveItem(*it);
        } catch (...) {
            continue;
        }
    }
}

void Grid::moveItem(GItem * item)
{
    //Check wether it's a dynamic or static item.
    if (item->getItemType() < (int)ITEM_SYNTAX::PACMAN) {
        throw std::runtime_error("Error: cannot move static item!\n");
    }
    // It's dynamic so we reinterpret the cast
    DynamicItem * dItem = reinterpret_cast<DynamicItem *>(item);
    
    try {
        std::vector<GItem *> nextCase = getItem(dItem->getNextPosition());

        //Check next position
        if (nextCase[0]->getItemType() != ITEM_SYNTAX::WALL) {
            if (dItem->getItemType() == ITEM_SYNTAX::PACMAN) {
                this->updateCase(reinterpret_cast<Pacman *>(dItem), nextCase);
            }
            if (dItem->getItemType() > ITEM_SYNTAX::PACMAN) {
                //TODO: MANAGE GHOSTS BEHAVIOR
            }
        }
    } catch(...) {
        //If we enconter nothing then move
        dItem->updatePosition(dItem->getNextPosition(), m_width, m_height);
    }
}

void Grid::deleteGridItem(GItem * item) {
    std::vector<GItem *>::const_iterator it;

    for (it = m_gridItems.begin(); it < m_gridItems.end(); ++it) {
        if (*it == item) {
            m_gridItems.erase(it);
        }
    }
}

void Grid::updateCase(Pacman * pac, std::vector<GItem *> cell) {
    std::vector<GItem *>::const_iterator it;
    uint tmpScore = 0;

    for (it = cell.begin(); it < cell.end(); ++it) {
        switch ((*it)->getItemType()) {
            case ITEM_SYNTAX::SUPER_PAC_GUM:
            case ITEM_SYNTAX::PAC_GUM:
                pacmanFoodCollision(pac, *it);
                tmpScore += (*it)->getScore();
                break;
            case ITEM_SYNTAX::FRUIT:
                pac->updatePosition(pac->getNextPosition(), this->m_width, this->m_height);
                if (!reinterpret_cast<Fruit *>(*it)->getEatenState()) {
                    tmpScore += (*it)->getScore();
                    reinterpret_cast<Fruit *>(*it)->updatePopCounter(50);
                }
                break;
            case ITEM_SYNTAX::BLINKY:
            case ITEM_SYNTAX::PINKY:
            case ITEM_SYNTAX::INKY:
            case ITEM_SYNTAX::CLYDE:
                tmpScore += pacmanGhostCollision(pac, reinterpret_cast<Ghost *>(*it));
                break;
            default:
                break;
        }
    }
    pac->updateScores(tmpScore);
}

void Grid::pacmanFoodCollision(Pacman * pac, GItem * food) {
    pac->updatePosition(pac->getNextPosition(), this->m_width, this->m_height);
    
    if (food->getItemType() == ITEM_SYNTAX::SUPER_PAC_GUM) {
        pac->updateSuperCounter(30);
    }
    this->deleteGridItem(food);
}

uint Grid::pacmanGhostCollision(Pacman * pac, Ghost * ghost) {
    uint tmpScore = 0;
    
    if (!ghost->isAlive()) {
        pac->updatePosition(pac->getNextPosition(), this->m_width, this->m_height);
    
    } else if(pac->isSuper() && ghost->isAlive()) {
        tmpScore += ghost->getScore();
        ghost->updateDeathCounter(30);
        pac->updatePosition(pac->getNextPosition(), this->m_width, this->m_height);
    
    } else {
        pac->updateLives(-1);
        pac->setPosition(pac->getFirstPosition());
    }

    return tmpScore;
}

void Grid::displayGrid() {
    GItem * currItem;
    enum ITEM_SYNTAX currType;

    for (uint i = 0; i < m_height; ++i) {
        for (uint j = 0; j < m_width; ++j) {
            try {  
                currItem = this->getItem(glm::vec2((float)i, (float)j))[0];
                currType = currItem->getItemType();

                if (currType == ITEM_SYNTAX::FRUIT &&
                    reinterpret_cast<Fruit *>(currItem)->getEatenState()
                ) {
                    std::cout << "  ";
                } else {
                    std::cout << m_displayMap[currType] << " ";
                }
            } catch(...){
                std::cout << m_displayMap[ITEM_SYNTAX::FLOOR] << " ";
            }

        }
        std::cout << std::endl;
    }
}