#include <cstdio>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i<n; i += 1){
		scanf("%d", &a[i]);
	}
	if(a[0] > a[n-1]){
		reverse(a,a+n);
	}
	int dp[n];
	dp[0] = 1;
	for (int i = 1; i < n; i += 1){
		if(a[i] > a[i-1]){
			dp[i] = dp[i-1] + 1;
		}else{
			dp[i]  = 1;
			int j = i-1;
			// printf("Value of i is %d, j is %d, a[i] is %d, a[j] is %d, and dp[j] is %d and dp[i] is %d\n", i, j, a[i], a[j], dp[j], dp[i]);
			while(j >= 0 && a[j] > a[j+1] && dp[j]<=dp[j+1]){
				// printf("i=%d and j=%d, Dp table till now: \n", i, j);
				// for (int i = 0; i < n; i += 1){
				// 	printf("%d ", dp[i]);
				// }
				// printf("\n");
				// printf("Went into the while loop\n");
				dp[j--]++;
			}
		}
	}
	// printf("Here is the dp array: " );
	// for (int i = 0; i < n; i += 1){
	// 	printf("%d ", dp[i]);
	// }
	printf("%lld\n",accumulate(dp, dp+n, (long long)0));;
}