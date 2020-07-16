#include "board.h"
#include <iostream>

Board::Board() 
{
	char number_cell = '1';
	for (int i = 2; i >= 0; --i)
	{
		for (int j = 0; j < 3; ++j)
		{
			matrix[i][j] = number_cell++;
		}
	}
}

Board::~Board()
{
}

char Board::GetItem(int i, int j)
{
	return matrix[i][j];
}

void Board::ShowBoard()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			std::cout << " " << GetItem(i, j);
			if (j != 2)
			{
				std::cout << " |";
			}
		}
		std::cout << std::endl;
	}
}

void Board::HelloMessage()
{
	char press_button;
	std::cout << "Tic-Tac-Toe Game" << std::endl;
	std::cout << "It's your field with numbers.\n\n";
	ShowBoard();
	std::cout << "\nPlease, enter necessary digit and\nhere will show your sign\n";
	std::cout << "If you're ready to play so press on button '1'\n";
	std::cin >> press_button;
	if(press_button == '1')
	{
		system("cls");
		ShowBoard();
	}
	else
	{
		system("cls");
		HelloMessage();
	}
}