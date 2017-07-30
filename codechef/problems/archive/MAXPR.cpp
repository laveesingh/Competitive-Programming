#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int pow(int a, int p){
	if(p == 0) return 1;
	if(p == 1) return a;
	if(p%2) return (a*pow(a,p-1))%mod;
	int x = pow(a, p/2);
	return (x*x)%2;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		int ans = 0;
		for(int diff = -100; diff <= 100; diff += 1){
			vector<int> sum(101, 0);
			vector<int> dp(n, 0);
			int cur = 0;
			for(int i = 0; i < n; i += 1){
				if(a[i]-diff >= 1 and a[i]-diff <= 100){
					dp[i] = sum[a[i]-diff]+1;
					dp[i] %= mod;
				}
				sum[a[i]] += dp[i];
				sum[a[i]] %= mod;
				cur += dp[i];
				cur %= mod;
			}
			ans += cur;
			ans -= n;
			ans %= mod;
		}
		ans = (ans+n)%mod;
		// ans = (pow(2,n)-1-ans)%mod;
		cout << ans << endl;
	}
}