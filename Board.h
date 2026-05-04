#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>
using namespace std; 

enum class Symbol { empty = 0, X, O };

class Board
{
private:
	int size; //3*3 or 4*4 or 5*5
	vector<vector<Symbol>> grid;
	int cellSize; 
	int movesCount; //to check the tie case (isDraw)
	bool checkPath(int row, int column, int rowDirection, int columnDirection, Symbol symbol) const; //the main logic 

public: 
	Board(int size, int screenWidth);
	void draw() const; 
	bool updateCell(int row, int column, Symbol symbol); 
	bool isWin(Symbol symbol) const;
	bool isDraw(); 
	int getCellSize() const;
	int getSize() const; 
};

