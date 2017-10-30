#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 1;
const int LN = 14;
vector<int> Adj[N];
vector<vector<int> > Chains(LN, vector<int>());
int n, base_size, total_chains = 1, chainno;
int subsize[N], par[N], chain_no[N], head[LN], depth[N], chain_index[N], base_index[N], lca[N][LN], edge_cost[N], node_cost[N], edge_to_node[N], base_array[N], tree[4*N+5];
map< pair<int, int>, int> edge_no;

void debug_log(){
  cerr << "Followings are " << total_chains << "  chains" << endl;
  for(int i = 0; i < total_chains; i++){
    cerr << i << ": ";
    for(int node: Chains[i]) cerr << node+1 << " ";
    cerr << endl;
  }
  cerr << "Followings are node costs" << endl;
  for(int i = 0; i < n; i++)
    cerr << i+1 << ": " << node_cost[i] << ", ";
  cerr << endl;
  cerr << "Following is base_array" << endl;
  for(int i = 0; i < base_size; i++) cerr << base_array[i] << " ";
  cerr << endl;
  cerr << "Following is segment tree" << endl;
  for(int i = 0; i < 4*base_size; i++) cerr << tree[i] << " ";
  cerr << endl;

}

void dfs(int cur){ // par[0] == -1, depth[0] = 0
  subsize[cur] = 1;
  for(int adj: Adj[cur]){
    if(adj == par[cur]) continue;
    depth[adj] = depth[cur] + 1;
    par[adj] = cur;
    edge_to_node[edge_no[make_pair(cur, adj)]] = adj;
    dfs(adj);
    subsize[cur] += subsize[adj];
  }
}

void hld(int cur){
  Chains[chainno].push_back(cur);
  chain_no[cur] = chainno;
  if(subsize[cur] == 1) return;
  int sc = -1, sw = -1;
  for(int adj: Adj[cur]){
    if(adj == par[cur]) continue;
    if(subsize[adj] > sw)
      sc = adj, sw = subsize[adj];
  }
  hld(sc);
  for(int adj: Adj[cur]){
    if(adj == par[cur] || adj == sc) continue;
    chainno++;
    head[chainno] = adj;
    hld(adj);
  }
  total_chains = max(total_chains, chainno+1);
}

void push_chains_to_base(){
  int bindex = 0;
  for(int i = 0; i < total_chains; i++){
    for(int node: Chains[i]){
      base_index[node] = bindex;
      base_array[bindex] = node_cost[node];
      bindex++;
      base_size = max(base_size, bindex);
    }
  }
}

void _build(int node, int st, int en){
  if(st == en) tree[node] = base_array[st];
  else{
    int mid = (st + en)/2;
    _build(2*node, st, mid);
    _build(2*node+1, mid+1, en);
    tree[node] = max(tree[2*node], tree[2*node+1]);
  }
}

int _query(int node, int st, int en, int i, int j){
  if(i <= st && en <= j) return tree[node];
  if(i > en || j < st || st > en) return 0;
  int mid = (st + en)/2;
  return max(_query(2*node, st, mid, i, j), _query(2*node+1, mid+1, en, i, j));
}

void _update(int node, int st, int en, int i, int x){
  if(st == en && st == i) tree[node] = x;
  else if(i > en || i < st || st > en) return;
  else{
    int mid = (st + en)/2;
    _update(2*node, st, mid, i, x);
    _update(2*node+1, mid+1, en, i, x);
    tree[node] = max(tree[2*node], tree[2*node+1]);
  }
}

void build_lca(){
  for(int i = 0; i < n; i++) for(int j = 0; (1<<j) < n; j++)
      lca[i][j] = -1;
  for(int i = 0; i < n; i++) lca[i][0] = par[i];
  for(int j = 1; (1<<j) < n; j++)
    for(int i = 0; i < n; i++) if(lca[i][j-1] != -1)
        lca[i][j] = lca[lca[i][j-1]][j-1];
}

int get_lca(int x, int y){
  if(depth[x] < depth[y]) swap(x, y);
  int log;
  for(log = 1; (1<<log) <= depth[x]; log++);
  log--;
  for(int i = log; i >= 0; i--)
    if(depth[x]-(1<<i) >= depth[y])
      x = lca[x][i];
  if(x == y) return x;
  for(int i = log; i >= 0; i--)
    if(lca[x][i] != -1 and lca[x][i] != lca[y][i])
      x = lca[x][i], y = lca[y][i];
  return par[x];
}

int query(int a, int b){
  a = edge_to_node[a], b = edge_to_node[b];
  int l = get_lca(a, b);
  int ans = base_array[base_index[a]];
  while(a != l){
    if(head[chain_no[a]] == head[chain_no[l]]){
      ans = max(ans, _query(1, 0, base_size-1, base_index[a], base_index[l]));
      a = l;
    }else{
      int heada = head[chain_no[a]];
      ans = max(ans, _query(1, 0, base_size-1, base_index[a], base_index[heada]));
      a = par[heada];
    }
  }
  while(b != l){
    if(head[chain_no[b]] == head[chain_no[l]]){
      ans = max(ans, _query(1, 0, base_size-1, base_index[b], base_index[l]));
      b = l;
    }else{
      int headb = head[chain_no[b]];
      ans = max(ans, _query(1, 0, base_size-1, base_index[b], base_index[headb]));
      b = par[headb];
    }
  }
  return ans;
}

int update(int a, int x){
  a = edge_to_node[a];
  base_array[base_index[a]] = x; // check if base_index is working
  _update(1, 0, base_size-1, base_index[a], x);
  debug_log();
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, x, y, z;
  cin >> t;
  while(t--){
    cin >> n;
    for(int i = 0; i < n; i++) Adj[i].clear();
    for(int i = 0; i < LN; i++) Chains[i].clear();
    edge_no.clear();
    for(int i = 0; i < n-1; i++){
      cin >> x >> y >> z;
      Adj[x-1].push_back(y-1);
      Adj[y-1].push_back(x-1);
      edge_no[make_pair(x-1, y-1)] = i;
      edge_no[make_pair(y-1, x-1)] = i;
      edge_cost[i] = z;
    }
    par[0] = -1, depth[0] = 0;
    dfs(0);
    node_cost[0] = 0;
    for(int edge = 0; edge < n-1; edge++)
      node_cost[edge_to_node[edge]] = edge_cost[edge];
    build_lca();
    head[0] = 0;
    chainno = 0;
    hld(0);
    push_chains_to_base();
    _build(1, 0, base_size-1);
    debug_log();
    string qtype;
    int a, b;
    while(1){
      cin >> qtype;
      if(qtype[0] == 'Q'){
        cin >> a >> b;
        a--, b--;
        cout << query(a, b) << endl;
      }else if(qtype[0] == 'C'){
        cin  >> a >> b;
        a--;
        update(a, b);
      }else{
        break;
      }
    }
  }
}
