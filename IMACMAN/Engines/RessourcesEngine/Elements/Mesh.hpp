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
	uint m_vertexCount;
	
	//Vertex infos
	uint m_vertexSize;
	uint m_positionOffset;
	uint m_normalOffset;
	uint m_textureOffset;
};

#endif /* Mesh_hpp */
