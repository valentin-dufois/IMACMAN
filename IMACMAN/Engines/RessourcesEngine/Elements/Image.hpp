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
    std::unique_ptr<glm::vec4[]> m_pixels;

public:
    //Constructor
    Image(rId rID, ressourceType type, uint width, uint height): Asset(rID, type), m_width(width), m_height(height), m_pixels(new glm::vec4[width * height]) {};

};

#endif /* Image_hpp */
