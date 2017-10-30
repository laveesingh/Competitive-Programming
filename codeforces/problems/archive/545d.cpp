#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  for(long long i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  long long ans = 0, sum = 0;
  for(long long i = 0; i < n; i++){
    if(a[i] < sum) continue;
    else{
      sum += a[i];
      ans++;
    }
  }
  cout << ans << endl;
}


