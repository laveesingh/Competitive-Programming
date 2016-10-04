#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define piii pair<pii, int>
#define inf INT_MAX
int X[] = {-1, 0, 1, 0};
int Y[] = {0, 1, 0, -1};

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		int M[n][m];
		queue<piii> st;
		
		int a[n][m];
		for(int i = 0; i < n; i += 1){
			for(int j = 0; j < m; j += 1){
				a[i][j] = inf;
			}
		}
		for(int i = 0; i < n; i += 1){
			string temp;
			cin >> temp;

			for(int j = 0; j < m; j += 1){
				M[i][j] = temp[j]-'0';

				if(M[i][j] == 1){
					a[i][j] = 0;
					st.push({{i,j}, 0});
				}

		    }
		}
		
		while(!st.empty()){
//			cout << "Stuck" << endl;
			piii cur = st.front();
			st.pop();
			int w = cur.second;
			int x = cur.first.first;
			int y = cur.first.second;
			for(int i = 0; i < 4; i += 1){
				int nx = x+X[i];
				int ny = y+Y[i];
				if(nx < n and nx >= 0 and ny < m and ny >= 0){
					if(a[nx][ny] > w+1){
						a[nx][ny] = w+1;
						st.push({{nx,ny},w+1});
					}
				}
			}
		}
		for(int i = 0; i < n; i += 1){
			for(int j = 0; j < m; j += 1){
				cout << a[i][j] << " " ;
			}
			cout << endl;
		}
	}
}
