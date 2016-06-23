#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define mod 1000000007

typedef vector<vector<ll> > matrix;

matrix mult(matrix a, matrix b){
	matrix c(a.size(), vector<ll>(b[0].size()));
	for (ll i = 0; i < a.size(); i += 1){
		for (ll j = 0; j < b[0].size(); j += 1){
			c[i][j] = 0;
			for (ll k = 0; k < a[0].size(); k += 1){
				c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod;
			}
		}
	}
	return c;
}

matrix pow(matrix a, ll p){
	if(p == 1){
		return a;
	}else if(p%2){
		return mult(a, pow(a, p-1));
	}else{
		matrix x = pow(a, p/2);
		return mult(x, x);
	}
}

int main(void){
	ll t;
	cin >> t;
	while(t--){
		ll a, b, n;
		cin >> a >> b >> n;
		// vector<ll> base({b, a});
		matrix M(2, vector<ll>(2, 1));
		M[1][1] = 0;
		if (n == 1){
			cout << b%mod << endl;
		}else if(n == 0){
			cout << a%mod << endl;
		}else{
			M = pow(M, n-1);
			ll res = M[0][0]*b + M[0][1]*a;
			cout << res%mod << endl;

		}

	}
}