#include <iostream>
#include <cstdio>
#include <cstring> 

using namespace std;

#define ull unsigned long long

int ans = 0;
int temp;
// int solve(string a, int n){
// 	if (n <= 0) return 0;
// 	if (n == 1) {
// 		// ans += 1;
// 		return 1;

// 	}
// 	else{
// 		if (a[n-2] > '2'){
// 			// ans += 1+solve(a,n-1);
// 			return 1+solve(a,n-1);
// 		}else if(a[n-2]=='2' && a[n-1] > '6'){
// 			// ans += 1+solve(a,n-1);
// 			return 1+solve(a,n-1);
// 		}else{

// 			temp =  max(1+solve(a,n-1),1+solve(a,n-2));
// 			ans += temp;
// 			return temp;
// 		}
// 	}
// }


ull dp[5001];
string a;

ull solve(int n){
	memset(dp, 0, 5001);
	dp[0] = 1;
	for (int i = 1; i <n; i += 1){
		int x = (a[i-1]-'0')*10 + (a[i]-'0');
		if (a[i]-'0') dp[i] = dp[i-1];
		if (x >= 10 && x <= 26){
			dp[i] += dp[(i-2)<0 ? 0 : (i-2)];
		}
	}
	return dp[n-1];
}

int main(void){
	while (1){
		cin >> a;
		if (a[0] == '0') break;
		// dp = new ull[a.length()];
		cout << solve(a.length()) << endl;
		// delete[] dp;
	}

}