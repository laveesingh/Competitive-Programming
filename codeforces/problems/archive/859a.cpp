#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  int mx = *max_element(a, a+n);
  if(mx < 25) cout << 0 << endl;
  else cout << mx - 25 << endl;
}

