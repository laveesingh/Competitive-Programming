#include <bits/stdc++.h>

using namespace std;

const int N = 3e3 + 1;
int dp[2][N];

int main(void){
  int n;
  cin >> n;
  int a[n], b[n], c[n];
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++) cin >> b[i];
  for(int i = 0; i < n; i++) cin >> c[i];
  dp[0][n-1] = a[n-1];
  dp[1][n-1] = b[n-1];
  for(int i = n-2; i >= 0; i--){
    dp[0][i] = max(a[i] + dp[1][i+1], b[i] + dp[0][i+1]);
    dp[1][i] = max(b[i] + dp[1][i+1], c[i] + dp[0][i+1]);
  }
  cout << dp[0][0] << endl;
}
