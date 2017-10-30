#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define ll long long

bool fits(ll n, ll x){
	ll ans = 0;
	while (n > 0){
		ans += n/5;
		n /= 5;
	}
	if(ans >= x) return true;
	return false;
}

int main(void){
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll lo = 0, hi = (ll)pow(10,18), mid;
		while(hi - lo > 1){
			mid = lo + (hi-lo)/2;
			if(fits(mid, n)){
				hi = mid;
			}else{
				lo = mid+1;
			}
		}
		if(lo > hi){
			swap(lo,hi);
		}
		if(fits(lo, n)){
			hi = lo;
		}
		cout << hi << endl;
	}
}