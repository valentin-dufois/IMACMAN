//
//  Asset.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 28/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Asset.hpp"

bool Asset::isRenderable()
{
	switch(getType())
	{
		case MESH:
			return true;
			break;
		default:
			return false;
	}
};

Asset::operator Font*()
{
	if(getType() != FONT)
		throw std::runtime_error("Invalid conversion.\nInvalid conversion from Asset * to Font * : Given Asset * is not a Font.");

	return dynamic_cast<Font *>(this);
}

Asset::operator Level*()
{
	if(getType() != LEVEL)
		throw std::runtime_error("Invalid conversion.\nInvalid conversion from Asset * to Level * : Given Asset * is not a Level.");

	return dynamic_cast<Level *>(this);
}

Asset::operator Mesh*()
{
	if(getType() != MESH)
		throw std::runtime_error("Invalid conversion.\nInvalid conversion from Asset * to Mesh * : Given Asset * is not a Mesh.");

	return dynamic_cast<Mesh *>(this);
}

Asset::operator Shader*()
{
	if(getType() != SHADER)
		throw std::runtime_error("Invalid conversion.\nInvalid conversion from Asset * to Shader * : Given Asset * is not a Shader.");

	return dynamic_cast<Shader *>(this);
}

Asset::operator Image*()
{
	if(getType() != IMAGE)
		throw std::runtime_error("Invalid conversion.\nInvalid conversion from Image * to Shader * : Given Asset * is not an Image.");

	return dynamic_cast<Image *>(this);
}

