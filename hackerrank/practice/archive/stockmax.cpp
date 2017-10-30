#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define ll long long

int main(void){
	ll t;
	scanf("%lld",&t);
	while(t--){
		ll n;
		scanf("%lld", &n);
		ll a[n];
		for (ll i = 0; i < n; i += 1){
			scanf("%lld", &a[i]);
		}
		vector<ll> maxindices;
		ll maxind = max_element(a, a+n)-a;
		while(maxind < n){
			// cout << "Maxind: " << maxind << endl;
			maxindices.push_back(maxind);
			maxind = max_element(a+maxind+1, a+n)-a;
		}
		ll profit = a[maxindices[0]] * (maxindices[0]) - accumulate(a, a+maxindices[0], (ll)0);
		profit = profit > 0 ? profit : 0;
		// cout << "Initial profit " << profit << endl;
		for (ll i = 1; i < maxindices.size(); i += 1){
			ll toadd = a[maxindices[i]]*(maxindices[i]-maxindices[i-1]-1) - accumulate(a+maxindices[i-1]+1, a+maxindices[i], (ll)0);
			// cout << "next variation " << toadd << " ";
			profit += toadd > 0 ? toadd : 0;
			// cout << "Final profit after maxindex: " << maxindices[i] << endl;
		}
		printf("%lld\n", profit);

	}
}