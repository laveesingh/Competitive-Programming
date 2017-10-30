#include <bits/stdc++.h>
using namespace std;

const int N = 10001;
const int LN = 15;
#define mp make_pair
#define pii pair<int, int>

// Node properties
int par[N], depth[N], size[N], pos[N], chain[N], chain_heads[N], pa[LN][N];
// edge properties
int weight[N], deeper[N];
// other tracks
vector<int> adj[N];
map<pii, int> edges;
int arr[N], tree[4*N], n;

void dfs(int cur, int prev, int dep){
	par[cur] = prev, depth[cur] = dep, size[cur] = 1;
	for(int Adj: adj[cur])
		if(Adj != prev){
			deeper[edges[mp(cur, Adj)]] = Adj;
			dfs(Adj, cur, dep+1);
			size[cur] += size[Adj];
		}
}

void hld(int ncur, int id, int *ecount, int *cchain){ // chain_heads is global, don't need here
	if(chain_heads[*cchain] == -1) chain_heads[*cchain] = ncur;
	chain[ncur] = *cchain, pos[ncur] = *ecount;
	arr[(*ecount)++] = weight[id];
	int sp_child = -1, sp_edge = -1;
	for(int Adj: adj[ncur])
			if(Adj != par[ncur] && (sp_child == -1 || size[sp_child] < size[Adj]))
				sp_child = Adj, sp_edge = edges[mp(ncur, Adj)];
	if(sp_child != -1) hld(sp_child, sp_edge, ecount, cchain);
	for(int Adj: adj[ncur]) if(Adj != par[ncur] && Adj != sp_child){
			(*cchain)++;
			hld(Adj, edges[mp(ncur, Adj)], ecount, cchain);
		}
}
// Verfied till here

void constructST(int node, int st, int en){
	if(st == en-1) tree[node] = arr[st];
	else{
		int mid = (st+en)/2;
		constructST(2*node, st, mid);
		constructST(2*node+1, mid, en);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
}

void updateST(int node, int st, int en, int i, int x){
	if(st > i || en <= i);
	else if(st == i && st == en-1) tree[node] = x;
	else{
		int mid = (st+en)/2;
		updateST(2*node, st, mid, i, x);
		updateST(2*node+1, mid, en, i, x);
		tree[node] = max(tree[2*node], tree[2*node+1]);
	}
}

void change(int e, int val){ updateST(1, 0, n, pos[deeper[e]], val); }

int LCA(int u, int v){
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) {
		return u;
	}
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v])
		u = pa[i][u], v = pa[i][v];
	return pa[0][u];
}

int rmq(int node, int st, int en, int i, int j){
	if(i <= st && en-1 <= j) return tree[node];
	if (i > en-1 || j < st) return -1;
	int mid = (st + en)/2;
	return max(rmq(2*node, st, mid, i, j), rmq(2*node+1, mid, en, i, j));
}

int crawl_tree(int u, int v){
	int cv = chain[v], cu, ans = 0;
	while(true){
		cu = chain[u];
		if(cu == cv){
			if(u == v) ;
			else ans = max(rmq(1, 0, n, pos[v]+1, pos[u]), ans);
			break;
		}else{
			ans = max(ans, rmq(1, 0, n, pos[chain_heads[cu]], pos[u]));
			u = par[chain_heads[cu]];
		}
	}
	return ans;
}

int max_edge(int u, int v){
	int lca = LCA(u, v);
	return max(crawl_tree(u, lca), crawl_tree(v, lca));
}

int main(void){
	int t, x, y, w;
	//cin >> t;
	scanf("%d", &t);
	while(t--){
		//cin >> n;
		scanf("%d", &n);
		edges.clear();
		int ecount = 0, cchain = 0;
		for(int i=0; i<=n; i++){
			chain_heads[i] = -1;
			for(int j=0; j<LN; j++)
				pa[j][i] = -1;
			adj[i].clear();
		}
		for(int i=0; i<n-1; i++){
			//cin >> x >> y >> w;
			scanf("%d %d %d", &x,&y, &w);
			x--, y--;
			edges[mp(x, y)] = i;
			edges[mp(y, x)] = i;
			weight[i] = w;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs(0, -1, 0);
		hld(0, -1, &ecount, &cchain);
		constructST(1, 0, ecount);
		for(int i=0; i<LN; i++)
			for(int j=0; j<n; j++) {
				if(i==0) pa[i][j] = par[j];
				else if(pa[i-1][j] != -1) pa[i][j] = pa[i-1][pa[i-1][j]];
			}

		char type[10];
		while(1){
			//cin>>type;
			scanf("%s", type);
			if(type[0] == 'D') break;
			//cin >> x >> y;
			scanf("%d %d", &x, &y);
			if(type[0] == 'Q'){
				x--, y--;
				//cout << max_edge(x, y) << endl;
				printf("%d\n", max_edge(x, y));
			}else{
				x--;
				change(x, y);
			}
		}
	}
}

