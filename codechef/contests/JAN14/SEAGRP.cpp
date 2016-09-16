/*input
1
2 2
1 2
1 2
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
#define print(a,n) F(i,n) {cerr << a[i] << " ";} cerr << endl
// graphs all will be 1 based indexed
#define uduwginp(g, m) F(i,m){cin>>x>>y;g[x].psb(y);g[y].psb(x);}
#define duwginp(g,m) F(i,m){cin>>x>>y; g[x].psb(y);}
#define printgraph(g,n) for(int i = 1; i <= n; i += 1){cout<< endl<<i<<": "; for(int adj:g[i]) cout << adj <<" ";} cout << endl


int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, m, x, y;
		cin >> n >> m;
		int ispair[n+1][n+1];
		memset(ispair, 0, sizeof(ispair[0][0])*(n+1)*(n+1));
		vvi graph(n+1,vi());
		int degree[n+1], final_degree[n+1];
		memset(degree, 0, sizeof(degree[0])*(n+1));
		memset(final_degree, 0, sizeof(final_degree[0])*(n+1));
		// cerr << "Initial degree: "; print(degree, n+1);
		// cerr << "Initial final_degree: "; print(final_degree, n+1);
		F(i,m){
			cin >> x >> y;
			if(ispair[x][y]) continue;
			graph[x].psb(y);
			graph[y].psb(x);
			ispair[x][y] = 1;
			ispair[y][x] = 1;
			degree[x] += 1;
			degree[y] += 1;
		}
		if(n&1){
			cout << "NO" << endl;
			continue;
		}
		set<pii> st;
		for(int i = 1; i <= n; i += 1){
			st.insert({degree[i],i});
		}
		set<pii>::iterator it, it2;
		string ans = "YES";
		// cerr << "degree: "; print(degree, 4);
		for(int i = 1; i <=n; i += 1){
			if(final_degree[i]==1)continue;
			it = st.begin();
			it2 = it;
			it2++;
			st.erase(it, it2);
			int first = (*it).second, adj;
			// cerr << "Looking for: " << first << endl;
			bool flag = false;
			for(it = st.begin(); it != st.end(); it++){
				adj = (*it).second;
				if(ispair[adj][first] and final_degree[adj] == 0){
					flag = true;
					break;
				}
			}
			if(flag == false){
				// cerr << "Couldn't find any" << endl;
				ans = "NO";
				break;
			}else{
				// cerr << "Found: " << adj << endl;
				st.erase({degree[adj],adj});
				final_degree[first] += 1;
				final_degree[adj] += 1;
				for(int ad: graph[first]){
					st.erase({degree[ad], ad});
					degree[ad] -= 1;
					st.insert({degree[ad], ad});
				}
				for(int ad: graph[adj]){
					st.erase({degree[ad], ad});
					degree[ad] -= 1;
					st.insert({degree[ad], ad});
				}
			}
		}
		for(int i = 1; i<=n; i+=1){
			if(final_degree[i]!=1){
				ans = "NO";
				break;
			}else{
				// DO nothing
			}
		}
		cout << ans << endl;
	}
	
}