#include <iostream>
#include <unordered_map>

using namespace std;

#define umap unordered_map

const long long N = 1e6 + 1;

long long spf[N];
umap<long long, long long> prime_factors[N];

void set_smallest_prime_factor(){
  for(long long i = 0; i < N; i += 1)
    spf[i] = i%2 ? i : 2;
  for(long long i = 3; i < N; i += 2) if(spf[i] == i)
      for(long long j = i; j < N; j += i)
        spf[j] = min(spf[j], i);
}

void set_prime_factors(){
  for(long long i = 2; i < N; i += 1){
    long long x = i, sp;
    while(x > 1){
      sp = spf[x];
      prime_factors[i][sp] += 1;
      x /= sp;
    }
  }
}

long long query(long long i, long long x, long long y){
  long long ret = 0;
  for(pair<long long, long long> xy: prime_factors[i]){
    if(xy.first >= x && xy.first <= y)
      ret += xy.second;
  }
  return ret;
}

int main(void){
  ios::sync_with_stdio(false);
  set_smallest_prime_factor();
  set_prime_factors();
  long long n;
  cin >> n;
  long long a[n];
  for(long long i = 0; i < n; i += 1){
    cin >> a[i];
  }
  long long q;
  cin >> q;
  long long x, y, l, r;
  for(long long i = 0; i < q; i += 1){
    cin >> l >> r >> x >> y;
    l--, r--;
    long long ans = 0;
    for(long long j = l; j <= r; j += 1){
      ans += query(a[j], x, y);
    }
    cout << ans << endl;
  }
}