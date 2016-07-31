#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int solve(int n, int k){
	int m = n;
	int digit[10]={0};
	int count = 0;
	while (m>0){
		int cur = m%10;
		// cout << cur << " " << n << endl;
		if(cur != 0 && digit[cur] == 0 && n%cur == 0){

			digit[cur] = 1;
			count++;
		}
		m /= 10;
	}
	// if (count >= k)
		// cout << n << " => " << count << endl;
	return count;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int x, y, k;
		cin >> x >> y >> k;
		if(y > 1000000000) return 0;
		int ans = 0;
		for(int i = x; i <= y; i += 1){
			if (solve(i, k) >= k) ans++;
		}
		cout << ans << endl;
	}
}