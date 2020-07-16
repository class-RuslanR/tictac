#pragma once
#include "board.h"

class Game : public Board
{
	int flag = 0;
	int counter = 0;
public:
	void PlayerInterface();
	bool GetMove(char sign, int flag);
	bool WhoWinner(int flag);
	bool WrongMessage();
};