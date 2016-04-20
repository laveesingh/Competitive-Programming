#include <cstdio>

int *val, *weight;

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

int solve(int n, int w){
	int dp[2][w+1];
	for (int i = 0; i <= n; i += 1){
		for (int j = 0; j <= w; j += 1){
			if (i%2 == 0){
				if (i == 0 || j == 0) dp[0][j] = 0;
				else if(weight[i-1] > j) dp[0][j] = dp[1][j];
				else dp[0][j] = max(val[i-1]+dp[1][j-weight[i-1]],dp[1][j]);
			}else{
				if (i == 0 or j == 0) dp[1][j] = 0;
				else if (weight[i-1] > j)
					dp[1][j] = dp[0][j];
				else
					dp[1][j] = max(val[i-1]+dp[0][j-weight[i-1]],dp[0][j]);
			}
		}
	}
	for (int i = 0; i <= w; i += 1){
		printf("%d ",dp[n%2][i]);
	}
	printf("\n");
	return dp[n%2][w-1]!=dp[n%2][w] ? dp[n%2][w] : -1;
}

int main(void){
	int n, w;
	scanf("%d %d",&n,&w);
	val = new int[n];
	weight = new int[n];
	for (int i = 0; i < n ; i += 1){
		scanf("%d %d", &val[i], &weight[i]);
	}
	int ans = solve(n, w);
	if (ans == -1){
		printf("Got caught!\n");
	}else{
		printf("%d\n",ans);
	}
}