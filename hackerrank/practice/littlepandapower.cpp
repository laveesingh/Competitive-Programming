#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

ll sp[1000001];
void smallestprimes(){
	for (ll i = 1; i < 1000001; i += 1){
		sp[i] = i;
	}
	for (ll i = 2; i < 1001; i += 1){
		if(sp[i] == i){
			for (ll j = 2*i; j < 1000001; j += i){
				sp[j] = min(sp[j], i);
			}
		}
	}
}
ll phi[1000001];
void phis(){
	phi[1] = 1;
	for (ll i = 2; i < 1000001; i += 1){
		if(sp[i] == sp[i/sp[i]]){
			phi[i] = phi[i/sp[i]]*sp[i];
		}else{
			phi[i] = phi[i/sp[i]]*(sp[i]-1);
		}
	}
}


ll pow(ll a, ll b, ll m){
	if(b == 1){
		return a%m;
	}
	if (b%2){
		return (a * pow(a, b-1, m))%m;
	}
	ll X = pow(a, b/2, m);
	return (X * X)%m;
}

ll power(ll a, ll b, ll x){
	if (b < 0){
		return pow(pow(a, phi[x]-1, x), -b, x);
	}
	if (b == 0) return 1%x;
	return pow(a, b, x);
}

int main(void){
	smallestprimes();
	phis();
	ll t;
	cin >> t;
	while(t--){
		ll a, b, x;
		cin >> a >> b >> x;
		cout << power(a, b, x) << endl;
	}
}