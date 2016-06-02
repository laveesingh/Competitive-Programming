#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(void){
	int t;
	double a, b, c, d;
	cin >> t;
	while(t--){
		cin >> a >> b >> c >> d;
		double s = (a+b+c+d)/2;
		double ans = 1.0;
		ans *= s-a;
		ans *= s-b;
		ans *= s-c;
		ans *= s-d;
		// cout << sqrt(ans) << endl;
		printf("%.2lf\n", sqrt(ans));
	}
}