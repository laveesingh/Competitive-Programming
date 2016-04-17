#include <bits/stdc++.h>


using namespace std;

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

void solve(int n, int w, int val[], int weight[]){
	int dp[2][w+1];
	for (int i = 0; i < 2; i += 1){
		for (int j = 0; j < w+1; j += 1){
			dp[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i += 1){
		for (int j = 1; j <= w; j += 1){
			if (i%2){
				if (weight[i-1] > j){
					dp[1][j] = dp[0][j];
				}else{
					dp[1][j] = max(val[i-1]+dp[0][j-weight[i-1]], dp[0][j]);
				}
			}else{
				if (weight[i-1] > j){
					dp[0][j] = dp[1][j];
				}else{
					dp[0][j] = max(val[i-1]+dp[1][j-weight[i-1]], dp[1][j]);
				}
			}
			// if (i == 0 || j == 0){
			// 	dp[i%2][j] = 0;
			// }else if(weight[i-1] > j){
			// 	dp[(i%2)][j] = dp[(i%2)^1][j];
			// }else{
			// 	dp[i%2][j] = max(val[i-1]+dp[(i%2)^1][j-weight[i-1]], dp[(i%2)^1][j]);
			// }
		}
	}
	int ans;
	if (n%2) ans = dp[1][w];
	else ans = dp[0][w];
	printf("%d\n", ans);
}

int main(void){
	int t, n, w;
	scanf("%d %d", &w, &n);
	int val[n];
	int weight[n];
	for (int i = 0; i < n; i += 1){
		scanf("%d %d", &val[i], &weight[i]);
	}
	solve(n, w, val, weight);
		

}