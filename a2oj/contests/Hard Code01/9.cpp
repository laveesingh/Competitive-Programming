#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll sqM = 1000000;
ll primes[1000000];

bool issq(float a){
	if((ll)a == a) return true;
	return false;
}

void set_primes(){
	fill_n(primes, sqM, 1);
	primes[0] = primes[1] = 0;
	for (ll i = 4; i < sqM; i += 2){
		primes[i] = 0;
	}
	for (ll i = 3; i < sqrt(sqM)+1; i += 2){
		if(primes[i]){
			for(ll j = i*i; j < sqM; j += i){
				primes[j] = 0;
			}
		}
	}
}

int main(void){
	ll n;
	set_primes();
	ll x;
	cin >> n;
	for (ll i = 0; i < n; i += 1){
		cin >> x;
		float fsqx = sqrt(x);
		int sqx = fsqx;
		if((ll)sqx*sqx == x && primes[sqx]){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}