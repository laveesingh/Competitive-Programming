#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int t, n, k, i;
	cin >> t;
	while(t--){
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		sort(a, a+n);
		i = 0;
		int ans = a[n-1]-a[0];
		for (int i = 0; i < n-k+1; i += 1){
			if (a[i+k-1] - a[i] < ans) ans = a[i+k-1]-a[i];
		}
		cout << ans << endl;
	}
}