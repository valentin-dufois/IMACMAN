#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <iostream>

//GAME ENGINE ENUMS START
enum PLAYER_TYPE {
	AI,
	HUMAN
};

enum ITEM_SYNTAX {
	FLOOR,
	WALL,
	PAC_GUM,
	SUPER_PAC_GUM,
	FRUIT,
	PACMAN,
	BLINKY,
	PINKY,
	INKY,
	CLYDE
};

enum DIRECTION {
    UP,
    DOWN,
    LEFT,
    RIGHT
};
//GAME ENGINE ENUMS END

//RENDER ENGINE ENUMS START
enum MANAGER_TYPE {
	GRID_M,
	PACMAN_M,
	BLINKY_M,
	PINKY_M,
	INKY_M,
	CLYDE_M,
};
//RENDER ENGINE ENUMS END

//RESSOURCE ENGINE ENUMS START

//RESSOURCE ENGINE ENUMS END
#endif /* ENUMS_HPP */