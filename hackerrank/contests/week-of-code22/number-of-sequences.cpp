#include <bits/stdc++.h>

using namespace std;

int is_nice(int a[], int n){
	for (int k = 1; k <= n; k += 1){
		for (int m = k; m <= n; m += k){
			if (a[k]%k == a[m]){
				// do nothing
			}else{
				return 0;
			}
		}
	}
	return 1;
}

int main(void){
	ios::sync_with_stdio(false);
	int n = 5;
	int a[] = {0, 1, 2, 3, 4};
	cout << is_nice(a, n) << endl;
	cout << "Didn't work" << endl;
}