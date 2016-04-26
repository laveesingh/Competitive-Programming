#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int min(int a, int b, int c){
	return min(min(a,b),c);
}

int solve(string a, string b, int m, int n){
	int dp[m+1][n+1];
	for (int i = 0; i <= m; i += 1){
		for (int j = 0; j <= n; j += 1){
			if (i == 0){
				dp[i][j] = j;
			}else if(j == 0){
				dp[i][j] = i;
			}else if(a[i-1]==b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}else{
				dp[i][j] = 1 + min(dp[i][j-1],
					dp[i-1][j],
					dp[i-1][j-1]);
			}
		}
	}
	return dp[m][n];
}

int main(void){
	int t;
	scanf("%d",&t);
	// char *a = new char[2000];
	// char *b = new char[2000];
	string sa, sb;	
	while (t--){
		// scanf("%s %s",a, b);
		// sa = a;
		// sb = b;
		cin >> sa >> sb;
		printf("%d\n",solve(sa, sb, sa.length(), sb.length()));
	}
	// delete a;
	// delete b;
}