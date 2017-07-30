#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
stringstream answer;

void solve(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int dp[n+1];
	dp[0] = 0;
	for (int i = 1; i <= n; i += 1){
		if (a[i-1] <= k){
			dp[i] = a[i-1];
		}else{
			dp[i] = 0;
		}
		int maxx1 = 0, maxx2 = 0;
		// print "For number ",a[i-1]
		// cout << "For number " << a[i-1];
		for (int j = 0; j < i-2; j += 1){
			if (dp[i]+a[j] <= k){
				maxx1 = max(a[j], maxx1);
			}
		}
		for (int j = 0; j < i-1; j += 1){
			if (dp[i]+dp[j] <= k){
				maxx2 = max(dp[j], maxx2);
			}
		}
		// cout <<  "Found max" << maxx << endl;
		dp[i] += max(maxx1, maxx2);
		dp[i] = max(dp[i], dp[i-1]);
	}
	// for (int i = 0; i <= n; i += 1){
	// 	cout << dp[i] << " ";
	// }
	// cout << endl;
	answer <<  dp[n] << endl;;

}

int main(void){

	int t;
	cin >> t;
	for(int i = 1; i <= t; i += 1){
		answer << "Scenario #"<<i<<": ";
		solve();
	}
	cout << answer.str() << endl;

}