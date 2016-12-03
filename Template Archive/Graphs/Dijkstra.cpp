#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)
#define mp make_pair

const int N = 1e5 + 1;
const int inf = 1e9 + 7;
vector<pair<int, int> > graph[N];
int dist[N];

int main(void){
	int t, n, m, st, en, x, y, z;
	iint(t);
	while(t--){
		iint(n);iint(m);iint(st);iint(en);
		for(int i = 1; i <= n; i++) graph[i].clear();
		set<pair<int, int> > s;
		for(int i = 0; i < m; i += 1){
			scanf("%d %d %d", &x, &y, &z);
			graph[x].push_back(mp(y, z));
			graph[y].push_back(mp(x, z));
		}
		//cerr << "Graph is created" << endl;
		fill_n(dist, (n+1), inf);
		//cerr << "Dist filled with inf" << endl;
		dist[st] = 0;
		//cerr << "Initialized dist source to 0" << endl;
		s.insert(mp(dist[st], st));
		//cerr << "Entering the while loop " << endl;
		while(!s.empty()){
			int u = s.begin() -> second;
			s.erase(s.begin());
			//cerr << "Considering " << u << endl;
			for(auto p: graph[u]){
				if(dist[p.first] > dist[u]+p.second){
					s.erase({dist[p.first], p.first});
					dist[p.first] = dist[u] + p.second;
					s.insert({dist[p.first], p.first});
				}
			}
		}
		//cerr << "Done dijkstra" << endl;
		if(dist[en] == inf){
			ostr("NONE");
		}else{
			oint(dist[en]);
		}
	}
}

