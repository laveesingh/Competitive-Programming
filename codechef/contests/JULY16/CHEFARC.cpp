#include <iostream>
#include <utility>
#include <cmath>
#include <deque>
#include <algorithm>
#include <set>

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


// void dijkstra1(pii src, int k){
// 	// cout << "Entering dijkstra1" << endl;
// 	dist1 = new int*[n];
// 	for (int i = 0; i < n; i += 1) {
// 		dist1[i] = new int[m];
// 		for(int j = 0; j < m; j += 1){
// 			dist1[i][j] = INF;
// 		}
// 	}
// 	dist1[src.first][src.second] = 0;
// 	set<pii> notinc;
// 	for(int i = 0; i < n; i += 1){
// 		for(int j = 0; j < m; j += 1){
// 			if(a[i][j] == 0){
// 				notinc.insert(mp(i, j));
// 			} else {
// 				// let it go
// 			}
// 		}
// 	}
// 	while(!notinc.empty()){
// 		pii cur;
// 		int x, y;
// 		int mindist1 = INF;
// 		for(set<pii>::iterator it = notinc.begin(); it != notinc.end(); it++){
// 			x = (*it).first, y = (*it).second;
// 			if(dist1[x][y] < mindist1){
// 				mindist1 = dist1[x][y];
// 				cur = *it;
// 			}
// 		}
// 		if(mindist1 == INF) break;
// 		notinc.erase(cur);
// 		x = cur.first;
// 		y = cur.second;
// 		// cout << "x " << x << " y " << y << " notinc size " << notinc.size() << "mindist: " << mindist1<< endl;
// 		for (int i = 0; i < 4; i += 1){
// 			for (int j = 1; j <= k; j += 1){
// 				int tx = x + X[i]*j, ty = y + Y[i]*j;
// 				if(isvalid(tx, ty) && a[tx][ty] == 0){
// 					dist1[tx][ty] = min(dist1[tx][ty], dist1[x][y]+1);
// 				}
// 			}
// 		}
// 		for (int i = 4; i < 8; i += 1){
// 			for (int j = 1; j <= k; j += 1){
// 				for(int l = 1; l+j <= k; l += 1){
// 					int tx = x + X[i]*j, ty = y + Y[i]*l;
// 					if(isvalid(tx, ty) && a[tx][ty] == 0){
// 						dist1[tx][ty] = min(dist1[tx][ty], dist1[x][y]+1);
// 					}
// 				}
// 			}
// 		}
// 	}
// }

void dijkstra1(int k){
	dist1 = new int*[n];
	for(int i = 0; i < n; i += 1){
		dist1[i] = new int[m];
		for(int j = 0; j < m; j += 1){
			dist1[i][j] = INF;
		}
	}
	dist1[0][0] = 0;
	pii cur = mp(0,0);
	set< pair<int, pii> > todo;
	todo.insert(mp(0, cur));
	while(!todo.empty()){
		cur = todo.begin()->second;
		int x = cur.first;
		int y = cur.second;
		todo.erase(todo.begin());
		for(int i = 0; i < 4; i += 1){
			for (int j = 1; j <= k; j += 1){
				int tx = x + X[i]*j, ty = y + Y[i]*j;
				if(isvalid(tx, ty) && a[tx][ty] == 0){
					if(dist1[tx][ty] > dist1[x][y]+1){
						todo.erase(mp(dist1[tx][ty], mp(tx, ty)));
						dist1[tx][ty] = dist1[x][y] + 1;
						todo.insert(mp(dist1[tx][ty], mp(tx, ty)));
					}
				}
			}
		}
		for(int i = 4; i < 8; i += 1){
			for(int j = 1; j <= k; j += 1){
				for (int l = 1; l+j <= k; l += 1){
					int tx = x + X[i]*j, ty = y + Y[i]*l;
					if(isvalid(tx, ty) && a[tx][ty] == 0){
						if(dist1[tx][ty] > dist1[x][y]+1){
							todo.erase(mp(dist1[tx][ty], mp(tx, ty)));
							dist1[tx][ty] = dist1[x][y] + 1;
							todo.insert(mp(dist1[tx][ty], mp(tx, ty)));
						}
					}
				}
			}
		}
	}
}

