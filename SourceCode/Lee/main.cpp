#include <iostream>
#include <Windows.h>

#include "cBoard.h"
#include "cPathing.h"

using std::cout;
using std::endl;

cBoard board;
cPathing pathing;

void main()
{
	pathing.generatePath(point(2, 5, B_START), point(15, 17, B_END));

	Sleep(1000);
	board.clearPathing();
	board.draw();

	pathing.drawPath();
}