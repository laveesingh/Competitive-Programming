#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int M = *max_element(a, a+n) * 2
  sort(a, a+n);
  set<int> aset(a, a+n);
  int ans = 0;
  for(int aj: aset){
    for(int cur = 2*aj; cur < M; cur += aj){
      int ind = upper_bound(a, a+n, cur - 1) - a;
      //cerr << "for " << cur << " found " << ind << endl;
      if(ind <= n){
        if(ind >= 0 and ind < n and a[ind] < cur and a[ind] >= aj)
          ans = max(ans, a[ind] % aj);
        if(ind > 0 and a[ind-1] < cur and a[ind-1] >= aj)
          ans = max(ans, a[ind-1] % aj);
      }
    }
  }
  cout << ans << endl;
}

