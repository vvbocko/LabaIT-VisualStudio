#include <windows.h>
#include "GameLogic.h"
#include "Board.h"

int main() {
    Board boardGame;
    GameLogic logic;

    logic.Initialise(boardGame);
    logic.GetInput(boardGame);

    while (true) {
        boardGame.Update();
        boardGame.Render();
        Sleep(500);
    }
    return 0;
}