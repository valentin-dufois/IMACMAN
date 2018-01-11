//
//  DrawCursor.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 08/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#ifndef DrawCursor_hpp
#define DrawCursor_hpp

#include "libraries.hpp"

#include <glm/gtc/matrix_transform.hpp>

class DrawCursor
{
public:

	DrawCursor(): m_cursor(glm::mat4(1.0)), m_sourceCursor(glm::mat4(1.0)) {};
	DrawCursor(const glm::mat4 &cursor): m_cursor(cursor), m_sourceCursor(cursor) {};

	/**
	 Translate the cursor along the given vector

	 @param X X offset
	 @param Y Y offset
	 @param Z Z offset
	 @return Cursor for chaining
	 */
	inline DrawCursor * translate(const float &X, const float &Y, const float &Z) {
		return translate(glm::vec3(X, Y, Z));
	};

	/**
	 Translate the cursor along the given vector

	 @param vector Vector offset
	 @return Cursor for chaining
	 */
	DrawCursor * translate(const glm::vec3 &vector);

	/**
	 Scale the cursor for the given factors

	 @param X X factor
	 @param Y Y factor
	 @param Z Z factor
	 @return Cursor for chaining
	 */
	inline DrawCursor * scale(const float &X, const float &Y, const float &Z) {
		return scale(glm::vec3(X, Y, Z));
	};

	/**
	 Scale the cursor for the given factors

	 @param vector Vector factor
	 @return Cursor for chaining
	 */
	DrawCursor * scale(const glm::vec3 &vector);

	/**
	 Rotate the cursor for the given angle on the selected axis

	 @param angle Angle to rotate in degrees
	 @param X Rotate factor on the X axis
	 @param Y Rotate factor on the Y axis
	 @param Z Rotate factor on the Z axis
	 @return Cursor for chaining
	 */
	inline DrawCursor * rotate(const float &angle, const float &X, const float &Y, const float &Z) {
		return rotate(angle, glm::vec3(X, Y, Z));
	};

	/**
	 Rotate the cursor for the given angle on the selected axis

	 @param angle Angle to rotate in degrees
	 @param vector Rotate factors
	 @return Cursor for chaining
	 */
	DrawCursor * rotate(const float &angle, const glm::vec3 &vector);

	/**
	 Inverse the cursor's matrix

	 @return Cursor for chaining
	 */
	DrawCursor * inverse();

	/**
	 Transpose the cursor's matrix

	 @return Cursor for chaining
	 */
	DrawCursor * transpose();

	/**
	 Build a perspective matrix with the given attributes

	 @param fov Field of view in degrees
	 @param aspect Aspect of the FOV
	 @param nearest Distance to the nearest point
	 @param farthest Distance to the farthest point
	 @return Cursor for chaining
	 */
	DrawCursor * perspective(const float &fov, const float &aspect, const float &nearest, const float &farthest);

	/**
	 Generate a 2D ortho matrix for the given coordinates

	 @param left Left point
	 @param right Right point
	 @param bottom Bottom point
	 @param top Top point
	 @return Cursor for chaining
	 */
	DrawCursor * ortho(const float &left, const float &right, const float &bottom, const float &top);

	/**
	 Replace the current cursor matrix with the given one
	 The source cursor is conserved

	 @param mat The new matrix
	 @return Cursor for chaining
	 */
	DrawCursor * setMatrix(const glm::mat4 &mat);

	/**
	 Return the matrix depicting the cursor state

	 @return The cursor as a mat4
	 */
	inline glm::mat4 getMatrix() const { return m_cursor; };

	/**
	 Move back the cursos to its starting state
	 */
	inline DrawCursor * reset() { m_cursor = m_sourceCursor; return this; };

	//////////////////////
	//Comparison operators

	/**
	 Compare the cursor with another cursor

	 @param cursor The cursor to compare to
	 @return True if equals, false otherwise
	 */
	bool operator == (const DrawCursor &cursor) const
	{
		if(m_cursor == cursor.m_cursor)
			return true;

		return false;
	}

	/**
	 Compare the cursor position with a mat4

	 @param cursor The mat4 to compare to
	 @return True if equals, false otherwise
	 */
	bool operator == (const glm::mat4 &cursor) const
	{
		if(m_cursor == cursor)
			return true;

		return false;
	}

	/**
	 Cast the cursor as a mat4

	 @return The cursor's matrix
	 */
	operator glm::mat4 () const
	{
		return m_cursor;
	}

	/**
	 Multiplication operator

	 @param term Another mat4/DrawCursor
	 @return A new cursor with the resulting value
	 */
	DrawCursor operator * (glm::mat4 term) const
	{
		return DrawCursor(m_cursor * term);
	}

	/**
	 Assignement operator

	 @param term The new value
	 @return The updated cursor with the new value
	 */
	DrawCursor * operator = (glm::mat4 term)
	{
		m_cursor = term;
		return this;
	}


private:
	glm::mat4 m_cursor;
	glm::mat4 m_sourceCursor;
};

#endif /* DrawCursor_hpp */
