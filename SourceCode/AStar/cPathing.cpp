#include <Windows.h>	// Sleep()
#include <stdlib.h>		// abs()
#include <iostream>

#include "cPathing.h"
#include "cBoard.h"
#include "cNode.h"

using namespace std;

void cPathing::generatePath(cVector start, cVector end)
{
	// generate distances to find route to the end
	generateDistances(start, end);

	// generate the final path stack
	traceBack(start, end);

	Sleep(10);
	board.clearBoard();
	board.draw();

	// display the final path
	displayPath();	
}

void cPathing::generateDistances(cVector start, cVector end)
{
	cVector curr_point;

	// set start/end to the board
	board.board[start.x][start.y].setI(B_START);
	board.board[end.x][end.y].setI(B_END);

	// update squares adjacent to the start position
	updateAdjSquares(start, end);

	// now start looping through the wset until adjacent to the end point, or until the wset is empty
	while(!wset.empty() && !isAdjIndex(wset.top(), B_END))
	{
		curr_point = wset.top();
		wset.pop();
		
		updateAdjSquares(curr_point, end);
		board.draw();
		Sleep(10);
	}
}

void cPathing::updateAdjSquares(cVector point, cVector goal)
{
	// g = path length so far (the index) // h = estimated distance to travel to the goal
	/* 1 update the distance number of the West adjacent node*/
	// (1) Get the West adjacent node from board.board[][] 
	// (2) Check whether the West adjacent node is empty by comparing its index (getI()) with the Macro "B_EMPTY"
	// (3) calculate the tentative g, h, f costs of the West adjacent node, g is the distance of the current node plus one, h is the Manhattan distance from the West adjacent node to target node
	// (4) if the tentative f cost is greater than the old f cost of the West adjacent node, then update the g, h, f cost using the function "board.board[][].setFGH()"
	// (5) push the updated West adjacent point "cVector" to the working set using the member function of "wset.push()".
	
	int f_value, g_value, h_value;
	
	// Checks the west adjacent cell.
	if(board.board[point.x - 1][point.y].getI() == B_EMPTY)
	{
		// Current path length.
		g_value = (board.board[point.x][point.y].getI() + 1);
		
		// The difference of x + the difference of y.
		// Estimated value to the end point.
		h_value = abs(goal.x - point.x) + abs(goal.y - point.y);
		
		// The total distance covered.
		f_value = g_value + h_value;

		// If the new "f" value is less than the old f value of the cell, update the f, g and h costs.
		if(board.board[point.x - 1][point.y].getF() < f_value)
		{
			board.board[point.x - 1][point.y].setFGH(g_value, h_value);
		}
	
		cVector new_point(point.x - 1, point.y, board.board[point.x - 1][point.y].getF());
		wset.push(new_point);
	}

	// Checks the north adjacent cell.
	if(board.board[point.x][point.y - 1].getI() == B_EMPTY)
	{
		g_value = (board.board[point.x][point.y].getI() + 1);
		h_value = abs((goal.x - point.x)) + abs((goal.y - point.y));
		f_value = g_value + h_value;

		if(board.board[point.x][point.y - 1].getF() < f_value)
		{
			board.board[point.x][point.y - 1].setFGH(g_value, h_value);
		}
	
		cVector new_point(point.x, point.y - 1, board.board[point.x][point.y - 1].getF());
		wset.push(new_point);
	}

	// Checks the east adjacent cell.
	if(board.board[point.x + 1][point.y].getI() == B_EMPTY)
	{
		g_value = (board.board[point.x][point.y].getI() + 1);
		h_value = abs((goal.x - point.x)) + abs((goal.y - point.y));
		f_value = g_value + h_value;

		if(board.board[point.x + 1][point.y].getF() < f_value)
		{
			board.board[point.x + 1][point.y].setFGH(g_value, h_value);
		}
	
		cVector new_point(point.x + 1, point.y, board.board[point.x + 1][point.y].getF());
		wset.push(new_point);
	}

	// Checks the south adjacent cell.
	if(board.board[point.x][point.y + 1].getI() == B_EMPTY)
	{
		g_value = (board.board[point.x][point.y].getI() + 1);
		h_value = abs((goal.x - point.x)) + abs((goal.y - point.y));
		f_value = g_value + h_value;

		if(board.board[point.x][point.y + 1].getF() < f_value)
		{
			board.board[point.x][point.y + 1].setFGH(g_value, h_value);
		}
		
		cVector new_point(point.x, point.y + 1, board.board[point.x][point.y + 1].getF());
		wset.push(new_point);
	}
}

