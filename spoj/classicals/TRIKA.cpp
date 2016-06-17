#include <iostream>
#include <algorithm>

using namespace std;

int readint(){
	
}

int main(void){
	int n, m;
	cin >> n >> m;
	int x, y;
	cin >> x >> y;
	int a[n][m];
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < m; j += 1){
			cin >> a[i][j];
			// a[i][j] = readint();
		}
	}
	x -= 1;
	y -= 1;
	int dp[n][m];
	dp[x][y] = 0;
	for (int i = y+1; i < m; i += 1){
		dp[x][i] = dp[x][i-1]+a[x][i];
	}
	for(int i = x+1; i < n; i += 1){
		dp[i][y] = dp[i-1][y]+a[i][y];
	}
	for(int i = x+1; i < n; i += 1){
		for (int j = y+1; j < m; j += 1){
			dp[i][j] = min(dp[i-1][j],dp[i][j-1])+a[i][j];
		}
	}
	// cout << "Here is the dp table" << endl;
	// for (int i = 0; i < n; i += 1){
	// 	for (int j = 0; j < m; j += 1){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int ans = dp[n-1][m-1];
	// for (int i = y; i < m; i += 1){
	// 	if (dp[n-1][i] < ans) ans = dp[n-1][i];
	// }
	// cout << "answer is " << ans << endl;
	if(ans > a[x][y]){
		cout << "N" << endl;
	}else{
		cout << "Y " << a[x][y]-ans << endl;
	}
}