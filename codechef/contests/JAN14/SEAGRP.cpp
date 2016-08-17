/*input
3
2 2
1 2
1 2
3 2
1 2
2 3
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/

#include <bits/stdc++.h>

using namespace std;

map<int, set<int>> graph;
int n, m, x, y;
map<int, int> visited;
bool isOddCycle = 0;

int flip(int a){
	if (a == 1) return 2;
	return 1;
}

void dfs(int node, int parent){
	cout << "DFSing for " << node << endl;
	visited[node] = flip(visited[parent]);
	for (int adj: graph[node]){
		if (visited[adj] == visited[node]){
			isOddCycle = 1;
			return;
		}else if(!visited[adj]){
			dfs(adj, node);
		}
	}
}


int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		graph.clear();
		visited.clear();
		isOddCycle = 0;
		for (int i = 0; i < m; i += 1){
			cin >> x >> y;
			graph[x].insert(y);
			graph[y].insert(x);
		}
		visited[0] = 2;
		dfs(1, 0);
		cout << "After dfs visited says " << endl;
		for (int i = 0; i <= n; i += 1){
			cout << i << ": " << visited[i] << endl;
		}
		if (isOddCycle){
			cout << "NO" << endl;
		}else{
			cout << "YES" << endl;
		}
	}	
}