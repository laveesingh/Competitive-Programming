#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)

const int N = 201;
int dist[N][N];

int main(void){
	int t, n;
	iint(t);
	while(t--){
		iint(n);
		for(int i = 0; i < n; i += 1)
			for(int j = 0; j < n; j += 1)
				iint(dist[i][j]);
		vector<pair<int, int> > pairs;
		for(int i = 0; i < n; i += 1){
			for(int j = i+1; j < n; j += 1){
				int flag = 0;
				for(int k = 0; k < n; k += 1){
					if(k == i or k == j) continue;
					if(dist[i][k]+dist[k][j] == dist[i][j]){
						flag = 1;
						break;
					}
				}
				if(flag == 0){
					pairs.push_back({i, j});
				}
			}
		}
		sort(pairs.begin(), pairs.end());
		for(int i = 0; i < pairs.size(); i += 1){
			printf("%d %d\n", pairs[i].first+1, pairs[i].second+1);
		}
		printf("\n");
	}
}

