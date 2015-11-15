#include <iostream>
#include "cBoard.h"

using std::cout;
using std::endl;

cBoard::cBoard()
{
	// Sets the board bounds.
	for(int y = 0; y < BOARD_Y; y++)
	{
		for(int x = 0; x < BOARD_X; x++)
		{
			if(x == 0 || y == 0 || x == BOARD_X - 1 || y == BOARD_Y - 1)
				board[x][y] = B_WALL;
			else
				board[x][y] = B_EMPTY;
		}
	}

	for(int i = 0; i < 10; i++)
	{
		int randX = rand() % 24;
		int randY = rand() % 21;

		board[randX][randY] = B_WALL;
		board[randX][randY - 1] = B_WALL;
	}
	
	board[4][18] = B_WALL;
	board[4][17] = B_WALL;
	board[4][16] = B_WALL;
	board[4][15] = B_WALL;
	board[4][14] = B_WALL;
	board[4][13] = B_WALL;
	board[4][12] = B_WALL;

	board[5][18] = B_WALL;
	board[5][17] = B_WALL;
	board[5][16] = B_WALL;
	board[5][15] = B_WALL;
	board[5][14] = B_WALL;
	board[5][13] = B_WALL;
	board[5][12] = B_WALL;

	board[10][18] = B_WALL;
	board[10][17] = B_WALL;
	board[10][16] = B_WALL;
	board[10][15] = B_WALL;
	board[10][14] = B_WALL;
	board[10][13] = B_WALL;
	board[10][12] = B_WALL;

	board[11][16] = B_WALL;

	board[12][16] = B_WALL;
	board[12][15] = B_WALL;
	board[12][14] = B_WALL;
	board[12][13] = B_WALL;
	board[12][12] = B_WALL;
	board[12][11] = B_WALL;
	board[12][10] = B_WALL;

	board[13][16] = B_WALL;
	board[13][15] = B_WALL;
	board[13][14] = B_WALL;
	board[13][13] = B_WALL;
	board[13][12] = B_WALL;
	board[13][11] = B_WALL;
	board[13][10] = B_WALL;

	board[14][3] = B_WALL;
	board[14][4] = B_WALL;
	board[14][5] = B_WALL;
	board[14][10] = B_WALL;
	board[14][11] = B_WALL;
	
	board[15][4] = B_WALL;
	board[15][5] = B_WALL;
	board[15][10] = B_WALL;
	board[15][11] = B_WALL;

	board[16][4] = B_WALL;
	board[16][5] = B_WALL;
	board[16][6] = B_WALL;
	board[16][7] = B_WALL;
	board[16][8] = B_WALL;
	board[16][9] = B_WALL;
	board[16][10] = B_WALL;
}

void cBoard::draw()
{
	system("cls");

	for(int y = 0; y < BOARD_Y; y++)
	{
		cout << endl;

		for(int x = 0; x < BOARD_X; x++)
		{
			switch(board[x][y])
			{
				case B_EMPTY:	cout << "   ";	break;
				case B_WALL:	cout << "#  ";	break;
				case B_START:	cout << "S  ";	break;
				case B_END:		cout << "T  ";	break;
				default:
					if(board[x][y] < 10)
						cout << board[x][y] << "  ";
					else
						cout << board[x][y] << " ";
					break;
			}
		}
	}
	cout << endl << endl << endl;
}

void cBoard::clearPathing()
{
	for(int y = 0; y < BOARD_Y; y++)
	{
		for(int x = 0; x < BOARD_X; x++)
		{
			if(board[x][y] != B_WALL && board[x][y] != B_START && board[x][y] != B_END)
				board[x][y] = B_EMPTY;
		}
	}
}

void cBoard::setSquare(int x, int y, int type)
{
	board[x][y] = type;
}

int cBoard::getSquare(int x, int y)
{
	return board[x][y];
}