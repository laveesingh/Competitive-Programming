#include <iostream>

using namespace std;

int *a;
int m;

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

int solve(int n, int k){
	int cs = 0, ms = 0, i = 0, ii = 0;
	while (i < n){
		cs += a[i];
		if (cs > k){
			while(cs > k){
				cs -= a[ii];
				ii += 1;
			}
		}
		if(cs > ms) ms = cs;
		i += 1;
	}
	return ms;

}

int main(void){
	int n, m;
	cin >> n >> m;
	a = new int[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	cout << solve(n, m) << endl;
}