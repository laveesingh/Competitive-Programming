#include <iostream>
#include <algorithm>
// #include <numeric>

using namespace std;

bool solve(int a[], int n){
	int cnt2 = count(a, a+n, 2);
	if (cnt2 > 0) return false;
	int cnt5 = count(a, a+n, 5);
	if (cnt5 < 1) return false;
	int sum = accumulate(a, a+n, 0)/n;
	if (sum < 4) return false;
	return true;
}

int main(void){
	ios::sync_with_stdio(false);
	int n, t;
	cin >> t;
	while(t--){
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		if (solve(a, n)){
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}