/*input
2
5 1 5 1
10 2 2 2
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
	ios::sync_with_stdio(false);
	ll t, l, d, s, c, likes;
	cin >> t;
	string ans;
	while(t--){
		cin >> l >> d >> s >> c;
		ans = l > s ? "DEAD AND ROTTING" : "ALIVE AND KICKING";
		while(d > 1){
			s *= (1+c);
			if (s >= l){
				ans = "ALIVE AND KICKING";
				break;
			}
			d -= 1;
		}
		cout << ans << endl;
	}

}