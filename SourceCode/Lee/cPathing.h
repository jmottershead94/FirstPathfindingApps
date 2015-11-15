#ifndef CPATHING_H
#define CPATHING_H

#include <iostream>
#include <stack>
#include <queue>
#include "cBoard.h"

using namespace std;

extern cBoard board;

#define MAX_I 50

struct point
{
	int x, y, i;

	point(){}
	point(int a, int b, int c)
	{
		x = a;
		y = b;
		i = c;
	}
};

class cPathing
{
	public:
		cPathing();
		void generatePath(point s, point e);
		void drawPath();

	private:
		unsigned long t;
		double time_taken;
		std::stack<point> path_final;
		std::queue<point> wset;

		void generateDistances();
		void traceBack();
		void updateAdjSquares(point current);
		bool checkAdjIndex(point tester, int index);

		point start, end;
};

#endif