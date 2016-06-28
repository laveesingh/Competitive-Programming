#include <cstdio>

using namespace std;

#define sc(n) scanf("%lld", &n)

typedef long long ll;

int main(void){
	ll t;
	sc(t);
	while(t--){
		ll n;
		sc(n);
		n -= 1;
		ll x = n/3, y = n/5, z = n/15;
		ll ans = 3*((x*(x+1))/2) + 5*((y*(y+1))/2) - 15*((z*(z+1))/2);
		printf("%lld\n", ans);
	}

}