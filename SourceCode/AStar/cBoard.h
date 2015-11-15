#ifndef CBOARD_H
#define CBOARD_H

#include "cNode.h"

#define BOARD_X 20
#define BOARD_Y 20

#define B_EMPTY 1000
#define B_WALL	999
#define B_START	0
#define B_END	1001

class cBoard
{
public:

	cBoard();
	void draw();
	void clearBoard();

	cNode board[BOARD_X][BOARD_Y];
};

#endif CBOARD_H