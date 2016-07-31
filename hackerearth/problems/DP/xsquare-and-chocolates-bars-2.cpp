#include <iostream>
#include <algorithm>

using namespace std;

int solve(string a, int n){
	int dp[n]={0};
	for (int i = 2; i < n ; i += 1){
		if (a[i] == a[i-1] && a[i] == a[i-2]){
			// Do nothing
		}else{
			dp[i] = 3 + (i-3 >= 0 ? dp[i-3] : 0);
		}
	}
	return *max_element(dp, dp+n);
}

int main(void){
	int t;
	string a;
	cin >> t;
	while (t--){
		cin >> a;
		cout << a.length()-solve(a, a.length()) << endl;
	}
}