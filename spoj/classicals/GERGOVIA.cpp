#include <iostream>


using namespace std;

#define ull long long


// ull abs(ull a){
// 	if (a >= 0) return a;
// 	return -a;
// }

void Print(ull a[], ull n){
	for (ull i = 0; i < n; i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(void){
	ull n;
	while(1){
		cin >> n;
		if (n == 0) break;
		ull a[n];
		for (ull i = 0; i < n; i += 1){
			cin >> a[i];
		}
		// cout << "Here is the pre-array: ";Print(a,n);
		ull ans = 0;
		for (ull i = 0; i < n-1; i += 1){
			ans += abs(a[i]);
			a[i+1] += a[i];
		}
		// cout << "Here is the post-arrya: ";Print(a, n);
		cout << ans << endl;
	}
}