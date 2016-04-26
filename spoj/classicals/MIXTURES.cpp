#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

#define pvi pair<vector<int>, int>
#define mp make_pair

using namespace std;

map<pvi, int> store;


int solve(vector<int> a, int n){
	if (store[mp(a, n)]){
		cout << "YES FOUND ONE!" << endl;
		return store[mp(a,n)];
	}
	if (n <= 1) return 0;
	if (n == 2) return a[0]*a[1];
	int x, y, z, first, second;
	x = a[n-3];
	y = a[n-2];
	z = a[n-1];
	a[n-3] += a[n-2];
	a[n-3] %= 100;
	a[n-2] = a[n-1];
	first = solve(a, n-1)+x*y;
	store[mp(a, n-1)] = first;
	a[n-3] = x;
	a[n-2] = y;
	a[n-1] = z;
	x = a[n-2];
	y = a[n-1];
	a[n-2] += a[n-1];
	a[n-2] %= 100;
	second = solve(a, n-1)+x*y;
	store[mp(a,n-1)] = second;
	a[n-2] -= a[n-1];
	return min(first, second);
}

// int solve(int a[], int n){
// 	int dp[n], x, y, z, first, second;
// 	for (int i = 0; i < n; i += 1){
// 		if (i <= 0) dp[i] = 0;
// 		else if (i == 1) {
			
// 			dp[i] = a[0]*a[1];
// 		}else{

// 			x = a[i-3];
// 			y = a[i-2];
// 			z = a[i-1];
// 			a[i-3] += a[i-2];
// 			a[i-3] %= 100;
// 			a[i-2] = a[i-1];
// 			first = dp[i-1]+x*y;
// 			a[i-3] = x;
// 			a[i-2] = y;
// 			a[i-1] = z;
// 			x = a[i-2];
// 			y = a[i-1];
// 			a[i-2] += a[i-1];
// 			a[i-2] %= 100;
// 			second = dp[i-1] + x*y;
// 			a[i-2] -= a[i-1];
// 			dp[i] = min(first, second);
// 		}
// 	}
// 	return dp[n-1];
// }

int main(void){
	int n;
	while (cin >> n){
		store.clear();
		if (!n || n <= 0) break;
		vector<int> a(n);
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		cout << solve(a, n) << endl;
	}
}