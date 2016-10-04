#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define vi vector<int>

int main(void){
	int n, m, T, x, y, z;
	cin >> n >> m >> T;
	vector<vi> Graph(n+1, vi());
	int dist[n+1][n+1];
	for(int i= 0; i < m; i += 1){
		cin >> x >> y >> z;
		Graph[x].push_back(y);
		dist[x][y] = z;
		dist[y][x] = z;
	}

	deque<pair<pii>, vi> q;
	q.push_back({{1, 0}, {1}});
	vi origpath;
	map<int, int> par;
	par[1] = -1;
	int vis[n+1];
	memset(vis, 0, sizeof(int)*(n+1));
	vis[1] = 1;
	while (!q.empty()){
		pii cur = q.front();
		q.pop_front();
		// cout << "current: " << cur.first << endl;
		for (int child: Graph[cur.first]){
			par[child] = cur.first;
			if (!vis[child] and cur.second+dist[cur.first][child] <= T){
				q.push_back({child, cur.second+dist[cur.first][child]});
				vis[child] = 1;
				if(child == n){
					int curpathlen = 0;
					int curchild = child;
					while(curchild != -1){
						curpathlen += 1;
						curchild = par[curchild];
					}
					if(curpathlen > origpath.size()){
						origpath.clear();
						curchild = child;
						while(curchild != -1){
							origpath.push_back(curchild);
							curchild = par[curchild];
						}
					}
				}
			}
		}
	}
	reverse(origpath.begin(), origpath.end());
	cout << origpath.size() << endl;
	for(int s: origpath){
		cout << s << " ";
	}
	cout << endl;
}