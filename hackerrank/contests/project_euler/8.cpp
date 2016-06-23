#include <iostream>
#include <cstdio>

using namespace std;

int solve(string a, int n, int k){
	int ans = 0;
	for (int i = 0; i < n-k+1; i += 1){
		int prod = 1;
		for (int j = i; j < i+k; j += 1){
			prod *= (a[j]-'0');
		}
		if(prod > ans) ans = prod;
	}
	return ans;
}

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		string a;
		cin >> a;
		cout << solve(a, n, k) << endl;
	}
}