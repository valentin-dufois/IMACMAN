//
//  LevelImporter.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "LevelImporter.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <numeric>

Asset * LevelImporter::getAsset(std::string path)
{
    if (path.substr(path.find_last_of('.') + 1) != "txt")
		throw std::runtime_error("Error: bad file extention! (.txt authorized only)");
	
    //Create stream
	std::ifstream file(path);
	
	if (!file.is_open())
		throw std::runtime_error("Error while opening file: " + path);


    //Read width and height params from File for Level constructor
    std::string param;
    file >> param;
    uint width = atoi(param.c_str());
    file >> param;
    uint height = atoi(param.c_str());

	//std::cout << "width: " << width << "\nheight: " << height << std::endl;
    
	std::vector<int> grid;
	char c;

	while (file.get(c)) {
		if (c != '\n') {
			grid.push_back((int)(c - '0'));
		}
	}

	//std::cout << "grid_size: " << grid.size() << std::endl;

	if (file.bad())
		throw std::runtime_error("Error while reading file: " + path);

	file.close();

    return new Level(width, height, grid);
}

LevelImporter::~LevelImporter()
{

}
