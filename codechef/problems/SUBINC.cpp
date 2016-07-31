#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main(void){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;
		ll a[n];
		for(ll i = 0; i < n; i += 1){
			cin >> a[i];
		}
		vector<ll> lens;
		ll curlen = 1;
		for(ll i = 1; i < n; i += 1){
			if(a[i] < a[i-1]){
				lens.push_back(curlen);
				curlen = 1;
			} else {
				curlen++;
			}
		}
		lens.push_back(curlen);
		ll ans = 0;
		for(ll i = 0; i < lens.size(); i += 1){
			ans += (lens[i]*(lens[i]+1))/2;
		}
		cout << ans << endl;
	}
}