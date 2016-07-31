#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define limit 220000

int dp[41]={0};
int primes[limit], isprime[limit];

void noways(){
	dp[0] = dp[1] = dp[2] = dp[3] = 1;
	for (int i = 4; i < 41; i += 1){
		dp[i] = dp[i-1] + dp[i-4];
	}
	return ;
}

void precomputePrimes(){
	fill_n(isprime, limit, 1);
	isprime[0] = isprime[1] = 0;
	for (int i = 4; i < limit; i += 2){
		isprime[i] = 0;
	}
	for (int i = 3; i < (int)sqrt(limit)+1; i += 2){
		if(isprime[i]){
			for (int j = i*i; j < limit; j += 2*i){
				isprime[j] = 0;
			}
		}
	}
	primes[0] = primes[1] = 0;
	for (int i = 2; i < limit; i += 1){
		if(isprime[i]){
			primes[i] = primes[i-1] + 1;
		} else {
			primes[i] = primes[i-1];
		}
	}
	return;
}

int solve(int n){
	return primes[dp[n]];
}

int main(void){
	precomputePrimes();
	noways();
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		cout << solve(n) << endl;
	}
}