#include <iostream>

using namespace std;

#define ll long long

void Print(ll a[], int n){
	for (int i = 0; i < n; i += 1){
		cout << a[i] << " " ;
	}
	cout << endl;
}

ll solve(ll a[], int n){
	ll dp[n+1];
	dp[0] = 0;
	dp[1] = a[0];
	for (int i = 2; i <= n; i += 1){
		dp[i] = max(dp[i-1], dp[i-2]+a[i-1]);
	}
	// Print(dp, n+1);
	return dp[n];
}

int main(void){
	int t,n;
	cin >> t;
	for(int j = 1; j <= t; j += 1){
		cin >> n;
		ll a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		cout << "Case " << j << ": " << solve(a, n) << endl;
	}
}