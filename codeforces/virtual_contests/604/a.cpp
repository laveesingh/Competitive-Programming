/*input
119 119 119 119 119
0 0 0 0 0
10 0
*/

#include <bits/stdc++.h>

using namespace std;

double eval(double x, double m, double w){
	double f = 0.3 * x;
	double s = (1 - (double(m)/250.0))*x - 50*w;
	return max(f, s);
}

int main(void){
	ios::sync_with_stdio(false);
	double x[] = {500, 1000, 1500, 2000, 2500};
	double m[5], w[5], hs, hu;
	for (int i = 0; i < 5; i += 1){
		cin >> m[i];
	}	
	for (int i = 0; i < 5; i += 1){
		cin >> w[i];
	}
	cin >> hs >> hu;
	double ans = 0;
	for (int i = 0; i < 5; i += 1){
		ans += eval(x[i], m[i], w[i]);
	}
	ans += hs*100;
	ans -= hu*50;
	cout << ans << endl;
}
