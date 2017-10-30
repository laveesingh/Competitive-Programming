#include <bits/stdc++.h>

using namespace std;

const int N = 8010;
int dp[N][4];

bool isprime(int n){
  for(int i = 2; i <= sqrt(n); i++)
    if(n%i == 0) return false;
  return true;
}

int main(void){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  set<int> sprimes;
  for(int i = 1; i <= 100; i++)
    for(int j = 1; j <= 100; j++)
      if(isprime(i*i + j*j))
        sprimes.insert(i*i + j*j);
  vector<int> vprimes(sprimes.begin(), sprimes.end());
  sort(vprimes.begin(), vprimes.end());
  for(int n = 0; n < N; n++)
    for(int i = 1; i < 4; i++){
      if(n == 0 or n == 1 or i == 1) dp[n][i] = 1;
      else if(i == 2) dp[n][i] = dp[n-1][1] + (n>=2 ? dp[n-2][2]: 0);
      else if(i == 3) dp[n][i] = dp[n-1][1] + (n>=2 ? dp[n-2][2]: 0) + (n>=3 ? dp[n-3][3]: 0);
    }
  //for(int n = 1; n < 10; n++){
    //cerr << n << ": ";
    //for(int i = 1; i < 4; i++)
      //cerr << dp[n][i] << " ";
    //cerr << endl;
  //}
  int t, n, k;
  cin >> t;
  while(t--){
    cin >> n >> k;
    n--;
    n = vprimes[n];
    cout << dp[n][k] << endl;
  }
}

