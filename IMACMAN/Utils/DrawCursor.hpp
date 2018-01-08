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
	 */
	inline DrawCursor * translate(const float &X, const float &Y, const float &Z) {
		return translate(glm::vec3(X, Y, Z));
	};

	/**
	 Translate the cursor along the given vector

	 @param vector Vector offset
	 */
	DrawCursor * translate(const glm::vec3 &vector);

	/**
	 Scale the cursor for the given factors

	 @param X X factor
	 @param Y Y factor
	 @param Z Z factor
	 */
	inline DrawCursor * scale(const float &X, const float &Y, const float &Z) {
		return scale(glm::vec3(X, Y, Z));
	};

	/**
	 Scale the cursor for the given factors

	 @param vector Vector factor
	 */
	DrawCursor * scale(const glm::vec3 &vector);

	/**
	 Rotate the cursor for the given angle on the selected axis

	 @param angle Angle to rotate in degrees
	 @param X Rotate factor on the X axis
	 @param Y Rotate factor on the Y axis
	 @param Z Rotate factor on the Z axis
	 */
	inline DrawCursor * rotate(const float &angle, const float &X, const float &Y, const float &Z) {
		return rotate(angle, glm::vec3(X, Y, Z));
	};

	/**
	 Rotate the cursor for the given angle on the selected axis

	 @param angle Angle to rotate in degrees
	 @param vector Rotate factors
	 */
	DrawCursor * rotate(const float &angle, const glm::vec3 &vector);

	/**
	 Return the matrix depicting the cursor state

	 @return The cursor as a mat4
	 */
	inline glm::mat4 getMatrix() { return m_cursor; };

	/**
	 Move back the cursos to its starting state
	 */
	void reset() { m_cursor = m_sourceCursor; };

	//////////////////////
	//Comparison operators

	/**
	 Compare the cursor with another cursor

	 @param cursor The cursor to compare to
	 @return True if equals, false otherwise
	 */
	bool operator == (const DrawCursor &cursor)
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
	bool operator == (const glm::mat4 &cursor)
	{
		if(m_cursor == cursor)
			return true;

		return false;
	}

private:
	glm::mat4 m_cursor;
	glm::mat4 m_sourceCursor;
};

#endif /* DrawCursor_hpp */
