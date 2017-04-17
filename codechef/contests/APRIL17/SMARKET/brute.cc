#include <bits/stdc++.h>

using namespace std;

int *a;

int query(int i, int j, int k){
  int cur = a[i], curlen = 1;
  vector<int> lengths;
  for(int ind = i+1; ind <= j; ind++){
    if(a[ind] != cur){
      lengths.push_back(curlen);
      cur = a[ind];
      curlen = 1;
    }else{
      curlen++;
    }
    if(ind == j){
      lengths.push_back(curlen);
      curlen = -1;
    }
  }
  if(curlen != -1)
    lengths.push_back(curlen);
  int ret = 0;
  for(int len: lengths)
    ret += (len >= k);
  return ret;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n, q;
    cin >> n >> q;
    a = new int[n];
    for(int i = 0; i < n; i += 1)
      cin >> a[i];
    int x, y, z;
    for(int i = 0; i < q; i += 1){
      cin >> x >> y >> z;
      cout << query(x-1, y-1, z) << endl;
    }
  }
}
