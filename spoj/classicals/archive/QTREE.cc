#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

class Node{
public:
	int par, 	depth, 	size, 		pos_segbase, 					chain;
	// parent, depth, sizeOfSubTree,PositionInSegmentTreeBaseArray, Chain Number
	Node(){
		par = -1, depth = 0, size = 0, pos_segbase = 0, chain = 0;
	}
};
class Edge{
public: 
	int weight, deeper_end;
	// weight, endOfEdgeWhichHasHigherDepth
};
const int N = 10001;
const int LGN = 15;
map<pair<int, int>, int> tree;//(PairOfNodes)->(EdgeNo)
vector<int> graph[N];
Node node[N];
Edge edge[N];
int baseArray[N], segTree[6*N];
int chainHead[LGN], pa[LGN][N];
inline void addEdge(int edgeNo, int node1, int node2, int weight){
	tree[mp(node1-1, node2-1)] = edgeNo-1;
	tree[mp(node2-1, node1-1)] = edgeNo-1;
	edge[edgeNo-1].weight = weight;
} 
void dfs (int curNode, int prev, int dep){
	node[curNode].par = prev;
	node[curNode].depth = dep;
	node[curNode].size = 1;
	for(int adj: graph[curNode])
		if(adj != prev){
			edge[tree[mp(adj, curNode)]].deeper_end = adj;
			dfs(adj, curNode, dep+1);
			node[curNode].size += node[adj].size;
		}
}
void hld(int curNode, int id, int& edgeCount, int& curChain){
	if(chainHead[curChain] == -1) chainHead[curChain] = curNode;
	node[curNode].chain = curChain;
	node[curNode].pos_segbase = edgeCount;
	baseArray[edgeCount++] = edge[id].weight;
	int sChild = -1, sEdgeId;
	for(int adj: graph[curNode])
		if(adj != node[curNode].par and (sChild == -1 or
								node[sChild].size < node[adj].size))
			sChild = adj, sEdgeId = tree[mp(curNode, adj)];
	if (sChild != -1)
		hld(sChild, sEdgeId, edgeCount, curChain);
	for(int adj: graph[curNode])
		if(adj != node[curNode].par and adj != sChild)
			hld(adj, tree[mp(curNode, adj)], edgeCount, ++curChain);
}
void build(int node, int st, int en){
// Here's the difference, I used st == en instead of st == en-1 for using 0-based
	if(st == en){
		segTree[node] = baseArray[st];
	}else{
		int mid = (st + en)/2;
		build(2*node, st, mid);
		build(2*node+1, mid+1, en);
		segTree[node] = max(segTree[2*node], segTree[2*node+1]);
	}
}
void update(int node, int st, int en, int i, int val){
	if (st > i or en < i) return;
	if (st == i and st == en) segTree[node] = val;
	else{
		int mid = (st + en)/2;
		update(2*node, st, mid, i, val);
		update(2*node+1, mid+1, en, i, val);
		segTree[node] = max(segTree[2*node], segTree[2*node+1]);
	}
}
void change(int e, int val, int n){
	update(1, 0, n-1, node[edge[e].deeper_end].pos_segbase, val);
}
int LCA(int u, int v){
	if(node[u].depth < node[v].depth) swap(u, v);
	int diff = node[u].depth - node[v].depth;
	for(int i = 0; i < LGN; i += 1)
		if((diff >> i)&1) u = pa[i][u];
	if(u == v) return u;
	for(int i = LGN-1; i >= 0; i--)
		if(pa[i][u] != pa[i][v])
			u = pa[i][u], v = pa[i][v];
	return pa[0][u];
}
int query(int node, int st, int en, int x, int y){
	if(x <= st and en <= y) return segTree[node];
	if(en < x or st > y) return -1;
	int mid = (st + en)/2;
	return max(query(2*node, st, mid, x, y), 
								query(2*node+1, mid+1, en, x, y));
}
int RMQ(int x, int y, int n){
	return query(1, 0, n-1, x, y);
}
inline int crawlTree(int u, int v, int n){
	int chainU, chainV = node[v].chain, ans = 0;
	while(true){
		chainU = node[u].chain;
		if(chainU == chainV){
			if(u==v);
			else
				ans = max(RMQ(node[v].pos_segbase+1, 
								node[u].pos_segbase, n), ans);
			break;
		}else{
			ans = max(ans, RMQ(node[chainHead[chainU]].pos_segbase, 
				node[u].pos_segbase, n));
			u = node[chainHead[chainU]].par;
		}
	}
	return ans;
}
inline int maxEdge(int u, int v, int n){
	int lca = LCA(u, v);
	return  max(crawlTree(u, lca, n),crawlTree(v, lca, n));
}
int main(void){
	ios::sync_with_stdio(false);
	int t, n=0, x, y, w;
	string type;
	cin >> t;
	while(t--){
		cin >> n;
		tree.clear();
		for(int i = 1; i <= n; i += 1) graph[i].clear();
		memset(chainHead, -1, sizeof(chainHead));
		for(int i = 1; i < n; i += 1){
			cin >> x >> y >> w;
			addEdge(i, x, y, w);
		}
		int root = 1, proot = -1, droot = 0;
		dfs(root, proot, droot);
		int edgeCount = 0, curChain= 0;
		hld(root, n-1, edgeCount, curChain);
		build(1, 0, n-1);
		while(1){
			cin >> type;
			if(type == "DONE") break;
			if(type == "QUERY"){
				cin >> x >> y;
				cout << maxEdge(x-1, y-1, n) << endl;
			}else{
				cin >> x >> y;
				change(x-1, y-1, n);
			}
		}
	}
}
