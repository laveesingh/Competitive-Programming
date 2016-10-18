#include <bits/stdc++.h>
using namespace std;
const int inf = INT_MAX;
int chess[8][8];
int X[] = {1, 1, -1, -1, 2, 2, -2, -2};
int Y[] = {2, -2, 2, -2, 1, -1, 1, -1};
bool valid(int i, int j){
	if(i < 0 or i >= 8) return false;
	if(j < 0 or j >= 8) return false;
	return true;
}

int solve(int x, int y, int tx, int ty){
	F(i,8){
		F(j,8){
			chess[i][j] = inf;
		}
	}
	chess[x][y] = 0;
	deque<pii> q;
	q.push_back({x,y});
	int newx, newy;
	while(!q.empty()){
		pii cur = q.front();
		q.pop_front();
		F(i,8){
			newx = cur.first+X[i];
			newy = cur.second+Y[i];
			if(valid(newx, newy) and chess[newx][newy] > chess[cur.first][cur.second]+1){
				chess[newx][newy] = chess[cur.first][cur.second]+1;
				q.push_back({newx,newy});
			}
		}
	}
	return chess[tx][ty];				
}

pii mapper(string a){
	int f = a[0]-'a';
	int s = a[1]-'1';
	return {f,s};
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	string a, b;
	cin >> t;
	while(t--){
		cin >> a >> b;
		pii pa = mapper(a);
		pii pb = mapper(b);
		cout << solve(pa.first, pa.second, pb.first, pb.second) << endl;
	}
}

