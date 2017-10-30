#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  set<int> aset(a, a+n);
  vector<int> ans;
  int type = 1;
  while(m >= type){
    if(aset.find(type) == aset.end()){
      ans.push_back(type);
      m -= type;
    }
    type++;
  }
  cout << ans.size() << endl;
  for(int i: ans) cout << i << " ";
  cout << endl;
}

