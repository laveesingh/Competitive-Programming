#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
#define pii pair<int, int>
vector<pii> Adj[N];
int parity[N];

bool dfs(int source){
  bool ret = true;
  deque<int> st;
  st.push_back(source);
  while(!st.empty()){
    source = st.front();
    st.pop_front();
    for(pii adj: Adj[source]){
      int y = adj.first, bit = adj.second;
      if(parity[y] == -1){
        if(bit) parity[y] = parity[source]^1;
        else parity[y] = parity[source];
        st.push_back(y);
        //ret = ret && dfs(y);
      }else{
        if(bit && parity[y] == parity[source]){
          return false;
        }else if((!bit) && parity[y] != parity[source]){
          return false;
        }
      }
    }
  }
  return ret;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t; 
  int n, q, x, y, bit;
  while(t--){
    int source = 0;
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
      Adj[i].clear();
    for(int i = 0; i < q; i++){
      cin >> x >> y >> bit;
      Adj[x].push_back({y, bit});
      Adj[y].push_back({x, bit});
      if(not source) source = x;
    }
    fill_n(parity, n+1, -1);
    parity[source] = 0;
    bool okay = dfs(source);
    for(int i = 1; i <= n; i++){
      if(parity[i] == -1){
        parity[i] = 0;
        okay = okay && dfs(i);
      }
    }
    if(okay) cout << "yes" << endl;
    else cout << "no" << endl;
  }
}

