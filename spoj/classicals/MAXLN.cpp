#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
	int t;
	float r;
	cin >> t;
	for (int i = 1; i <= t; i += 1){
		cin >> r;
		float ans = (4 * r * r) + 0.25;
		printf("Case %d: %.2f\n",i, ans);
	}
}