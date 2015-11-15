#include <Windows.h>
#include <ctime>
#include "cPathing.h"
#include "cBoard.h"

cPathing::cPathing(){}

void cPathing::generatePath(point s, point e)
{
	start = s;
	end = e;

	int startX = 1;
	int startY = 3;
	int endX = 23;
	int endY = 20;

	start.x = startX;
	start.y = startY;
	end.x = endX;
	end.y = endY;

	board.setSquare(start.x, start.y, start.i);
	board.setSquare(end.x, end.y, end.i);

	board.draw();
	Sleep(1000);

	// generate distances
	generateDistances();

	// work back from T, populate pathing stack to generate path S -> T
	traceBack();
}

void cPathing::generateDistances()
{
	// add start to the working set
	wset.push(point(start.x, start.y, start.i));

	int temp = 0; // for the simulation board draw to look nicer
	
	// loop until current node is adjacent to the end
	while(!wset.empty() && !checkAdjIndex(wset.front(), B_END))
	{
		updateAdjSquares(wset.front());

		if(wset.front().i > temp)
		{
			Sleep(100);
			board.draw();
			temp++;
		}
	
		wset.pop();
	}
}

bool cPathing::checkAdjIndex(point tester, int index)
{
	if(board.getSquare(tester.x + 1, tester.y) == index)
		return true;
	else
	{
		if(board.getSquare(tester.x - 1, tester.y) == index)
			return true;
		else
		{
			if(board.getSquare(tester.x, tester.y + 1) == index)
				return true;
			else
			{
				if(board.getSquare(tester.x, tester.y - 1) == index)
					return true;
				else
					return false;
			}
		}
	}
}

void cPathing::updateAdjSquares(point current)
{
	/* update the distance number of the West adjacent square*/
	// 1. get the x, y coordiantes of the West adjacnet square using the member funtion of "board.getSquare()" 
	// 2. and cheke whether it is empty by comparing the distance with the Macro "B_EMPTY"
	// 3. if it is empty, update the distance number using the current distance plus 1 using the member function of "board.setSquare()"
	// 4. push the updated West adjacnet square to the working set using the member function of "wset.push_back()".		
	if(board.getSquare(current.x - 1, current.y) == B_EMPTY)
	{
		board.setSquare(current.x - 1, current.y, current.i + 1);
		wset.push(point(current.x - 1, current.y, current.i + 1));
	}
	
	/* update the distance number of the North adjacent square*/
	if(board.getSquare(current.x, current.y - 1) == B_EMPTY)
	{
		board.setSquare(current.x, current.y - 1, current.i + 1);
		wset.push(point(current.x, current.y - 1, current.i + 1));
	}
	
	/* update the distance number of the East adjacent square*/
	if(board.getSquare(current.x + 1, current.y) == B_EMPTY)
	{
		board.setSquare(current.x + 1, current.y, current.i + 1);
		wset.push(point(current.x + 1, current.y, current.i + 1));
	}
		
	/* update the distance number of the South adjacent square*/
	if(board.getSquare(current.x, current.y + 1) == B_EMPTY)
	{
		board.setSquare(current.x, current.y + 1, current.i + 1);
		wset.push(point(current.x, current.y + 1, current.i + 1));
	}
}

void cPathing::traceBack()
{
	// push the end point to the path stack using the function "path_final.push()"
	path_final.push(end);

	// find the lowest distance around the end point in the order of West, North, East and South, using the function of "board.getSquare()"  
	point lowestDistance;

	// Sets the lowest distance to west to start with.
	lowestDistance = point(end.x - 1, end.y, board.getSquare(end.x - 1, end.y));

	// Checks the north cell.
	if(board.getSquare(end.x, end.y - 1) < lowestDistance.i)
	{
		lowestDistance = point(end.x, end.y - 1, board.getSquare(end.x, end.y - 1));
	}
	
	// Checks the east cell.
	if(board.getSquare(end.x + 1, end.y) < lowestDistance.i)
	{
		lowestDistance = point(end.x + 1, end.y, board.getSquare(end.x + 1, end.y));
	}

	// Checks the south cell.
	if(board.getSquare(end.x, end.y + 1) < lowestDistance.i)
	{
		lowestDistance = point(end.x, end.y + 1, board.getSquare(end.x, end.y + 1));
	}

	// push the adjacent point with lowest distance to the path stack using the function of "path_final.push()"
	path_final.push(lowestDistance);
	
	/* work back from lowest to S to populate the stack with the final path from S to T*/
	// 1. using a do-while loop, starting from the lowest point to the end point, ending at the start point
	// 2. in each loop, find the lowest point from the four adjacent points of the current point in the order of West, North, East and South, using fucntion of "board.getSquare()"
	// 3. in each loop, push the lowest point to the path stack using the function of "path_final.push()"
	do
	{
		// Checks the west cell.
		if(board.getSquare(lowestDistance.x - 1, lowestDistance.y) < lowestDistance.i)
		{
			lowestDistance = point(lowestDistance.x - 1, lowestDistance.y, board.getSquare(lowestDistance.x - 1, lowestDistance.y));
		}

		// Checks the north cell.
		if(board.getSquare(lowestDistance.x, lowestDistance.y - 1) < lowestDistance.i)
		{
			lowestDistance = point(lowestDistance.x, lowestDistance.y - 1, board.getSquare(lowestDistance.x, lowestDistance.y - 1));
		}
	
		// Checks the east cell.
		if(board.getSquare(lowestDistance.x + 1, lowestDistance.y) < lowestDistance.i)
		{
			lowestDistance = point(lowestDistance.x + 1, lowestDistance.y, board.getSquare(lowestDistance.x + 1, lowestDistance.y));
		}

		// Checks the south cell.
		if(board.getSquare(lowestDistance.x, lowestDistance.y + 1) < lowestDistance.i)
		{
			lowestDistance = point(lowestDistance.x, lowestDistance.y + 1, board.getSquare(lowestDistance.x, lowestDistance.y + 1));
		}

		path_final.push(lowestDistance);
	}while(lowestDistance.i != start.i);
}

void cPathing::drawPath()
{
	while(!path_final.empty())
	{
		board.setSquare(path_final.top().x, path_final.top().y, path_final.top().i);
		path_final.pop();
		board.draw();
		Sleep(50);
	}
}