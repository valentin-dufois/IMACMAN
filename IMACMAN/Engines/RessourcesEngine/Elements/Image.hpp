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
    SDL_Surface *m_image;

public:
    //Constructor
    Image(rId rID, ressourceType type, SDL_Surface *img): Asset(rID, type), m_image(img){}

    //Getters
    SDL_Surface* getImage() const;
    int getImageSize() const;

    //Setters
    void setImage(SDL_Surface* image);

    //Utils
    bool scaleImage(const int width = 100, const int height = 100);

};

#endif /* Image_hpp */
