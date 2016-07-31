#include <cstdio>

using namespace std;

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0;i < n; i += 1){
			scanf("%d", &a[i]);
		}
		int dp[n];
		dp[0] = a[0];
		for(int i = 1; i < n; i += 1){
			dp[i] = dp[i-1]^a[i];
		}
		int q, x, y;
		scanf("%d", &q);
		for(int i = 0; i < q; i += 1){
			scanf("%d %d", &x, &y);
			if(x == 0){
				printf("%d\n", dp[y]);
			}else{
				printf("%d\n", dp[x-1]^dp[y]);
			}
		}
	}
}