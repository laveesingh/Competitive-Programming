/*input
3
10 4
7 3
11 8
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll sigma(ll a){
	return (a*(a+1))/2;
}

ll comp(ll i, ll k){
	if (i < k/2.0 ) return (k-i);
	if (i == k) return 2*k;
	return (2*k - i);
}

int main(void){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;
		ll ans = 0;
		for (int i = 1; i <= k; i += 1){
			ll freq = (comp(i,k)<=n ? (n - comp(i,k))/k + 1 : 0);
			ans += sigma(freq);
		}
		cout << ans << endl;
	}
}