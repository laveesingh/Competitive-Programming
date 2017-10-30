#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 1;
const int inf = 2e9;

int capt[N], assis[N], suff_capt[N], dp[N][N/2 + 1];

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> capt[i] >> assis[i];
  suff_capt[n-1] = capt[n-1];
  for(int i = n-2; i >= 0; i--) suff_capt[i] = capt[i] + suff_capt[i+1];
  for(int i = n-1; i >= 0; i--){
    for(int j = n/2; j >= 0; j--){
      if(j == n/2) dp[i][j] = suff_capt[i];
      else if(i == n-1){
        if(j == n/2) dp[i][j] = capt[i];
        else dp[i][j] = inf;
      }else{
        if(j > i-j)
          dp[i][j] = min(dp[i+1][j+1]+assis[i], dp[i+1][j]+capt[i]);
        else
          dp[i][j] = dp[i+1][j+1]+assis[i];
      }
    }
  }
  cout << dp[0][0] << endl;
}

