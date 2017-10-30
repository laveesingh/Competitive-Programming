#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, y;
  cin >> n;
  set<int> cset;
  map<int, int> tfreq, bfreq;
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    tfreq[x]++;
    if(x != y) bfreq[y]++;
    cset.insert(x);
    cset.insert(y);
  }
  int ans = 2*1e9;
  for(int color: cset){
    int front = tfreq[color];
    int back = bfreq[color];
    int req = (n + 1)/2;
    if(front+back < req) continue;
    else
      ans = min(ans, max(0, req - front));
  }
  if(ans == 2*1e9) cout << -1 << endl;
  else cout << ans << endl;
}










