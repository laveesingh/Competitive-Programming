#include <bits/stdc++.h>

using namespace std;

vector<long long> BIT;

void bit_add(long long i, long long val){
  while(i < BIT.size()){
    BIT[i] += val;
    i += (i & -i);
  }
}

void bit_insert(long long i){
  bit_add(i, 1);
}

void bit_delete(long long i){
  bit_add(i, -1);
}

long long bit_getsum(long long i){
  long long ans = 0;
  while(i > 0){
    ans += BIT[i];
    i -= (i & -i);
  }
  return ans;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  long long a[n];
  for(long long i = 0; i < n; i++) cin >> a[i];
  // start coordinate compression
  vector<long long> b(a, a+n);
  sort(b.begin(), b.end());
  map<long long, long long> val;
  long long cur = 1;
  val[b[0]] = cur;
  for(long long i = 1; i < n; i++){
    if(b[i] == b[i-1]) continue;
    else
      val[b[i]] = ++cur;
  }
  for(long long i = 0; i < n; i++) a[i] = val[a[i]];
  // coordinate compression done in O(NlogN)
  long long N = n+2;
  BIT = vector<long long>(N);
  long long freq[N], rfreq[n];
  fill_n(freq, N, 0);
  fill_n(rfreq, n, 0);
  for(long long i = n-1; i >= 0; i--){
    freq[a[i]]++;
    rfreq[i] = freq[a[i]];
    bit_insert(rfreq[i]);
  }
  fill_n(freq, N, 0);
  long long ans = 0;
  for(long long i = 0; i < n; i++){
    freq[a[i]]++;
    bit_delete(rfreq[i]);
    long long rank = bit_getsum(freq[a[i]] - 1);
    //cerr << "Found " << rank << " below " << freq[a[i]] << endl;
    ans += rank;
  }
  cout << ans << endl;
}

