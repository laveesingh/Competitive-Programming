#include <cstdio>

using namespace std;

#define ll long long

const ll mod = 1000000009;
const ll limit = 10000001;

ll dpe[limit], dpo[limit]; // for even and odd numbers

void compute_even(){
	dpe[0] = 0;
	ll inc = -1;
	ll last = 0;
	for (ll i = 2; i < limit; i += 2){
		dpe[i] = dpe[i-2];
		inc += 2;
		// if(i == 8){
			// prllf("value of dpe[%d] is %d ", 6, dpe[6]);
		// }
		for (ll j = 0; j < 4; j += 1){
			last += inc;
			// if(i == 6 || i == 8)
				// prllf("Adding %d ", last);
			dpe[i] = (dpe[i] + last)%mod;
		}
	}
}

void compute_odd(){
	dpo[1] = 1;
	ll last = 1;
	ll inc = 0;
	for (ll i = 3; i < limit; i += 2){
		dpo[i] = dpo[i-2];
		inc += 2;
		for(ll j = 0; j < 4; j += 1){
			last += inc;
			dpo[i] = (dpo[i] + last)%mod;
		}
	}
}

int main(void){
	ll t;
	compute_even();
	compute_odd();
	// for (ll i = 2; i < 10; i += 2){
	// 	prllf("%d\n", dpe[i]);
	// }
	scanf("%lld",&t);
	while(t--){
		ll n;
		scanf("%lld", &n);
		if(n%2){
			printf("%lld\n", dpo[n]);
		}else{
			printf("%lld\n", dpe[n]);
		}
	}
}