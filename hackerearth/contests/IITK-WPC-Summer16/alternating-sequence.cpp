#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;


int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int dp[n];
	fill_n(dp, n, 1);
	dp[0] = 1;
	for (int i = 1; i < n; i += 1){
		for (int j = 0; j < i; j += 1){
			// cout << (a[i]^a[j]) << " " << abs(a[i]) << " " << abs(a[j]) << endl;
			if((a[i]^a[j]) < 0 && abs(a[j]) < abs(a[i])){
				// cout << "Coming in " << endl;
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
	}
	// for (int i = 0; i < n; i += 1){
	// 	cout << dp[i] << " ";
	// }
	cout <<  *max_element(dp, dp+n) << endl;
}