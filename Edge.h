#ifndef Edge_h
#define Edge_h

#include "Point.h"
#include <iostream>

class Edge
{
private:
	Point *	begin;
	Point *	end;
	Point *	direction;
	Point *	left;
	Point *	right;

	double		k;
	double		b;

public:
	Edge(Point * start1, Point * left1, Point * right1)
	{
		begin = start1;
		left = left1;
		right = right1;
		end = 0;
		direction = new Point(right->y - left->y, -(right->x - left->x));
	}

	~Edge();

};

#endif