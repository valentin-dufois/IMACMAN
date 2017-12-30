//
//  Asset.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "../../../main.hpp"

Asset::operator Font*()
{
	if(getType() != FONT)
		throw new std::runtime_error("Invalid conversion.\nInvalid conversion from Asset * to Font * : Given Asset * is not a Font.");

	return reinterpret_cast<Font *>(this);
}

Asset::operator Shader*()
{
	if(getType() != SHADER)
		throw new std::runtime_error("Invalid conversion.\nInvalid conversion from Asset * to Shader * : Given Asset * is not a Shader.");

	return reinterpret_cast<Shader *>(this);
}

