#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int **dp;

int main(void){
	int k;
	char a[2001], b[2001];
	scanf("%s", a);
	scanf("%s", b);
	scanf("%d", &k);
	
	int n = 0;
	while(a[n] != '\0'){
		n += 1;
	}
	int m = 0;
	while(b[m] != '\0'){
		m += 1;
	}
	dp = new int*[n+1];
	for(int i = 0; i <= n; i += 1){
		dp[i] = new int[m+1];
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i += 1){
		dp[i][0] = i*k;
	}
	for(int j = 1; j <= m; j += 1){
		dp[0][j] = j*k;
	}
	for(int i = 1; i <=  n; i += 1){
		for (int j = 1; j <= m; j +=1){
			dp[i][j] = min(min(k+dp[i-1][j], k+dp[i][j-1]), dp[i-1][j-1]+abs(a[i-1]-b[j-1]));
		}
	}
	printf("%d\n", dp[n][m]);
}
