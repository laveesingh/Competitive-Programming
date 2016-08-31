/*input
5
3 1 4 5 1
2
3 3
*/
#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define init(a, n) a.find(n) != a.end()

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll h[n];
	for (ll i = 0; i < n; i += 1){
		cin >> h[i];
	}	
	ll m, temp;
	cin >> m;
	set<ll> st;
	for (ll i = 0; i < m; i += 1){
		cin>>temp;
		st.insert(temp-1);
	}
	vector<ll> l(st.begin(), st.end());
	ll j = 0;
	ll y = l[j];
	for (ll i = 0; i < n; i += 1){
		if (y <= i){
			if(j+1 == l.size()) y = 1000000000;
			else y = l[++j];
		}
		h[i] = min(h[i], y-i);
	}
	// for (int i = 0; i< n; i += 1){
	// 	cout << h[i] << " ";
	// }
	// cout << endl;
	cout << accumulate(h, h+n, (ll)0ll) << endl;
}