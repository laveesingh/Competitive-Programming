#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  double a[n], l;
  cin >> n >> l;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  double max_dist = max(a[0] - 0, l - a[n-1]);
  for(int i = 0; i < n-1; i++)
    max_dist = max(a[i+1] - a[i], max_dist);
  cout << (max_dist/2.0) << endl;
}

