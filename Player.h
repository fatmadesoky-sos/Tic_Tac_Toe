#pragma once
#include "Board.h" 

class Player
{
private:
	string name; 
	Symbol symbol; //X or O 

public: 
	void setup(const string &name, Symbol symbol); 
	Symbol getSymbol() const; 
	string getName() const; 
};

