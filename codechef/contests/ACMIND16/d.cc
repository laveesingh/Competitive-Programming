#include <iostream>
#include <algorithm>


using namespace std;

const int N = 8e5;
const int MOD = 1e9 + 7;

int main(void){
  int t;
  cin >> t;
  int n;
  while(t--){
    cin >> n;
    int a[n];
    for(int i =0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    reverse(a, a+n);
    int dp[N];
    for(int i = 0; i < N; i++) dp[i] = 0;
    for(int i = 0; i < n; i){
      dp[a[i]] = 1;
      for(int j = 2*a[i]; j < N; j += a[i]){
        dp[a[i]] = (dp[a[i]] + dp[j]) % MOD;
      }
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
      sum = (sum + dp[a[i]]) % MOD;
    cout << sum << endl;
  }

}
