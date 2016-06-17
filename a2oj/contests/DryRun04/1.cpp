#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void){
	int n, l;
	cin >> n >> l;
	double a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	sort(a, a+n);
	double f = a[0]-0;
	double t = l-a[n-1];
	double maxdist = 0;
	for (int i = 1; i < n; i += 1){
		maxdist = max(maxdist, a[i]-a[i-1]);
	}
	double ans = max(max(f, t), maxdist/2.0);
	printf("%0.10lf\n", ans);
}