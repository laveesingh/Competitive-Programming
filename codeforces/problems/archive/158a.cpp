#include <iostream>
#include <array>

using namespace std;

int main(void){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int kk = a[k-1];
	int ans = 0;
	for (int i = 0; i < n; i += 1){
		if (a[i] >= kk and a[i] > 0){
			ans += 1;
		}
	}
	cout << ans << endl;
}