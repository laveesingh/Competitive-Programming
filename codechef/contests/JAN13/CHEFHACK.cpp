#include <bits/stdc++.h>

using namespace std;

const int limit = 10000001;
int isprime[limit];
int dpprime[limit];
int **a, **visited, **cost, n;
int X[] = {1, 0, -1, 0};
int Y[] = {0, 1, 0, -1};

#define pii pair<int, int>
#define F(i,n) for(int i = 0; i < n; i += 1)
#define even(n)  (!isprime[n] && n%2 == 0)
#define odd(n)  (!isprime[n] && !even(n))
#define ustries(n) (isprime[n] ? dpprime[n]-1 : (even(n) ? n/2 : (n+3)/2))
#define isvalid(i,j) (i >= 0 and i < n and j >= 0 and j < n)

void sieve(){
	fill_n(isprime, limit, 1);
	isprime[0] = isprime[1] = 0;
	for (int i = 4; i < limit; i += 2){
		isprime[i] = 0;
	}
	for (int i = 3; i < sqrt(limit)+1; i += 2){
		if (isprime[i]){
			for(int j = i*i; j < limit; j += 2*i){
				isprime[j] = 0;
			}
		}
	}
	dpprime[0]=dpprime[1] = 0;
	for (int i = 2; i < limit; i += 1){
		dpprime[i] = isprime[i] ? dpprime[i-1]+1 : dpprime[i-1];
	}
}

void dfs(int i, int j){
	if(isprime[a[i][j]]) return;
	deque<pii> stack;
	stack.push_back({i,j});
	while(!stack.empty()){
		pii cur = stack.back();
		stack.pop_back();
		int x = cur.first, y = cur.second, nx, ny;
		for(int I = 0; I < 4; I += 1){
			nx = x+X[I];
			ny = y+Y[I];
			if(isvalid(nx, ny) and !isprime[a[nx][ny]] and a[nx][ny]%2 == a[x][y]%2 and !visited[nx][ny]){
				visited[nx][ny] = 1;
				stack.push_back({nx, ny});
			}
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	sieve();
	int t;
	cin >> t;
	while(t--){
		// cout << "Initial values of isprime and dpprime are as follows: " << endl;
		// for (int i = 0; i < 20; i += 1){
		// 	if (isprime[i]) cout << i << " ";
		// 	else cout << "  ";
		// }
		// cout << endl;
		// for (int i = 0; i < 20; i += 1){
		// 	cout << dpprime[i] << " ";
		// }
		// cout << endl;
		cin >> n;
		a = new int*[n];
		visited = new int*[n];
		cost = new int*[n];
		F(i,n) {
			a[i] = new int[n];
			visited[i] = new int[n];
			cost[i] = new int[n];
			// F(j,n) visited[i][j] = 0;
			fill_n(visited[i], n, 0);
			// F(j,n) cost[i][j] = 0;
			fill_n(cost[i], n, 0);
		}
		F(i,n) F(j,n) cin >> a[i][j];
		// cout << "Initial matrices are " << endl;
		// F(i,n){
		// 	F(j,n){
		// 		cout << a[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// F(i,n){
		// 	F(j,n){
		// 		cout << visited[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// F(i,n){
		// 	F(j,n){
		// 		cout << cost[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		long long ans = 0;
		F(i,n){
			F(j,n){
				if(!visited[i][j]){
					visited[i][j] = 1;
					cost[i][j] = ustries(a[i][j]);
					dfs(i,j);
				}
			}
		}
		// cout << "Here's the cost matrix" << endl;
		F(i,n){
			F(j,n){
				// cout << cost[i][j] << " ";
				ans += cost[i][j];
			}
			// cout << endl;
		}
		cout << ans << endl;
	}
}