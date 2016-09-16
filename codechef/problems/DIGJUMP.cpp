/*input
01234567890
*/

#include <bits/stdc++.h>

using namespace std;

#define inf INT_MAX
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define mci map<char, int>
#define mic map<int, char>
#define vit vi::iterator
#define sit si::iterator
#define psb push_back
#define ppb pop_back
#define mp make_pair
#define F(i,n) for (int i = 0; i < n; i += 1)
#define inp(a,n) F(i,n) cin>>a[i]
#define print(a,n) F(i,n) {cout << a[i] << " ";} cout << endl
// graphs all will be 1 based indexed
#define uduwginp(g, m) F(i,m){cin>>x>>y;g[x].psb(y);g[y].psb(x);}
#define duwginp(g,m) F(i,m){cin>>x>>y; g[x].psb(y);}
#define printgraph(g,n) for(int i = 1; i <= n; i += 1){cout<< endl<<i<<": "; for(int adj:g[i]) cout << adj <<" ";} cout << endl


int main(void){
	ios::sync_with_stdio(false);
	string a;
	cin >> a;
	int n = a.length();
	vi freq[10];
	for (int i = 0; i < n; i += 1){
		freq[a[i]-'0'].psb(i);
	}
	int dist[n], visited[n], filled[10];
	fill_n(dist, n, inf);
	fill_n(filled, 10, 0);
	fill_n(visited, n, 0);
	queue<pii> q;
	q.push({0, 0});
	dist[0] = 0;
	visited[0] = 1;
	while(!q.empty()){
		pii cur = q.front();
		q.pop();
		int ci = cur.first;
		int cd = cur.second;
		if (!filled[a[ci]-'0']){
			filled[a[ci]-'0'] = 1;
			for (int ind: freq[a[ci]-'0']){
				if (ci != ind){

					visited[ind] = 1;
					dist[ind] = min(dist[ind], cd+1);
					q.push({ind, cd+1});
				}
			}
		}
		if (ci > 0 and !visited[ci-1]){
			visited[ci-1] =1;
			dist[ci-1] = min(dist[ci-1], cd+1);
			q.push({ci-1, cd+1});
		}
		if (ci < n-1 and !visited[ci+1]){
			visited[ci+1] = 1;
			dist[ci+1] = min(dist[ci+1], cd+1);
			q.push({ci+1, cd+1});
		}
	}
	cout << dist[n-1] << endl;
}