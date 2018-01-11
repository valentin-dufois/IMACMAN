//
//  ShaderImporter.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "ShaderImporter.hpp"

Asset * ShaderImporter::getAsset(std::string path)
{
	std::ifstream input(path.c_str());

	if(!input)
	{
		throw std::runtime_error("Unable to load shader file " + path);
	}

	std::stringstream shaderBuffer;
	shaderBuffer << input.rdbuf();

	Shader * shader = new Shader(path, getShaderType(path));
	shader->setSource(shaderBuffer.str().c_str());
	shader->compile();

	return shader;
}

GLenum ShaderImporter::getShaderType(std::string path)
{
	std::vector<size_t> positions;

	size_t pos = path.find('.', 0);
	while(pos != std::string::npos)
	{
		positions.push_back(pos);
		pos = path.find('.',pos+1);
	}

	std::string shaderType = path.substr(positions[positions.size()-2]+1, 2);

	if(shaderType == "vs")
		return GL_VERTEX_SHADER;
	else if(shaderType == "fs")
		return GL_FRAGMENT_SHADER;

	//else
	throw std::runtime_error("Unsupported shader format : " + shaderType);
}
