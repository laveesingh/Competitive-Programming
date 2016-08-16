/*input
5 2
3 5 2 2 4
1 4
*/

#include <bits/stdc++.h>

using namespace std;

#define isin(a, n) a.find(n) != a.end()
#define ll long long

ll sPOP(vector<ll> a, ll b[]){
	// cout << "vector: ";
	// for (ll x: a) cout << x << " ";
	ll total = 0;
	ll psum = 0;
	for (ll x: a){
		total += psum*b[x];
		psum += b[x];
	}
	// cout << "total: " << total << endl;
	return total;
}

int main(void){
	ios::sync_with_stdio(false);
	ll n, k,temp;
	cin >> n >> k;
	ll b[n];
	for (ll i = 0; i < n; i += 1){
		cin >> b[i];
	}
	ll sum = accumulate(b, b+n, 0);
	set<ll> Xs;
	vector<ll> Xv;
	for (ll i = 0; i < k; i += 1){
		cin >> temp;
		temp--;
		Xs.insert(temp);
		Xv.push_back(temp);
	}
	ll ans = 0;
	for (set<ll>::iterator it = Xs.begin(); it != Xs.end(); it++){
		ans += sum*b[(*it)] - b[(*it)]*b[(*it)];
	}
	// cout << "Xv vector is ";
	// for (ll x: Xv) cout << x << " ";
	// cout << endl;
	// cout << "ans: " << ans << endl;
	// for (ll i = 0; i < Xv.size()-1; i += 1){
	// 	ans -= b[Xv[i]]*b[Xv[i+1]];
	// }
	ans -= sPOP(Xv, b);
	// cout << "ans: " << ans << endl;
	for (ll i = 0; i < n-1; i += 1){
		if (isin(Xs, i) or isin(Xs, i+1)){
			continue;
		}
		// cout << i << " " << i+1 << endl;
		ans += b[i]*b[i+1];
	}
	if (!(isin(Xs, 0) or isin(Xs,n-1))){
		ans += b[0]*b[n-1];
	}
	cout << ans << endl;



}