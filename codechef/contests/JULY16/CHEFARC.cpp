#include <iostream>
#include <utility>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

int INF = 1000000000;
int n, m, k1, k2, **a, **dist1, **dist2, **visited;
int X[] = {-1, 0, 1, 0, 1, 1, -1, -1};
int Y[] = {0, -1, 0, 1, 1, -1, 1, -1};

bool isvalid(int i, int j){
	if (i >= 0 && i < n && j >= 0 && j < m) return true;
	return false;
}

void bfs1(int k){
	// x,y is the starting cell
	dist1 = new int*[n];
	visited = new int*[n];
	for (int i = 0; i < n; i += 1){
		dist1[i] = new int[m];
		visited[i] = new int[m];
		for (int j = 0; j < m; j += 1){
			dist1[i][j] = INF;
			visited[i][j] = 0;
		}
	}
	visited[0][0] = 1;
	dist1[0][0] = 0;
	deque<pii> stack;
	stack.push_back(mp(0,0));
	while(!stack.empty()){
		pii cur = stack.front();
		stack.pop_front();
		int x = cur.first;
		int y = cur.second;
		for(int i = 0; i < 4; i += 1){
			for (int j = 1; j <= k; j += 1){

				int tempx = x+j*X[i];
				int tempy = y+j*Y[i];
				if(isvalid(tempx, tempy) && a[tempx][tempy] == 0){
					dist1[tempx][tempy] = min(dist1[tempx][tempy], dist1[x][y] + j);
					if(!visited[tempx][tempy]){
						visited[tempx][tempy] = 1;
						stack.push_back(mp(tempx, tempy));
					}
				}
			}
		}
		if(k > 1){
			for (int i = 4; i < 8; i += 1){
				for (int j = 1; j <= k/2; j += 1){
					int tempx = x+j*X[i];
					int tempy = y+j*Y[i];
					if (isvalid(tempx, tempy) && a[tempx][tempy] == 0){
						dist1[tempx][tempy] = min(dist1[tempx][tempy], dist1[x][y] + j*2);
						if(!visited[tempx][tempy]){
							visited[tempx][tempy] = 1;
							stack.push_back(mp(tempx, tempy));
						}
					}
				}
			}
		}
	}
}


void bfs2(int k){
	// x,y is the starting cell
	dist2 = new int*[n];
	visited = new int*[n];
	for (int i = 0; i < n; i += 1){
		dist2[i] = new int[m];
		visited[i] = new int[m];
		for (int j = 0; j < m; j += 1){
			dist2[i][j] = INF;
			visited[i][j] = 0;
		}
	}
	visited[0][m-1] = 1;
	dist2[0][m-1] = 0;
	deque<pii> stack;
	stack.push_back(mp(0,m-1));
	while(!stack.empty()){
		pii cur = stack.front();
		stack.pop_front();
		int x = cur.first;
		int y = cur.second;
		for(int i = 0; i < 4; i += 1){
			for (int j = 1; j <= k; j += 1){

				int tempx = x+j*X[i];
				int tempy = y+j*Y[i];
				if(isvalid(tempx, tempy) && a[tempx][tempy] == 0){
					dist2[tempx][tempy] = min(dist2[tempx][tempy], dist2[x][y] + j);
					if(!visited[tempx][tempy]){
						visited[tempx][tempy] = 1;
						stack.push_back(mp(tempx, tempy));
					}
				}
			}
		}
		if(k > 1){
			for (int i = 4; i < 8; i += 1){
				for (int j = 1; j <= k/2; j += 1){
					int tempx = x+j*X[i];
					int tempy = y+j*Y[i];
					if (isvalid(tempx, tempy) && a[tempx][tempy] == 0){
						dist2[tempx][tempy] = min(dist2[tempx][tempy], dist2[x][y] + j*2);
						if(!visited[tempx][tempy]){
							visited[tempx][tempy] = 1;
							stack.push_back(mp(tempx, tempy));
						}
					}
				}
			}
		}
	}
}


int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> k1 >> k2;
		a = new int*[n];
		for (int i = 0; i < n; i += 1){
			a[i] = new int[m];
			for (int j = 0; j < m; j += 1){
				cin >> a[i][j];
			}
		}
		bfs1(k1);
		bfs2(k2);
		int minmoves = INF;
		for (int i = 0; i < n; i += 1){
			for (int j = 0; j < m; j += 1){
				if(a[i][j] == 0){
					int d1 = dist1[i][j];
					int d2 = dist2[i][j];
					int moves = (int)max(ceil((float)d1/(float)k1), ceil((float)d2/(float)k2));
					minmoves = min(minmoves, moves);
				}
			}
		}
		cout << (minmoves == INF ? -1 : minmoves) << endl;
	}
}

// 4 5 2 2
// 0 1 1 0 0 
// 0 1 1 0 0
// 0 1 1 1 1
// 0 0 0 0 0