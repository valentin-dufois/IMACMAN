#include "Grid.hpp"

//GETTERS
std::vector<GItem *> * Grid::getGrid()
{
    return &m_gridItems;
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
    glm::vec3 translation = glm::vec3(0.f);

    //Check wether it's a dynamic or static item.
    if (item->getItemType() < (int)ITEM_SYNTAX::PACMAN) {
        throw std::runtime_error("Error: cannot move static item!\n");
    }
    // It's dynamic so we reinterpret the cast
    DynamicItem * dItem = reinterpret_cast<DynamicItem *>(item);
    glm::vec2 nextPosition = dItem->getNextPosition(translation);

    try {
        std::vector<GItem *> nextCase = getItem(nextPosition);

        //Check next position
        if (nextCase[0]->getItemType() != ITEM_SYNTAX::WALL) {
            //If we are handling the pacman then special case !
            if (dItem->getItemType() == ITEM_SYNTAX::PACMAN) {
                this->updateCase(reinterpret_cast<Pacman *>(dItem), nextCase);
            } else {
                this->updateCase(reinterpret_cast<Ghost *>(dItem), nextCase);
            }
        }
        // Hangling Ghosts IA => direction
        if (dItem->getItemType() != ITEM_SYNTAX::PACMAN) {
            handleIA(dItem);
        }
    } catch(...) {
        //If we enconter nothing then move and update mesh transformations
        glm::vec2 previousPosition = dItem->getPosition();
        dItem->updatePosition(nextPosition, this->m_width, this->m_height);
        dItem->getMesh()->getCursor()->translate(translateMesh(dItem->getPosition(), previousPosition));
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
    glm::vec3 translation = glm::vec3(0.f);
    glm::vec2 nextPosition = pac->getNextPosition(translation);
    glm::vec2 previousPosition = pac->getPosition();
    std::vector<GItem *>::const_iterator it;
    uint tmpScore = 0;

    //UPDATE POSITION AND MESH TRANSLATION / TODO ROTATION
    pac->updatePosition(nextPosition, this->m_width, this->m_height);
    pac->getMesh()->getCursor()->translate(translateMesh(pac->getPosition(), previousPosition));

    for (it = cell.begin(); it < cell.end(); ++it) {
        switch ((*it)->getItemType()) {
            case ITEM_SYNTAX::SUPER_PAC_GUM:
            case ITEM_SYNTAX::PAC_GUM:
                pacmanFoodCollision(pac, *it, nextPosition);
                tmpScore += (*it)->getScore();
                break;
            case ITEM_SYNTAX::FRUIT:
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

void Grid::updateCase(Ghost * ghost, std::vector<GItem *> cell) {
    glm::vec3 translation = glm::vec3(0.f);
    glm::vec2 nextPosition = ghost->getNextPosition(translation);
    glm::vec2 previousPosition = ghost->getPosition();
    std::vector<GItem *>::const_iterator it;
    uint tmpScore = 0;

    //UPDATE POSITION AND MESH TRANSLATION / TODO ROTATION
    ghost->updatePosition(nextPosition, this->m_width, this->m_height);
    ghost->getMesh()->getCursor()->translate(translateMesh(ghost->getPosition(), previousPosition));

    for (it = cell.begin(); it < cell.end(); ++it) {
        switch ((*it)->getItemType()) {
            case ITEM_SYNTAX::SUPER_PAC_GUM:
            case ITEM_SYNTAX::PAC_GUM:
            case ITEM_SYNTAX::FRUIT:
            case ITEM_SYNTAX::BLINKY:
            case ITEM_SYNTAX::PINKY:
            case ITEM_SYNTAX::INKY:
            case ITEM_SYNTAX::CLYDE:
                break;
            case ITEM_SYNTAX::PACMAN:
                ghostPacmanCollision(reinterpret_cast<Pacman *>(*it), ghost);
                break;
            default:
                break;
        }
    }
}

void Grid::pacmanFoodCollision(Pacman * pac, GItem * food, glm::vec2 nextPosition) {    
    if (food->getItemType() == ITEM_SYNTAX::SUPER_PAC_GUM) {
        pac->updateSuperCounter(30);
    }
    this->deleteGridItem(food);
}

uint Grid::pacmanGhostCollision(Pacman * pac, Ghost * ghost) {
    uint tmpScore = 0;
    
    if (!ghost->isAlive()) {
    
    } else if(pac->isSuper() && ghost->isAlive()) {
        tmpScore += ghost->getScore();
        ghost->updateDeathCounter(30);
        //Position handling
        ghost->getMesh()->getCursor()->translate(
            translateMesh(ghost->getFirstPosition(), ghost->getPosition())
        );
        ghost->setPosition(ghost->getFirstPosition());

    
    } else {
        pac->updateLives(-1);
        //Position handling
        pac->getMesh()->getCursor()->translate(
            translateMesh(pac->getFirstPosition(), pac->getPosition())
        );
        pac->setPosition(pac->getFirstPosition());
    }

    return tmpScore;
}

uint Grid::ghostPacmanCollision(Pacman * pac, Ghost * ghost) {
    uint tmpScore = 0;

    if(ghost->isAfraid() && ghost->isAlive()) {
        tmpScore += ghost->getScore();
        ghost->updateDeathCounter(30);
        //Position handling
        pac->getMesh()->getCursor()->translate(
            translateMesh(ghost->getFirstPosition(), ghost->getPosition())
        );
        ghost->setPosition(ghost->getFirstPosition());
    
    } else {
        pac->updateLives(-1);
        //Position handling
        pac->getMesh()->getCursor()->translate(
            translateMesh(pac->getFirstPosition(), pac->getPosition())
        );
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

glm::vec3 Grid::translateMesh(glm::vec2 nextPosition, glm::vec2 currentPosition) {
    glm::vec2 translation = glm::vec3(0.f);
    translation.x = (nextPosition.x - currentPosition.x);
    translation.y = (nextPosition.y - currentPosition.y);

    return glm::vec3(translation, 0.f);
}

glm::vec3 Grid::translationToOrigin(glm::vec2 initialPosition, glm::vec2 currentPosition) {
    glm::vec2 translation = glm::vec3(0.f);
    float xDifference = abs((currentPosition.x - initialPosition.x));
    float yDifference = abs((currentPosition.y - initialPosition.y));

    translation.x = currentPosition.x >= initialPosition.x ? -xDifference : xDifference;
    translation.y = currentPosition.y >= initialPosition.y ? -yDifference : yDifference;

    return glm::vec3(translation, 0.f);
}


void Grid::handleIA(DynamicItem * dItem) {
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    );
    srand(ms.count());

    if (dItem->getItemType() != ITEM_SYNTAX::PACMAN &&
        reinterpret_cast<Ghost *>(dItem)->isAfraid() == true
    ) {
        dItem->updateDirection(afraidIA());
    } else {
        switch(dItem->getItemType()) {
            case ITEM_SYNTAX::BLINKY :
                dItem->updateDirection(randomMoveIA(dItem));
                break;
            case ITEM_SYNTAX::PINKY :
                dItem->updateDirection(turnRightIA());
                break;
            case ITEM_SYNTAX::INKY :
                dItem->updateDirection(stalkerIA());
                break;
            case ITEM_SYNTAX::CLYDE :
                dItem->updateDirection(terminatorIA());
                break;
            default:
                dItem->updateDirection(randomMoveIA(dItem));
                break;
        }
    }
}

enum DIRECTION Grid::randomMoveIA(DynamicItem * dItem) {
    std::vector<DIRECTION> directions;

    if (this->getItem(dItem->getNextPosition(DIRECTION::UP)).front()->getItemType() != ITEM_SYNTAX::WALL) {
        directions.push_back(DIRECTION::UP);
    } 
    if (this->getItem(dItem->getNextPosition(DIRECTION::DOWN)).front()->getItemType() != ITEM_SYNTAX::WALL) {
        directions.push_back(DIRECTION::DOWN);
    } 
    if (this->getItem(dItem->getNextPosition(DIRECTION::LEFT)).front()->getItemType() != ITEM_SYNTAX::WALL) {
        directions.push_back(DIRECTION::LEFT);
    } 
    if (this->getItem(dItem->getNextPosition(DIRECTION::RIGHT)).front()->getItemType() != ITEM_SYNTAX::WALL) {
        directions.push_back(DIRECTION::RIGHT);
    }

    enum DIRECTION currentDirection = dItem->getDirection();
    enum DIRECTION result = currentDirection;

    if (directions.size() > 2 || (directions.size() == 2 && std::find_if(
            directions.begin(),
            directions.end(),
            [currentDirection](const enum DIRECTION direction) -> bool {
                return direction == currentDirection;
            }
        ) == directions.end())) {
        result = directions[rand() % directions.size()];
    } else {
        result = directions.front();
    }

    return result;
}

enum DIRECTION Grid::turnRightIA() {
    int direction = rand() % 3;
    return (DIRECTION)direction;
}

enum DIRECTION Grid::stalkerIA() {
    int direction = rand() % 3;
    return (DIRECTION)direction;
}

enum DIRECTION Grid::terminatorIA() {
    int direction = rand() % 3;
    return (DIRECTION)direction;
}

enum DIRECTION Grid::afraidIA() {
    int direction = rand() % 3;
    return (DIRECTION)direction;
}