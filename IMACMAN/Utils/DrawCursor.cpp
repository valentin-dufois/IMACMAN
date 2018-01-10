//
//  DrawCursor.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 08/01/2018.
//  Copyright © 2018 Valentin Dufois. All rights reserved.
//

#include "DrawCursor.hpp"

DrawCursor * DrawCursor::translate(const glm::vec3 &vector)
{
	m_cursor = glm::translate(m_cursor, vector);
	return this;
}

DrawCursor * DrawCursor::scale(const glm::vec3 &vector)
{
	m_cursor = glm::scale(m_cursor, vector);
	return this;
}

DrawCursor * DrawCursor::rotate(const float &angle, const glm::vec3 &vector)
{
	m_cursor = glm::rotate(m_cursor, angle, vector);
	return this;
}

DrawCursor * DrawCursor::inverse()
{
	m_cursor = glm::inverse(m_cursor);
	return this;
}

DrawCursor * DrawCursor::transpose()
{
	m_cursor = glm::transpose(m_cursor);
	return this;
}

DrawCursor * DrawCursor::perspective(float fov, float aspect, float nearest, float farthest)
{
	m_cursor = glm::perspective(glm::radians(fov), aspect, nearest, farthest);
	return this;
}
