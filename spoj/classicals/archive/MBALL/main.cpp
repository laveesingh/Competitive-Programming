#include <bits/stdc++.h>

using namespace std;

const long long N = 1e5 + 1;
long long dp[N][6];

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long s[5] = {2, 3, 6, 7, 8};
  for(long long i = 0; i < 5; i++){
    dp[0][i] = 1;
  }
  for(long long i = 1; i < N; i++){
    for(long long j = 0; j < 5; j++){
      long long x = (i >= s[j] ? dp[i-s[j]][j] : 0);
      long long y = (j > 0 ? dp[i][j-1]: 0);
      dp[i][j] = x+y;
    }
  }
  long long n, x;
  cin >> n;
  for(long long i = 0; i < n; i++){
    cin >> x;
    cout << dp[x][4] << endl;
  }
}

