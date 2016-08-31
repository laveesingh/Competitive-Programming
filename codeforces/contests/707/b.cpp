/*input

*/

#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define inf INT_MAX

int main(void){
	ios::sync_with_stdio(false);
	int n, m, k, x, y, z, ans = inf;
	cin >> n >> m >> k;
	map<pii, int> dist;
	map<pii, int> isedge;
	vector<vi> graph(n+1, vi());
	for (int i = 0; i < m; i += 1){
		cin >> x >> y >> z;
		if(!isedge[{x,y}]){
			// cout << "First edge: " << x << " " << y << endl;
			graph[x].pb(y);
			graph[y].pb(x);
			dist[{x,y}] = z;
			dist[{y,x}] = z;
			isedge[{x,y}] = 1;
			isedge[{y,x}] = 1;
		}else{
			// cout << "Second edge: " << x << " " << y << endl;
			if (dist[{x,y}] > z){
				dist[{x,y}] = z;
				dist[{y,x}] = z;
			}
		}
		// cout << "After setting: " << x << " " << y << ": " << dist[{x,y}] << endl;
	}
	if (k == 0) ans = -1;
	else{
		int K[k];
		int isK[n+1];
		fill_n(isK, n+1, 0);
		for (int i = 0; i < k; i += 1){
			cin >> K[i];
			isK[K[i]] = 1;
		}
		for (int i = 0; i < k; i += 1){
			int s = K[i];
			for (int adj: graph[s]){
				if (!isK[adj]){
					ans = min(ans, dist[{s, adj}]);
				}
			}
		}
	}
	cout << (ans == inf ? -1 : ans) << endl;
}