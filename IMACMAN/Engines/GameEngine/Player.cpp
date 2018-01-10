//
//  Player.cpp
//  IMACMAN
//
//  Created by Laurie Greinert on 22/11/2017.
//  Copyright © 2017 Valentin Dufois. All rights reserved.
//

#include "Player.hpp"

//SETTERS
/**
 Set type of the player
 */
void Player::setType(enum PLAYER_TYPE type){
	m_type = type;
}

/**
 Set name of the player
 */
void Player::setName(std::string name){
	m_name = name;
}

/**
 Set life of the player
 */
void Player::setLife(uint life){
	m_life = life;
}

/**
 Set score of the player
 */
void Player::setScore(double score){
	m_score = score;
}

//GETTERS
/**
 Get type of the player
 
 @return type
 */
enum PLAYER_TYPE Player::getPlayerType() const{
	return m_type;
}

/**
 Get name of the player
 
 @return name
 */
std::string Player::getName() const{
	return m_name;
}

/**
 Get life of the player
 
 @return life
 */
uint Player::getLife() const{
	return m_life;
}

/**
 Get score

 @return score
 */
double Player::getScore() const{
	return m_score;
}
