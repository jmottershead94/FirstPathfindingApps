#ifndef CBOARD_H
#define CBOARD_H

#define BOARD_X 25
#define BOARD_Y 22
#define B_EMPTY 1000
#define B_WALL	999
#define B_START	0
#define B_END	1001

class cBoard
{
	public:
		cBoard();
		void draw();
		void clearPathing();
		void setSquare(int x, int y, int type);
		int getSquare(int x, int y);

	private:
		int board[BOARD_X][BOARD_Y];

};

#endif CBOARD_H