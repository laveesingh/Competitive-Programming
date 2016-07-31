#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
	ios::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;

	ll rows[n], cols[n];
	fill_n(rows, n, 0);
	fill_n(cols, n, 0);

	ll ans = n*n;
	ll i, j;
	ll crows = 0, ccols = 0;
	for(ll pos = 0; pos < m; pos++){
		cin >> i >> j;
		i--;
		j--;
		ll attacker = 2*n - 1;

		if(rows[i] and cols[j]){
			attacker = 0;
		}else if(rows[i]){
			attacker -= (n + crows - 1);
			ccols += 1;
			cols[j] = 1;
		}else if(cols[j]){
			attacker -= (n + ccols - 1);
			crows += 1;
			rows[i] = 1;
		}else{
			attacker -= (crows + ccols);
			crows += 1;
			ccols += 1;
			rows[i] = 1;
			cols[j] = 1;
		}
		ans -= attacker;
		cout << ans << " ";
	}
	cout << endl;
}