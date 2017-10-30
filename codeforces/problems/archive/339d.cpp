#include <bits/stdc++.h>

using namespace std;

const int N = (1<<17) + 1;
int tree[4*N + 4], arr[N];

void build(int node, int st, int en, int level){
  if(st == en){
    tree[node] = arr[st];
  }else{
    int mid = (st + en)/2;
    build(2*node, st, mid, level+1);
    build(2*node+1, mid+1, en, level+1);
    if(level&1)
      tree[node] = tree[2*node] | tree[2*node + 1];
    else
      tree[node] = tree[2*node] ^ tree[2*node + 1];
  }
}

void update(int node, int st, int en, int idx, int x, int level){
  if(st == en and idx == st){
    tree[node] = x;
  }else{
    int mid = (st + en)/2;
    if(idx < st or idx > en or st > en) return ;
    update(2*node, st, mid, idx, x, level+1);
    update(2*node+1, mid + 1, en, idx, x, level+1);
    if(level&1)
      tree[node] = tree[2*node] | tree[2*node + 1];
    else
      tree[node] = tree[2*node] ^ tree[2*node + 1];
  }
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int level = (n%2);
  n = (1<<n);
  for(int i = 0; i < n; i++) cin >> arr[i];
  build(1, 0, n-1, level);
  int p, b;
  for(int i = 0; i < m; i += 1){
    cin >> p >> b;
    update(1, 0, n-1, p-1, b, level);
    cout << tree[1] << endl;
  }
}

