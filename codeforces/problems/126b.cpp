/*input
qwertyqwertyqwerty
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll pow(ll a, ll b, ll c){
	if (b == 0) return 1;
	if (b == 1) return a%c;
	if (b&1) return (a*pow(a, b-1, c))%c;
	ll x = pow(a, b/2, c);
	return (x*x)%c;
}

ll multmod(ll a, ll b, ll c){
	if (b == 0) return 0;
	if (b == 1) return a%c;
	if (b&1) return (a+multmod(a, b-1, c))%c;
	ll x = multmod(a, b/2, c);
	return (x+x)%c;
}

ll solve(string a, ll n){
	ll lps[n];
	lps[0] = 0;
	ll i = 1, j = 0;
	while (i < n){
		if (a[i] == a[j]){
			lps[i++]  = ++j;
		}else{
			if(j != 0){
				j = lps[j-1];
			}else{
				lps[i++] = 0;
			}
		}
	}
	ll suffix = lps[n-1];
	if (suffix == 0) return 0;
	string b = a.substr(n-suffix, suffix);
	cout << "New String b is " << b << endl;
	ll Hash[suffix];
	ll mod = 100000007;
	ll p = 37;
	Hash[0] = multmod((b[0]-'a' + 1), pow(p, 1, mod), mod)%mod;
	for (ll i = 1; i < suffix; i += 1){
		Hash[i] = (Hash[i-1] + multmod( b[i]-'a'+1, pow(p,i+1,mod), mod) )%mod;
	}
	cout << "Here's the hash array" << endl;
	for (ll i= 0; i < suffix; i += 1){
		cout << Hash[i] << " ";
	}
	cout << endl;
	ll match = 0;
	cout << "Distinct character have hash: " << endl;
	cout << b[0] << ": " << Hash[0] << endl;
	for (int i = 0; i < suffix; i += 1){
		cout << b[i] << ": " << (Hash[i]-Hash[i-1])%mod << endl;
	}
	// for (ll i = 0; i < suffix-1; i += 1){
	// 	cout << "hash of length " << i+1 << " " << Hash[i]  << " and from end: " << (Hash[suffix-1]-Hash[suffix-i-1]+mod)%mod << endl;
	// 	if(Hash[i] == Hash[suffix-1]-Hash[suffix-i-1]){
	// 		match = i;
	// 	}
	// }
	return match;
}

int main(void){
	ios::sync_with_stdio(false);
	string a;
	cin >> a;
	ll n = a.length();
	ll ans = solve(a, n);
	if(ans == 0){
		cout << "Just a legend" << endl;
	}else{
		cout << a.substr(0,ans) << endl;
	}
}