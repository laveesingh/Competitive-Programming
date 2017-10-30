#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  set<int> dist;
  bool imp = false;
  for(int i = 0; i < n; i++){
    int gind, sind;
    string x;
    cin >> x;
    for(int j = 0; j < m; j++){
      if(x[j] == 'G') gind = j;
      else if(x[j] == 'S') sind = j;
    }
    if (gind > sind) imp = true;
    dist.insert(sind - gind);
  }
  if(imp) cout << -1 << endl;
  else cout << dist.size() << endl;
}

