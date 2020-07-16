#include "game.h"
#include "board.h"
#include <iostream>

void Game::PlayerInterface()
{
	char symbol;
	bool play = false, player_move;
	HelloMessage();
	while (play != true)
	{
		if (flag == 0)
		{
			std::cout << "\nMove X\nEnter digit: ";
			std::cin >> symbol;
			player_move = GetMove(symbol, flag);
			if (player_move == false)
			{
				continue;
			}
			system("cls");
			ShowBoard();
			play = WhoWinner(flag);
			if (play == true)
			{
				break;
			}
			++flag;
		}
		else
		{
			std::cout << "\nMove O\nEnter digit: ";
			std::cin >> symbol;
			player_move = GetMove(symbol, flag);
			if (player_move == false)
			{
				continue;
			}
			system("cls");
			ShowBoard();
			play = WhoWinner(flag);
			if (play == true)
			{
				break;
			}
			--flag;
		}
	}
}

bool Game::GetMove(char sign, int flag)
{
	bool result = true;
	char symbol;
	if (flag == 0)
	{
		symbol = 'X';
	}
	else
	{
		symbol = 'O';
	}
	switch (sign)
	{
	case('1'):
		if (matrix[2][0] != 'X' && matrix[2][0] != 'O') { matrix[2][0] = symbol; break; }
			 else { result = WrongMessage(); break; }
	case('2'):
		if (matrix[2][1] != 'X' && matrix[2][1] != 'O') { matrix[2][1] = symbol; break; }
			 else { result = WrongMessage(); break; }
	case('3'):
		if (matrix[2][2] != 'X' && matrix[2][2] != 'O') { matrix[2][2] = symbol; break; }
			 else { result = WrongMessage(); break; }
	case('4'):
		if (matrix[1][0] != 'X' && matrix[1][0] != 'O') { matrix[1][0] = symbol; break; }
			 else { result = WrongMessage(); break; }
	case('5'):
		if (matrix[1][1] != 'X' && matrix[1][1] != 'O') { matrix[1][1] = symbol; break; }
			 else { result = WrongMessage(); break; }
	case('6'):
		if (matrix[1][2] != 'X' && matrix[1][2] != 'O') { matrix[1][2] = symbol; break; }
			 else { result = WrongMessage(); break; }
	case('7'):
		if (matrix[0][0] != 'X' && matrix[0][0] != 'O') { matrix[0][0] = symbol; break; }
			 else { result = WrongMessage(); break; }
	case('8'):
		if (matrix[0][1] != 'X' && matrix[0][1] != 'O') { matrix[0][1] = symbol; break; }
			 else { result = WrongMessage(); break; }
	case('9'):
		if (matrix[0][2] != 'X' && matrix[0][2] != 'O') { matrix[0][2] = symbol; break; }
			 else { result = WrongMessage(); break; }
	default:
		std::cout << "Error!\nWrong entering!Repeat, please!\n"; result = false;
	}
	return result;
}

bool Game::WhoWinner(int flag)
{
	++counter;                                                                                   
	if ((matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) || 
		(matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]))
	{
		if (flag == 0)                                                                      
		{
			std::cout << "\nX is winner!\nOn diagonal!\n"; 
			return true;
		}
		else
		{
			std::cout << "\nO is winner!\nOn diagonal!\n"; 
			return true;
		}
	}
	if ((matrix[0][0] == matrix[0][1] && matrix[0][0] == matrix[0][2]) || 
		(matrix[1][0] == matrix[1][1] && matrix[1][0] == matrix[1][2]) || 
		(matrix[2][0] == matrix[2][1] && matrix[2][0] == matrix[2][2]))
	{
		if (flag == 0)
		{
			std::cout << "\nX is winner!\nOn horizontal!\n"; 
			return true;
		}
		else
		{
			std::cout << "\nO is winner!\nOn horizontal!\n"; 
			return true;
		}
	}
	if ((matrix[0][0] == matrix[1][0] && matrix[0][0] == matrix[2][0]) || 
		(matrix[0][1] == matrix[1][1] && matrix[0][1] == matrix[2][1]) || 
		(matrix[0][2] == matrix[1][2] && matrix[0][2] == matrix[2][2]))
	{
		if (flag == 0)
		{
			std::cout << "\nX is winner!\nOn vertical!\n"; 
			return true;
		}
		else
		{
			std::cout << "\nO is winner!\nOn vertical!\n"; 
			return true;
		}
	}
	if (counter == 9) 
	{
		std::cout << "\nDraw!\n"; 
		return true;
	}
	return false;
}

bool Game::WrongMessage()
{
	std::cout << "\nError!\nCell is busy!!!\n";
	return false;
}