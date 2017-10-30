#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> d;

class edge{
public:
	int node1, node2, weight;
	edge(){}
	edge(int n1, int n2, int w){
		node1 = n1;
		node2 = n2;
		weight = w;
	}
};

int find(int i){
	if(d[i]==-1)return i;
	return find(d[i]);
}


void Union(int x, int y){
	int xroot = find(x);
	int yroot = find(y);
	d[xroot] = yroot;
}

bool comp(edge e1, edge e2){
	if (e1.weight == e2.weight){
		return e1.node1+e1.node2+e1.weight < e2.node1+e2.node2+e2.weight ? true : false;
	}
	return e1.weight < e2.weight ? true : false;
}

int main(void){
	int m, n, n1, n2, w,start;
	cin >> n >> m;
	for (int i = 1; i <= n; i += 1) d[i] = -1;
	edge graph[m];
	for (int i = 0; i < m; i += 1){
		cin >> n1 >> n2 >> w;
		graph[i] = edge(n1, n2, w);
	}
	cin >> start;

	sort(graph, graph+m, comp);

	int ans = 0;
	for (edge e: graph){
		if (find(e.node1) == find(e.node2)){
			// Nothing to be done in that case. we just ignore the current edge
		}
		else{
			Union(e.node1, e.node2);
			ans += e.weight;
		}
	}
	cout << ans << endl;
}