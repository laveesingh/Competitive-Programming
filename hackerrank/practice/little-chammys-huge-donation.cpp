#include <cstdio>

using namespace std;

#define ll long long

bool satisfies(ll n, ll x){
	if(n/6 < 0) return false;
	if((n*(n+1))/6 < 0) return false;
	if(((n+1)*(2*n+1))/6 < 0) return false;
	if ((n*(n+1)*(2*n+1))/6 <= x && (n*(n+1)*(2*n+1))/6 > 0){
		return true;
	}
	return false;
}

int main(void){
	ll t;
	scanf("%lld", &t);
	while(t--){
		ll x;
		scanf("%lld", &x);
		ll lo = 0, hi = 500001, mid;
		while (hi - lo > 1){
			// printf("lo=%lld hi=%lld ", lo, hi);
			mid = lo + (hi - lo)/2;
			// printf("mid=%lld ", mid);
			// if(mid == lo) break;
			if(satisfies(mid, x)){
				// printf("satisfies \n");
				lo = mid;
			}else{
				// printf("doesn't satisfy\n");
				hi = mid;
			}

		}
		// if(satisfies(lo+1, x)) lo++;

		printf("%lld\n", lo);
	}
}