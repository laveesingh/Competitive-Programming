#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e8;
int N1, N2, K1, K2;
int dp[101][101][11][11];

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N1 >> N2 >> K1 >> K2;
  for(int n1 = 0; n1 <= N1; n1++)
    for(int n2 = 0; n2 <= N2; n2++)
      for(int k1 = 0; k1 <= K1; k1++)
        for(int k2 = 0; k2 <= K2; k2++)
          if(n1 == 0){
            if(n2 > K2) dp[n1][n2][k1][k2] = 0;
            else dp[n1][n2][k1][k2] = 1;
          }else if(n2 == 0){
            if(n1 > K1) dp[n1][n2][k1][k2] = 0;
            else dp[n1][n2][k1][k2] = 1;
          }else if(k1 == K1){
            dp[n1][n2][k1][k2] = dp[n1][n2-1][0][k2+1];
          }else if(k2 == K2){
            dp[n1][n2][k1][k2] = dp[n1-1][n2][k1+1][0];
          }else{
            dp[n1][n2][k1][k2] = (dp[n1][n2-1][0][k2+1] + dp[n1-1][n2][k1+1][0]) % MOD;
          }
  cout << dp[N1][N2][0][0] << endl;
}

