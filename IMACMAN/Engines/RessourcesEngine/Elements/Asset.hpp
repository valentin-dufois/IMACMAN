//
//  Asset.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Asset_hpp
#define Asset_hpp

//////////////////////
//Forward declarations
class Font;
class Mesh;
class Shader;

#include "libraries.hpp"
#include "../RessourcesEngine.hpp"

class Asset
{
public:

	/**
	 Asset constructor

	 - Warning : Must be called by Asset childs

	 @param type Type of the asset
	 */
	Asset(ressourceType type): m_type(type) {};

	/**
	 Return the type of the asset

	 @return assetsType
	 */
	inline ressourceType getType()
	{
		return m_type;
	};

	/**
	 Casting operator for Font assets

	 @return Return the asset as a Font, nullptr if the asset is not a Font
	 */
	 operator Font*();

	/**
	 Casting operator for Mesh assets

	 @return Return the asset as a Mesh, nullptr if the asset is not a Mesh
	 */
	operator Mesh*();

	/**
	 Casting operator for Shader assets

	 @return Return the asset as a Shader, nullptr if the asset is not a Shader
	 */
	operator Shader*();

protected:
	ressourceType m_type;
};

#include "Font.hpp"
#include "Mesh.hpp"
#include "Shader.hpp"

#endif /* Asset_hpp */
