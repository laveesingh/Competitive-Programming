#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 1;
const int inf = 1e9;
int dp[N];
int n;
int tree[4*N + 4];

void build(int n){
  fill_n(tree, 4*n+4, 0);
}

void _update(int node, int st, int en, int ind, int val){
  if(st == en and st == ind){
    tree[node] = val;
  }else if(ind < st || ind > en || st > en){
    return;
  }else{
    int mid = (st + en)/2;
    _update(2*node, st, mid, ind, val);
    _update(2*node+1, mid+1, en, ind, val);
    tree[node] = max(tree[2*node], tree[2*node+1]);
  }
}

void update(int pos, int val){
  _update(1, 0, n-1, pos, val);
}

int query(int node, int st, int en, int x, int y){
  if(x <= st && en <= y)
    return tree[node];
  else if(y < st || x > en || st > en)
    return 0;
  else{
    int mid = (st + en)/2;
    return max(query(2*node, st, mid, x, y), query(2*node+1, mid+1, en, x, y));
  }
}

int get_max(int x, int y){
  return query(1, 0, n-1, x, y);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, l;
  cin >> t;
  while(t--){
    cin >> n;
    int a[n];
    fill_n(dp, n, 0);
    build(n);
    vector<int> inds[N];
    for(int i = 0; i < n; i++){
      cin >> a[i];
      inds[a[i]].push_back(i);
    }
    vector<int> arr(a, a+n);
    sort(a, a+n);
    int pos, ans;
    for(int i = 0; i < n; i++){
      //cerr << "Considering " << a[i];
      pos = inds[a[i]].back();
      inds[a[i]].pop_back();
      //cerr << " with index: " << pos;
      ans = get_max(0, pos-1);
      //cerr << " found ans: " << ans;
      update(pos, ans+1);
      dp[pos] = ans+1;
      //cerr << endl;
    }
    cin >> l;
    ans = inf;
    //for(int i = 0; i < n; i++) cerr << dp[i] << " ";
    //cerr << endl;
    //for(int i = 0; i < n; i++) cerr << arr[i] << " ";
    //cerr << endl;
    for(int i = 0; i < n; i++)
      if(dp[i] == l)
        ans = min(ans, arr[i]);
    if(ans == inf) cout << -1 << endl;
    else cout << ans << endl;
  }
}

