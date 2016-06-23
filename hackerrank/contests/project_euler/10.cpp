#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll limit = 1000001;
const ll sqlimit = 1001;

ll isprime[limit];
ll dp[limit];

void sieve(){
	fill_n(isprime, limit, 1);
	isprime[0] = isprime[1]= 0;
	for (ll i = 4; i < limit; i += 2){
		isprime[i] = 0;
	}
	for (ll j = 3; j < sqlimit; j += 2){
		if(isprime[j]){
			for (ll k = j*j; k < limit; k += 2*j){
				isprime[k]  = 0;
			}
		}
	}
	dp[0]= dp[1] = 0;
	for (ll i = 2; i < limit; i += 1){
		if(isprime[i]){
			dp[i] = dp[i-1]+i;
		}else{
			dp[i] = dp[i-1];
		}
	}
}

int main(void){
	sieve();
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		cout << dp[n] << endl;
	}
}