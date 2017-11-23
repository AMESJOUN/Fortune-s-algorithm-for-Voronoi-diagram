#ifndef Point_h
#define Point_h

struct Point
{
public:
	double x, y;

	Point(double nx, double ny) {
		x = nx;
		y = ny;
	}
	~Point();
};

#endif