// void dijkstra2(pii src, int k){
// 	dist2 = new int*[n];
// 	for (int i = 0; i < n; i += 1){
// 		dist2[i] = new int[m];
// 		for(int j = 0; j < m; j += 1){
// 			dist2[i][j] = INF;
// 		}
// 	}
// 	dist2[src.first][src.second] = 0;
// 	set<pii> notinc;
// 	for(int i = 0; i < n; i += 1){
// 		for(int j = 0; j < m; j += 1){
// 			if(a[i][j] == 0){
// 				notinc.insert(mp(i, j));
// 			} else {
// 				// let it go
// 			}
// 		}
// 	}
// 	while(!notinc.empty()){
// 		pii cur;
// 		int x, y;
// 		int mindist2 = INF;
// 		for(set<pii>::iterator it = notinc.begin(); it != notinc.end(); it++){
// 			x = (*it).first, y = (*it).second;
// 			if(dist2[x][y] < mindist2){
// 				mindist2 = dist2[x][y];
// 				cur = *it;
// 			}
// 		}
// 		if(mindist2 == INF) break;
// 		notinc.erase(cur);
// 		x = cur.first;
// 		y = cur.second;
// 		for (int i = 0; i < 4; i += 1){
// 			for (int j = 1; j <= k; j += 1){
// 				int tx = x + X[i]*j, ty = y + Y[i]*j;
// 				if(isvalid(tx, ty) && a[tx][ty] == 0){
// 					dist2[tx][ty] = min(dist2[tx][ty], dist2[x][y]+1);
// 				}
// 			}
// 		}
// 		for (int i = 4; i < 8; i += 1){
// 			for (int j = 1; j <= k; j += 1){
// 				for(int l= 1; l+j <= k; l += 1){
// 					int tx = x + X[i]*j, ty = y + Y[i]*l;
// 					if(isvalid(tx, ty) && a[tx][ty] == 0){
// 						dist2[tx][ty] = min(dist2[tx][ty], dist2[x][y]+1);
// 					}
// 				}
// 			}
// 		}
// 	}
// }

void dijkstra2(int k){
	dist2 = new int*[n];
	for(int i = 0; i < n; i += 1){
		dist2[i] = new int[m];
		for(int j = 0; j < m; j += 1){
			dist2[i][j] = INF;
		}
	}
	dist2[0][m-1] = 0;
	pii cur = mp(0,m-1);
	set< pair<int, pii> > todo;
	todo.insert(mp(0, cur));
	while(!todo.empty()){
		cur = todo.begin()->second;
		int x = cur.first;
		int y = cur.second;
		todo.erase(todo.begin());
		for(int i = 0; i < 4; i += 1){
			for (int j = 1; j <= k; j += 1){
				int tx = x + X[i]*j, ty = y + Y[i]*j;
				if(isvalid(tx, ty) && a[tx][ty] == 0){
					if(dist2[tx][ty] > dist2[x][y]+1){
						todo.erase(mp(dist2[tx][ty], mp(tx, ty)));
						dist2[tx][ty] = dist2[x][y] + 1;
						todo.insert(mp(dist2[tx][ty], mp(tx, ty)));
					}
				}
			}
		}
		for(int i = 4; i < 8; i += 1){
			for(int j = 1; j <= k; j += 1){
				for (int l = 1; l+j <= k; l += 1){
					int tx = x + X[i]*j, ty = y + Y[i]*l;
					if(isvalid(tx, ty) && a[tx][ty] == 0){
						if(dist2[tx][ty] > dist2[x][y]+1){
							todo.erase(mp(dist2[tx][ty], mp(tx, ty)));
							dist2[tx][ty] = dist2[x][y] + 1;
							todo.insert(mp(dist2[tx][ty], mp(tx, ty)));
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
		dijkstra1(k1);
		// cout << "Dist1: " << endl;
		// for (int i = 0; i < n; i += 1){
		// 	for (int j = 0; j < m; j += 1){
		// 		cout << (dist1[i][j] == INF ? "~" : to_string(dist1[i][j])) << " ";
		// 	}
		// 	cout << endl;
		// }
		dijkstra2(k2);
		// cout << "Dist2: " << endl;
		// for (int i = 0; i < n; i += 1){
		// 	for (int j = 0; j < m; j += 1){
		// 		cout << (dist2[i][j] == INF ? "~" : to_string(dist2[i][j])) << " ";
		// 	}
		// 	cout << endl;
		// }
		int minmoves = INF;
		for (int i = 0; i < n; i += 1){
			for (int j = 0; j < m; j += 1){
				if(a[i][j] == 0){
					int d1 = dist1[i][j];
					int d2 = dist2[i][j];
					// int moves = (int)max(ceil((float)d1/(float)k1), ceil((float)d2/(float)k2));
					int moves = max(d1, d2);
					minmoves = min(minmoves, moves);
				}
			}
		}
		cout << (minmoves == INF ? -1 : minmoves) << endl;
	}
}

// 6 6 2 3
// 0 0 1 1 0 0
// 0 1 0 1 1 0
// 1 1 1 1 0 1
// 0 0 0 0 0 0
// 0 0 0 0 0 0
// 0 0 0 0 0 0
