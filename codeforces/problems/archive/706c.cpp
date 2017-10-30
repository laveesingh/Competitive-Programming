#include <bits/stdc++.h>

using namespace std;

const long long  inf = 1e18;
const long long  N = 1e5 + 1;
long long  n;
string a[N][2];
long long dp[N][2];
long long c[N];


void relax(long long& a, long long b){
  if(b < a)
    a = b;
}

long long solve(){
  for(long long i = 0; i < n; i++){
    dp[i][0] = inf;
    dp[i][1] = inf;
  }
  for(long long i = 0; i < n; i++){
    if(i==0){
      dp[i][0] = 0;
      dp[i][1] = c[0];
    }else{
      if(a[i][0] >= a[i-1][0])
        relax(dp[i][0], dp[i-1][0]);
      if(a[i][0] >= a[i-1][1])
        relax(dp[i][0], dp[i-1][1]);
      if(a[i][1] >= a[i-1][0])
        relax(dp[i][1], dp[i-1][0]+c[i]);
      if(a[i][1] >= a[i-1][1])
        relax(dp[i][1], dp[i-1][1]+c[i]);
    }
  }
  return min(dp[n-1][0], dp[n-1][1]);
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for(long long i = 0; i < n; i++) cin >> c[i];
  for(long long i = 0; i < n; i++){
    cin >> a[i][0];
    a[i][1] = a[i][0];
    reverse(a[i][1].begin(), a[i][1].end());
  }
  long long  ans = solve();
  cout << (ans == inf ? -1 : ans) << endl;
}

