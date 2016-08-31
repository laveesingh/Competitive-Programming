/*input
3

61 0 41

11 31 51

21 71 1
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main(void){
	ios::sync_with_stdio(false);
	ll n;
	cin >> n;
	if (n == 1){
		cout << 1 << endl;
		return 0;
	}
	ll a[n][n], indi, indj;
	for (ll i = 0; i < n; i += 1){
		for (ll j = 0; j < n; j += 1){
			cin >> a[i][j];
			if (a[i][j] == 0){
				indi = i;
				indj = j;
			}
		}
	}
	
	ll Sum = 0, tofill, have;
	Sum = indi == 0 ? accumulate(a[n-1], a[n-1]+n, (ll)0) : accumulate(a[0], a[0]+n, (ll)0);
	have = 0;
	have = accumulate(a[indi], a[indi]+n, (ll)0);
	tofill = Sum-have;
	// cout << "SUm is " << Sum << " Tofill " << tofill << endl;
	a[indi][indj] = tofill;
	for (ll i = 0; i < n; i += 1){
		if(accumulate(a[i],a[i]+n, (ll)0) != Sum){
			cout << -1 << endl;
			return 0;
		}
	}
	for (ll i = 0; i < n; i += 1){
		ll cols = 0;
		for (ll j = 0; j < n; j += 1){
			cols += a[j][i];
		}
		if (cols != Sum){
			cout << -1 << endl;
			return 0;
		}
	}
	ll diags = 0;
	for (ll i = 0; i < n; i += 1){
		diags += a[i][i];
	}
	if (diags != Sum){
		cout << -1 << endl;
		return 0;
	}
	diags = 0;
	for (ll i = 0; i < n; i += 1){
		diags += a[i][n-i-1];
	}
	if(diags != Sum){
		cout << -1 << endl;
		return 0;
	}
	if (tofill <= 0){
		cout << -1 << endl;
	}else{
		cout << tofill << endl;
	}

}