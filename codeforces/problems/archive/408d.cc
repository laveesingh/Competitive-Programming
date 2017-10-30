#include <iostream>
using namespace std;
const int N = 1e4;
int p[N], vis[N], n, dp[N][2];
int cnt = 0;

int solve(int i){
  cnt++;
  cerr << i << ": " << vis[i]%2 << endl;
  vis[i]++;
  if(dp[i][vis[i]%2]) return dp[i][vis[i]%2];
  if(vis[i]%2 == 0 and i == n) return 1;
  if(vis[i]%2 and p[i] == n+1) return 1;
  int ans = 0;
  if(vis[i]%2 == 0)
    ans = solve(i+1) + 1;
  else
    ans = solve(p[i]) + 1;
  return dp[i][vis[i]%2] = ans;
}

int main(void){
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> p[i];
  cout << solve(1) << endl;
  cerr << "recursion: " << cnt << endl;
}
