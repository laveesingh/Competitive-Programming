/*input
4
1 1 1 12
4 5 6 0
*/

#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[n], b[n];
	for (ll i = 0; i < n; i += 1){
		cin >> a[i];
	}	
	for (ll i = 0; i < n; i +=1){
		cin >> b[i];
	}

	sort(a, a+n);
	sort(b, b+n);
	ll pos = 0, neg = 0;
	for (ll i = 0; i < n; i += 1){
		if (a[i] < b[i]){
			// cout << "F" << endl;
			pos += abs(b[i]-a[i]);
		}else if(a[i] > b[i]){
			// cout << "S" << endl;
			neg += abs(a[i]-b[i]);
		}else{
			// elements are equal so do nothing
		}
	}
	// cout << "pos " << pos << " neg " << neg << endl;
	if (pos == neg){
		cout << pos << endl;
	}else{
		cout << -1 << endl;
	}
}