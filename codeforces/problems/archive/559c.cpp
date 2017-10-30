#include <bits/stdc++.h>

using namespace std;

const int N = 2 * 1e5 + 1;
const int MOD = 1e9 + 7;
int fact[N];

int bin_exp(int b, int e){
  //cerr << "bin exp " << b << " " << e << " is ";
  if(e == 0) return 1;
  int ans = 1;
  while(e > 0){
    if(e&1) ans = (long long)ans * b % MOD;
    b = (long long)b * b % MOD;
    e = e>>1;
  }
  //cerr << ans << endl;
  return ans;
}

int mmi(int x){
  return bin_exp(x, MOD-2);
}

int comb(int x, int y){
  if(y > x) return 0;
  int ans = fact[x];
  ans = (long long)ans * mmi(fact[y]) % MOD;
  ans = (long long)ans * mmi(fact[x-y]) % MOD;
  return ans;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  fact[0] = 1;
  for(int i = 1; i < N; i++)
    fact[i] = (long long)fact[i-1] * i % MOD;
  int h, w, n, x, y;
  cin >> h >> w >> n;
  pair<int, int> A[n+1];
  for(int i = 0; i < n; i++){
    cin >> x >> y;
    A[i] = {x, y};
  }
  A[n] = {h, w};
  sort(A, A+(n+1));
  int ways[n+1];
  for(int i = 0; i <= n; i++){
    x = A[i].first, y = A[i].second;
    int total = comb(x+y-2, x-1);
    //cerr << "total: " << total << " for " << x << " " << y << endl;
    for(int j = 0; j < i; j++){
      int xi = A[i].first - A[j].first;
      int yi = A[i].second - A[j].second;
      if(xi >= 0 and yi >= 0){
        total = (total - ((long long)ways[j]*comb(xi+yi, yi))%MOD + MOD) %MOD;
      }
    }
    ways[i] = total;
  }
  //for(int i = 0; i < n; i++) cerr << ways[i] << endl;
  cout << ways[n] << endl;
}
