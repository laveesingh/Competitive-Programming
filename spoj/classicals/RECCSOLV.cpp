#include <iostream>
#include <cstdio>
#include <cmath>
#include <regex>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

typedef vector<vector<ll>> matrix;

#define MOD (ll)pow(10,9)+9
#define F(i,n) for (ll i = 0; i < n; i += 1)

map<ll, ll> coeff;
ll k;
vector<ll> bases;
map<ll, ll> store;

matrix mult(matrix a, matrix b){
	matrix c(k, vector<ll>(k));

	F(i,k) F(j,k) c[i][j]=0;

	for (ll i = 0; i < k; i += 1){
		for (ll j = 0; j < k; j += 1){
			for (ll x = 0; x < k; x += 1){
				c[i][j] += a[i][x]*b[x][j];
				c[i][j] %= MOD;
			}
		}
	}


	return c;
}

matrix power(matrix a, ll p){
	if (p == 1) return a;
	if (p%2){
		return mult(a, power(a,p-1));
	}
	matrix X = power(a,p/2);
	return mult(X, X);
}

void scanner(string a){
	k = 0;
	string temp = "";
	ll cof, kt;
	bool flag = false;
	ll i = 7;
	if (a[i]=='-') flag = true;
	while ( i < a.length()){
		if (a[i] == 'f'){
			cof = temp == "" ? 1 : stoi(temp);
			if (flag){
				cof = -cof;
			}
			temp = "";
			kt = a[i+4]-'0';
			coeff[kt] = cof;
			k = max(k, kt);
			// cout << "coeff[" << kt << "]: " << cof << endl;
			if (i+7 < a.length()){
				flag = a[i+7]=='+' ? false : true;
			}
			i += 9;
		}else{
			temp += a[i];
			i += 1;
		}
	}

}

void Prll(matrix T){
	for (ll i = 0; i < k; i += 1){
		for (ll j = 0; j < k; j += 1){
			cout << T[i][j] << " ";
		}
		cout << endl;
	}
}

bool iscur = false;
ll last;
matrix cur;

ll fib(ll n){
	if (store[n]) return store[n];
	if (n < k) return bases[n];
	n = n-k+1;
	vector<ll> V(k);
	for (ll i = 0; i < k; i += 1){
		V[i] = bases[k-i-1];
	}
	matrix T(k, vector<ll>(k));
	for (ll i = 0; i < k; i += 1){
		T[0][i] = coeff[i+1];
	}
	for (ll i = 1; i < k; i += 1){
		for (ll j = 0; j < k; j += 1){
			if (j == i-1){
				T[i][j] = 1;
			}else{
				T[i][j] = 0;
			}
		}
	}
	if (iscur == false){
		T = power(T, n);
		cur = T;
		last = n;
	}else{
		T = mult(cur, power(T, n-last));
	}
	// cout << "Power 1:"<<endl;
	// Prll(power(T,1));
	// cout << "Power 2:"<<endl;
	// Prll(power(T,2));
	// cout << "Power 3:"<<endl;
	// Prll(power(T,3));

	// for (ll i = 0; i < k; i += 1){
	// 	for (ll j = 0; j < k; j += 1){
	// 		cout << T[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	return T[0][0];

}

// vector<ll> queries;
// vector<ll> answers;

vector<ll> sorted(vector<ll> a){
	sort(a.begin(), a.end());
	return a;
}


int main(void){
	string a;
	ll temp, t, n;
	char tempar[200];
	// scanf("%s", tempar);
	getline(cin, a);
	// gets(tempar);
	// a = tempar;
	scanner(a);
	for (ll i = 0; i < k; i += 1){
		// cin >> temp;
		scanf("%lld", &temp);
		bases.push_back(temp);
	}
	// cin >> t;

	scanf("%lld", &t);
	vector<ll> queries(t);
		for (ll i = 0; i < t; i += 1){
		// cin >> n;
		scanf("%lld", &queries[i]);
		// cout << fib(n) << endl;
	}
	vector<ll> sorted(queries.begin(), queries.end());
	sort(sorted.begin(), sorted.end());
	map<ll,ll> answers;
	for (ll i = 0; i < t; i += 1){
		// printf("%lld\n", fib(queries[i]));
		// cout << "finding for " << queries[i] << endl;
		if (answers[sorted[i]]){
			// do nothing
		}else{

			answers[sorted[i]] = fib(sorted[i]);
			// printf("%lld\n",fib(sorted[i]));
		}
	}
	for (ll query: queries){
		printf("%lld\n", answers[query]);
	}
}

/*f(n) = 2f(n-1) + 3f(n-3) + 4f(n-6)
0 1 2 3 4 5
5
234
5342
266666
999999
1*/

// def case():
//  n = 10000
//  prll n
//  for _ in xrange(n):
//   prll randll(0,4294967296)
