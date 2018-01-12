//
//  Shader.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Shader_hpp
#define Shader_hpp

#include "Asset.hpp"

class Shader : public Asset
{
public:
	Shader(std::string shaderPath, GLenum shaderType): Asset(SHADER), m_shaderPath(shaderPath), m_shaderID(glCreateShader(shaderType)) {};

	inline void setSource(const char * source)
	{
		glShaderSource(m_shaderID, 1, &source, 0);
	}

	void compile();

	inline GLuint getShaderID() const { return m_shaderID; };

	~Shader();

private:
	
	//Shader infos
	std::string m_shaderPath;
	GLuint m_shaderID;

	const std::string getCompileLog() const;
};

#endif /* Shader_hpp */
