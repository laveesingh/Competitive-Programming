#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	int ans = 0;
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	sort(a, a+n);
	for (int i = 0; i < n-1; i += 1){
		if (a[i] < a[i+1]) ans += 1;
	}
	cout << ans << endl;
}