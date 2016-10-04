#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
	ll t;
	cin >> t;

	while(t--){
		ll a, b,c,d;
		cin >> a >> b >> c >> d;
		ll ans = 0;
		for(ll i = a; i <= b; i += 1){
			if(c > i){
				ans += d-c+1;
			}else if(i >= d){
				ans += 0;
			}else{
				ans += d-i;
			}
		}
		cout << ans << endl;
	}
}
