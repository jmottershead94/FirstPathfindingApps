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
	pathing.generatePath(cVector(2, 16), cVector(15, 10));
}