#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

#define ll long long

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		ll h, s;
		scanf("%lld %lld", &h, &s);
		ll sqb = (h*h + 4*s)/2;
		ll sqa = (h*h - 4*s)/2;
		double b = sqrt(sqb);
		double a = sqrt(sqa);
		if (a < b){
			printf("%.5lf %.5lf %.5lf\n", a, b, (double)h);
		} else {
			printf("%.5lf %.5lf %.5lf\n", b, a, (double)h);
		}
	}
}