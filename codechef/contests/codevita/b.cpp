#include <bits/stdc++.h>

using namespace std;


#define mod 1000000007
#define ll long long

ll *f;

void compute_facts(ll n, ll m){
	f = new ll[n+1];
	f[0] = 1;
	for (ll i = 1; i <= n; i += 1){
		f[i] = (f[i-1]*i)%m;
	}
}

ll pow(ll a, ll b, ll m){
	if (b == 0) return 1;
	if (b == 1) return a%m;
	if(b%2){
		return (a*pow(a,b-1,m))%m;
	}
	ll x = pow(a, b/2, m);
	return (x*x)%m;
}

ll mmi(ll a, ll m){
	// cout << "a " << a << " m " << m << endl;
	return pow(a, m-2,m);
}

ll comb(ll n, ll r, ll m){
	// cout << "Comb n,r " << n << " " << r << endl;
	ll ans = f[n];
	// cout << "Initial answer " << f[n] << endl;
	ans *= mmi(f[r], m);
	// cout << "f[r]" << f[r] << " mmi " << mmi(f[r], m) << endl;
	ans %= m;
	ans *= mmi(f[n-r], m);
	// cout << "f[n-r] " << f[n-r] << " mmi " << mmi(f[n-r], m) << endl;
	ans %= m;
	return ans;
}

int main(void){
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	compute_facts(n, mod);
	ll ans = 0;
	for (ll i = 0; i <= k; i += 2){
		ans = (ans + comb(n, i, mod))%mod;
	}
	cout << ans << endl;
}
