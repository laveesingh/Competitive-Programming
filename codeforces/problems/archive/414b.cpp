#include <bits/stdc++.h>

using namespace std;

const long long N = 2001;
const long long K = 2001;
const long long MOD = 1e9 + 7;
long long dp[N][K];

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, k;
  cin >> n >> k;
  for(long long len = 1; len <= k; len++){
    if(len==1){
      for(long long j = 1; j <= n; j++)
        dp[len][j] = 1;
    }else{
      for(long long i = 1; i <= n; i++)
        for(long long j = i; j <= n; j += i)
          dp[len][j] = (dp[len][j] + dp[len-1][i]) % MOD;
    }
  }
  long long ans = 0;
  for(long long i = 1; i <= n; i++)
    ans = (ans + dp[k][i]) % MOD;
  cout << ans << endl;
}

