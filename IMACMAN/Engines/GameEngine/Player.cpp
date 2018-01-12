//
//  Player.cpp
//  IMACMAN
//
//  Created by Laurie Greinert on 22/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Player.hpp"

//SETTERS
void Player::setType(PLAYER_TYPE type){
	m_type = type;
}

void Player::setName(std::string name){
	m_name = name;
}

void Player::setLife(uint life){
	m_life = life;
}

void Player::setScore(double score){
	m_score = score;
}

//GETTERS
PLAYER_TYPE Player::getPlayerType() const{
	return m_type;
}

std::string Player::getName() const{
	return m_name;
}

uint Player::getLife() const{
	return m_life;
}

double Player::getScore() const{
	return m_score;
}
