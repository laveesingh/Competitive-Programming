#include <iostream>

using namespace std;

#define ll long long

ll pow(ll a, ll b, ll mod){
	ll res = 1;
	while (b>0){
		if(b%2){
			res = (res * a)%mod;
		}
		a = (a*a)%mod;
		b >>= 1;
	}
	return res;
}

int main(void){
	ll t;
	cin >> t;
	while(t--){
		ll a, m;
		cin >> a >> m;
		if(a == 0 || pow(a, (m-1)/2, m) == 1){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}