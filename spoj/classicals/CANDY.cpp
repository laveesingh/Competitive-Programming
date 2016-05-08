#include <iostream>
#include <numeric>

using namespace std;

#define FOR(i) for(int i = 0; i < n; i += 1)

int main(void){
	int n;
	while (1){
		cin >> n;
		if (n == -1) break;
		int a[n];
		FOR(i){
			cin >> a[i];
		}
		int sum = accumulate(a, a+n, 0);
		if (sum % n != 0){
			cout << -1 << endl;
		}else{
			int pp = sum/n;
			int ans = 0;
			FOR(i){
				if (a[i] > pp) ans += a[i]-pp;
			}
			cout << ans << endl;
		}

	}
}