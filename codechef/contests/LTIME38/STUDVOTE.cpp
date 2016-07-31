#include <bits/stdc++.h>

using namespace std;

#define inf INT_MAX

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int temp, n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
			a[i]--;
		}
		int elig[n];
		fill_n(elig, n, 0);
		for (int i = 0; i < n; i += 1){
			if (a[i] == i) elig[i] = -inf;
			else{
				elig[a[i]]++;
			}
		}
		int ans = 0;
		// for (int i = 0; i < n; i += 1){
		// 	cout << a[i] << " ";
		// }
		// cout << endl;
		for (int i = 0; i < n; i += 1){
			// cout << elig[i] << " ";
			if(elig[i] >= k) ans++;
		}
		// cout << endl << ans << endl;
		cout << ans << endl;	
	}
}