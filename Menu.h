#pragma once
#include <string>
class Menu
{
public:
    struct Settings {
        std::string player1Name;
        std::string player2Name;
        int gridSize; //3 X 3 or 4 X 4 or 5 X 5 and so on 
    };

    Settings show();
};