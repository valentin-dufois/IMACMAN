//
//  Mesh.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include "Asset.hpp"

class Mesh : public Asset
{
	private:
	//Structural infos
	
	//Mesh infos
	unsigned int m_vertexCount;
	
	//Vertex infos
	unsigned int m_vertexSize;
	unsigned int m_positionOffset;
	unsigned int m_normalOffset;
	unsigned int m_textureOffset;
};

#endif /* Mesh_hpp */
