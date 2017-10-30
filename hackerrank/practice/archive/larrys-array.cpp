#include <iostream>

using namespace std;

bool solve(int a[], int n){
	int inv = 0;
	for (int i = 0; i < n-1; i += 1){
		for (int j = i+1; j < n; j += 1){
			if (a[j]<a[i]){
				inv += 1;
			}
		}
	}
	if (inv%2 == 0) return true;
	return false;
}

int main(void){
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i] ;
		}
		bool ans = solve(a, n);
		cout << (ans ? "YES" : "NO" ) << endl;
	}
}