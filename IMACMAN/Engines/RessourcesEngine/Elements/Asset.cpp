//
//  Asset.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Asset.hpp"

Asset::operator Font*()
{
	if(getType() != FONT)
		throw std::runtime_error("Invalid conversion.\nInvalid conversion from Asset * to Font * : Given Asset * is not a Font.");

	return reinterpret_cast<Font *>(this);
}

Asset::operator Mesh*()
{
	if(getType() != MESH)
		throw std::runtime_error("Invalid conversion.\nInvalid conversion from Asset * to Mesh * : Given Asset * is not a Mesh.");

	return reinterpret_cast<Mesh *>(this);
}

Asset::operator Shader*()
{
	if(getType() != SHADER)
		throw std::runtime_error("Invalid conversion.\nInvalid conversion from Asset * to Shader * : Given Asset * is not a Shader.");

	return reinterpret_cast<Shader *>(this);
}
