#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ill(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define oll(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)
#define ll long long

const ll N = 5 * 1e4 + 1;
const ll mod = 1e9 + 7;
ll notprime[N];
ll tillprime[N];
vector<ll> primes;
inline void setprime(){
	notprime[0] = notprime[1] = 1;
	for(ll i = 4; i < N; i+=2) notprime[i] = 1;
	for(ll i = 3; i < sqrt(N)+1; i += 2)
		if(!notprime[i])
			for(ll j = i*i; j < N; j += 2*i)
				notprime[j] = 1;
	for(ll i = 1; i < N; i += 1)
		if(!notprime[i])
			tillprime[i] = tillprime[i-1] + 1, primes.push_back(i);
		else
			tillprime[i] = tillprime[i-1];
}

inline ll largePow(ll n, ll p){
	// returns largest power of p in n!
	ll ret = 0;
	while(n){
		n /= p;
		ret+=n;
	}
	return ret;
}

ll divfact(ll n){
	ll ans = 1;
	for(ll prime: primes){
		if(prime > n) break;
		ans *= (largePow(n, prime)+1);
		ans %= mod;
	}
	return ans;
}

int main(void){
	setprime();
	ll t;
	ill(t);
	while(t--){
		ll n;
		ill(n);
		oll(divfact(n));
	}
}

