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

#include "libraries.hpp"
#include "Core/GameObject.hpp"
#include "Engines/RessourcesEngine/RessourcesEngine.hpp"

#include <glm/glm.hpp>

#include <map>

class ShaderProgram
{
public:
	ShaderProgram(const GLuint &programID): m_programID(programID) {};
	ShaderProgram(std::string vsPath, std::string fsPath);

	/**
	 Use this program for futur renderings

	 If program is already binded, it will not be binded again
	 */
	void use() const;

	/**
	 Get the GL program ID

	 @return The program ID
	 */
	inline GLuint getProgramID() const { return m_programID; };

	/**
	 Pass the given matrix to the program as uniform

	 @param uniformName Name of the uniform var
	 @param value A 4x4 Matrix
	 */
	void setUniformMat4(const std::string &uniformName, const glm::mat4 &value);

	/**
	 Pass the given uint to the uniform var

	 @param uniformName Name of the uniform var
	 @param value A uint
	 */
	void setUniformUint(const std::string &uniformName, const uint &value);

	~ShaderProgram();

private:
	GLuint m_programID;

	std::string m_vsPath;
	std::string m_fsPath;

	Shader * m_vsShader;
	Shader * m_fsShader;

	/**
	 Locate and store uniform locations as needed

	 @param uniformName Uniform name
	 @return The uniform location
	 */
	GLuint getUniformLocation(const std::string &uniformName);
	std::map<std::string, GLuint> m_uniformLocations;

	const std::string getCompileLog() const;

	static GLuint currentProgram;
};

#endif /* ShaderProgram_hpp */
