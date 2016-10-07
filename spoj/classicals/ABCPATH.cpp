#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<pii, int> piii;
typedef map<int, int> mii;
typedef deque<int> di;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<pll, ll> plll;
typedef map<ll, ll> mll;
typedef deque<ll> dl;

#define F(i, n) for(ll i = 0; i < n; i += 1)
#define PRINT(a,n) for(ll i = 0; i < n; i += 1){ cout << a[i] << " ";} cout<<endl;
#define arrinp(a,n) for(ll i = 0; i < n; i += 1) cin >> a[i];
#define init(a,n) a.find(n) != a.end()
#define Front(a) *(a.begin())
#define Back(a) *(a.rbegin())
#define Index(a, x) a.find(x) - a.begin()

const int inf = INT_MAX;

int main(void){
	ios::sync_with_stdio(false);
	int H, W;
	int Case = 1;	
	while(true){	
			cin >> H >> W;
			if(H == 0 or W == 0) break;
			char grid[H][W];
			stack<pii> Q;
			int vis[H][W];
			memset(vis, 0, sizeof(int)*(H*W));
			F(i,H){
				F(j,W){
					cin >> grid[i][j];
					if(grid[i][j] == 'A'){
						Q.push({i,j});
						vis[i][j] = 1;
					}
				}
			}
			int X[] = {0, 1, 0, -1, 1, -1, 1, -1};
			int Y[] = {1, 0, -1, 0, 1, -1, -1, 1};
			int ans = !Q.empty();

			while(!Q.empty()){
				pii cur = Q.top();
				Q.pop();
				int x = cur.first, y = cur.second;
				F(i,8){
					int newx = x+X[i];
					int newy = y+Y[i];
					if(newx >= 0 and newx < H and newy >= 0 and newy < W){
						if(grid[newx][newy] == grid[x][y]+1 and not vis[newx][newy]){
							ans = max(ans, grid[newx][newy]-'A'+1);
							Q.push({newx, newy});
							vis[newx][newy] = 1;
						}
					}
				}
				if (ans == 26) break;
			}

		cout << "Case " << Case++ << ": " << ans << endl;
	}

}

