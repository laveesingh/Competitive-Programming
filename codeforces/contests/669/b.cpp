#include <iostream>

using namespace std;

string solve(int dist[], string steps){
	int limit = 0;
	int n = steps.length();
	int visited[n] = {0};
	int curi = 0;
	// int total = 0;
	while (1){
		if (visited[curi]){
			return "INFINITE";
		}
		if (steps[curi] == '>'){
			visited[curi] = 1;
			curi += dist[curi];
			if (curi > n-1) return "FINITE";
		}else{
			visited[curi] = 1;
			curi -= dist[curi];
			if (curi < 0) return "FINITE";
		}
	}
	return "INFINITE";
}

int main(){
	int n;
	string steps;
	cin >> n;
	cin >> steps;
	int dist[n];
	for (int i = 0; i < n; i += 1){
		cin >> dist[i];
	}
	cout << solve(dist, steps) << endl;
}