#include <cstdio>
#include <iostream>

using namespace std;

#define mod 10000007
#define ll long long

ll pow(ll a, ll b){
	if(b < 0) cout << "Fucked up" << endl;
	if (b == 0) return 1;
	if (b == 1) return a%mod;
	if(b % 2){
		return (a*pow(a, b-1))%mod;
	}
	ll x = pow(a, b/2);
	return (x*x)%mod;
}



ll solve(ll n, ll k){
	int ans = ((pow(n%mod, n) + pow(n%mod, k))%mod + (2*pow((n-1)%mod, k) + 2*pow((n-1)%mod, n-1))%mod)%mod;
	return ans % mod;
}

int main(void){
	while(1){
		ll n, k;
		scanf("%lld %lld", &n, &k);
		if(n == 0 && k == 0) break;
		printf("%lld\n", solve(n, k));
	}
}