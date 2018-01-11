//
//  Item.hpp
//  Music Composer
//
//  Created by Valentin Dufois on 24/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include "libraries.hpp"
#include "Engines/RessourcesEngine/Elements/Mesh.hpp"

#include <iostream>
#include <functional>

class Item
{
public:

	/**
	 Item constructor

	 @param posX x/col position
	 @param posY y/row position
	 @param width Width of the Item (ignored if small)
	 @param height Height of the Item (ignored if small)
	 @param caption Text of the Item
	 @param callback Item callback
	 */
	Item(const uint &posX, const uint &posY, const uint &width, const uint &height, const std::string &caption, std::function<void()> callback);

	/**
	 Set neighboor Items
	 Allow interactions with the arrow keys

	 @param top Top Item
	 @param right Right Item
	 @param bottom Bottom Item
	 @param left Left Item
	 */
	void setNeighboors(Item * top, Item * right, Item * bottom, Item * left);

	/**
	 Set the textures used by the item

	 @param idleTexture Texture GL ID
	 @param activeTexture Texture GL ID
	 */
	void setTextures(const GLuint &idleTexture, const GLuint &activeTexture);

	/**
	 Return the top neighboor

	 @return Top neighboor
	 */
	Item * getTopNeighboor();

	/**
	 Return the right neighboor

	 @return Right neighboor
	 */
	Item * getRightNeighboor();

	/**
	 Return the bottom neighboor

	 @return Bottom neighboor
	 */
	Item * getBottomNeighboor();

	/**
	 Return the left neighboor

	 @return Left neighboor
	 */
	Item * getLeftNeighboor();

	/**
	 Tell if Item is selected or not

	 @return true if selected, false otherwise
	 */
	bool isSelected();

	/**
	 Mark the item as selected
	 */
	void select();

	/**
	 Mark the item as deselected
	 */
	void deSelect();

    /**
     Tell if the item is shown or not

     @return true if shown, false otherwise
     */
    bool isShown();
    
	/**
	 Disable the Item
	 */
	void hide();
	/**
	 Enable the Item
	 */
	void show();

	/**
	 Print the Item
	 */
	void print();

	/**
	 Execute Item action
	 */
	void action();

private:

	//Display properties
	bool m_display;

	//Positionning
	uint m_posX;
	uint m_posY;

	//Dimensions
	uint m_width;
	uint m_height;

	//Caption
	std::string m_caption;

	//current state
	bool m_selected;

	//Neighboors
	Item * m_topItem;
	Item * m_rightItem;
	Item * m_bottomItem;
	Item * m_leftItem;

	//The tile
	Mesh * m_tile;

	//The textures
	GLuint m_idleTexture;
	GLuint m_activeTexture;

	std::function<void()> m_callback;
};

#endif /* Item_hpp */
