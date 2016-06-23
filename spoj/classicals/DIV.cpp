#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define ll long long

ll isprime[1000001];

ll pow(ll a, ll b){
	if (b ==1) return a;
	if(b%2){
		return a*pow(a, b-1);
	}
	ll x = pow(a, b/2);
	return x*x;
}

vector<ll> sieve(){
	fill_n(isprime, 1000001, 1);
	isprime[0] = isprime[1] = 0;
	for (ll i =2 ; i < 1001; i += 1){
		if(isprime[i]){
			for (ll j = i*i; j < 1000001; j += i){
				isprime[j] = 0;
			}
		}
	}
	vector<ll> temp;
	for (ll i = 2; i < 1000001; i += 1){
		if(isprime[i]){
			temp.push_back(i);
		}
	}
	return temp;
}

int main(void){

	vector<ll> primes = sieve();
	// cout << "Here are some primes: " << endl;
	// for (ll i = 0; i< 20; i += 1){
	// 	cout << primes[i] << " ";
	// }
	// cout << endl;
	vector<ll> ans;
	ll P = primes.size();
	cout << "Total primes are: " << P << endl;
	ll limit = 1000001;
	ll x, y;
	for (ll i = 0; i < P-1; i += 1){
		for (ll j = i+1; j < P; j += 1){
			x = 0; 
			y = 0;
			if(primes[i]*primes[j] >= limit) break;
			// cout << "primes[i]= " << primes[i] << " primes[j]= " << primes[j] << endl;
			while (pow(primes[i], primes[x]) < limit){
				y = 0;
				while(pow(primes[i], primes[x]-1)*pow(primes[j], primes[y]-1) < limit){
					// cout << "primes[i]= " << primes[i] << " primes[j]= " << primes[j] << " primes[x]= " << primes[x] << " primes[y] " << primes[y] << " pow1: " << pow(primes[i], primes[x]-1) << " pow2: " << pow(primes[j], primes[y]-1) << endl;
					if(primes[x] != primes[y]){
						// cout << "Pushing: " << pow(primes[i], primes[x]-1)*pow(primes[j], primes[y]-1) << endl;
						ans.push_back(pow(primes[i], primes[x]-1)*pow(primes[j], primes[y]-1));
					}
					y += 1;
				}
				x += 1;
			}
		}
	}
	ll rems[] = {6, 10, 14, 22, 15, 21};
	ll bases[] = {2, 3, 5, 7};
	for (ll i = 0; i < 4; i += 1){
		for (ll j = 0; j < 6; j += 1){
			ll x = pow(bases[i], rems[j]-1);
			if(x > 0 && x < limit){
				ans.push_back(x);
			} 
		}
	}
	ans.push_back(pow(11, 5));
	sort(ans.begin(), ans.end());
	for (ll i = 8; i < ans.size(); i += 9){
		cout << ans[i] << endl;
	}
}