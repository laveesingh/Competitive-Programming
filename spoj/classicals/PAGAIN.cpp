#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long

ll pow(ll a, ll b, ll m){
	if(b == 1){
		return a%m;
	}
	if(b%2){
		return (a*pow(a,b-1, m))%m;
	}
	ll x = pow(a, b/2, m);
	return (x*x)%m;
}

bool isprime(ll n){
	if(n < 2) return false;
	if(n == 2) return true;
	for(ll i = 0; i < 10; i += 1){
		ll x = rand()%(n-1) + 1;
		if(pow(x, n-1, n) != 1) return false;
	}
	return true;
}


ll bprime(ll n){
	// prime below n
	if (n == 3) return 2;
	n -= (n%2) ? 2: 1;
	while (1){
		if(isprime(n)) return n;
		n -= 2;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	srand(time(NULL)); // random number generator
	int t;
	cin >> t;
	ll n;
	while(t--){
		cin >> n;
		cout << bprime(n) << endl;
	}
	// cout << isprime(4294967291) << endl;
	
}