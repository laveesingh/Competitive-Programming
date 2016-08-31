/*input
7 6
1 3 2 4 3 2 4
*/

#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define inf INT_MAX

int n, k;

int main(void){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	map<int, int> d;
	for (int i = 0; i < n ;i += 1){
		int x = (i < n/2 ? i+1 : n-i);
		if (!d[a[i]]){
			d[a[i]] = x;
		}else{
			d[a[i]] = min(d[a[i]], x);
		}
	}
	// cout << "Min weights: " << endl;
	// for (int i = 0; i < n; i += 1){
	// 	cout << a[i] << ": " << d[a[i]] << endl;
	// }
	int ans = inf;
	for (int i = 0; i < n; i += 1){
		if(d[k-a[i]] and a[i] != (k-a[i])){
			ans = min(ans, max(d[a[i]],d[k-a[i]]));
		}
	}
	cout << (ans == inf ? -1 : ans) << endl;

}