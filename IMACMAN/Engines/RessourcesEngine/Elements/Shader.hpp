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
	private:
	//Structural infos
	
	//Shader infos
	GLuint m_shaderID;
	bool m_isCompiled;
};

#endif /* Shader_hpp */
