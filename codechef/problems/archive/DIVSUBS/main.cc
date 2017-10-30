#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int a[n];
    for(int i= 0; i < n; i += 1){
      cin >> a[i];
    }
    int b[n+1];
    for(int i = 0; i <= n; i += 1){
      if (i == 0) b[i] = 0;
      else{
        b[i] = (b[i-1] + a[i-1]) % n;
      }
    }
    vector<pair<int, int> > vec(n+1);
    for(int i = 0; i <= n; i += 1){
      vec[i] = {b[i], i};
    }
    int st, en;
    sort(vec.begin(), vec.end());
    for(int i = 0; i < n; i += 1){
      if(vec[i].first == vec[i+1].first){
        st = vec[i].second, en = vec[i+1].second;
        break;
      }
    }
    if(st > en)
      swap(st, en);
    cout << en - st  << endl;
    for(int i = st; i < en; i += 1)
      cout << i+1 << " ";
    cout << endl;
  }
}
