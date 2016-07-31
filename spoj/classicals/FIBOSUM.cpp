#include <iostream>
#include <cmath>
#include <vector>

// #define sq 2.23606797749979
// #define MOD 1000000007
#define MOD 1000000007
#define F(i,n) for (int i = 0; i < n; i += 1)

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> matrix;

const int k = 2;
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
	if (n == 0 || n == 1) return n;
	matrix T(2, vector<ll>(2));
	T[0][0] = 1;
	T[0][1] = 1;
	T[1][0] = 1;
	T[1][1] = 0;
	T = power(T, n-1);
	return T[0][0];
}

ll fibosum(int n){
	return fib(n+1)-1;
}

int main(void){
	int n, t, m;
	cin>> t;
	while(t--){
		cin >> n >> m;
		cout << ((1+fibosum(m-n))*fib(n) + fibosum(m-n+1)*fib(n+1))%MOD << endl;
	}
	
}
