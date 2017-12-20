//
//  Image.cpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Image.hpp"

//Getters
uint Image::getWidth() const
{
  return m_width;
}

uint Image::getHeight() const
{
  return m_height;
}

uint Image::getSize() const
{
  return m_width * m_height;
}

uint Image::getAlphaChannel() const {
  return m_alphaChannel;
}

//Setters
void Image::setWidth(const uint width)
{
  m_width = width;
}

void Image::setHeight(const uint height)
{
  m_height = height;
}

void Image::setAlphaChannel(const uint alphaChannel)
{
  m_alphaChannel = alphaChannel;
}

//Utils
