/*input
2
3
1 1 1
2 3 1000
ARM
4
1 2 3 4
0 1 1000
AMAM
*/

#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll multmod(ll a, ll b, ll c){
	if (b == 0) return 0;
	if (b == 1) return (a%c);
	if (b%2) return (a+multmod(a, b-1, c))%c;
	ll x = multmod(a, b/2, c);
	return (x+x)%c;
}

int main(void){
	ios::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--){
		ll n, a, b, c;
		string ram;
		cin >> n;
		ll L[n];
		for (ll i = 0; i < n; i +=1){
			cin >> L[i];
		}
		cin >> a >> b >> c;
		cin >> ram;
		// cout << "Input taken successful" << endl;
		ll add, mult;
		add = 0, mult = 1;
		ll direction = 1;
		ll begin = 0, end = n-1;
		ll newL[n];
		for (ll i = 0; i < n; i += 1){
			// if (i%1 == 0) cout << i << endl;
			if(ram[i] == 'R'){
				// cout << "F" << endl;
				swap(begin, end);
				direction = -direction;
				newL[i] = (multmod(L[begin], mult, c) + add)%c;
			}else if(ram[i] == 'A'){
				add = (add+a)%c;
				// cout << "Added to be " << add << endl;
				newL[i] = (multmod(L[begin], mult, c) + add)%c;
			}else{
				mult = multmod(mult, b, c);
				add = multmod(add, b, c);
				// cout << "Mult to be " << mult << " and added to be " << add << endl;
				newL[i] = (multmod(L[begin], mult, c) + add)%c;
			}
			begin += direction;
		}
		for (ll i = 0; i < n; i += 1){
			cout << newL[i] << " ";
		}
		cout << endl;
	}
}