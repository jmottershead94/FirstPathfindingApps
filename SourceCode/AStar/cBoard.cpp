#include <iostream>

#include "cBoard.h"

using std::cout;
using std::endl;

cBoard::cBoard()
{
	for(int y = 0; y < BOARD_Y; y++)
	{
		for(int x = 0; x < BOARD_X; x++)
		{
			if(x == 0 || y == 0 || x == BOARD_X - 1 || y == BOARD_Y - 1)
				board[x][y].setI(B_WALL);
			else
				board[x][y].setI(B_EMPTY);
		}
	}

	board[5][18].setI(B_WALL);
	board[5][17].setI(B_WALL);
	board[5][16].setI(B_WALL);
	board[5][15].setI(B_WALL);
	board[5][14].setI(B_WALL);
	board[5][13].setI(B_WALL);
	board[5][12].setI(B_WALL);

	board[4][18].setI(B_WALL);
	board[4][17].setI(B_WALL);
	board[4][16].setI(B_WALL);
	board[4][15].setI(B_WALL);
	board[4][14].setI(B_WALL);
	board[4][13].setI(B_WALL);
	board[4][12].setI(B_WALL);

	board[8][17].setI(B_WALL);
	board[8][16].setI(B_WALL);
	board[8][15].setI(B_WALL);
	board[8][14].setI(B_WALL);
	board[8][13].setI(B_WALL);
	board[8][12].setI(B_WALL);
	board[8][11].setI(B_WALL);
	board[8][10].setI(B_WALL);
	board[8][9].setI(B_WALL);
	board[8][8].setI(B_WALL);
	board[8][7].setI(B_WALL);
	board[8][6].setI(B_WALL);
	board[8][5].setI(B_WALL);
}

void cBoard::draw()
{
	system("cls");

	for(int y = 0; y < BOARD_Y; y++)
	{
		cout << endl;
		for(int x = 0; x < BOARD_X; x++)
		{
			switch(board[x][y].getI())
			{
				case B_EMPTY:	cout << "   ";	break;
				case B_WALL:	cout << "#  ";	break;
				case B_START:	cout << "S  ";	break;
				case B_END:		cout << "T  ";	break;
				default:
					if(board[x][y].getI() < 10)
						cout << board[x][y].getI() << "  ";
					else
						cout << board[x][y].getI() << " ";
					break;
			}
		}
	}
	cout << endl << endl << endl;
}

void cBoard::clearBoard()
{
	for(int y = 0; y < BOARD_Y; y++)
	{
		for(int x = 0; x < BOARD_X; x++)
		{
			if(board[x][y].getI() != B_WALL && board[x][y].getI() != B_START && board[x][y].getI() != B_END)
				board[x][y].setI(B_EMPTY);
		}
	}
}