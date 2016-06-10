#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define all(c) c.begin(), c.end()



int dfs(int i, const vii &graph, vi &visited){ // i is already visited
	vector<int> temp;
	// cout << "dfs for " << i << " ";
	for(int s : graph[i]){
		// cout << "checking " << s << " => " << visited[s] ;
		if(!visited[s]){
			visited[s] = visited[i]%2 + 1;
			// cout << " painted " << s << " ";
			temp.push_back(dfs(s, graph, visited));
		}else{
			if (visited[s] == visited[i]) return 0;
		}
	}
	// cout << endl;
	return find(all(temp), 0) == temp.end();
}

void Print(vector<int> a){
	for(int i = 0; i < a.size(); i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

void Print(vii b){
	for (int i = 0; i < b.size(); i += 1){
		Print(b[i]);
	}
}

int main(void){

	int t;
	// cin >> t;
	scanf("%d", &t);
	for (int j = 1; j <= t; j += 1){
		// cout << "Scenario #" << j << ":" << endl;
		printf("Scenario #%d:\n", j);
		int n, m, tempx, tempy;
		// cin >> n >> m;
		scanf("%d %d", &n, &m);
		vi visited(n, 0);
		vii graph(n, vector<int>(0,0));
		for(int i = 0; i < m; i += 1){
			// cin >> tempx >> tempy;
			scanf("%d %d", &tempx, &tempy);
			tempx--;
			tempy--;
			graph[tempx].push_back(tempy);
			graph[tempy].push_back(tempx);
		}
		// cout << "Done creating graph, now entering the loop" << endl;
		vi::iterator it = visited.begin();
		bool done = false;
		// cout << "The graph is " << endl;
		// Print(graph);

		do{
			// cout << "DFS for " << (it-visited.begin()) << endl;
			visited[it-visited.begin()] = 1;
			if (!dfs((it-visited.begin()), graph, visited)){
				// cout << "Suspicious bugs found!" << endl;
				printf("Suspicious bugs found!\n");
				done = true;
				break;
			}else{
				it = find(all(visited), 0);
			}
			// cout << "After bfs visited: "; Print(visited);
		}while(it != visited.end());
		if (done == false){
			// cout << "No suspicious bugs found!" << endl;
			printf("No suspicious bugs found!\n");
		}
	}

}