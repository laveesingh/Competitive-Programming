#include <iostream>
#include <algorithm>
#include <map>


using namespace std;

class edge{
public:
	int n1,n2;
	long long w;
	edge(){}
	edge(int a, int b, long long c){
		n1 = a;
		n2 = b;
		w = c;
	}
};

bool comp(edge e1, edge e2){
	if (e1.w == e2.w){
		return e1.w+e1.n1+e1.n2 < e2.w+e2.n1+e2.n2 ? true : false;
	}
	return e1.w < e2.w ? true : false;
}

map<int, int> d;

int find(int i){
	if (d[i] == -1) return i;
	return find(d[i]);
}

int Union(int x, int y){
	int xroot = find(x);
	int yroot = find(y);
	d[xroot] = yroot;
}

int main(void){
	int n, m, x, y;
	long long z;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i += 1){
		d[i] = -1;
	}
	edge graph[m];
	for (int i = 0; i < m; i += 1){
		cin >> x >> y >> z;
		graph[i] = edge(x, y, z);
	}
	sort(graph, graph+m, comp);
	// for (int i = 0; i < m; i += 1){
	// 	cout << graph[i].n1 << " " << graph[i].n2 << " " << graph[i].w << endl;
	// }
	int ans = 0;
	for (int i = 0; i < m; i += 1){
		x = graph[i].n1;
		y = graph[i].n2;
		z = graph[i].w;
		if (find(x) == find(y)){
			// Do nothing, we're supposed to ignore these edges.
		}else{
			ans += z;
			Union(x,y);
		}
	}
	cout << ans << endl;


}