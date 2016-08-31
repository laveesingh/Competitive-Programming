/*input
 2
 2
 5
 7
 1 2 1
 2 3 2
 2 4 6
 5 2 1
 5 1 3
 4 5 2
 3 4 3
 1
 9
 13
 1 2 4
 2 3 8
 3 4 7
 4 5 9
 5 6 10
 4 6 14
 6 7 2
 7 8 1
 8 9 7
 3 9 2
 3 6 4
 7 9 6
 2 8 11
 1 8 8
*/

#include <bits/stdc++.h>

using namespace std;

class edge{
public:
	int n1, n2, w;
	edge(){}
	edge(int a, int b, int c){
		n1 = a;
		n2 = b;
		w = c;
	}
	friend bool operator<(edge a, edge b);
};

bool operator<(edge a, edge b){
	return a.w < b.w;
}

edge *graph;
int *parent, p, n, m;

int find(int i){
	// cout << "Finding parent of " << i << endl;
	if (parent[i] == -1) return i;
	return find(parent[i]);
}

void Union(int i, int j){
	int x = find(i);
	int y = find(j);
	if (x < y){
		parent[y] = x;
		// cout << "Updated parent["<< y << "]: " << parent[y] << endl;
	}else{
		parent[x] = y;
		// cout << "Updated paernt[" << x << "]: " << parent[x] << endl;
	}
}

void print(int a[], int n){
	for (int i = 0; i < n; i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(void){
	ios::sync_with_stdio(false);
	int t, x, y, z;
	cin >> t;
	while(t--){
		cin >> p >> n >> m;
		graph = new edge[m];
		parent = new int[n];
		fill_n(parent, n+1, -1);
		for (int i = 0; i < m; i += 1){
			cin >> x >> y >> z;
			graph[i] = edge(x, y, z);
		}
		sort(graph, graph+m);
		int count = 0, ans = 0;
		for (int i = 0; i < m; i += 1){
			// cout << "Parent: "; print(parent, n+1);
			edge e = graph[i];
			if (count == n-1) break;
			if (find(e.n1) != find(e.n2)){
				// cout << "Including " << e.n1 << ", " << e.n2 << endl;
				count += 1;
				ans += e.w;
				Union(e.n1, e.n2);
			}
		}
		cout << (ans*p) << endl;
	}
}