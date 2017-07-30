#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<vector<ll> > matrix;

matrix mult(matrix a, matrix b, ll mod){
	ll n = 2;
	ll m = 2;
	matrix c(2, vector<ll>(2, 0));
	for (ll i = 0; i < 2; i += 1){
		for (ll j = 0; j < 2; j += 1){
			c[i][j] = 0;
			for (ll k = 0; k < 2; k += 1){
				c[i][j] = (c[i][j] + a[i][k]*b[k][j])%mod;
			}
		}
	}
	return c;
}

matrix pow(matrix a, ll p, ll mod){
	if(p == 1){
		return a;
	} else if(p%2) {
		return mult(a, pow(a, p-1, mod), mod);
	} else {
		matrix X = pow(a, p/2, mod);
		return mult(X, X, mod);
	}
}

ll solve(ll n, ll m){
	ll mod = (ll)pow(2, m);
	matrix M(2, vector<ll>(2,1));
	M[1][1] = 0;
	M = pow(M, n, mod);
	return M[0][0];
}

int main(void){
	ll t;
	cin >> t;
	while(t--){
		ll n, m;
		cin >> n >> m;
		cout << solve(n, m) << endl;
	}
}