#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<pii, int> piii;
typedef map<int, int> mii;
typedef deque<int> di;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<pll, ll> plll;
typedef map<ll, ll> mll;
typedef deque<ll> dl;

#define F(i, n) for(ll i = 0; i < n; i += 1)
#define PRINT(a,n) for(ll i = 0; i < n; i += 1){ cout << a[i] << " ";} cout<<endl;
#define arrinp(a,n) for(ll i = 0; i < n; i += 1) cin >> a[i];
#define init(a,n) a.find(n) != a.end()
#define Front(a) *(a.begin())
#define Back(a) *(a.rbegin())
#define Index(a, x) a.find(x) - a.begin()

const int inf = INT_MAX;

typedef vvi matrix;

matrix mult(const matrix& a, const matrix& b, int mod=1000000007){
    int n = a.size();
    int m = b[0].size();
    matrix c(n, vi(m, 0));
    F(i,n){
        F(j,m){
            c[i][j] = 0;
            F(k,b.size()){
                c[i][j] += a[i][k]*b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}


matrix pow(matrix a, int p, int mod=1000000007){
    if(p == 1) return a;
    if (p & 1) return mult(a, pow(a, p-1, mod), mod);
    matrix X = pow(a, p/2, mod);
    return mult(X, X, mod);
}

int fibn(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    matrix T(2, vi(2,1));
    T[1][1] = 0;
    vi coef({1,1});
    T = pow(T, n-1, 1000000007);
    // F(i,2){
    //     F(j,2){
    //         cout << T[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return T[0][0];
}



int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; i += 1){
		int x;
		cin >> x;
		cout << fibn(x) << endl;
	}
}

