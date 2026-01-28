#include <iostream>
#include <cctype>

// Game params
int moveScore = 0;
const int GRID_SIZE = 3;
const int BOARD_SIZE = GRID_SIZE + 1;
const char EMPTY_CHAR = '_';
const char PLAYER1_CHAR = 'O';
const char PLAYER2_CHAR = 'X';

// Game State
char input_x =0;
int input_y = 0;
char BOARD[BOARD_SIZE][BOARD_SIZE];
char currentPlayer = PLAYER1_CHAR;
bool isGameFinished = false;
bool isGameTied = false;

// Game Loop Template
void Initialise();
bool GetInput();
bool Update();
void Render();
void Shutdown();

// other methods
bool IsMoveValid(int row, int columns);
void DrawBoard();
void MakeMove(int row, int columns);
void CheckForWin();
void ChangePlayerTurn();
bool CheckRows();
bool CheckColumns();
bool CheckDiagonals();


int main() 
{
	Initialise();

	while (!isGameFinished)
	{
		if (!GetInput()) continue;
		if (!Update()) continue;
		Render();
	}
	Shutdown();
	return 0;
}



void Initialise()
{
	std::cout << "Welcome to Tic Tac Toe \n";
	std::cout << "Player 'O' starts. \n";

	BOARD[0][0] = ' ';

	for (int i = 1; i < BOARD_SIZE; i++)
	{
		BOARD[i][0] = '0' + i;
		BOARD[0][i] = '@' + i;

		for (int j = 1; j < BOARD_SIZE; j++)
		{
			BOARD[i][j] = EMPTY_CHAR;
		}
	}
	DrawBoard();
}

void DrawBoard() 
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			std::cout << BOARD[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

bool GetInput()
{
	std::string input;

	std::cout << "Enter coordinates (format: A1): ";
	std::cin >> input;

	if (input.length() != 2)
	{
		std::cout << "Error: wrong format\n";
		return false;
	}

	char letter = std::toupper(input[0]);
	char number = input[1];

	if (letter < 'A' || letter >= 'A' + GRID_SIZE)
	{
		std::cout << "Error: "<< letter <<" is a wrong column letter\n";
		return false;
	}

	if (number < '1' || number > '0' + GRID_SIZE)
	{
		std::cout << "Error: " << number << " is a wrong row number\n";
		return false;
	}

	input_x = letter;
	input_y = number - '0';

	return true;
}

bool Update()
{
	int column = input_x - '@';
	int row = input_y;

	if (!IsMoveValid(row, column)) 
	{
		std::cout << "Error: cant place on an occupied field\n";
		return false;
	}
	MakeMove(row, column);
	CheckForWin();
	if (!isGameFinished) 
	{
		ChangePlayerTurn();
	}

	return true;
}

bool IsMoveValid(int row, int column)
{
	return BOARD[row][column] == EMPTY_CHAR;
}

void MakeMove(int row, int column)
{
	BOARD[row][column] = currentPlayer;
	moveScore++;
}

void CheckForWin() 
{
	if(CheckRows() || CheckColumns() || CheckDiagonals() )
	{
		isGameFinished = true;
		return;
	}

	if (moveScore == (GRID_SIZE)*(GRID_SIZE))
	{
		isGameTied = true;
		isGameFinished = true;
	}
}

bool CheckRows()
{
	for (int row = 1; row <= GRID_SIZE; ++row)
	{
		bool won = true;
		for (int column = 1; column <= GRID_SIZE; ++column)
		{
			if (BOARD[row][column] != currentPlayer)
			{
				won = false;
				break;
			}
		}
		if(won) 
		{ 
			return true; 
		}
	}
	return false;
}


bool CheckColumns()
{
	for (int column = 1; column <= GRID_SIZE; ++column)
	{
		bool won = true;
		for (int row = 1; row <= GRID_SIZE; ++row)
		{
			if (BOARD[row][column] != currentPlayer)
			{
				won = false;
				break;
			}
		}
		if (won)
		{
			return true;
		}
	}
	return false;
}

bool CheckDiagonals()
{
	bool won1 = true , won2 = true;

	for (int i = 1; i <= GRID_SIZE; ++i)
	{
		
		if (BOARD[i][i] != currentPlayer)
		{
			won1 = false;
		}
		if (BOARD[i][BOARD_SIZE - i] != currentPlayer)
		{
			won2 = false;
		}
		
	}
	return won1 || won2;
}

void ChangePlayerTurn()
{
	if (isGameFinished) return;

	currentPlayer = currentPlayer == PLAYER1_CHAR ? PLAYER2_CHAR : PLAYER1_CHAR;
	
	std::cout << "\n========  Player '"<< currentPlayer <<"' turn  ========\n";
}

void Render() 
{
	DrawBoard();
}
void Shutdown() 
{
	if (isGameTied)
	{
		std::cout << "Game ended in a Tie!" << std::endl;
		return;
	}
	std::cout << "Player '" << currentPlayer << "' won!" << std::endl;
}