/*input
1 3
3
3 3 2
-2 3 6
-2 7 10
*/

#include <bits/stdc++.h>

using namespace std;

#define inf INT_MAX

double dist(double a, double b, double c, double d){
	return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

int main(void){
	ios::sync_with_stdio(false);
	double a, b, x,y, v;
	cin >> a >> b;
	int n;
	cin >> n;
	double ans = inf;
	for (int i = 0; i < n; i += 1){
		cin >> x >> y >> v;
		double time = dist(a,b,x,y)/v;
		ans = min(ans, time);
	}
	cout << setprecision(8) << fixed << ans << endl;
}