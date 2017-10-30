#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
int res[N], vis[N];

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  fill_n(res, N, 1e9);
  res[n] = 0;
  deque<int> st;
  st.push_back(n);
  vis[n] = 1;
  while(!st.empty()){
    int cur = st.front();
    st.pop_front();
    if(cur > 1 && !vis[cur-1]){
      vis[cur-1] = 1;
      res[cur-1] = min(res[cur-1], res[cur] + 1);
      st.push_back(cur-1);
    }
    if(cur < m && !vis[cur*2]){
      vis[cur*2] = 1;
      res[cur*2] = min(res[cur*2], res[cur] + 1);
      st.push_back(cur*2);
    }
  }
  //for(int i = 0; i < 20; i++){
    //cerr << i << ": " << res[i] << endl;
  //}
  cout << res[m] << endl;
}

