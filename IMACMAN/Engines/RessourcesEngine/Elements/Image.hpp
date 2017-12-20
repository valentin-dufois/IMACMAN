//
//  Image.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Image_hpp
#define Image_hpp

#include "Asset.hpp"
#include "../../../libs/FilePath.hpp"

class Image : public Asset
{
private:
    //Image infos
    uint m_width;
    uint m_height;
    std::vector<SDL_Color> m_pixels;
    bool m_alphaChannel;

public:
    //Constructor
    Image(rId rID, ressourceType type, uint width, uint height, std::vector<SDL_Color> pixels): Asset(rID, type), m_width(width), m_height(height), m_pixels(pixels){}

    //Getters
    uint getWidth() const;
    uint getHeight() const;
    uint getSize() const;
    uint getAlphaChannel() const;

    //Setters
    void setWidth(const uint width);
    void setHeight(const uint height);
    void setAlphaChannel(const uint alphaChannel);

    //Utils

};

#endif /* Image_hpp */
