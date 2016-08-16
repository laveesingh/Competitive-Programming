/*input
5
3 10 8 6 11
4
1
10
3
11
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	sort(a, a+n);
	int q, x;
	cin >> q;
	for (int i = 0; i <q; i += 1){
		cin >> x;
		int ind = upper_bound(a, a+n, x)-a;
		cout << ind << endl;
	}
}