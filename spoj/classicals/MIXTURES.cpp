#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define pvi pair<vector<int>, int>
#define mp make_pair
#define ull unsigned long long
#define INF 1000000000

using namespace std;

int dp[105][105];
int *a;

ull msum(int i, int j){
	ull sum = 0;
	for (int k = i; k <= j; k += 1){
		sum += a[k];
	}
	return sum%100;
}

ull solve(int n){
	ull count;
	int j;
	for (int i = 1; i < n; i += 1){
		dp[i][i] = 0;
	}
	for (int l = 2; l <= n; l += 1){
		for (int i = 1; i <= n-l+1; i += 1){
			j = i+l-1;
			// if (i == 0 || j == 0)dp[i][j] = 0;
			if (i == j) dp[i][j] = 0;
			else{
				count = INF;

				for (int k = i; k < j; k += 1){
					ull temp = dp[i][k] + dp[k+1][j] + msum(i,k)*msum(k+1,j);
					if (temp < count ) count = temp;
				}
				dp[i][j] = count;
			}

		}
	}
	return dp[1][n];
}

int main(void){
	int n;
	while (cin >> n){
		// cin >> n;
		a = new int[n+1];
		// dp = new int*[n];
		// for (int i = 0; i <= n; i += 1){
		// 	dp[i] = new int[n];
		// }
		for (int i = 0; i < n; i += 1){
			cin >> a[i+1];
		}
		cout << solve(n) << endl;
		delete[] a;

	}
}