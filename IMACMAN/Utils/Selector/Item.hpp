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
#include "Engines/RessourcesEngine/Elements/Font.hpp"

#include <iostream>
#include <functional>

enum ITEM_TYPE
{
	ITEM_IMAGE,
	ITEM_TEXT
};

class Item
{
public:

	/**
	 Item constructor

	 @param posX x/col position
	 @param posY y/row position
	 @param width Width of the Item (ignored if small)
	 @param height Height of the Item (ignored if small)
	 @param callback Item callback
	 */
	Item(const ITEM_TYPE &type, const uint &posX, const uint &posY, const uint &width, const uint &height, std::function<void()> callback);

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
	 Set the textures used by the item using their rId

	 @param idleTexture RessourceEngine Image ID
	 @param activeTexture RessourceEngine Image ID
	 */
	void setTextures(const rId &idleTexture, const rId &activeTexture);

	/**
	 Set the font to use
	 The item height is redifined to match the font height.
	 Item width is ignored at rendering

	 @param font A font object
	 */
	void setFont(Font * font, const std::string &caption);

	/**
	 Update the caption to display
	 This regenerate the tile

	 @param caption New caption
	 */
	void setCaption(const std::string &caption);

	/**
	 Set the Zindex of the item
	 A higher z-index means the item is farther

	 @param zIndex the new z-index
	 */
	inline void setZIndex(const uint &zIndex) { m_zIndex = zIndex; };

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
	ITEM_TYPE m_type;

	//Positionning
	uint m_posX;
	uint m_posY;
	uint m_zIndex = 0;

	//Dimensions
	uint m_width;
	uint m_height;

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

	//The text
	Font * m_font;
	std::string m_caption;

	std::function<void()> m_callback;
};

#endif /* Item_hpp */
