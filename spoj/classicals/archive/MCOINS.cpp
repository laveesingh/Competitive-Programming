#include <iostream>

using namespace std;

int main(void){
	int k, l, m, q;
	cin >> k >> l >> m;
	int dp[1000001];
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < 1000001; i += 1){
		if (i == k || i == l){
			dp[i] = 1;
		}else if (dp[i-1] == 0){
			dp[i] = 1;
		}else if(i-k > 0 && dp[i-k] == 0){
			dp[i] = 1;
		}else if(i-l > 0 && dp[i-l] == 0){
			dp[i] = 1;
		}else{
			dp[i] = 0;
		}
	}
	for (int i = 0; i < m; i += 1){
		cin >> q;
		if (dp[q] == 1){
			cout << "A";
		}else{
			cout << "B";
		}
	}
	cout << endl;
}