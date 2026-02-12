#pragma once
#include "CellState.h"
#include <iostream>

class Board
{
private:
    static const int SIZE = 30;
    CellState BOARD[SIZE][SIZE];
    CellState COPY[SIZE][SIZE];

public:
    Board();
    void Update();
    void Render();
    void DrawBoard();
    void MakeCopy();
    void SetCopyToCurrent();
    void CheckNeighbours(int row, int column);

    void setCell(int row, int column, CellState state);
    CellState getCell(int row, int column) const;
    int getSize() const { return SIZE; }
};