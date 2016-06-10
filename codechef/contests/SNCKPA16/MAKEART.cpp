#include <iostream>

using namespace std;

bool solve(int a[], int n){
	for (int i = 2; i < n; i += 1){
		if (a[i] == a[i-1] && a[i-1]  == a[i-2]) return true;
	}
	return false;
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		cout << (solve(a, n) ? "Yes" : "No") << endl;
	}
}