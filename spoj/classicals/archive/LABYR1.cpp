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
	int t;
	cin >> t;
	while(t--){
		int R, C;
		cin >> C >> R;
		char LAB[R][C];
		int dist[R][C];
		int sti = 0, stj = 0;
		F(i,R){
			F(j,C){
				cin >> LAB[i][j];
				if (LAB[i][j] == '#'){
					dist[i][j] = -1;
				}else{
					dist[i][j] = 0;
					sti = i;
					stj = j;
				}
			}
		}
		queue<pii> Q;
		Q.push({sti, stj});
		int X[] = {1, 0, -1, 0};
		int Y[] = {0, 1, 0, -1};
		int vis[R][C];
		memset(vis, 0, sizeof(int)*(R*C));
		dist[sti][stj] = 0;
		vis[sti][stj] = 1;
		#ifdef DEBUG
			cerr << "First starting point is " << sti << "," << stj << endl;
		#endif
		while(!Q.empty()){
			pii cur = Q.front();
			Q.pop();
			for(int i = 0;i < 4; i += 1){
				int newi = cur.first + X[i];
				int newj = cur.second + Y[i];
				if (newi >= 0 and newj >= 0 and newi < R and newj < C){
					if(not (vis[newi][newj]) and LAB[newi][newj] == '.'){
						dist[newi][newj] = dist[cur.first][cur.second]+1;
						#ifdef DEBUG
							cout << dist[cur.first][cur.second] << "=>" << dist[newi][newj] << endl;
						#endif
						Q.push({newi, newj});
						vis[newi][newj] = 1;
					}
				}
			}

		}
		#ifdef DEBUG
			cerr << "The first distance matrix is as follows: " << endl;
			F(i,R){
				F(j,C){
					cerr << dist[i][j] << " ";
				}
				cerr << endl;
			}
		#endif
		int maxi = 0, maxj = 0;
		F(i,R){
			F(j,C){
				if(dist[i][j] > dist[maxi][maxj]){
					maxi = i;
					maxj = j;
				}
			}
		}
		memset(vis, 0, sizeof(int)*(R*C));
		memset(dist, 0, sizeof(int)*(R*C));
		Q = queue<pii>();
		Q.push({maxi, maxj});
		dist[maxi][maxj] = 0;
		vis[maxi][maxj] = 1;
		int maxans = 0;
		#ifdef DEBUG
			cerr << "Second starting point is " << maxi << "," << maxj << endl;
		#endif
		while (!Q.empty()){
			pii cur = Q.front();
			Q.pop();
			for(int i = 0;i < 4; i += 1){
				int newi = cur.first + X[i];
				int newj = cur.second + Y[i];
				if (newi >= 0 and newj >= 0 and newi < R and newj < C){
					if(not (vis[newi][newj]) and LAB[newi][newj] == '.'){
						dist[newi][newj] = dist[cur.first][cur.second]+1;
						maxans = max(maxans, dist[newi][newj]);
						Q.push({newi, newj});
						vis[newi][newj] = 1;
					}
				}
			}
		}
		#ifdef DEBUG
			cerr << "The second distance matrix is as follows: " << endl;
			F(i,R){
				F(j,C){
					cerr << dist[i][j] << " ";
				}
				cerr << endl;
			}
		#endif
		cout << "Maximum rope length is " << maxans << "." << endl;
	}
}

