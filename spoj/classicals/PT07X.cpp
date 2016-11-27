#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)
#define pii pair<int, int>
#define mp make_pair

int main(void){
	int n, x, y;
	iint(n);
	vector<int> tree[n+1];
	int degree[n+1], marked[n+1];
	memset(degree, 0, sizeof(degree));
	memset(marked, 0, sizeof(marked));
	for(int i = 0; i < n-1; i += 1){
		iint(x);
		iint(y);
		tree[x].push_back(y);
		tree[y].push_back(x);
		degree[x]++;
		degree[y]++;
	}
	set<pii> nodes;
	for(int i = 1; i <= n; i += 1)
		nodes.insert(mp(degree[i], i));
	for(set<pii>::iterator it = nodes.begin(); it != nodes.end(); it++){
		pii cur = *it;
		int x = cur.second;
		if(marked[x]) continue;
		for(int y : tree[x])
			marked[y] = 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i += 1)
		ans += marked[i];
	oint(ans);
}

