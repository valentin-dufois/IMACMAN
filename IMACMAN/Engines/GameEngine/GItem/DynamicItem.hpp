#ifndef DYNAMIC_ITEM_HPP
#define DYNAMIC_ITEM_HPP

#include "GItem.hpp"

class DynamicItem: public GItem
{
public:
	/////////////
    //CONSTRUCTOR
	DynamicItem(Mesh * mesh, glm::vec2 position, std::string name, uint score, enum ITEM_SYNTAX type, enum DIRECTION dir):
        GItem(mesh, position, score, type),
        m_name(name),
        m_firstPosition(position),
        m_currentDirection(dir)
	{};

	////////////
    //DESTRUCTOR
	~DynamicItem() = default;

	/////////
    //GETTERS
	/**
	 Return the name of the item

	 @return The item's name
	 */
	std::string getName() const { return m_name; };

	/**
	 Return the current direction of the item

	 @return The item's direction
	 */
	inline DIRECTION getDirection() const { return m_currentDirection; };

	/**
	 Return the first position of the item

	 @return A vec2 position
	 */
	glm::vec2 getFirstPosition() const { return m_firstPosition; };

	/////////
    //SETTERS
	/**
	 Set the name of the object

	 @param name The name
	 */
	void setName(std::string name) { m_name = name; };

	/**
	 Change the item direction

	 @param direction The new direction
	 */
	void updateDirection(enum DIRECTION direction) { m_currentDirection = direction; };

	/////////
    //METHODS
	/**
	 Return the next position of the object

	 @param translation The direction to follow as a vector
	 @return The next position
	 */
	glm::vec2 getNextPosition(glm::vec3 &translation) const;

	/**
	 Return the next position of the object if it was following the given direction

	 @param nextDirection The direction to follow as an enum
	 @return The next position
	 */
	glm::vec2 getNextPosition(const DIRECTION &nextDirection) const;

protected:
	std::string m_name;
	glm::vec2 m_firstPosition;
	enum DIRECTION m_currentDirection;
};

#endif /* DYNAMIC_ITEM_HPP */
