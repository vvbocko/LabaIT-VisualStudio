#include "Board.h"
#include <cstdlib>

Board::Board()
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int column = 0; column < SIZE; column++)
        {
            BOARD[row][column] = CellState::Dead;
        }
    }
}

void Board::Update()
{
    MakeCopy();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            CheckNeighbours(i, j);
        }
    }
    SetCopyToCurrent();
}

void Board::Render()
{
    system("cls");
    DrawBoard();
}

void Board::DrawBoard()
{
    std::cout << " \n";

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << (char)BOARD[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << " \n";
}



void Board::MakeCopy()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            COPY[i][j] = BOARD[i][j];
        }
    }
}


void Board::SetCopyToCurrent()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            BOARD[i][j] = COPY[i][j];
        }
    }
}

void Board::setCell(int row, int column, CellState state)
{
    if (row >= 0 && row < SIZE && column >= 0 && column < SIZE)
    {
        BOARD[row][column] = state;
    }
}

CellState Board::getCell(int row, int column) const
{
    if (row >= 0 && row < SIZE && column >= 0 && column < SIZE)
    {
        return BOARD[row][column];
    }
    return CellState::Dead;
}



void Board::CheckNeighbours(int row, int column)
{
    int neighbourCount = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++) 
        {
            int nRow = row + i;
            int nCol = column + j;

            if (nRow >= 0 && nRow < SIZE && nCol >= 0 && nCol < SIZE)
            {
                if (i == 0 && j == 0) continue;
                if (BOARD[nRow][nCol] == CellState::Alive)
                {
                    neighbourCount++;
                }
            }
        }
    }


    if (neighbourCount == 3 && BOARD[row][column] == CellState::Dead)
    {
        COPY[row][column] = CellState::Alive;
    }
    else if (neighbourCount != 2 && neighbourCount != 3)
    {
        COPY[row][column] = CellState::Dead;
    }
    else
    {
        COPY[row][column] = BOARD[row][column];
    }
}