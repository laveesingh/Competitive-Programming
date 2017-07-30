#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll solve(ll n, ll a[]){
	if (n == 0) return 0;
	if (n == 1) return a[0];
	ll dp[n];
	dp[0] = a[0];
	dp[1] = max(a[0], a[1]);
	for (ll i = 2; i < n; i += 1){
		dp[i] = max(dp[i-1], dp[i-2]+a[i]);
	}
	return dp[n-1];
}

int main(void){
	ll t;
	cin >> t;
	for (ll j = 0; j < t; j += 1){
		ll n;
		cin >> n;
		ll a[n];
		for (ll i = 0; i < n; i += 1) cin >> a[i];
		cout << "Case " << j+1 << ": " << solve(n, a) << endl;
	}
}