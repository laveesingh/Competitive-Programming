#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <iostream>


using namespace std;

#define ll long long
#define pii pair<int, int>
#define mp make_pair

int main(void){
	ll n, k, q;
	// ll a[n];
	ll temp;
	vector<ll> a;
	scanf("%lld %lld %lld", &n, &q, &k);
	for (ll i = 0; i < n; i += 1){
		scanf("%lld", &temp);
		a.push_back(temp);
	}
	// for (int i = 0; i < n; i+= 1){
	// 	cout << a[i] << endl;
	// }
	ll x, y;
	vector<pii> queries;
	for(ll i = 0; i < q; i += 1){
		scanf("%lld %lld", &x, &y);
		queries.push_back(mp(x, y));
	}
	for (int i = 0; i < q; i += 1){
		if(i > 0 && queries[i].first >= queries[i-1].first && queries[i].second <= queries[i-1].second){
			// do nothing
		}else if(i < q-1 && queries[i].first >= queries[i+1].first && queries[i].second <= queries[i+1].second){
			// do nothing
		}else{
			sort(a.begin()+queries[i].first, a.begin()+queries[i].second+1);
		}
	}
	// for (int i = 0; i < n; i+= 1){
	// 	cout << a[i] << endl;
	// }
	printf("%lld\n", a[k]);
}

