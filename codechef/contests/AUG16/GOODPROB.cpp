/*input
5
2 3 7 4 1
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}	
	int dp[n][n];
	for (int i = 0; i < n; i += 1){
		dp[i][i] = a[i];
	}
	for (int i = 0; i < n-1; i += 1){
		for (int j = i+1; j < n; j += 1){
			dp[i][j] = max(dp[i][j-1], a[j]);
		}
	}
	int ans = 0, cnt = 0;
	for (int i = 0; i < n-1; i += 1){
		for (int j = i+1; j < n; j += 1){
			// cout << "a[i] " << a[i] << " a[j] " << a[j] <<  " a[i]&a[j] " << (a[i]&a[j]) << endl;
			int F;
			if((a[i]&a[j]) == a[i]){
				F = 1;
			}else if((a[i]&a[j]) == a[j]){
				F = 1;
			}else{
				F = 0;
			}
			ans += F * dp[i][j];
			// if (F != 0){
			// 	cout << "a[i] " << a[i] << " a[j] " << a[j] <<  " a[i]&a[j] " << (a[i]&a[j]) << endl;
			// 	// cout << i+1 << " " << j+1 << endl;
			// 	cnt++;
			// }
		}
	}
	cout << ans << endl;
	// cout << cnt << endl;
}