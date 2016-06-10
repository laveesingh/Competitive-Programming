#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

#define ll long long
#define limit (ll)pow(10,7)+1

set<ll> tprimes;
ll num;
float sqn;

bool isperfsquare(ll n){
	 sqn = sqrt(n);
	cout << "square root is" << sqn << endl;
	return (sqn-(ll)sqn) == 0.0;
}

void init(){
	ll primes[limit+1];
	fill_n(primes, limit+1, 1);
	primes[0] = primes[1] = 0;
	tprimes.insert(4);
	for (ll i = 4; i < limit; i += 2){
		primes[i] = 0;
	}
	for (ll i = 3; i < (ll)sqrt(limit+1)+1; i +=2){
		if (primes[i]){
			tprimes.insert(i*i);
			// if(i==(ll)sqn) cout << "Found sqrt" << endl;
			// if (i*i == num){
			// 	cout << "Found" << endl;
			// }
			for (ll j = i*i; j < limit+1; j += i){
				primes[j] = 0;
			}
		}
	}
}

bool istprime(ll n){
	if(tprimes.find(n) != tprimes.end()) return true;
	return false;
}

int main(void){
	ll n, x;
	cin >> n;
	num = 999966000289ll;
	cout << "perfsu" << isperfsquare(num) << endl;
	sqn = sqrt(n);
	init();
	for (int i = 0; i < n; i += 1){
		cin >> x;
		if (istprime(x)){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	
}