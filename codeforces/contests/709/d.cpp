#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
	ios::sync_with_stdio(false);
	map<ll, ll> desumm;
	ll total = 0;
	for (ll i = 1; i < 100000; i += 1){
		total += i;
		desumm[total] = i;
	}
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int zs = desumm[a];
	int os = desumm[d];
	if (zs == 0 or os == 0){
		cout <<"Impossible" << endl;
	}else{
		vector<int> ans(zs, 0);
		int deviation = 0;
		if () 
	}
}