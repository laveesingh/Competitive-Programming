#include <cstdio>
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

#define INF 1000000000
#define ll long long
#define pii pair<ll, ll>
#define mp make_pair

void solve(){
	ll n, m, p;
	// scanf("%l64d %l64d %l64d", &n, &m, &p);
	cin >> n >> m >> p;
	ll a[n][m];
	for (ll i = 0; i < n; i += 1){
		for (ll j = 0; j < m; j += 1){
			cin >> a[i][j];
			// scanf("%l64d", &a[i][j]);
		}
	}
	vector<pii> indices[p+1];
	for (ll i = 0; i < n; i += 1){
		for (ll j = 0; j < m; j+= 1){
			indices[a[i][j]].push_back(mp(i,j));
		}
	}
	// for (ll i = 0; i <= p; i += 1){
	// 	for (ll j = 0; j < indices[i].size(); j += 1){
	// 		cout << indices[i][j].first << "," << indices[i][j].second << " " ;
	// 	}
	// 	cout << endl;
	// }
	ll dist[n][m];
	for(ll i = 0; i < n; i += 1){
		for (ll j = 0; j < m; j += 1){
			if(a[i][j] == 1){
				dist[i][j] = i+j;
			}
		}
	}
	for(ll i = 2; i <= p; i += 1){
		for (pii temp: indices[i]){
			ll x = temp.first;
			ll y = temp.second;
			dist[x][y] = INF;
			for (pii temp2: indices[i-1]){
				ll xi = temp2.first;
				ll yi = temp2.second;
				dist[x][y] = min(dist[x][y], dist[xi][yi]+abs(xi-x)+abs(yi-y));
			}
		}
	}
	pii temp3 = indices[p][0];
	cout <<  dist[temp3.first][temp3.second] << endl;
}

int main(void){
	solve();
}