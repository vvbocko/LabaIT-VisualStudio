#include <iostream>
#include <ctime>
#include "GameLogic.h"
#include "Board.h"

void GameLogic::Initialise(Board& board) {
    for (int i = 0; i < board.getSize(); i++)
    {
        for (int j = 0; j < board.getSize(); j++)
        {
            CellState state = ((rand() % 100) < 25) ? CellState::Alive : CellState::Dead;
            board.setCell(i, j, state);
        }
    }
}

void GameLogic::GetInput(Board& board)
{
    int rowInput;
    int columnInput;

    std::cout << "Input coordinates (x y) (from 0 to 29)\n";
    std::cout << "Write -1 -1 to start simuation.\n";

    while (true)
    {
        std::cin >> rowInput >> columnInput;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "ERROR: enter numbers form 0-29 or '-1 -1' to start simulation\n" << std::endl;
            continue;
        }

        if (rowInput >= 0 && rowInput < board.getSize() && columnInput >= 0 && columnInput < board.getSize())
        {
            board.setCell(rowInput, columnInput, CellState::Alive);
            board.DrawBoard();
        }
        else if (rowInput == -1 && columnInput == -1)
        { 
            break; 
        }
    }
}