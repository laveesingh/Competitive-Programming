#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

int solve(int arr[], int brr[], int n){
	vector<int> dp(n);
	vector<int> a(n);
	for (int i = 0; i < n; i += 1){
		dp[arr[i]] = i;
	}
	for (int i = 0; i < n; i += 1){
		a[i] = dp[brr[i]];
	}
	vector <int> d(n+1, 1000000000);
	for (int i = 0; i <= n; i += 1){
		*lower_bound(d.begin(), d.end(), a[i]) = a[i];
	}
	for (int i = 0; i <= n; i += 1){
		if (d[i] == 1000000000){
			return i;
		}
	}
	return 1;
}

int main(void){
	int t, n;
	scanf("%d", &t);
	while (t--){
		scanf("%d", &n);
		int arr[n];
		int brr[n];
		for (int i = 0; i < n; i += 1){
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < n; i += 1){
			scanf("%d", &brr[i]);
		}
		printf("%d\n",solve(arr, brr, n));
	}
}