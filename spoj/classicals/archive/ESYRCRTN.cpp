#include <iostream>

using namespace std;

#define ull unsigned long long

int f(ull n){
	int a[] = {-2, 1, 3, 2, -1, -3};
	return a[n%6];
}

int main(void){
	int t;
	ull n;
	cin >> t;
	while(t--){
		cin >> n;
		n %= 6;
		int ans = 0;
		for (int i = 1; i <= n; i += 1){
			ans += f(i);
		}
		cout << ans << endl;
	}
}