bool cPathing::isAdjIndex(cVector point, int i)
{
	if(board.board[point.x + 1][point.y].getI() == i)
		return true;
	else
	{
		if(board.board[point.x - 1][point.y].getI() == i)
			return true;
		else
		{
			if(board.board[point.x][point.y + 1].getI() == i)
				return true;
			else
			{
				if(board.board[point.x][point.y - 1].getI() == i)
					return true;
				else
					return false;
			}
		}
	}
}

void cPathing::traceBack(cVector start, cVector end)
{
	// push the end point to the path stack using the function "path_final.push()", note that the data type in the path stack is "cVector"
	path_final.push(end);
	
	// find the node "board.board[][]" with lowest distance around the end node in clockwise orientation of West, North, East and South  
	cVector lowest_point(end.x - 1, end.y, end.f);
	
	// Checks if the first lowest point is north.
	if(board.board[end.x][end.y - 1].getI() < board.board[path_final.top().x][path_final.top().y].getI())
	{
		lowest_point = cVector(end.x, end.y - 1, end.f);
	}

	// Checks if the east cell is the lowest point.
	if(board.board[end.x + 1][end.y].getI() < board.board[path_final.top().x][path_final.top().y].getI())
	{
		lowest_point = cVector(end.x + 1, end.y, end.f);
	}

	// Checks if the south cell is the lowest point.
	if(board.board[end.x][end.y + 1].getI() < board.board[path_final.top().x][path_final.top().y].getI())
	{
		lowest_point = cVector(end.x, end.y + 1, end.f);
	}

	// push the adjacent point with lowest distance to the path stack using the function of "path_final.push(cVector())"
	path_final.push(lowest_point);

	/* work back from lowest to S to populate the stack with the final path from S to T*/
	// 1. using a do-while loop, starting from the lowest point "cVector" around the target point, finishing at the start point
	// 2. in each loop, find the lowest node "board.board[][]" from the four adjacent node of the current node in clockwise orientation of West, North, East and South
	// 3. in each loop, push the lowest point "cVetor" to the path stack using the function of "path_final.push()"
	do
	{
		// Checks the west adjacent cell.
		if(board.board[path_final.top().x - 1][path_final.top().y].getI() < board.board[path_final.top().x][path_final.top().y].getI())
		{
			path_final.push(cVector(path_final.top().x - 1, path_final.top().y));
		}

		// Checks the north adjacent cell.
		if(board.board[path_final.top().x][path_final.top().y - 1].getI() < board.board[path_final.top().x][path_final.top().y].getI())
		{
			path_final.push(cVector(path_final.top().x, path_final.top().y - 1));
		}

		// Checks the east adjacent cell.
		if(board.board[path_final.top().x + 1][path_final.top().y].getI() < board.board[path_final.top().x][path_final.top().y].getI())
		{
			path_final.push(cVector(path_final.top().x + 1, path_final.top().y));
		}

		// Checks the south adjacent cell.
		if(board.board[path_final.top().x][path_final.top().y + 1].getI() < board.board[path_final.top().x][path_final.top().y].getI())
		{
			path_final.push(cVector(path_final.top().x, path_final.top().y + 1));
		}
	
	} while(!isAdjIndex(path_final.top(), B_START));		
}

void cPathing::displayPath()
{
	while(!path_final.empty())
	{
		board.board[path_final.top().x][path_final.top().y].setI(path_final.size());
		path_final.pop();

		board.draw();
		Sleep(10);
	}
}