#ifndef CPATHING_H
#define CPATHING_H

#include <stack>
#include <queue> 
#include <vector>

#include "cNode.h"
#include "cBoard.h"

using namespace std;

struct cVector
{
	int x, y, f;

	cVector(){};

	cVector(int a, int b)
	{
		x = a;
		y = b;
	}

	cVector(int a, int b, int c)
	{
		x = a;
		y = b;
		f = c;
	}

// The comparison operator used to order the priority queue.
// Overloads the operator  >

	bool operator>(const cVector &a) const
	{
		return f > a.f;
	}
};

extern cBoard board;

class cPathing
{
	public:
		void generatePath(cVector start, cVector end);

	private:
		std::stack<cVector> path_final;

		// Declare the priority_queue use the replate of cVector, Container of std::vector and greater Compare 
		priority_queue<cVector, vector<cVector>, greater<cVector>> wset;
	
		void generateDistances(cVector start, cVector end);
		void traceBack(cVector start, cVector end);
		void displayPath();

		void updateAdjSquares(cVector point, cVector goal);
		bool isAdjIndex(cVector point, int i);
};

#endif