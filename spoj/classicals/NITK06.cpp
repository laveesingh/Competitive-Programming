#include <iostream>

using namespace std;

bool solve(int a[], int n){
	for (int i = n-1; i > 0; i -= 1){
		if (a[i-1] < a[i]) return false;
		a[i-1] -= a[i];
	}
	return a[0] == 0;
}

int main(void){
	int t, n;
	cin >> t;
	while (t--){
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		// bool ans = solve(a, n);
		cout << (solve(a,n) ? "YES" : "NO") << endl;
	}
}