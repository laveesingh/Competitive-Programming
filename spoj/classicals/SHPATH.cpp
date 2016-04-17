#include <queue>
#include <cstdio>
#include <functional>
#include <map>
#include <vector>
#include <utility>

using namespace std;

#define pii pair<int, int>
#define psi pair<string, int>
#define INF 2000001
#define MAX 10001

vector<pii> graph[MAX];
int dist[MAX];
int visited[MAX];

map<string, int> names;

vector<pii> edges;

void minDist(int n, int start, int end){
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));
	for (int i = 1; i <= n; i += 1){
		dist[i] = INF;
		visited[i] = 0;
	}
	dist[start] = 0;
	while (!pq.empty()){
		// int wi = pq.top().first;
		int ui = pq.top().second;
		pq.pop();
		if (visited[ui]) continue;
		int size = graph[ui].size();
		for (int j = 0; j < size; j += 1){
			int edge = graph[ui][j].second;
			int weight = graph[ui][j].first;
			if(!visited[edge] && dist[ui]+weight < dist[edge]){
				dist[edge] = dist[ui]+weight;
				pq.push(pii(dist[edge], edge));
			}
		}
		visited[ui] = 1;
		if (ui == end) break;
	}
	printf("%d\n", dist[end]);
}

int main(void){
	int t, n, non, v, w, q;
	char city[11];
	scanf("%d",&t);
	while(t--){
		scanf("%d", &n);
		for (int i = 1; i <= n; i += 1){
			scanf("%s %d", city, &non);
			names[city] = i;
			for (int j = 1; j <= non; j += 1){
				scanf("%d %d", &v, &w);
				graph[i].push_back(pii(w, v));
			}
		}
		scanf("%d", &q);
		for (int i = 0; i < q; i += 1){
			scanf("%s",city);
			int start = names[city];
			scanf("%s", city);
			int end = names[city];
			minDist(n, start, end);
		}
		for (int i= 1; i <= n; i += 1) graph[i].clear();
		names.clear();
	}
}