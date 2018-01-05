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

//SETTERS
void Grid::loadGrid(std::vector<int> level)
{
    for (uint i = 0; i < m_height; ++i) {
        for (uint j = 0; j < m_width; ++j) {
            try {
                m_gridItems.push_back(GItemFactory::createItem(
                    static_cast<ITEM_SYNTAX>(level[i * m_width + j]),
                    glm::vec2((float)i, (float)j)
                ));
            } catch(...) {
                continue;
            }
        }
    }
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
                this->updateCase(dItem, nextCase);
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

void Grid::updateCase(DynamicItem * pac, std::vector<GItem *> cell) {
    std::vector<GItem *>::const_iterator it, it2;
    uint tmpScore = 0;

    for (it = cell.begin(); it < cell.end(); ++it) {
        switch ((*it)->getItemType()) {
            case ITEM_SYNTAX::PAC_GUM:
            case ITEM_SYNTAX::SUPER_PAC_GUM:
            case ITEM_SYNTAX::FRUIT:
                tmpScore += (*it)->getScore();
                pac->updatePosition(pac->getNextPosition(), m_width, m_height);

                for (it2 = m_gridItems.begin(); it2 < m_gridItems.end(); ++it2) {
                    if (*it2 == *it) {
                        m_gridItems.erase(it2);
                    }
                }

                if ((*it)->getItemType() == ITEM_SYNTAX::SUPER_PAC_GUM) {
                    reinterpret_cast<Pacman *>(pac)->setIsSuper(true);
                }

                break;
            case ITEM_SYNTAX::BLINKY:
            case ITEM_SYNTAX::PINKY:
            case ITEM_SYNTAX::INKY:
            case ITEM_SYNTAX::CLYDE:
                tmpScore = pacmanGhostCollision(
                    reinterpret_cast<Pacman *>(pac),
                    reinterpret_cast<Ghost *>(*it)
                );
                break;
            default:
                break;
        }
    }
    pac->updateScore(tmpScore);
}

uint Grid::pacmanGhostCollision(Pacman * pac, Ghost * ghost) {
    uint tmpScore = 0;
    
    if (!ghost->isAlive()) {
        pac->updatePosition(pac->getNextPosition(), m_width, m_height);
    
    } else if( pac->isSuper() ? true : false && ghost->isAlive()) {
        tmpScore += ghost->getScore();
        ghost->setIsAlive(false);
        pac->updatePosition(pac->getNextPosition(), m_width, m_height);
    
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

                std::cout << m_displayMap[currType] << " ";
            } catch(...){
                std::cout << m_displayMap[ITEM_SYNTAX::FLOOR] << " ";
            }

        }
        std::cout << std::endl;
    }
}

void Grid::moveGhost(Ghost * ghost){
	enum DIRECTION nextDirection;
	glm::vec2 nextPosition = ghost->getNextPosition();

	//Parcourir le tableau d'item pour savoir si c'est un mur
	
	//WHAT GHOST IT IS?
	switch(ghost->getItemType()) {
		case ITEM_SYNTAX::BLINKY:
			if(nextPosition == glm::vec2(0,0)){
				std::cout << "Blinky if going right" << std::endl;
			}
			//FOLLOWS PACMAN ALL THE TIME//
			break;
		case ITEM_SYNTAX::PINKY:
			//vise l'endroit ou se dirige Pac-Man (seulement une fois sur 4 apparemment). Recherche de la position de Pacman, on calcule si en allant à une case à droite ou une case à gauche on s'en approche. Si on s'en approche, on prend cette direction.//
			break;
		case ITEM_SYNTAX::INKY:
			//de temps en temps, part dans la direction opposees de Pac-Man: recherche de la position de Pac-Man, puis selon la position du fantome, on calcule si en allant à une case à droite ou une case à gauche on s'en éloigne. Si on s'en éloigne, on prend cette direction.
			break;
		case ITEM_SYNTAX::CLYDE:
			//de temps en temps, change de direction: donc au hasard
			break;
		default:
			break;
	}
	
	//Le faire sortir après un timer
	ghost->updateDirection(nextDirection);
}
