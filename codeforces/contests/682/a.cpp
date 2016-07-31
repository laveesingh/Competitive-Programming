#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long

int main(void){
	ll n, m;
	cin >> n >> m;
	ll a[n+1];
	fill_n(a, n+1, 0);
	a[0] = 0;
	ll ans = 0;
	if (n+m < 5){
		cout << 0 << endl;
	}else{
		a[0] = m/5;
		for (ll i = 1; i <= n; i += 1){
			if(a[i%5]){
				ans += a[i%5];
			}else{
				ll j = m;
				while((j+i)%5 != 0 && j > 0){
					// cout << "i: " << i << "j:" << j << endl;
					j--;
				}
				if(j <= 5 && j > 0){
					ans += 1;
				}else if(j > 0){
					ans += (j/5 + 1);
				}
			}
		}
		cout << ans << endl;
	}
}