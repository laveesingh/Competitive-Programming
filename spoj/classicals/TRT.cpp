#include <iostream>
#include <cstdio>
#include <utility>
#include <map>

#define pii pair<int, int>
#define mp make_pair

using namespace std;

int *a;

int store[2001][2001] = {0};

int solve(int n, int m, int age){
	if (store[n][m]) return store[n][m];
	if (n == m) 
		return age*a[n];
	long long temp1 = solve(n+1, m, age+1);
	store[n+1][m] = temp1;
	long long temp2 = solve(n, m-1, age+1);
	store[n][m-1] = temp2;
	return max(age*a[n] + temp1,
		age*a[m] + temp2);
}

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

// int solve(){
// 	int age = 1;
// 	int dp[n+1][m+1];
// 	for (int i = 0; i <= n; i += 1){
// 		for (int j = 0; j <= m; j += 1){
// 			if (i == j){
// 				dp[i][j] = age*a[i];
// 			}else{
// 				dp[i][j] = max(age*a[i] + dp[i+1])
// 			}
// 		}
// 	}
// }

int main(void){
	int n;
	scanf("%d", &n);
	a = new int[n];
	for (int i = 0; i < n; i += 1){
		scanf("%d", &a[i]);
		// cin >> a[i];
	}
	// cout << solve(0, n-1, 1) << endl;
	printf("%d\n", solve(0,n-1,1));

}