#include <iostream>

using namespace std;

#define ll long long

ll pow(ll b, ll e, ll m){
	if (e == 1) return b%m;
	if (e%2) return (b*pow(b, e-1, m))%m;
	ll x = pow(b, e/2, m);
	return (x*x)%m;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	ll b, e, m;
	cin >> t;
	for (int test = 1; test <= t; test += 1){
		cin >> b >> e >> m;
		cout << test << ". " << pow(b,e,m) << endl;
	}
}