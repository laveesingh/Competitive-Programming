#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int LN = 17;
int par[N], depth[N], subsize[N], base_index[N], chain_no[N],
    lca[LN][N];

vector<int> adj[N];
int base_array[N], tree[4*N + 5], n;

void dfs(int cur, int d){
  subsize[cur] = 1, depth[cur] = d;
  for(int Adj: adj[cur])
    if(Adj != par[cur]){
      par[Adj] = cur;
      dfs(Adj, d+1);
      size[cur] += size[Adj];
    }
}

void hld(int cur){



int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);

}
