#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;
const int mod = 1e9 + 7;
int dp[N];

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int t, k;
  cin >> t >> k;
  for(int i = 0; i < N; i++){
    if(i < k) dp[i] = 1;
    else
      dp[i] = (dp[i-k] + dp[i-1]) % mod;
  }
  int psum[N];
  for(int i = 0; i < N; i++){
    if(i==0) psum[i] = 0;
    else psum[i] = (psum[i-1] + dp[i]) % mod;
  }
  int a, b;
  for(int i = 0; i < t; i++){
    cin >> a >> b;
    cout << (psum[b] - psum[a-1] + mod) % mod << endl;
  }
}

