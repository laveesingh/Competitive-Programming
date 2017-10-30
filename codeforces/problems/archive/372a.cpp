#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;
int n;
int a[N];

bool fits(int mid){
  if(mid > n/2) return false;
  int i = mid-1, j = n-1;
  //cerr << "n " << n << " for mid " << mid << " i " << i << " j " << j << endl;
  while(i >= 0 && j >= 0){
    if(a[i] <= a[j]/2)
      i--, j--;
    else
      return false;
  }
  if(i >= 0) return false;
  return true;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  int lo = 0, hi = n, mid = n;
  while(lo <= hi){
    if(mid == (lo + hi)/2) break;
    mid = (lo + hi)/2;
    if(fits(mid))
      lo = mid;
    else
      hi = mid;
  }
  if(hi < lo) swap(lo, hi);
  if(fits(hi)) cout << n-hi << endl;
  else cout << n-hi+1 << endl;
}

