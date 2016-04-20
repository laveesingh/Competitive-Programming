#include <iostream>
using namespace std;

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

int **dp;

int lcs(string a, string b){
	// cout << "a: " << a << " b: " << b << endl;; 
	int n = a.length();
	int m = a.length();
	for (int i = 0; i <= m; i += 1){
		for (int j = 0; j <= n; j += 1){
			if (i == 0 || j == 0) dp[i][j] = 0;
			else if (a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1]+1;
			}else{
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	// for (int i = 0; i <= n; i += 1){
	// 	for (int j = 0; j <=n ;j += 1){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "The length of the lcs is : ", dp[n][m];
	return dp[n][m];
}

int solve(string a){
	string b = "";
	for (int i = a.length()-1; i > -1; i -= 1){
		b.push_back(a[i]);
	}
	return a.length()-lcs(a,b);
}

int main(void){
	int t;
	string a;
	cin >> t;
	while (t--){
		cin >> a;
		dp = new int*[a.length()+1];
		for (int i = 0; i <= a.length(); i += 1){
			dp[i] = new int[a.length()+1];
		}
		cout << solve(a) << endl;
	}
}