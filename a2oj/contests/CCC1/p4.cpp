#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n, dist, power;
	cin >> n;
	int a[1000001];
	fill_n(a, 1000001, 0);
	for (int i = 0; i < n; i += 1){
		cin >> dist >> power;
		a[dist] = power;
	}
	int dp[1000001];
	dp[0] = 0;
	for (int i = 1; i < 1000001; i += 1){
		if(!a[i]){
			dp[i] = dp[i-1];
		}else{
			dp[i] = (i-a[i]-1 >= 0 ? dp[i-a[i]-1]+1 : 0);
		}
	}
	int maximum = *max_element(dp, dp+1000001);
	cout << n -maximum-1 << endl;
}