#include <cstdio>
#include <set>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node{
	int n;
	set<int> adjacents;
	Node(){}
};

set<int> graph[200001];
int deactivated[200001];

bool connected(int x, int y){
	if(deactivated[x] || deactivated[y]) return false;
	if(graph[x].find(y) != graph[x].end()) {
		cout << x << " and " << y << " are directly connected" << endl;
		return true;
	}
	for (set<int>::iterator it = graph[x].begin(); it != graph[x].end(); it++){
		if(!deactivated[*it]){
			if(graph[*it].find(y) != graph[*it].end()) return true;
		}
	}
	return false;
}

int main(void){
	int N, E,x,y;
	scanf("%d %d", &N, &E);
	int G[N];
	int n = N;
	for (int i = 0; i < n; i += 1){
		scanf("%d", &G[i]);
	}
	for (int i = 0; i < E; i += 1){
		scanf("%d %d", &x, &y);
		graph[x].insert(y);
		graph[y].insert(x);
	}
	map<int, vector<int> > favteam;
	for (int i = 0; i < n; i += 1){
		favteam[G[i]].push_back(i+1);
	}
	cout << "Starting deactivation process; " << endl;
	for (int i = 1; i <= n; i += 1){
		deactivated[i] = 1;
		int sadpairs = 0;
		for(map<int,vector<int>>::iterator it = favteam.begin(); it != favteam.end(); it++){
			vector<int> curvect = it->second;
			for (int j = 0; j < curvect.size()-1; j += 1){
				for (int k = j+1; k < curvect.size(); k += 1){
					cout << "Checking for : " << curvect[j] << " and " << curvect[k] << " ";
					if(!connected(curvect[j], curvect[k])) {
						cout << "Found connected" << endl;
						sadpairs += 1;
					}else{
						cout << "Found disconnected" << endl;
					}
				}
			}
		}
		// cout << sadpairs << endl;
		printf("%d\n", sadpairs);

		deactivated[i] = 0;
	}
}