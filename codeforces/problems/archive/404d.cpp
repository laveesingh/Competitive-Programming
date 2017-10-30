#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const long long N = 1e6 + 1;
long long dp[N][5];

bool valid(string a){
  long long n = a.length();
  for(long long i = 0; i < n; i++){
    if(a[i] == '0'){
      if(i-1 >= 0 and a[i-1] == '*') return false;
      if(i+1 < n and a[i+1] == '*') return false;
    }
    else if(a[i] == '1'){
      if(i-1 >= 0 and a[i-1] == '*' and i+1 < n and a[i+1] == '*') return false;
      if(i-1 >= 0 and a[i-1] != '*' and a[i-1] != '?' and i+1 < n and a[i+1] != '*' and a[i+1] != '?') return false;
    }
    else if(a[i] == '2'){
      if(i == n-1 || i == 0) return false;
      if(a[i-1] != '?' and a[i-1] != '*') return false;
      if(a[i+1] != '?' and a[i+1] != '*') return false;
    }
  }
  return true;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string a;
  cin >> a;
  if(!valid(a)){
    cout << 0 << endl;
    return 0;
  }
  long long n = a.size();
  for(long long i = n-1; i >= 0; i--){
    if(i == n-1){
      if(a[i] != '?'){
        if(a[i] == '0') dp[i][0] = 1;
        else if(a[i] == '1'){
          dp[i][1] = 1;
          dp[i][2] = 0;
        }
        else dp[i][4] = 1;
      }else{
        dp[i][0] = 1;
        dp[i][1] = 1;
        dp[i][2] = 0;
        dp[i][3] = 0;
        dp[i][4] = 1;
      }
      continue;
    }
    if(a[i] != '?'){
      if(a[i] == '0') dp[i][0] = (dp[i+1][0] + dp[i+1][2]) % mod;
      else if(a[i] == '1'){
        dp[i][1] = (dp[i+1][0] + dp[i+1][2]) % mod;
        dp[i][2] = dp[i+1][4];
      }else if(a[i] == '2') dp[i][3] = dp[i+1][4];
      else dp[i][4] = (dp[i+1][1] + dp[i+1][3] + dp[i+1][4]) % mod;
      continue;
    }
    dp[i][0] = (dp[i+1][0] + dp[i+1][2]) % mod;
    dp[i][1] = (dp[i+1][0] + dp[i+1][2]) % mod;
    dp[i][2] = dp[i+1][4];
    dp[i][3] = dp[i+1][4];
    dp[i][4] = (dp[i+1][1] + dp[i+1][3] + dp[i+1][4]) % mod;
  }
  //for(long long i = 0; i < n; i++){
    //for(long long j = 0; j < 5; j++){
      //cerr << dp[i][j] << " ";
    //}
    //cerr << endl;
  //}
  cout << (dp[0][0] + dp[0][2] + dp[0][4]) % mod << endl;
}

