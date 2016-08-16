/*input
7
1 0 1 0 0 0 0
0 0 0 0 0 0 0
0 0 1 0 0 0 0
0 0 0 0 0 0 0
0 1 0 0 0 0 0
0 0 1 0 0 0 1
0 0 0 0 1 0 1
7
5 1
78 5
42 5
46 1
91 6
48 4
16 6
*/


#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define vi vector<int>
#define pvi pair<vi, int>
#define pb push_back
#define si set<int>
#define vsi vector<si>
#define isin(a, n) a.find(n) != a.end()


map<pvi, int> store;
map<int, vi> graph;
int n, m;
map<int, int> intervals;


set<int> solve(int k, int x){
	map<si, int> phase;
	map<int, si> revphase;
	si hm;
	hm.insert(x);
	phase[hm] = 0;
	revphase[0] = hm;
	for (int i = 1; i < k+1; i += 1){
		si nhm;
		for (int s: hm){ // change it to standard iterator
			for (int adj: graph[s]){
				nhm.insert(adj);
			}
		}
		hm = set<int>(nhm.begin(), nhm.end());
		if (isin(phase, hm)){
			int j = phase[hm];
			int interval = i-j;
			int ind = (k-j)%interval;
			return revphase[ind+j];
		}
		phase[hm] = i;
		revphase[i] = hm;
	}
	return hm;
}

int main(void){
	ios::sync_with_stdio(false);
	cin >> n;
	int temp;
	for (int i = 0; i < n; i+= 1){
		for (int j = 0; j < n; j += 1){
			cin >> temp;
			if (temp == 1){
				graph[i].pb(j);
			}
		}
	}
	cin >> m;
	int k, x;
	for (int _ = 0; _ < n; _ += 1){
		cin >> k >> x;
		x -= 1;
		si ans = solve(k,x);
		cout << ans.size() << endl;
		if (ans.size() == 0){
			cout << -1 << endl;
		}else{
			for (int s: ans){
				cout << s+1 << " ";
			}
			cout << endl;
		}

	}

}