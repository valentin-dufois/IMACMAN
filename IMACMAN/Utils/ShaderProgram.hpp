//
//  ShaderProgram.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 30/12/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef ShaderProgram_hpp
#define ShaderProgram_hpp

//Forward declaration
class Shader;
class ShaderProgram;

#include "libraries.hpp"
#include "Core/GameObject.hpp"
#include "Engines/RessourcesEngine/RessourcesEngine.hpp"

class ShaderProgram
{
public:
	ShaderProgram(std::string vsPath, std::string fsPath);

	inline void use() const { glUseProgram(m_programID); };

private:
	GLuint m_programID;

	std::string m_vsPath;
	std::string m_fsPath;

	Shader * m_vsShader;
	Shader * m_fsShader;

	const std::string getCompileLog() const;
};

#endif /* ShaderProgram_hpp */
