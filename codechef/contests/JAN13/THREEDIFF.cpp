#include <iostream>
#include <algorithm>

using namespace std;

#define ull unsigned long long

#define MOD 1000000007

int main(void){
	ull t;
	cin >> t;
	while(t--){
		ull n1, n2, n3;
		cin >> n1 >> n2 >> n3;
		ull a[] = {n1, n2, n3};
		sort(a, a+3);
		ull ans = 1;
		for (ull i = 0; i < 3; i += 1){
			ans = (ans*((a[i]-i)%MOD))%MOD;
		}
		cout << ans << endl;
	}
}