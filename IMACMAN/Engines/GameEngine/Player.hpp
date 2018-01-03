//
//  Player.hpp
//  IMACMAN
//
//  Created by Laurie Greinert on 22/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <iostream>

enum PlayerType {AI,Human};

class Player{
public:
	
	Player(PlayerType type, std::string name) : m_type(type), m_name(name), m_life(3), m_score(0){};
	~Player();
	
	//SETTERS
	void setType(PlayerType type);
	void setName(std::string name);
	void setLife(uint life);
	void setScore(double score);
	
	//GETTERS
	PlayerType getPlayerType() const;
	std::string getName() const;
	uint getLife() const;
	double getScore() const;
	
private:
	PlayerType m_type;
	std::string m_name;
	uint m_life;
	double m_score;
};

#endif /* Player_hpp */
