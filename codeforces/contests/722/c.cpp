#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<ll, ll>


int main(void){
	ll n;
	cin >> n;
	ll a[n];
	for(ll i = 0; i < n; i += 1){
		cin >> a[i];
	}
	ll dest[n];
	for(ll i = 0; i < n; i += 1){
		cin >> dest[i];
		dest[i]--;
	}
	map<pii, ll> store;
	map<ll, pii> rev_store;
	ll totalsum = accumulate(a, a+n, (ll)0);
	store[{0,}]
}