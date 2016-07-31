#include <iostream>
#include <cstdio>
#include <cmath>
#include <regex>
#include <map>

using namespace std;

typedef long long ll;

typedef vector<vector<ll>> matrix;

#define MOD (int)pow(10,9)
#define F(i,n) for (int i = 0; i < n; i += 1)

map<int, int> coeff;
int k;
vector<int> bases;
// map<int, ll> store;

matrix mult(matrix a, matrix b){
	matrix c(k, vector<ll>(k));

	F(i,k) F(j,k) c[i][j]=0;

	for (int i = 0; i < k; i += 1){
		for (int j = 0; j < k; j += 1){
			for (int x = 0; x < k; x += 1){
				c[i][j] += a[i][x]*b[x][j];
				c[i][j] %= MOD;
			}
		}
	}


	return c;
}

matrix power(matrix a, int p){
	// cout << ". ";
	if (p == 1) return a;
	if (p%2){
		return mult(a, power(a,p-1));
	}
	matrix X = power(a,p/2);
	return mult(X, X);
	// return mult(power(a,p/2), power(a,p/2));
}

ll fib(int n){
	n -= 1;
	// if (store[n]) return store[n];
	if (n < k) return bases[n];
	n = n-k+1;
	vector<int> V(k);
	for (int i = 0; i < k; i += 1){
		V[i] = bases[k-i-1];
	}
	matrix T(k, vector<ll>(k));
	for (int i = 0; i < k; i += 1){
		T[0][i] = coeff[i+1];
	}
	for (int i = 1; i < k; i += 1){
		for (int j = 0; j < k; j += 1){
			if (j == i-1){
				T[i][j] = 1;
			}else{
				T[i][j] = 0;
			}
		}
	}
	// for(int i = 0; i < k; i += 1){
	// 	for (int j = 0; j < k; j += 1){
	// 		cout << T[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	T = power(T, n);
	// for(int i = 0; i < k; i += 1){
	// 	for (int j = 0; j < k; j += 1){
	// 		cout << T[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	ll res = 0;
	for (int i = 0; i < k; i += 1){
		res += T[0][i]*V[i];
	}
	// store[n] = res;
	return res%MOD;
	// return store[n];

}



int main(void){
	int t, b, c, n,temp;
	scanf("%d", &t);
	while(t--){
		bases.clear();
		coeff.clear();
		scanf("%d", &k);
		for (int i = 0; i < k; i += 1){
			scanf("%d", &temp);
			bases.push_back(temp);
		}
		for (int i = 1; i <= k; i += 1){
			scanf("%d", &temp);
			coeff[i] = temp;
		}
		scanf("%d", &n);
		printf("%lld\n", fib(n));
	}
}
