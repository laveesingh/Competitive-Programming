#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <utility>


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

int* d;
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
	int t,n, neighbors, x, y;
	long long z, ans;
	string name;
	char* Name;
	scanf("%d",&t);
	for (int testcase=1; testcase <= t; testcase += 1){
		scanf("%d",&n);
		d = new int[n+1];
		for (int i = 1; i <= n; i += 1){
			d[i] = -1;
		}
		map<pair<int, int>, int> istaken;
		vector<edge> graph;
		for (int city=1; city <= n; city += 1){
			scanf("%*s %d",&neighbors);
			for (int non=0; non < neighbors; non += 1){
				scanf("%d %lld", &y, &z);
				if (istaken[make_pair(y,city)] && istaken[make_pair(city,y)]){
					// we're taking the reverse of already included edge
				}else{
					graph.push_back(edge(city, y, z));
					istaken[make_pair(city, y)] = 1;
					istaken[make_pair(y, city)] = 1;
				}
			}
		}
		sort(graph.begin(), graph.end(), comp);
		// for (int i = 0; i < graph.size(); i +=1){
		// 	cout << graph[i].n1 << " " << graph[i].n2 << " " << graph[i].w << endl;
		// }
		ans = 0;
		for(int i = 0; i < graph.size(); i += 1){
			x = graph[i].n1;
			y = graph[i].n2;
			z = graph[i].w;
			if (find(x) == find(y)){
				// Do nothing, we're supposed to ignore these two edges.
			}else{
				ans += z;
				Union(x, y);
			}
		}
		printf("%lld\n",ans);
	}

}

