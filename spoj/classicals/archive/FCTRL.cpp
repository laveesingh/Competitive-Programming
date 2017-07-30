#include <iostream>

using namespace std;

int solve(int n){
	int ans = 0;
	while (n > 0){
		ans += n / 5;
		n  /= 5;
	}
	return ans;
}

int main(void){
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		cout << solve(n) << endl;
	}
}