#pragma once
#include "Board.h"
#include "Player.h"
#include "Menu.h"

class Game
{
private:
    enum class GameState { PLAYING, GAME_OVER };
    GameState state;
    Board* board;
    Player player[2];
    int turn;
    string winnerName;
    void resetGame(const Menu::Settings& settings); //reset the game with the same settings 

public:
    void init();
    void run();
    ~Game();
};
