#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 1;
long long n, k;
long long a[N], b[N];
long long needed(long long mid){
  long long ret = 0;
  for(long long i = 0; i < n; i++){
    ret += max(0ll, mid*a[i] - b[i]);
    if(ret > k) return ret;
  }
  //cerr << "needed: " << ret << " for " << mid << endl;
  return ret;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for(long long i = 0; i < n; i += 1) cin >> a[i];
  for(long long i = 0; i < n; i += 1) cin >> b[i];
  long long lo = 0, hi = 2*1e9, mid = -1;
  while(lo <= hi){
    if(mid == (lo + hi)/2) break;
    mid = (lo + hi)/2;
    if(needed(mid) > k)
      hi = mid;
    else
      lo = mid;
  }
  if(lo > hi) swap(lo, hi);
  if(needed(hi) <= k) cout << hi << endl;
  else cout << lo << endl;
}

