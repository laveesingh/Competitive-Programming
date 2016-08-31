/*input
5 2
1 5 3 4 2
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}	
	sort(a, a+n);
	int ans = 0;
	for (int i = 0; i < n-1; i += 1){
		auto it = equal_range(a+i+1, a+n, k+a[i]);
		// cout << (it.first-a) << " " << (it.second-a) << endl;
		ans += (it.second - it.first);
	}
	cout << ans << endl;
}