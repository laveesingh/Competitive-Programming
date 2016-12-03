#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)
#define pii pair<int, int>

typedef tuple<int, int, int> state;

const int inf = 1e9 + 7;
const int N = 26;
char shop[N][N];
int dist[N][N];
int X[] = {0, 0, -1, 1};
int Y[] = {-1, 1, 0, 0};

int main(void){
	int w, h;
	while(true){
		iint(w); iint(h);
		if(w == 0) break;
		for(int i = 0; i < h; i += 1)
			istr(shop[i]);
		pii st, en;
		for(int i = 0; i < h; i += 1)
			for(int j = 0; j < w; j += 1){
				dist[i][j] = inf;
				if(shop[i][j] == 'S') st = {i,j};
				if(shop[i][j] == 'D') en = {i,j};
			}
		deque<pii> q;
		q.push_back(st);
		dist[st.first][st.second] = 0;
		shop[st.first][st.second] = '0';
		while(!q.empty()){
			int cf, cs;
			tie(cf, cs) = make_tuple(q.front());
//			pii cur = q.front();
			q.pop_front();
			for(int i = 0; i < 4; i++){
				int ni = cur.first + X[i], nj = cur.second + Y[i];
				if(ni >= 0 and ni < h and nj >= 0 and nj < w and shop[ni][nj] != 'X' and dist[ni][nj] > dist[cur.first][cur.second]+(shop[cur.first][cur.second]-'0')){
					dist[ni][nj] = dist[cur.first][cur.second] + (shop[cur.first][cur.second]-'0');
					q.push_back({ni, nj});
				}
			}
		}
		oint(dist[en.first][en.second]);					
	}
}

