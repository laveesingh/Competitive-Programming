#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

double pi = 3.141592653589793;

double hem(double r){
	return ((2.0/3) * pi * pow(r, 3));
}
double cyl(double r, double h){
	return (pi * pow(r, 2) * h);
}
double cone(double r, double h){
	return cyl(r, h)/3.0;
}

int main(void){
	int t ;
	double r1, h1, r2, h2;
	cin >> t ;
	while (t--){
		cin >> r1 >> h1 >> r2 >> h2 ;
		cout << fixed << setprecision(9) <<  (cone(r1, h1)+hem(r1)) << " " << cyl(r2, h2) << endl;
	}
}