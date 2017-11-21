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

class Image : public Asset
{
private:
    //Structural infos
    
    //Image infos
    uint m_width;
    uint m_height;
};

#endif /* Image_hpp */
