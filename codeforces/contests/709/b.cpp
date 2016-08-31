/*input
5 0
0 0 1000 0 0
*/

#include <bits/stdc++.h>

using namespace std;
#define inf 1000000000
#define ll long long
int main(void){
	ios::sync_with_stdio(false);
	ll n, a;
	cin >> n >> a;
	ll X[n];
	for (ll i = 0; i<n; i += 1){
		cin >> X[i];
	}	
	sort(X, X+n);
	map<ll, ll> freq;
	if (n == 1){
		cout << 0 << endl;
	}else if (n == 2){
		cout << min(abs(a-X[0]), abs(a-X[1])) << endl;
	}else if (a <= X[0]){
		ll dist = X[0] - a;
		for (ll i = 1; i < n-1; i += 1){
			dist += (X[i]-X[i-1]);
		}
		cout << dist << endl;
	}else if(a >= X[n-1]){
		ll dist = a-X[n-1];
		for (ll i = 2; i < n; i += 1){
			dist += (X[i]-X[i-1]);
		}
		cout << dist << endl;
	}else{
		ll ans = inf;
		ll dist1 = a - X[0];
		for (ll i = 1; i < n; i += 1){
			dist1 += X[i]-X[i-1];
		}
		// cout << "Total distance in 1st case: " << dist1 << endl;
		ans = min(dist1-(X[n-1]-X[n-2]), dist1-(min(X[1], a)-X[0])*2);
		// cout << "First case answer; " << ans << endl;
		ll dist2 = X[n-1]-a;
		for (ll i = 1; i < n; i += 1){
			dist2 += X[i]-X[i-1];
		}
		// cout << "total distance in 2nd ase: " << dist2 << endl;
		ll ans2 = min(dist2-(X[1]-X[0]), dist2-(X[n-1]-max(a,X[n-2]))*2);
		// cout << "Second case ansswer: " << ans2 << endl;
		ans = min(ans, ans2);
		cout << ans << endl;
	}
}