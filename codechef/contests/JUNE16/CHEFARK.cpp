#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

#define limit 100001
#define MOD 1000000007
#define ll long long

ll f[limit]; // factorial array
ll *a; // array itself
ll c; // no of 0's in the array

ll power(ll a, ll b, ll mod){
	ll x = 1, y = a;
	while (b > 0){
		if (b%2){
			x = (x*y)%mod;
		}
		y = (y*y)%mod;
		b /= 2;
	}
	return x%mod;
}

ll inv_euler(ll n){
	//cout << "inv_euler for N:"<<n<<" is " << power(n,MOD-2) << endl;;
	return power(n, MOD-2, MOD);
}

ll comb(ll n, ll k){
	//cout << "comb for " << n <<  " " << k << endl;
	//cout.flush();
	//cout << "f[n]: " << f[n] << " f[k]: " << f[k] << " f[n-k]: " << f[n-k] << endl;
	return (f[n]*((inv_euler(f[k])*inv_euler(f[n-k]))%MOD))%MOD;
}

ll solve(ll n, ll k){
	// printf("solve started...");
	//cout << "Solve started";
	//cout.flush();
	// for (ll i = 0; i < n; i += 1){
	// 	c += (a[i] == 0 ? 1 : 0);
	// }
	// printf("zeros counted...");
	//cout << "Zeroes counted";
	//cout.flush();
	if (c != 0 && k == 1){
		return n-c+1;
	}
	if (c == 0){
		// printf("zeros: %lld", c);
		//cout << " zeros " << c;
		//cout.flush();
		if (n == 1 || n == 2) return n;
		if (k%2){
			// printf("... k is odd...");
			//cout << " k is odd ";
			//cout.flush();
			ll ans = 0;
			for (ll i = 1; i < min(n,k)+1; i += 2){
				// ans += comb(n, i);
				ans = (ans+comb(n,i))%MOD;
			}
			return ans;
		}
		// printf(" ... k is even...");
		//cout << " K is even ";
		ll ans = 0;
		for(ll i = 0; i < min(n,k)+1; i += 2){
			// ans += comb(n,i);
			ans = (ans+comb(n,i))%MOD;
		}
		return ans;
	}
	n -= c;

	// cout << n << " " << endl;	
	return power(2,min(n,k), MOD);
}

int main(void){
	ll n, k, t;
	scanf("%lld", &t);
	f[0] = 1;
	f[1] = 1;
	for (ll i = 2; i < limit; i += 1){
		f[i] = (f[i-1]*i)%MOD;
	}
	while(t--){
		c = 0;
		scanf("%lld %lld", &n, &k);
	
		a = new ll[n];
		for (ll i = 0; i < n; i += 1){
			// printf("Enter element...\n");
			scanf("%lld", &a[i]);
			if (a[i] == 0) c += 1;
		}
		// printf("Entering solve function...\n");
		printf("%lld\n", solve(n, k));
	}
}