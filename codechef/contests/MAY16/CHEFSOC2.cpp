#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007

int n, m, s;
int **dp, *a;



int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m >> s;
		s -= 1;
		a = new int[m];
		for(int i = 0; i < m; i += 1){
			cin >> a[i];
		}
		dp = new int*[n];
		for (int i = 0; i < n; i +=1){
			dp[i] = new int[m+1];
			fill_n(dp[i], m, 0);
		}

		for (int j = 0; j <= m; j += 1){
			for (int i = 0; i < n; i += 1){
				if(j == 0){
					dp[i][j] = s==i;
					// cout << "dp[i][0] is set to " << dp[i][j] << endl;
				}else{
					if(i-a[j-1]>=0) dp[i][j] += dp[i-a[j-1]][j-1];
					if(i+a[j-1]<n) dp[i][j] += dp[i+a[j-1]][j-1];
					dp[i][j] %= mod;
				}
			}
		}
		// for (int i = 0; i < n; i += 1){
		// 	for (int j = 0; j <= m; j += 1){
		// 		cout << dp[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		for (int i = 0; i < n; i += 1){
			cout << dp[i][m] << " ";
		}
		cout << endl;
	}
}