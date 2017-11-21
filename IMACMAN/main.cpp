//
//  main.cpp
//  IMACMAN
//

#include "main.hpp"

int main(int argc, const char * argv[])
{
	//Init game
	Core core = Core();
	core.ignite();

	core.main();

    return 0;
}
