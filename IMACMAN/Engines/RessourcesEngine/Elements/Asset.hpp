//
//  Asset.hpp
//  IMACMAN
//
//  Created by Valentin Dufois on 20/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Asset_hpp
#define Asset_hpp

#include "../RessourcesEngine.hpp"

class Asset
{
private:
    //Ressource properties
    rId m_rID;
    ressourceType m_type;

public:
    
    //Constructor
    Asset(rId rID, ressourceType type): m_rID(rID), m_type(type) {};
    
    //Getters
	rId getID() const { return m_rID; }
	ressourceType getType() const { return m_type; }
	virtual uint getSize() = 0;
};

#endif /* Asset_hpp */
