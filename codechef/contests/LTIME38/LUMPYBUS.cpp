#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--){
		ll n, p, q;
		cin >> n >> p >> q;
		ll a[n];
		for (ll i = 0; i < n; i += 1){
			cin >> a[i];
		}
		sort(a, a+n);
		ll ans = 0, i = 0;
		for (int i = 0; i < n; i += 1){
			if(p <= 0 and q <= 0) break;
			if(a[i]%2 and p == 0){
				continue;
			}
			if(p+2*q < a[i]) break;
			ll x = a[i]/2;
			p -= (a[i]%2 ? 1 : 0);
			if(x > q){
				x -= q;
				q = 0;
				p -= 2*x;
			}else{
				q -= x;
			}
			ans++;
		}
		cout << ans << endl;

	}

}