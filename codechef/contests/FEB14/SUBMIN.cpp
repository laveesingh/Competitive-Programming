/*input
5
4 1 2 3 4
4
3
4
6
1
*/
#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	map<int, int> dp;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}	
	for (int i = 0; i < n; i += 1){
		int x = a[i];
		for (int j = i; j < n; j += 1){
			x = min(x, a[j]);
			dp[x] += 1;
		}
	}
	int q, x;
	cin >> q;
	for (int i = 0; i < q; i += 1){
		cin >> x;
		cout << dp[x] << endl;
	}
}