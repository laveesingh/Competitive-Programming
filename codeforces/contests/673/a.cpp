#include <iostream>
#include <algorithm>

using namespace std;

int solve(int a[], int n){
	int li = 0;
	for (int i = 0; i < n; i += 1){
		if (a[i] - li > 15){
			return min(li+15, 90);
		}else{
			li = a[i];
		}
	}
	return min(li+15, 90);
}

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	cout << solve(a, n) << endl;
}