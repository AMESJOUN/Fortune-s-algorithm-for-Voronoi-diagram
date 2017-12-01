#ifndef Edge_h
#define Edge_h

#include "Point.h"
#include <iostream>

class Edge
{
private:
	Point *	begin;
	Point *	end;
	Point *	direction; // directional vector
	Point *	left;  // pointer to Voronoi place on the left side of edge 
	Point *	right; // pointer to Voronoi place on the right side of edge
	Edge * neighbour; //edges can consist of two parts, neighbour is the pointer to another part (connecting in the end of algorithm)

	//edge lies on the line: y = k*x + b;
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
