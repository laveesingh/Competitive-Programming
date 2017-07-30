#include <iostream>
#include <map>
#include <cstring>
#include <cmath>

#define ll long long

using namespace std;

void Print(long long a[], int n){
	for (int i = 0; i < n; i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

int solve(string a, int n){
	ll dp[n+1];
	ll sum[n+1];
	map<char, int> last;
	dp[0] = 1;
	sum[0] = 1;
	ll tod = 0;
	for (int i = 1; i <= n; i += 1){
		dp[i] = sum[i-1];
		if (last[a[i]] > 0) dp[i] -= sum[last[a[i]] - 1];
		else if(a[0] == a[i]){
			tod += pow(2,i);
		}
		sum[i] = sum[i-1] + dp[i];
		last[a[i]] = i;
	}
	return sum[n]-tod;

}

int main(void){
	int t;
	cin >> t;
	while (t--){
		string a;
		cin >> a;
		cout << solve(a, a.length()) << endl;
	}
}