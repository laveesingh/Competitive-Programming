#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)

const int N = 1e5+1;
int par[N];
vector<int> tree[N];
int store[N][2];


void dfs(int i, int prev){
	for(int child: tree[i])
		if(child != prev){
			par[child] = i;
			dfs(child, i);
		}
}

int solve(int i, int state){
	if(store[i][state]) return store[i][state];
	if (state == 0){
		int flag = 0;
		int ret = 0;
		for(int child: tree[i])
			if(child != par[i]){
				flag = 1;
				if(!store[child][1]) store[child][1] = solve(child, 1);
				ret += store[child][1];
			}
		if (flag == 0) return 0;
		else return ret;
	}else{
		int flag = 0, ret = 0;
		for(int child: tree[i])
			if(child != par[i]){
				if(!store[child][1]) store[child][1] = solve(child, 1);
				if(!store[child][0]) store[child][0] = solve(child, 0);
				ret += min(store[child][1], store[child][0]);
				flag = 1;
			}
		if(flag == 0) return 1;
		else return ret+1;
	}
}
			

int main(void){
	int n, x, y;
	iint(n);
	for(int i = 0; i < n-1; i++){
		iint(x);
		iint(y);
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	par[1] = -1;
	dfs(1, -1);
	memset(store, 0, sizeof(store));
	int ans = solve(1, 0);
	memset(store, 0, sizeof(store));
	ans = min(ans, solve(1, 1));
	oint(ans);
}

