#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

const int INF = 1000000000;

int main(void){
	int n;
	cin >> n;
	int x[n][2], y[n][2];
	for (int i = 0; i < n; i += 1){
		cin >> x[i][0] >> x[i][1];
	}
	for (int i = 0; i < n; i += 1){
		cin >> y[i][0] >> y[i][1];
	}
	// int visited[n]={0};
	vector<int> visited(n, 0);
	int ans = 0;
	for (int i =0; i < n; i += 1){
		int mindist = INF;
		int mini = 0;
		for (int j = 0; j < n; j += 1){
			if(!visited[j]){
				int dist = abs(x[i][0]-y[i][0]) + abs(x[i][1]-y[i][1]);
				if(dist < mindist){
					mindist = dist;
					mini = j;
				}
			}
		}
		visited[mini] = 1;
		ans += mindist;
	}
	cout << ans << endl;
}