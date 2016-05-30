#include <iostream>
#include <cmath>

using namespace std;

float tri_area(int a){
	return 0.433*a*a;
}

int main(void){
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	float total_area = (a+b+c)*(a+b+c) - a*a - c*c - e*e;
	cout << (int) total_area << endl;
}