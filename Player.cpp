#include "Player.h"
#include "Board.h"

void Player::setup(const string &name, Symbol symbol)
{
	this->name = name; 
	this->symbol = symbol; 
}

Symbol Player::getSymbol() const
{
	return symbol; 
}

string Player::getName() const
{
	return name; 
}