#include <iostream>

using namespace std;

int *a;
bool solve(int x, int k){
	for (int i = 1; i <= k; i += 1){
		a[i] += a[i-1];
	}
	bool ans[x+1];
	ans[0] = true;
	for (int i = 1; i <= x; i += 1) ans[i] = false;
	for (int i = 1; i <= x; i += 1){
		for (int j = a[i]; j <= x; j += 1){
			ans[j]= ans[j] || ans[j-a[i]];
		}
	}
	return ans[x];
}

int main(void){
	int x, k;
	a = new int[k];
	cin >> x >> k;
	for (int i = 0; i < k ; i += 1){
		cin >> a[i];
	}
	cout << (solve(x, k) ? "YES" : "NO" )<< endl;
}
