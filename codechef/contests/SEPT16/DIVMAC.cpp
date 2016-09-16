/*input
1
6 10
863 1528 1337 1131 780 1497
0 1 5
0 6 6
1 5 5
0 2 6
0 1 4
1 1 3
1 2 6
0 5 6
1 3 5
1 1 4
*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define vi vector<int>
#define limit 100001
#define pb push_back
#define ppb pop_back
 
int *L, *A, n, m;
vi *T;
int lpdiv[10*limit]; // least prime divisor
 
inline void print(vi a){

	for(int s : a) cerr << s << " ";
}
 
inline void sieve(){
	int M = 10*limit;
	for (int i = 0; i < M; i += 1){
		if (i%2 == 0)
			lpdiv[i] = 2;
		else
			lpdiv[i] = i;
	}
	lpdiv[0] = 0;
	for(int i = 3; i*i <= M; i += 2){
		if(lpdiv[i] == i){
			for (int j = i*i; j < M; j += 2*i){
				lpdiv[j] = min(lpdiv[j], i);
			}
		}
	}
}
 
inline void combine(vi& a, vi& b, vi& c){
	int n = a.size(), m = b.size();
	c.clear();
	c.reserve(max(n,m));
	if(n > m){
		int i = 0;
		for (; i < n-m; i++){
			c.pb(a[i]);
		}
		for (int j = 0; j < m; i++,j++){
			c.pb(max(a[i], b[j]));
		}
	}else if(m > n){
		int i = 0;
		for(; i < m-n; i++){
			c.pb(b[i]);
		}
		for (int j = 0; j < n; i++,j++){
			c.pb(max(b[i], a[j]));
		}
	}else{
		for(int i = 0; i < m; i += 1){
			c.pb(max(a[i], b[i]));
		}
	}
}
 
inline void refresh(int node){
	while(!T[node].empty() and L[node] > 0){
		T[node].ppb();
		L[node] -= 1;
		// the condition check below may be disasterous
		if(2*node < 4*n+5){ 
			L[2*node] += 1;
			L[2*node+1] += 1;
		}
	}
}
 
inline void pdiv(int n, vi& a){
	vi ret;
	while(n > 1){
		ret.pb(lpdiv[n]);
		n /= lpdiv[n];
	}
	a = vi(ret.rbegin(), ret.rend());
}
 
void build(int node, int i, int j){
	if(i==j){
		pdiv(A[i], T[node]);
	}else{
		int mid = (i+j)/2;
		build(2*node, i, mid);
		build(2*node+1, mid+1, j);
		combine(T[2*node], T[2*node+1], T[node]);
	}
}
 
void update(int node, int st, int en, int i, int j){
	refresh(node);
	if(T[node].empty()) return;
	if(i < st or j > en or i > j or st > en) return;
	if(st == i and en == j){
		T[node].ppb();
		if(2*node < 4*n+5){
			L[2*node] += 1;
			L[2*node+1] += 1;
		}
	}else{
		int mid = (st+en)/2;
		if(j<=mid){
			update(2*node, st, mid, i,j);
		}else if(i > mid){
			update(2*node+1, mid+1, en, i, j);
		}else{
			update(2*node, st, mid, i, mid);
			update(2*node+1, mid+1, en, mid+1, j);
		}
		// The two refreshments below seem useless but they're not
		refresh(2*node);
		refresh(2*node+1);
		combine(T[2*node], T[2*node+1], T[node]);
	}
}
 
int get(int node, int st, int en, int i, int j){
	refresh(node);
	if(T[node].empty()) return 1;
	if(i<st or j > en or st > en or i > j) return 1;
	if(st == i and en == j){
		return T[node].back();
	}else{
		int mid = (st+en)/2;
		if ( j <= mid){
			return get(2*node, st, mid, i, j);
		}else if(i > mid){
			return get(2*node+1, mid+1, en, i, j);
		}else{
			int f = get(2*node, st, mid, i, mid);
			int s = get(2*node+1, mid+1, en, mid+1, j);
			return max(f,s);
		}
	}
}
 
int main(void){
	ios::sync_with_stdio(false);
	sieve();
	int t;
	scanf("%d", &t);
	while(t--){
		int type, x, y;
		scanf("%d %d", &n, &m);
		A = new int[n];
		L = new int[4*n+5];
		fill_n(L, 4*n+5, 0);
		T = new vi[4*n+5];
		for(int i = 0; i < n; i += 1){
			scanf("%d", &A[i]);
		}
		build(1, 0, n-1);
		for(int i = 1; i < 4*n+5; i += 1){
			cerr << i<<":(";print(T[i]); cerr<<"),  ";
		}
		cerr<< endl;
		for(int i = 0;i < m; i += 1){
			scanf("%d %d %d", &type, &x, &y);
			x--;
			y--;
			if(type == 0){
				update(1, 0, n-1, x, y);
				for(int i = 1; i < 4*n+5; i += 1){
					cerr << i<<":(";print(T[i]); cerr<<"),  ";
				}
				cerr<< endl;
			}else{
				printf("%d ", get(1, 0, n-1, x, y));
			}
		}
		printf("\n");
	}
} 