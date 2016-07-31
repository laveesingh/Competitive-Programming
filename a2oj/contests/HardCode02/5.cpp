#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define pii pair<int, int>
#define mp make_pair

int main(void){
	ios::sync_with_stdio(false);

	int n, par;
	cin >> n;
	vvi graph(n, vi());
	set<pii> uset; // pair(node, depth)
	int ans = 0;
	for(int i = 0; i < n; i += 1){
		cin >> par;
		if (par == -1){
			uset.insert({i, 1	});
		} else {
			graph[par-1].pb(i);
		}
	}
	vi visited(n+1, 0);
	while(!uset.empty()){
		pii cur = *uset.begin();
		uset.erase(uset.begin());
		deque<pii> stack;
		stack.pb(cur);
		visited[cur.first] = 1;
		while(!stack.empty()){
			cur = stack.back();
			stack.pop_back();
			ans = max(ans, cur.second);
			for(int node: graph[cur.first]){
				if(!visited[node]){
					visited[node] = 1;
					stack.pb({node, cur.second+1});
				}
			}
		}
	}
	cout << ans << endl;
}