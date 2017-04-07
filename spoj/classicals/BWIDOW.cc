#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  int t, n, x, y;
  cin >> t;
  while(t--){
    cin >> n;
    pair<int, int> rings[n];
    for(int i=0; i<n; i++){
      cin >> x >> y;
      rings[i] = {x, y};
    }
    int max_inner_index = 0, max_inner_rad = 0;
    for(int i=0; i<n; i++){
      if(rings[i].first > max_inner_rad){
        max_inner_rad = rings[i].first;
        max_inner_index = i;
      }
    }
    int max_outer_rad = 0;
    for(int i=0; i<n; i++)
      if(i != max_inner_index && rings[i].second > max_outer_rad)
        max_outer_rad = rings[i].second;
    if (max_inner_rad > max_outer_rad)
      cout << max_inner_index+1 << endl;
    else
      cout << -1 << endl;
  }
}
