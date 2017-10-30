#include <bits/stdc++.h>
using namespace std;

map<int, int> dp;
int cnt = 0;
int collatzSequenceLen(int n) {
  cnt++;
    if(dp[n]) return dp[n];
    //cerr << "recursing for " << n << endl;
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        if(not dp[n/2])
            dp[n/2] = collatzSequenceLen(n/2);
        return 1 + dp[n/2];
    }
    if(not dp[3*n+1])
        dp[3*n+1] = collatzSequenceLen(3*n+1);
    return 1 + dp[3*n+1];
}

int collatzSequenceSum(int T, int A, int B) {
    int n = 0;
    int result = 0;
    int mod = 5003;
    for(int i = 0; i <= mod; i++){
        if(not dp[i]) {
            //cerr << "going to set for " << i << " cnt: " << cnt << endl;
            dp[i] = collatzSequenceLen(i);
            //cerr << "set dp state for " << i << endl;
        }
    }
    //cerr << "Dp array follows: " << endl;
    //for(int i = 0; i < 20; i++)
        //cerr << i << ": " << dp[i] << endl;
    int max_to[mod+1];
    max_to[0] = 0;
    for(int i = 1; i <= mod; i++){
        if(dp[i] > dp[max_to[i-1]])
            max_to[i] = i;
        else
            max_to[i] = max_to[i-1];
    }
    //cerr << "max to array " << endl;
    //for(int i = 0; i < 20; i++)
      //cerr << i << ": " << max_to[i] << endl;
    while (T--) {
        n = (A*n + B) % 5003;
        //cerr << "current n: " << n << endl;
        result += (n>0 ? max_to[n] : 0);
    }
    return result;
}

int main() {
    int T;
    int A;
    int B;
    cin >> T >> A >> B;
    int result = collatzSequenceSum(T, A, B);
    cout << result << endl;
    return 0;
}
