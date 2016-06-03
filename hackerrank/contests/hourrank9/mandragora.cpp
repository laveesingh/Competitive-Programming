#include <iostream>
#include <map>
#include <utility>

using namespace std;

#define mp make_pair
#define pii pair<int, int>

int *h;

// map<pii, int> store;


// int solve(int n, int s = 1, int p = 0){
// 	// if (store[mp(n,p)]) return store[mp(n,p)];
// 	if(n == 0){
// 		return p;
// 	}
// 	int x = solve(n-1, s, p+s*h[n-1]);
// 	s += 1;
// 	int y = solve(n-1, s, p);
// 	// return store[mp(n,p)] = max(x, y);
// }

int solve(int n, int s = 1, int p = 0){
	int dp[n+1];
	dp[0] = 0;
	for (int i = 1; i <= n; i += 1){
		dp[i] = max(dp[i]+s*h[i-1]);
	}
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		store.clear();
		int n;
		cin >> n;
		h = new int[n];
		for (int i = 0; i < n; i += 1){
			cin >> h[i];
		}
		cout << solve(n, 1, 0) << endl;

	}
}