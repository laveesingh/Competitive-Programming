#include <cstdio>
#include <vector>

using namespace std;

#define ll long long

ll *fact;

ll pow(ll a, ll b, ll mod){
	if(b == 0) return 1;
	if(b == 1) return a;
	if(b%2) return a*pow(a, b-1, mod);
	ll x = pow(a, b/2, mod);
	return (x * x) % mod;
}

void compute_factorials(ll n, ll mod){
	fact = new ll[n+1];
	fact[0] = 1;
	for (ll i = 1; i <= n; i += 1){
		fact[i] = (fact[i-1] * i) % mod;
	}
}

ll smallC(ll n, ll r, ll mod){
	ll ans = 1;
	ans = (ans * fact[n])%mod;
	ans = (ans * pow(fact[n-r], mod-2, mod))%mod;
	ans = (ans * pow(fact[r], mod-2, mod))%mod;
	return ans;
}

vector<ll> getMRepresentation(ll n, ll mod){
	vector<ll> temp;
	while(n > 0){
		temp.push_back(n%mod);
		n /= mod;
	}
	return temp;
}

ll bigC(ll n, ll r, ll mod){
	compute_factorials(n, mod);
	vector<ll> N = getMRepresentation(n, mod), R = getMRepresentation(r, mod);
	ll ans = 1;
	for (ll i = 0; i < R.size(); i += 1){
		ans = (ans * smallC(N[i], R[i], mod))%mod;
	}
	return ans;
}

ll mod_inverse(ll a, ll mod){
	return pow(a, mod-2, mod);
}

ll solve(ll n, ll r){
	ll mods[] = {3, 11, 13, 37}; // 3 appears three times in original mod
	ll M[] = {11*13*37, 3*13*37, 3*11*37, 11*13*37};
	ll Y[4];
	for (ll i = 0; i < 3; i += 1){
		Y[i] = mod_inverse(M[i], mods[i]);
	}
	ll rems[4];
	for (ll i = 0; i < 3; i += 1){
		rems[i] = bigC(n, r, mods[i]);
		cout << ""
	}
	ll ans = 0;
	for (ll i = 0; i < 3; i += 1){
		ans = (ans + rems[i]*M[i]*Y[i])%(27*11*13*37);
	}
	return ans;
}


int main(void){
	ll t;
	scanf("%lld", &t);
	while(t--){
		ll n, r;
		scanf("%lld %lld", &n, &r);
		printf("%lld\n", solve(n, r));
	}
}