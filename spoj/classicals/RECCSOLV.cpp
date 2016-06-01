#include <iostream>
#include <cstdio>
#include <cmath>
#include <regex>
#include <map>

using namespace std;

typedef long long ll;

typedef vector<vector<ll>> matrix;

#define MOD (int)pow(10,9)+9
#define F(i,n) for (int i = 0; i < n; i += 1)

map<int, int> coeff;
int k;
vector<int> bases;
map<int, ll> store;

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
	int cof, kt;
	bool flag = false;
	int i = 7;
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

void Print(matrix T){
	for (int i = 0; i < k; i += 1){
		for (int j = 0; j < k; j += 1){
			cout << T[i][j] << " ";
		}
		cout << endl;
	}
}


ll fib(int n){
	if (store[n]) return store[n];
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
	T = power(T, n);
	// cout << "Power 1:"<<endl;
	// Print(power(T,1));
	// cout << "Power 2:"<<endl;
	// Print(power(T,2));
	// cout << "Power 3:"<<endl;
	// Print(power(T,3));

	// for (int i = 0; i < k; i += 1){
	// 	for (int j = 0; j < k; j += 1){
	// 		cout << T[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	
	return T[0][0];

}




int main(void){
	string a;
	int temp, t, n;
	char tempar[200];
	// scanf("%s", tempar);
	getline(cin, a);
	// gets(tempar);
	// a = tempar;
	scanner(a);
	for (int i = 0; i < k; i += 1){
		// cin >> temp;
		scanf("%d", &temp);
		bases.push_back(temp);
	}
	// cin >> t;
	scanf("%d", &t);
	for (int i = 0; i < t; i += 1){
		// cin >> n;
		scanf("%d", &n);
		// cout << fib(n) << endl;
		printf("%lld\n", fib(n));
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
//  n = randint(1,100)
//  print n
//  for _ in xrange(n):
//   print randint(0,4294967296)
