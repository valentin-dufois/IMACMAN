//
//  Renderable.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 06/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef Renderable_hpp
#define Renderable_hpp

#include "libraries.hpp"

class Renderable
{
public:

	inline GLuint getVBO() { return m_vbo; };
	inline GLuint getVAO() { return m_vao; };

private:

	GLuint m_vbo;
	GLuint m_vao;
};

#endif /* Renderable_hpp */
