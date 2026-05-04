#include "Game.h"

void Game::init()
{
    Menu menu;
    Menu::Settings settings = menu.show();

    InitWindow(600, 680, "Tic Tac Toe");
    SetTargetFPS(60);

    player[0].setup(settings.player1Name, Symbol::X);
    player[1].setup(settings.player2Name, Symbol::O);

    resetGame(settings);
}

void Game::resetGame(const Menu::Settings& settings)
{
    delete board;
    board = new Board(settings.gridSize, 600);
    turn = 0;
    winnerName = "";
    state = GameState::PLAYING;
}

void Game::run()
{
    while (!WindowShouldClose()) {
        if (state == GameState::PLAYING) {
            if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                Vector2 mouse = GetMousePosition();
                int column = mouse.x / board->getCellSize();
                int row = (mouse.y - 80) / board->getCellSize();

                if (board->updateCell(row, column, player[turn].getSymbol())) {
                    if (board->isWin(player[turn].getSymbol())) {
                        winnerName = player[turn].getName();
                        state = GameState::GAME_OVER;
                    }
                    else if (board->isDraw()) {
                        winnerName = "Nobody";
                        state = GameState::GAME_OVER;
                    }
                    else {
                        turn = 1 - turn; //switch turns (0 -> 1, 1 -> 0)
                    }
                }
            }
        }
        else if (state == GameState::GAME_OVER) {
            if (IsKeyPressed(KEY_SPACE)) {
                Menu::Settings currentSettings;
                currentSettings.player1Name = player[0].getName();
                currentSettings.player2Name = player[1].getName();
                currentSettings.gridSize = board->getSize(); 
                resetGame(currentSettings);
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (state == GameState::PLAYING) {
            string turnText = player[turn].getName() + "'s Turn ("; 
            if (player[turn].getSymbol() == Symbol::X) {
                turnText = turnText + "X)"; 
            }
            else {
                turnText = turnText + "O)";
            }
            DrawText(turnText.c_str(), 20, 20, 30, BLACK);
        }
        else if (state == GameState::GAME_OVER) {
            string winText = winnerName + " Wins!";
            DrawText(winText.c_str(), 20, 15, 35, DARKGREEN);
            DrawText("Press SPACE to play again", 20, 50, 20, GRAY);
        }

        board->draw();
        EndDrawing();
    }
}

Game::~Game()
{
    delete board;
    CloseWindow();
}