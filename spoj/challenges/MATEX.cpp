#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)
#define ll long long

const ll mod = 1e9 + 7;
typedef vector<vector<ll> >matrix;

matrix mult(const matrix& a, const matrix& b){
	int k = a.size();
	matrix c(k, vector<ll>(k,0));
	for (int i = 0; i < k; i += 1)
		for (int j = 0; j < k; j += 1)
			for (int x = 0; x < k; x += 1)
				c[i][j] = (c[i][j] + a[i][x]*b[x][j])%mod;
	return c;
}

//matrix power(matrix a, int p){
//	if (p == 1) return a;
//	if (p%2){
//		return mult(a, power(a,p-1));
//	}
//	return power(mult(a, a), p/2);
//}

matrix power(matrix a, ll p){
	matrix result(a.size(), vector<ll>(a.size(), 0));
	for(int i = 0; i < a.size(); i++) result[i][i] = 1;
	while(p > 0){
		if(p&1) result = mult(result, a);
		p = p>>1;
		a = mult(a, a);
	}
	return result;
}


class query{
public:
	ll i, j, n, ind;
	friend bool operator<(const query& q1, const query& q2){
		return q1.n < q2.n;
	}
};

int main(void){
	ll w, x, y, z;
	ilong(w);
	matrix a(w, vector<ll>(w,0));
	for(int i = 0; i < w; i += 1)
		for(int j = 0; j < w; j += 1)
			ilong(a[i][j]);
	matrix store[64];
	store[0] = a;
	for(int i = 1; i < 64; i++)
		store[i] = mult(store[i-1], store[i-1]);

	int N = 550;
	query queries[N];
	ll ans[N];
	for(int i = 0; i < N; i++){
		ilong(x);
		ilong(y);
		ilong(z);
		x--; y--;
		queries[i].i = x;
		queries[i].j = y;
		queries[i].n = z;
		queries[i].ind = i;
	}
	sort(queries, queries+N);
	//cerr << "queries sorted" << endl;
	ll curpow=1;
	matrix cur = store[0];
	for(int i = 0; i < N; i++){
		ll z = queries[i].n - curpow;	
		int powi = 0;
		//cerr << "z: " << z << endl;
		while(z){
			if(z&1)
				cur = mult(cur, store[powi]);
			powi++;
			z >>= 1;
		}
		//cerr << "Out of while: i:" << queries[i].i << " j: " << queries[i].j  << endl;
		ans[queries[i].ind] = cur[queries[i].i][queries[i].j];
		curpow = queries[i].n;
		//cerr << "Curpow: " << curpow << endl;
	}
	for(int i = 0; i < N; i++) olong(ans[i]);

//		for(ll j = 0; j < 64; j++)
//			if(z>>j & 1){
//				ans = mult(ans, store[j]);
//			}
//		olong(ans[x][y]);
	//}
}

