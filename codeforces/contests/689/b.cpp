#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define INF 1000000000

int main(void){
	ios::sync_with_stdio(false);
	int n, temp;
	cin >> n;
	vector<vector<int> > graph(n,vector<int>());
	for(int i = 0; i < n-1; i += 1){
		graph[i].push_back(i+1);
		graph[i+1].push_back(i);
	}
	for(int i = 0; i < n; i += 1){
		cin >> temp;
		temp -= 1;
		if(temp != i+1 && temp != i-1 && temp != i){
			graph[i].push_back(temp);
		}
	}
	int dist[n];
	fill_n(dist, n, INF);
	dist[0] = 0;
	int u;
	set<pair<int, int> > s;
	s.insert(make_pair(0, 0));
	while(!s.empty()){
		u = s.begin()->second;
		s.erase(s.begin());
		for(int p : graph[u]){
			if(dist[p] > dist[u]+1){
				s.erase(make_pair(dist[p], p));
				dist[p] = dist[u]+1;
				s.insert(make_pair(dist[p], p));
			}
		}
	}
	for(int x: dist) cout << x << " ";
	cout << endl;
}