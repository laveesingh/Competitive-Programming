#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define ll long long

const ll N = 20;
ll n;
vector<ll> subs[N];
ll store[(1<<N)+1][N];

ll solve(ll mask, ll stud){
	ll ans = 0;
	if(store[mask][stud] != -1)
		return store[mask][stud];
	if(stud < n-1){
		for(ll sub: subs[stud])
			if(mask & (1<<sub)){
				if(store[mask^(1<<sub)][stud+1] != -1){
					ans += store[mask^(1<<sub)][stud+1];
				}else{
					ll x = solve(mask^(1<<sub), stud+1);
					store[mask^(1<<sub)][stud+1] = x;
					ans += x;
				}
			}
	}else{
		for(ll sub: subs[stud])
			if(mask & (1<<sub))
				ans += 1;
	}
	return store[mask][stud] = ans;
}

int main(void){
	ll t, temp;
	ilong(t);
	while(t--){
		ilong(n);
		for(ll i = 0; i < n; i += 1){
			subs[i].clear();
			for(ll j = 0; j < n; j += 1){
				ilong(temp);
				if(temp) subs[i].push_back(j);
			}
		}
		ll mask = 0;
		for(ll i = 0; i < n; i += 1) mask ^= (1<<i);
		memset(store, -1, sizeof(store));
		olong(solve(mask, 0));
	}
}

