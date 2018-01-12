#ifndef GITEM_HPP
#define GITEM_HPP

#include <iostream>
#include <string>
#include <glm/glm.hpp>

#include "Utils/Enums.hpp"

class Mesh;

class GItem
{
public:
	/////////////
    //CONSTRUCTOR
	GItem(Mesh * mesh, glm::vec2 position, uint score, ITEM_SYNTAX type):
        m_mesh(mesh),
        m_position(position),
		m_positionOffset(0),
        m_score(score),
        m_type(type)
    {};

	////////////
    //DESTRUCTOR
	~GItem() = default;

	//////////
    //GETTERS
    /**
     Return the mesh of the object

     @return A Mesh
     */
	inline Mesh * getMesh() const { return m_mesh; };

    /**
     Return the position on the grid as a 2D vector

     @return Position as Vec2
     */
	inline glm::vec2 getPosition() const { return m_position; };

	inline int incrementPositionOffset() { return ++m_positionOffset; };
	inline int getPositionOffset() const { return m_positionOffset; };

    /**
     Return the score of the object (if any)

     @return The score
     */
	inline uint getScore() const { return m_score; };

	/**
	 Return the type of the object

	 @return The obbject's type
	 */
	inline ITEM_SYNTAX getItemType() const { return m_type; };

	/////////
    //SETTERS

    /**
     Set the mesh to be used by the object

     @param mesh The mesh to use
     */
	inline void setMesh(Mesh * &mesh) { m_mesh = mesh; };

    /**
     Position the object on the grid

     @param position Obejct's position as Vec2
     */
	inline void setPosition(const glm::vec2 &position) { m_position = position; };

    /**
     Update the object position on the grid

     @param newPosition The new position
     @param gridWidth The grid width
     @param gridHeight The grid height
     */
    void updatePosition(glm::vec2 newPosition, uint gridWidth, uint gridHeight)
	{
        m_position.y = newPosition.y >= 0 ? ((int)newPosition.y % gridWidth) : ((int)newPosition.y + gridWidth);
        m_position.x = newPosition.x >= 0 ? ((int)newPosition.x % gridHeight) : ((int)newPosition.x + gridHeight);

		m_positionOffset = -2;
    }

	/**
	 Add the given amount of points to the object's score

	 @param points Points to add
	 */
	inline void updateScore(const uint &points) { m_score += points; };

protected:

	Mesh * m_mesh;

	glm::vec2 m_position;
	int m_positionOffset;

	int m_offsetSize = 2;

	uint m_score;

	ITEM_SYNTAX m_type;
};

#endif /* GITEM_HPP */
