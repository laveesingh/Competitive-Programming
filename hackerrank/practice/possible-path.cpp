#include <iostream>

using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main(void){
	ll t, a, b, x, y;
	cin >> t;
	while(t--){
		cin >> a  >> b >> x >> y;
		ll G = gcd(a, b);
		ll G2 = gcd(x, y);
		cout << (G == G2 ? "YES" : "NO") << endl;
	}
}
