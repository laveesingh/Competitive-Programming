#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 1;
int cost[N];
vector<int> Adj[N];
int max_gcd[N], par[N], depth[N], divs[N];
int n;

vector<int> factors(int a){
  vector<int> ret;
  for(int i = 1; i <= sqrt(a); i++){
    if(a%i == 0){
      ret.push_back(i);
      if(a/i != i)
        ret.push_back(a/i);
    }
  }
  return move(ret);
}

// assume root has the cost 0
void initial_dfs(int cur){
  stack<int> st;
  st.push(cur);
  while(!st.empty()){
    cur = st.top();
    st.pop();
    for(int adj: Adj[cur]){
      if(adj == par[cur]) continue;
      max_gcd[adj] = __gcd(cost[adj], max_gcd[cur]);
      depth[adj] = depth[cur] + 1;
      par[adj] = cur;
      st.push(adj);
    }
  }
}

void dfs(int cur, int factor){
  stack<int> st;
  st.push(cur);
  while(!st.empty()){
    cur = st.top();
    st.pop();
    for(int adj: Adj[cur]){
      if(adj == par[cur]) continue;
      divs[adj] = divs[cur] + (cost[adj] % factor == 0);
      if(divs[adj] >= depth[adj])
        max_gcd[adj] = max(max_gcd[adj], factor);
      st.push(adj);
    }
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int x, y;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d", &cost[i]);
  for(int i = 0; i < n-1; i++){
    scanf("%d %d", &x, &y);
    Adj[x-1].push_back(y-1);
    Adj[y-1].push_back(x-1);
  }
  par[0] = -1;
  depth[0] = 0;
  max_gcd[0] = 0; 
  initial_dfs(0);
  max_gcd[0] = cost[0];
  vector<int> facts = factors(cost[0]);
  for(int factor: facts){
    divs[0] = 1;
    dfs(0, factor);
  }
  for(int i = 0; i < n; i++) printf("%d ", max_gcd[i]);
  printf("\n");
}

