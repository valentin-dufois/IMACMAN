//
//  ShaderProgram.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 30/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram(std::string vsPath, std::string fsPath): m_programID(glCreateProgram()), m_vsPath(vsPath), m_fsPath(fsPath)
{
	//Load shaders
	rId vsRId = GameObj->ressourcesEngine->loadAsset(vsPath, SHADER);
	rId fsRId = GameObj->ressourcesEngine->loadAsset(fsPath, SHADER);

	m_vsShader = *GameObj->ressourcesEngine->getAsset(vsRId);
	m_fsShader = *GameObj->ressourcesEngine->getAsset(fsRId);

	//Bind shaders
	glAttachShader(m_programID, m_vsShader->getShaderID());
	glAttachShader(m_programID, m_fsShader->getShaderID());

	//Compile program
	glLinkProgram(m_programID);

	GLint status;
	glGetProgramiv(m_programID, GL_LINK_STATUS, &status);

	if(status == GL_TRUE)
		return; //Compile OK

	//Compile error, display message
	throw std::runtime_error("Unable to compile program : " + getCompileLog());
}

const std::string ShaderProgram::getCompileLog() const
{
	GLint length;
	glGetProgramiv(m_programID, GL_INFO_LOG_LENGTH, &length);
	char* log = new char[length];

	glGetProgramInfoLog(m_programID, length, 0, log);

	std::string logString(log);
	delete [] log;

	return logString;
}
