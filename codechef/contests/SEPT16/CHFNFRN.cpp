/*input
1
6 6
2 6
1 5
5 6
4 5
1 3
2 4
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
#define init(a, n) a.find(n) != a.end()
#define F(i,n) for (int i = 0; i < n; i += 1)
#define inp(a,n) F(i,n) cin>>a[i]
#define print(a,n) F(i,n) {cout << a[i] << " ";} cout << endl
// graphs all will be 1 based indexed
#define uduwginp(g, m) F(i,m){cin>>x>>y;g[x].psb(y);g[y].psb(x);}
#define duwginp(g,m) F(i,m){cin>>x>>y; g[x].psb(y);}
#define printgraph(g,n) for(int i = 1; i <= n; i += 1){cout<< endl<<i<<": "; for(int adj:g[i]) cout << adj <<" ";} cout << endl

int **ispair, n, m;
vector<pii> a;

bool contradicting(vi temp){
	for(int s: temp){
		for (int t: temp){
			if(s != t and !ispair[s][t]){
				return true;
			}
		}
	}
	return false;
}

bool solve(vi first, vi second, si vis){
	if(vis.size() == a.size()) return true;
	// cout << "Solving" << endl;
	first.psb(a[0].second);
	vis.insert(0);
	for (int i = 1; i < a.size(); i += 1){
		if (!ispair[a[0].second][a[i].second]){
			second.psb(a[i].second);
			vis.insert(i);
		}
	}
	// cout << "Initial first: "; print(first, first.size());
	// cout << "Initial second: "; print(second, second.size());
	if(contradicting(second)) return false;
	int prev_size = vis.size();
	while (vis.size() < a.size()){
		// cout << "vis size: " << vis.size() << " a size: " << a.size() << endl;
		for (int i = 0; i < a.size(); i += 1){
			bool f1 = true, f2 = true;
			if (init(vis, i) == false){
				for (int s: first){
					if (!ispair[s][a[i].second]){
						f1 = false;
						break;
					}
				}
				for (int s: second){
					if (!ispair[s][a[i].second]){
						f2 = false;
						break;
					}
				}
				if(!f1 and !f2){
					return false;
				}else if(!f1){
					second.psb(a[i].second);
					vis.insert(i);
				}else if(!f2){
					first.psb(a[i].second);
					vis.insert(i);
				}
			}
		}
		if (vis.size() == prev_size){
			for(int i = 0; i < a.size(); i += 1){
				if(init(vis, i) == false){
					second.psb(a[i].second);
					vis.insert(i);
					break;
				}
			}
		}
		prev_size = vis.size();
	}
	return true;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x, y;
		// Input goes here
		cin >> n >> m;
		ispair = new int*[n+1];
		int degree[n+1];
		fill_n(degree, n+1, 0);
		for (int i = 0; i <= n; i += 1){
			ispair[i] = new int[n+1];
			for (int j = 0; j <= n; j +=1){
				ispair[i][j] = 0;
			}
		}
		for (int i = 0; i < m; i += 1){
			cin >>  x >> y;
			ispair[x][y] = 1;
			ispair[y][x] = 1;
			degree[x] += 1;
			degree[y] += 1;
		}
		// Input ends here
		// Solution starts here
		a.clear();
		for (int i = 1; i < n+1; i += 1){
			if(degree[i] < n-1)
				a.psb({degree[i], i});
		}
		vi first, second;
		sort(a.begin(), a.end());
		bool ans;
		if (a.empty()){
			ans = true;
		}else{
			si vis;
			ans = solve(first, second, vis);
		}
		if (ans){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
	
}