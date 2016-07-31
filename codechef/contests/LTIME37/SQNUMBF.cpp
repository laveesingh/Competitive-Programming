#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define sc(x) scanf("%lld", &x)

const ll limit = 1000002;

ll isprime[limit];
vector<ll> primes;

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

void sieve(){
	fill_n(isprime, limit, 1);
	isprime[0] = isprime[1] = 0;
	for (ll i = 4; i < limit; i += 2){
		isprime[i] = 0;
	}
	for (ll i = 3; i < (ll)sqrt(limit)+1; i += 2){
		if(isprime[i]){
			for (ll j = i*i; j < limit; j += 2*i){
				isprime[j] = 0;
			}
		}
	}
	primes.push_back(2);
	for (ll i = 3; i < limit; i += 2){
		if(isprime[i]){
			primes.push_back(i);
		}
	}
}

vector<ll> factorize(ll n){
	// cout << "Factorizing for " << n << endl;
	vector<ll> temp;
	if (isprime[n]){
		temp.push_back(n);
		return temp;
	}
	ll i = 0;
	while (n > 1 && i < primes.size()){
		// cout << "n = " << n << endl;
		if(n%primes[i] == 0){
			while(n%primes[i] == 0){
				temp.push_back(primes[i]);
				n /= primes[i];
			}
		}
		i += 1;
	}
	if (n > 1){
		temp.push_back(n);
	}
	return temp;
}

bool isSq(double n){
	return n-(ll)n == 0;
}

ll solve(ll a[], ll n){
	for(ll i = 0; i < n-1; i += 1){
		for (ll j = i+1; j < n; j += 1){
			if(gcd(a[i], a[j]) > 1){
				return gcd(a[i], a[j]);
			}
		}
	}
	for (ll i = 0; i < n; i += 1){
		for (ll q = 1; q < min(1000000ll, n); q += 1){
			if(a[i]%q == 0){
				ll x = a[i]/q;
				double sqrtx = (double)sqrt(x);
				if(isSq(sqrtx)){
					return (ll) sqrtx;
				}
			}
		}
		for (ll j = 0; j < primes.size(); j += 1){
			if (primes[j] > a[i]){
				break;
			} else {
				if(a[i] % (primes[j] * primes[j]) == 0){
					return primes[j];
				}
			}
		}
	}

}

int main(){
	ios::sync_with_stdio(false);	
	sieve();
	ll t;
	sc(t);
	while(t--){
		ll n;
		sc(n);
		ll a[n];
		for (ll i = 0; i < n; i += 1){
			sc(a[i]);
		}
		cout << solve(a, n) << endl;
		// bool done = false;
		// map<ll, ll> freq;
		// for (ll i =0; i < n; i += 1){
		// 	vector<ll> factors = factorize(a[i]);
		// 	// cout << "Here are the factors of " << a[i] << endl;
		// 	// for (int i = 0; i < factors.size(); i += 1){
		// 	// 	cout << factors[i] << " " ;
		// 	// }
		// 	// cout << endl;
			
		// 	for (ll i = 0; i < factors.size(); i += 1){
		// 		freq[factors[i]] += 1;
		// 	}
		// }
		// for (map<ll,ll>::iterator it = freq.begin(); it != freq.end(); it++){
		// 	if (it->second >= 2){
		// 		cout << it->first << endl;
		// 		break;
		// 	}
		// }
	}
}