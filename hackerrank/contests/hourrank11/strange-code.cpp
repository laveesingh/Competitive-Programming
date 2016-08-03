/*input
4
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
	ios::sync_with_stdio(false);
	long long t;
	cin >> t;
	ll pow2[40];
	pow2[0] = 1;
	for (ll i = 1; i < 40; i += 1){
		pow2[i] = pow2[i-1]*2;
	}
	ll n = 0;
	while(t+1 >= 3*pow2[n]-1){
		n++;
	}	
	// cout << "n:" << n << endl;
	ll s = 3*pow2[n-1]-1;
	s -= (t-s);
	cout << s << endl;
}