#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

const int N = 1e5 + 1;
const int K = 501;
int n, m, k;
int Type[N], C[K], Cpsum[K];
vector<pii> Adj[N];
int dist[K][K];

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  int node = 0;
  for(int i = 0; i < k; i++){
    cin >> C[i];
    for(int curnode = node; curnode <= node+C[i]; curnode++)
      Type[curnode] = i;
    node += C[i];
  }
  Cpsum[0] = C[0];
  for(int i = 1; i < k; i++)
    Cpsum[i] = Cpsum[i-1] + C[i];
  int u, v, x;
  for(int i = 0; i < m; i++){
    cin >> u >> v >> x;
    u--, v--;
    Adj[u].push_back({v, x});
    Adj[v].push_back({u, x});
  }
  bool correct = true;
  for(int i = 0; i < k; i++){
    int start = (i == 0 ? 0 : Cpsum[i-1]);
    int vis[N];
    fill_n(vis, N, 0);
    stack<int> st;
    st.push(start);
    vis[start] = 1;
    set<int> totals;
    totals.insert(start);
    while(!st.empty()){
      int cur = st.top();
      st.pop();
      for(pii adj: Adj[cur]){
        if(adj.second == 0 and !vis[adj.first]){
          st.push(adj.first);
          if(Type[adj.first] == Type[start]) totals.insert(adj.first);
          vis[adj.first] = 1;
        }
      }
    }
    if(totals.size() != C[i]) { correct = false; break; }
  }
  if(not correct) { cout << "No" << endl; return 0;}
  for(int i = 0; i < k; i++)
    for(int j = 0; j < k; j++) {
      dist[i][j] = (i == j ? 0 : 1e9);
    }
  for(int i = 0; i < N; i++){
    for(pii adj: Adj[i]){
      dist[Type[ i ]][Type[ adj.first ]] = min(dist[Type[ i ]][Type[ adj.first ]], adj.second);
      dist[Type[ adj.first ]][Type[ i ]] = min(dist[Type[ adj.first ]][Type[ i ]], adj.second);
    }
  }
  for(int l = 0; l < k; l++)
    for(int i = 0; i < k; i++)
      for(int j = 0; j < k; j++)
        if(dist[i][l] + dist[l][j] < dist[i][j])
          dist[i][j] = dist[i][l] + dist[l][j];
  cout << "Yes" << endl;
  for(int i = 0; i < k; i ++){
    for(int j = 0; j < k; j++){
      if(dist[i][j] == 1e9) dist[i][j] = -1;
      cout << dist[i][j] << " ";
    }
    cout << endl;
  }
}

