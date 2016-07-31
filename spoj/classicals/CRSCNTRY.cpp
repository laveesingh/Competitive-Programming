#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// int *a, *b;
vector<int> a, b;


int lcs(int n, int m){
	int dp[n+1][m+1]; // n is length of a and m is length of b
	for (int i = 0; i <= n; i += 1){
		for (int j = 0; j <= m; j += 1){
			if (i == 0 || j == 0){
				dp[i][j] = 0;
			}else{
				if (a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1] + 1;
				}else{
					dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
				}
			}
		}
	}
	// for (int i = 0; i <= n; i += 1){
	// 	for (int j = 0; j <= m; j += 1){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	return dp[n][m];
}

int main(void){
	int d, temp;
	cin >> d;
	while (d--){
		// cin >> temp;
		// if (temp == 0) break;

		while (1){
			cin >> temp;
			if (temp == 0) break;
			a.push_back(temp);
		}
		int max = 0;
		while (1){

			cin >> temp;
			if (temp == 0) break;
			b.push_back(temp);
			while (1){
				cin >> temp;
				if (temp ==0) break;
				b.push_back(temp);
			}
			int n = a.size();
			int m = b.size();
			int ans = lcs(n, m);
			// cout << ans << endl;
			b.clear();
			if (ans > max) max = ans;
		}
		cout << max << endl;
		a.clear();
	}
}