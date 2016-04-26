#include <iostream>
#include <cstdio>

using namespace std;

int *a;

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

// int solve(int n){
// 	if (n == 1) return a[n-1];
// 	if (n == 2) return max(a[n-1], a[n-2]);
// 	return max(solve(n-1), a[n-1]+solve(n-2));
// }

long long solve(int n){
	long long dp[n+1];
	for (int i = 0; i <= n; i += 1){
		if (i == 0){
			dp [i] = 0;
		}else if (i == 1){
			dp[i] = a[i-1];
		// }else if(i == 2){
		// 	dp[i] = max(a[i-1], a[i-2]);
		}else{
			dp[i] = max(dp[i-1], a[i-1]+dp[i-2]);
		}
	}
	return dp[n];
}

int main(void){
	int t, n;
	cin >> t;
	for (int j = 0; j < t; j += 1){
		cin >> n;
		a = new int[n];
		for (int i = 0 ; i < n; i +=1){
			cin >> a[i];
		}
		 // cout << "Case " << j+1 << ": " << solve(n) << endl;
		 printf("Case %d: %lld\n",j+1, solve(n));

	}
}