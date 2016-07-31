#include <iostream>

using namespace std;

#define mod 1000000007


int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int l, r;
	cin >> l >> r;
	int dp[r+1][n];
	for (int i = 0; i < n; i += 1){
		dp[0][i] = 1;
	}
	for (int i = 1; i < r+1; i += 1){
		for(int j = 0; j < n; j += 1){
			int x = (i-a[j] >= 0) ? dp[i-a[j]][j]%mod : 0;
			int y = (j >= 1) ? dp[i][j-1]%mod : 0;
			dp[i][j] = (x+y)%mod;
		}
	}
	int count = 0;
	for(int i = l; i <= r; i += 1){
		count = (count + dp[i][n-1])%mod;
	}
	cout << count << endl;
}