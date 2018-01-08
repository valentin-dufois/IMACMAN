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

	if(status != GL_TRUE)
	{
		//Compile error, display message
		throw std::runtime_error("Unable to compile program : " + getCompileLog());
		return;
	}
}

void ShaderProgram::use() const
{
	if(ShaderProgram::currentProgram == m_programID)
		return;

	glUseProgram(m_programID);
	ShaderProgram::currentProgram = m_programID;
}

//UNIFORMS
void ShaderProgram::setUniformMat4(std::string uniformName, glm::mat4 value)
{
	//THe program needs to be binded in order to pass uniforms
	use();

	glUniformMatrix4fv(glGetUniformLocation(m_programID, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(value));

	GLint id;
	glGetIntegerv(GL_CURRENT_PROGRAM,&id);
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

GLuint ShaderProgram::currentProgram = 0;
