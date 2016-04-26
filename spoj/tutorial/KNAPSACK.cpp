#include <cstdio>

using namespace std;

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

int solve(int n, int w, int val[], int weight[]){
	int dp[n+1][w+1];
	// for (int i = 0; i <= n; i += 1){
	// 	for (int j = 0; j <= w; j += 1){
	// 		dp[i][j] = 0;
	// 	}
	// }
	// for (int i = 0; i <= n; i += 1){
	// 	for (int j = 0; j <= w; j += 1){
	// 		printf("%d ", dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for (int i = 0; i <= n; i += 1){
		for (int j = 0; j <= w; j += 1){
			if (i == 0 || j == 0){
				dp[i][j] = 0;
			}else if(weight[i-1] > j){
				dp[i][j] = dp[i-1][j];
			}else{
				dp[i][j] = max(val[i-1]+dp[i-1][j-weight[i-1]], dp[i-1][j]);
			}
		}
	}
	// int i = w;
	// while (dp[n][i-1] == dp[n][w]) i -= 1;

	// for (int i = 0; i <= n; i += 1){
	// 	for (int j = 0; j <= w; j += 1){
	// 		printf("%d ", dp[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// return dp[n][w];
	printf("%d\n", dp[n][w]);
}

int main(void){
	int t, n, w;
	// scanf("%d", &t);
	// while(t--){
		scanf("%d %d", &w, &n);
		int val[n];
		int weight[n];
		for (int i = 0; i < n; i += 1){
			scanf("%d %d", &weight[i], &val[i]);
		}
		solve(n, w, val, weight);
		// printf("%d\n", solve(n, w, val, weight));
		// scanf("%d %d", &w, &n);
	// }

}