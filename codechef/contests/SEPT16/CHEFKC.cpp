/*input
5 19 6
1 5
1 2 1
1 3 4
1 4 9
1 5 8
2 1 7
2 3 2
2 4 5
2 5 1
3 2 4
3 4 1
3 5 5
4 1 4
4 2 5
4 3 1
4 5 7
5 1 8
5 2 7
5 3 2
5 4 6
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
#define init(a, n) (a.find(n) != a.end())
#define F(i,n) for (int i = 0; i < n; i += 1)
#define inp(a,n) F(i,n) cin>>a[i]
#define print(a,n) F(i,n) {cout << a[i] << " ";} cout << endl
// graphs all will be 1 based indexed
#define uduwginp(g, m) F(i,m){cin>>x>>y;g[x].psb(y);g[y].psb(x);}
#define duwginp(g,m) F(i,m){cin>>x>>y; g[x].psb(y);}
#define printgraph(g,n) for(int i = 1; i <= n; i += 1){cout<< endl<<i<<": "; for(int adj:g[i]) cout << adj <<" ";} cout << endl

#define ll long long
#define ssi set<si>

int s, t;
int **prnt;
ssi univ;

void parset(int n){
	ssi chld;
	int temp[n];
	for (int i = 0; i < n; i += 1) temp[i] = i;
	si name;
	for (int i = 0; i < (1<<n); i += 1){
		name.clear();
		for(int j = 0; j < n; j += 1){
			if ((i & (1<<j)) > 0) name.insert(temp[j]);
		}
		chld.insert(name);
	}

	// label:
	// cout << "In the label" << endl;
	for(si x: chld){
		// for(int xi: x) cout << xi << " ";
		// cout << endl;
		if (init(x,t) or (not init(x,s) and not init(x,t))){
			continue;
		}else{
			univ.insert(x);
		}
	}

}

int main(void){
	ios::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	prnt = new int*[n];
	for (int i = 0; i < n; i += 1){
		prnt[i] = new int[n];
	}
	int x, y, z;
	cin >> s >> t;
	s--;
	t--;
	for(int i = 0; i < m; i += 1){
		cin >> x >> y >> z;
		x--; y--;
		prnt[x][y] = z;
	}
	parset(n);
	ll weight[univ.size()];
	int i, sum;
	i = 0;
	for(si j: univ){
		sum = 0;
		for (int t: j){
			for(int l = 0; l < n; l += 1){
				if (!init(j, l)){
					sum += prnt[t][l];
				}
			}
		}
		weight[i] = sum;
		i += 1;
	}
	sort(weight, weight+univ.size());
	cout << weight[k-1] << endl;
}