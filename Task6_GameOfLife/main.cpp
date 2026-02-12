#include <iostream>
#include <cctype>
#include <windows.h>
#include <cstdlib>
#include "CellState.cpp"

// Game params
int moveScore = 0;
const int GRID_SIZE = 30;
const char DEAD_CHAR = '.';
const char ALIVE_CHAR = '#';

// Game State
char input_x =0;
int input_y = 0;
char BOARD[GRID_SIZE][GRID_SIZE];
char COPY[GRID_SIZE][GRID_SIZE];
int cellNeighbours[8];
bool isGameFinished = false;

// Game Loop Template
void Initialise();
//bool GetInput();
//bool Update();
void Render();
void Shutdown();

// other methods
void DrawBoard();
void MakeCopy();
void SetCopyToCurrent();
void CheckNeighbours(int row, int column);
bool IsMoveValid(int row, int column);

// have current board
// make board copy
// check all cells from current board and make changes in the copy
// make baord copy to be a current board
// render

int main() 
{
	Initialise();

	while (!isGameFinished)
	{
		MakeCopy();
		for (int i = 0; i < GRID_SIZE; i++)
		{
			for (int j = 0; j < GRID_SIZE; j++)
			{
				CheckNeighbours(i, j);
			}
		}
		SetCopyToCurrent();
		Render();
		Sleep(500);
	}
	Shutdown();
	return 0;
}



void Initialise()
{
	std::cout << "Game of Life\n";
	std::cout << " \n";
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			if ((rand() % 100) < 25) 
			{
				BOARD[i][j] = ALIVE_CHAR;
			}
			else 
			{
				BOARD[i][j] = DEAD_CHAR;
			}
			
		}
	}
	DrawBoard();
}

void DrawBoard() 
{
	std::cout << " \n";
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{
			std::cout << BOARD[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << " \n";
}

void MakeCopy()
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{

			COPY[i][j] = BOARD[i][j];
		}
	}
}

void SetCopyToCurrent()
{
	for (int i = 0; i < GRID_SIZE; i++)
	{
		for (int j = 0; j < GRID_SIZE; j++)
		{

			BOARD[i][j] = COPY[i][j];
		}
	}
}

void CheckNeighbours(int row, int column)
{
	int neighbourCount = 0;
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (BOARD[row + i][column + j] >= 0 && BOARD[row + i][column + j] <= GRID_SIZE)
			{
				continue;
			}
			if (i == 0 && j == 0)
			{
				continue;
			}
			else if (BOARD[row + i][column + j] == ALIVE_CHAR)
			{
				neighbourCount++;
			}
		}
	}
	if (neighbourCount == 3 && BOARD[row][column] == DEAD_CHAR)
	{
		COPY[row][column] = ALIVE_CHAR;
	}
	else if(neighbourCount != 2 && neighbourCount != 3)
	{
		if (BOARD[row][column] == ALIVE_CHAR)
		{
			COPY[row][column] = DEAD_CHAR;
		}
	}
}

bool IsMoveValid(int row, int column)
{
	return BOARD[row][column] == DEAD_CHAR;
}

void Render() 
{
	system("cls");
	DrawBoard();
}

void Shutdown() 
{
	std::cout << "Game ended" << std::endl;
	return;
}