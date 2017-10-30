#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  long long t;
  cin >> t;
  while(t--){
    long long n, d;
    cin >> n >> d;
    long long a[n];
    for(long long i = 0; i < n; i++) cin >> a[i];
    long long total = accumulate(a, a+n, 0ll);
    bool possible = true;
    if(total % n) possible = false;
    long long elem = total / n;
    long long steps = 0;
    for(long long i = 0; i < n-d; i++){
      long long diff = a[i] - elem;
      a[i] -= diff;
      a[i+d] += diff;
      steps += abs(diff);
    }
    for(long long i = 0; i < n; i++)
      if(a[i] != elem){
        possible = false;
        break;
      }
    if(!possible) cout << -1 << endl;
    else cout << steps << endl;
  }
}
