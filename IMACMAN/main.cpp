//
//  main.cpp
//  IMACMAN
//

#include "main.hpp"

#include "Core/Core.hpp"

int main(int argc, const char * argv[])
{
	//Init game
	Core core = Core();
	core.ignite(argv[0]);

	core.main();

    return 0;
}
