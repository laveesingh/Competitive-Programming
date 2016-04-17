#include <cstdio>
using namespace std;
int max(int a, int b){
	if (a > b) return a;
	return b;
}

int solve(int n, int k){
	int dp[n+1][k+1];
	for (int i = 0; i <= n; i += 1){
		for (int j = 0; j <= k; j += 1){
			if (j == 0 || j == 1 || i == 1){
				dp[i][j] = j;
			}else{
				dp[i][j] = 10000000;
				for (int x = 1; x < j+1; x += 1){
					int temp = max(dp[i-1][x-1], dp[i][j-x]);
					if (temp < dp[i][j]) dp[i][j] = temp;
				}
				dp[i][j] += 1;
			}
		}
	}
	return dp[n][k];
}

int main(void){
	int t, num, n, k;
	scanf("%d", &t);
	for (int i = 1; i <= t; i += 1){
		scanf("%d %d %d", &num, &n, &k);
		printf("%d %d\n", num, solve(n, k));
	}
}