#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  long long n;
  cin >> t;
  while(t--){
    cin >> n;
    long long a[n];
    for(long long i = 0; i < n; i++) cin >> a[i];
    long long psum[n], ssum[n];
    fill_n(psum, n, 0);
    fill_n(ssum, n, 0);
    for(long long i = 0; i < n; i++){
      if(i == 0) psum[i] = a[i];
      else psum[i] = psum[i-1] + a[i];
    }
    for(long long i = n-1; i >= 0; i--){
      if(i == n-1) ssum[i] = a[i];
      else ssum[i] = ssum[i+1] + a[i];
    }
    long long ind = 0, val = psum[0] + ssum[0];
    for(long long i = 1; i < n; i++)
      if(psum[i] + ssum[i] < val)
        val = psum[i] + ssum[i],
        ind = i;
    cout << ind+1 << endl;
  }
}

