#include <vector>
#include <cmath>
using namespace std;

struct Point {
    double x, y;
};

double dist(const Point& a, const Point& b)
{
	double y = b.y - a.y;
	double x = b.x - a.x;
	return (sqrt(y*y+x*x));
}
