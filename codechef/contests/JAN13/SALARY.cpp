#include <iostream>
#include <algorithm>

using namespace std;

#define input(a,n) for(int i = 0; i < n; i += 1) cin >> a[i]

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int a[n];
		// for (int i = 0; i < n; i += 1){
		// 	cin >> a[i];
		// }
		input(a,n);
		int sum = accumulate(a, a+n, 0);
		int minimum = *min_element(a, a+n);
		cout << (sum-minimum*n) << endl;
	}
}