#include "Grid.hpp"

//GETTERS
std::vector<GItem *> Grid::getGrid() const
{
    return m_gridItems;
}

/**
 Get items of the grid

 @param position Position of the item
 @return The pointeur to the item
 */
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

/**
 Get item of the grid
 
 @param enum ITEM_SYNTAX all the types of items
 @return the Item
 */
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

/**
 Check if items exist
 
 @param enum ITEM_SYNTAX all the types of items
 @return bool
 */
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

/**
 Load the grid
 
 @param level Level added
 */
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

/**
 Moves all the items of the grid
 */
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

/**
 Move an item in the grid
 
 @param item
 */
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
			
			//it's a pacman
			if (dItem->getItemType() == ITEM_SYNTAX::PACMAN) {
                this->updateCase(reinterpret_cast<Pacman *>(dItem), nextCase);
            }
			
			//It's a ghost
            if (dItem->getItemType() > ITEM_SYNTAX::PACMAN) {
				this->updateCase(reinterpret_cast<Ghost *>(dItem), nextCase);
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


/**
 Movement of Pacman
 Update the score
 @param pac pac
 @param cell Cell is in currently
 */
void Grid::updateCase(Pacman * pac, std::vector<GItem *> cell) {
    std::vector<GItem *>::const_iterator it;
    uint tmpScore = 0;

    for (it = cell.begin(); it < cell.end(); ++it) {
        switch ((*it)->getItemType()) {
            case ITEM_SYNTAX::SUPER_PAC_GUM:
            case ITEM_SYNTAX::PAC_GUM:
			{
                tmpScore += (*it)->getScore();
                pacmanFoodCollision(pac, *it);
                this->deleteGridItem((*it));
                --m_nbOfGums;
                break;
			}
            case ITEM_SYNTAX::FRUIT:
			{
                pac->updatePosition(pac->getNextPosition(), this->m_width, this->m_height);
                if (!reinterpret_cast<Fruit *>(*it)->getEatenState()) {
                    tmpScore += (*it)->getScore();
                    reinterpret_cast<Fruit *>(*it)->updatePopCounter(50);
                }
                break;
			}
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
	std::vector<GItem *>::const_iterator it;
	uint tmpScore = 0;
	
	for (it = cell.begin(); it < cell.end(); ++it) {
		switch ((*it)->getItemType()) {
			case ITEM_SYNTAX::PACMAN:
				//On vérifie qu'on peut manger pacman.
				//On le mange et le reset à la position intiale
				//vie--
				break;
			case ITEM_SYNTAX::SUPER_PAC_GUM:
			case ITEM_SYNTAX::PAC_GUM:
			case ITEM_SYNTAX::FRUIT:
			case ITEM_SYNTAX::BLINKY:
			case ITEM_SYNTAX::PINKY:
			case ITEM_SYNTAX::INKY:
			case ITEM_SYNTAX::CLYDE:
			default:
				break;
		}
	}
}

/**
 Move a ghost
 
 @param ghost Ghost to move
 */
void moveGhost(Ghost * ghost){
	enum DIRECTION nextDirection;
	glm::vec2 nextPosition = ghost->getNextPosition();
	
	switch(ghost->getItemType()) {
		case ITEM_SYNTAX::BLINKY:
		{
			if(nextPosition == glm::vec2(0,0)){
				std::cout << "Blinky if going right" << std::endl;
			}
			//FOLLOWS PACMAN ALL THE TIME//
			break;
		}
		case ITEM_SYNTAX::PINKY:
		{
			//vise l'endroit ou se dirige Pac-Man (seulement une fois sur 4 apparemment). Recherche de la position de Pacman, on calcule si en allant à une case à droite ou une case à gauche on s'en approche. Si on s'en approche, on prend cette direction.//
			break;
		}
		case ITEM_SYNTAX::INKY:
		{
			//de temps en temps, part dans la direction opposees de Pac-Man: recherche de la position de Pac-Man, puis selon la position du fantome, on calcule si en allant à une case à droite ou une case à gauche on s'en éloigne. Si on s'en éloigne, on prend cette direction.
			break;
		}
		case ITEM_SYNTAX::CLYDE:
		{
			//de temps en temps, change de direction: donc au hasard
			break;
		}
		default:
		{
			break;
		}
	}
	
	ghost->updateDirection(nextDirection);
}

/**
 Collision between Pacman and Food
Update the super counter
 @param pac
 @param food
 */
void Grid::pacmanFoodCollision(Pacman * pac, GItem * food) {
    pac->updatePosition(pac->getNextPosition(), this->m_width, this->m_height);
    
    if (food->getItemType() == ITEM_SYNTAX::SUPER_PAC_GUM) {
        pac->updateSuperCounter(30);
    }
}


/**
 Collision between Pacman and a Ghost
 Update the counter, the position and the lives
 @param pac
 @param ghost
 @return score to update
 */
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

/**
 Display the grid
 */
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
