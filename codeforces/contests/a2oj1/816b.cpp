#include <bits/stdc++.h>

using namespace std;

const long long N = 2 * 1e5 + 1;

pair<long long, long long> temps[N];
long long n, k, q;

long long lowest(long long x){
  long long lo = 0, hi = n-1, mid = -1;
  while(lo <= hi){
    if(mid == (lo+hi)/2) break;
    mid = (lo + hi)/2;
    if(temps[mid].first <= x && temps[mid].second >= x) hi = mid;
    else if(x < temps[mid].first) hi = mid-1;
    else lo = mid+1;
  }
  if(lo > hi) swap(lo, hi);
  if(temps[lo].first <= x && temps[lo].second >= x) return lo;
  if(temps[hi].first <= x && temps[hi].second >= x) return hi;
  return -1;
}

long long highest(long long x){
  long long lo = 0, hi = n-1, mid = -1;
  while(lo <= hi){
    if(mid == (lo+hi)/2) break;
    mid = (lo + hi)/2;
    if(temps[mid].first <= x && temps[mid].second >= x) lo = mid;
    else if(x < temps[mid].first) hi = mid-1;
    else lo = mid+1;
  }
  if(lo > hi) swap(lo, hi);
  if(temps[hi].first <= x && temps[hi].second >= x) return hi+1;
  if(temps[lo].first <= x && temps[lo].second >= x) return lo+1;
  return -1;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long x, y;
  cin >> n >> k >> q;
  for(long long i = 0; i < n; i++){
    cin >> x >> y;
    temps[i] = {x, y};
  }
  sort(temps, temps+n);
  long long freq[N];
  freq[0] = 0;
  for(long long i = 1; i < N; i++){
    freq[i] = highest(i) - lowest(i);
    cerr << "Initial freq(" <<
    if(freq[i] < k) freq[i] = 0;
    else freq[i] = 1;
    //if(i > 86 && i < 105) cerr << i << ": " << freq[i] << endl;
  }
  for(long long i = 2; i < N; i++) freq[i] += freq[i-1];
  for(long long i = 0; i < q; i++){
    cin >> x >> y;
    cout << freq[y] - freq[x-1] << endl;
  }
}

