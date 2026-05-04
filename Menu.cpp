#include "Menu.h"
#include "raylib.h"
#include <iostream>
using namespace std; 

Menu::Settings Menu::show()
{
    Settings settings;
    //data of player one 
    cout << "Enter Player 1 Name (symbol -> X): ";
    cin >> settings.player1Name;
    //data of player two 
    cout << "Enter Player 2 Name (symbol -> O): ";
    cin >> settings.player2Name;
    //the grid size can be any num but recommended from 3 to 5 
    cout << "Enter grid size: ";
    cin >> settings.gridSize;

    return settings;
}