#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int LN = 17;

int n;
vector<int> adj[N];
int depth[N];
int par[LN][N];


void dfs(int i, int d, int p){
  for(int Adj: adj[i]){
    if(Adj == p) continue;
    depth[Adj] = d+1;
    par[Adj][0] = i;
    dfs(Adj, d+1, i);
  }
}

void set_lca(){
  for(int i = 0; i < n; i++)
    for(int j = 0; (1<<j) < n; j++)
      par[i][j] = (j==0 ? par[i][j] : -1);
  for(int j = 1; (1<<j) < n; j++){
    for(int i = 0; i < n; i++){
      if(par[i][j-1] != -1)
        par[i][j] = par[par[i][j-1]][j-1];
    }
  }
}

int get_lca(int p, int q){
  if(depth[p] < depth[q]) swap(p, q);
  int Log;
  for(Log = 1; (1<<Log) <= depth[p]; Log++);
  Log--;
  for(int i = Log; i >= 0; i--)
    if(depth[p] - (1<<i) >= depth[q]) p = par[p][i];
  if(p == q) return q;
  for(int i = Log; i >= 0; i--)
    if(par[p][i] != -1 and par[p][i] != par[q][i])
      p = par[p][i], q = par[q][i];
  return par[p][0];
}

int dist(int p, int q){
  int l = get_lca(p, q);
  int ret = depth[p] + depth[q] - 2*depth[l];
  cout << "dist between " << p << " and " << q << " " << ret << endl;
  return ret;
}


int main(void){
  ios::sync_with_stdio(false);
  int q, p, a, b, c;
  cin >> n >> q;
  for(int i = 1; i < n; i++){
    cin >> p;
    p--;
    adj[i].push_back(p);
    adj[p].push_back(i);
  }
  dfs(0, 0, -1);
  set_lca();
  for(int query = 0; query < q; query++){
    cin >> a >> b >> c;
    int arr[3], f, s, t;
    sort(arr, arr+3);
    for(int _ = 0; _ < 3; _++) cin >> arr[_];
    f = arr[0] - 1;
    s = arr[1] - 1;
    t = arr[2] - 1;
    int fs = dist(f, s);
    int ft = dist(f, t);
    int st = dist(s, t);
    int dists[3] = {fs, ft, st};
    sort(dists, dists+3);
    for(int i = 0; i < 3; i++) cout << dists[i] << " ";
    cout << endl;
    cout << dists[1] << endl;
  }
}

