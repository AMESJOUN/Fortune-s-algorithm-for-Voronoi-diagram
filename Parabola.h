#ifndef Parabola_h
#define Parabola_h

#include "Point.h"
#include "Edge.h"

class Event; //Parabola has pointer to class Event and class Event has pointer to Parabola

 /* Class of archs of parabolas or an intersection between two archs -- edge
			 It's a binary tree, where internal nodes are edges, leaves are archs) */
class Parabola
{
public:
	bool isLeaf;  
	Point *	site;  // or focus point of parabola
	Edge *	edge;   //pointer to the edge
	Event *	circle_event; //pointer to the circle event (arch disappears)
	Parabola * parent;


	Parabola(); //for edge
	Parabola(Point * s); //for arch

	// Access to the children

	void SetLeft(Parabola * p) { _left = p; p->parent = this; }
	void SetRight(Parabola * p) { _right = p; p->parent = this; }

	Parabola * Left() { return _left; }
	Parabola * Right() { return _right; }

	static Parabola * GetLeftLeaf(Parabola * p);  //the closest left leaf of the TREE
	static Parabola * GetRightLeaf(Parabola * p); //the closest right leaf of the TREE
	static Parabola * GetLeftParent(Parabola * p); //the closest left parent
	static Parabola * GetRightParent(Parabola * p); //the closest right parent
	static Parabola * GetLeftChild(Parabola * p); //the closest left child of the NODE
	static Parabola * GetRightChild(Parabola * p); //the closest right child of the NODE

private:
	Parabola * _left;
	Parabola * _right;
};

#endif
