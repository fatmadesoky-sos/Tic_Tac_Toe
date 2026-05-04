#include "Board.h"

Board::Board(int size, int screenWidth): size(size), grid(size, vector<Symbol>(size, Symbol::empty))
{
    movesCount = 0; 
    cellSize = screenWidth / size;
}

bool Board::checkPath(int row, int column, int rowDirection, int columnDirection, Symbol symbol) const
{
    int count = 0;
    for (int step = 0; step < size; step++, row = row + rowDirection, column = column + columnDirection) {
        if (grid[row][column] == symbol) {
            count++;
        }
    }
    return (count == size);
}

void Board::draw() const
{
    for (int row = 0; row < size; row++) {
        for (int column = 0; column < size; column++) {
            int x = column * cellSize;
            int y = (row * cellSize) + 80; //offset = 80 

            DrawRectangleLines(x, y, cellSize, cellSize, LIGHTGRAY);
            if (grid[row][column] == Symbol::X) {
                int textX = x + (cellSize / 2) - 20;
                int textY = y + (cellSize / 2) - 30;
                DrawText("X", textX, textY, 60, RED);
            }
            else if (grid[row][column] == Symbol::O) {
                int textX = x + (cellSize / 2) - 20;
                int textY = y + (cellSize / 2) - 30;
                DrawText("O", textX, textY, 60, DARKGREEN);
            }
        }
    }
}

bool Board::updateCell(int row, int column, Symbol symbol)
{
    if (row >= 0 && row < size && column >= 0 && column < size && grid[row][column] == Symbol::empty) {
        grid[row][column] = symbol;
        movesCount++; 
        return true;
    }
    return false;
}


bool Board::isWin(Symbol symbol) const
{
    // Check rows
    for (int i = 0; i < size; i++) {
        if (checkPath(i, 0, 0, 1, symbol)) return true;
    }
    // Check columns
    for (int i = 0; i < size; i++) {
        if (checkPath(0, i, 1, 0, symbol)) {
            return true;
        }
    }
    // Check diagonals
    if (checkPath(0, 0, 1, 1, symbol)) {
        return true;
    }
    if (checkPath(0, size - 1, 1, -1, symbol)) {
        return true;
    }

    return false;
}

bool Board::isDraw()
{
    return (movesCount == (size * size));
}

int Board::getCellSize() const { 
    return cellSize; 
}

int Board::getSize() const
{
    return size;
}
