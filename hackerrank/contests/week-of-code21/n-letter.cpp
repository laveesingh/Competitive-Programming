#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

#define pii pair<int, int>
#define PI 3.14159
#define mp make_pair

class Point{
public:
	int x, y;
	Point(){}
	Point(int a, int b){
		x = a;
		y = b;
	}
};

int orientation(Point a, Point b, Point c){
	float sigma = (float)(b.y - a.y) / (float)(b.x - a.x);
	float tou = (float)(c.y - b.y) / (float)(c.x - b.x);
	if (tou > sigma) return 1; // counter clock wise
	if (tou < sigma) return -1; // clock wise
	return 0; // linear
}

bool isangle(Point a, Point b, Point c){
	// returns whether angle is less than 90 degrees
	float Angle = acos(((b.x-a.x)*(c.x-b.x)+(b.y-a.y)*(c.y-b.y))/
			sqrt((b.x-a.x)*(b.y-a.y))*sqrt((c.x-b.x)*(c.y-b.y))); // this line is incorrect
	// here I've to divide by sqrt of squares
	Angle *= 180;
	cout << "Angle is " << Angle << endl;
	Angle /= PI;
	if (Angle > 90) return false;
	return true;
}

int main(void){
	Point a, b, c, d;
	a = Point(1, 1);
	b = Point(1, 2);
	c = Point(2,1);
	d = Point(2,2);
	cout << orientation(a, b, c) << " " << isangle(a, b, c) << endl;
	cout << orientation(b, c, d) << " " << isangle(b, c, d) << endl;
}