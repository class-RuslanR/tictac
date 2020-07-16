#pragma once

class Board
{
protected:
	char matrix[3][3];
public:
	Board();
	~Board();
	char GetItem(int i, int j);
	void ShowBoard();
	void HelloMessage();
};