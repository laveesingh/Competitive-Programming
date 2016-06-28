#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>

using namespace std;

#define ll long long
#define sc(x) scanf("%lld", &x)

const ll limit = 10000002;

ll isprime[limit];
vector<ll> primes;

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

int main(){
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
		bool done = false;
		map<ll, ll> freq;
		for (ll i =0; i < n; i += 1){
			vector<ll> factors = factorize(a[i]);
			// cout << "Here are the factors of " << a[i] << endl;
			// for (int i = 0; i < factors.size(); i += 1){
			// 	cout << factors[i] << " " ;
			// }
			// cout << endl;
			
			for (ll i = 0; i < factors.size(); i += 1){
				freq[factors[i]] += 1;
			}
		}
		for (map<ll,ll>::iterator it = freq.begin(); it != freq.end(); it++){
			if (it->second >= 2){
				cout << it->first << endl;
				break;
			}
		}
	}
}