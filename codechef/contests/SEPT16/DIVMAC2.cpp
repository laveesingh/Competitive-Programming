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
 
#define inf INT_MAX
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define si set<int>
#define mii map<int, int>
#define mci map<char, int>
#define mic map<int, char>
#define vit vi::iterator
#define sit si::iterator
#define psb push_back
#define ppb pop_back
#define mp make_pair
#define init(a, n) a.find(n) != a.end()
#define F(i,n) for (int i = 0; i < n; i += 1)
#define inp(a,n) F(i,n) cin>>a[i]
#define print(a,n) F(i,n) {cout << a[i] << " ";} cout << endl
// graphs all will be 1 based indexed
#define uduwginp(g, m) F(i,m){cin>>x>>y;g[x].psb(y);g[y].psb(x);}
#define duwginp(g,m) F(i,m){cin>>x>>y; g[x].psb(y);}
#define printgraph(g,n) for(int i = 1; i <= n; i += 1){cout<< endl<<i<<": "; for(int adj:g[i]) cout << adj <<" ";} cout << endl
 
#define limit 100001
#define di deque<int>
 
// int A[limit];
// di T[4*limit];
// int lazy[4*limit];
int *lazy, *A,n;
di *T;
int lpdiv[10*limit]; // least prime divisors
 
void printdi(di temp, string delim=", "){
	for(int s: temp){
		cout << s << " ";
	}
	cout << delim;
}
 
void sieve(){
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
 
void combine(di& a, di& b, di& c){
	c.clear();
	int n = min(a.size(), b.size());
	for (int i = 0; i < n; i += 1){
		c.psb(max(a[i], b[i]));
	}
	if (n < a.size()){
		for (int i = n; i < a.size(); i += 1){
			c.psb(a[i]);
		}
	}else{
		for(int i = n; i < b.size(); i += 1){
			c.psb(b[i]);
		}
	}
}
 
di pdiv(int n){
	// return deque containing all the prime divisors with their frequency
	di ret;
	while (n > 1){
		ret.psb(lpdiv[n]);
		n /= lpdiv[n];
	}
	return ret;
}
 
void build(int node, int i, int j){
	if (i == j){
		// cout << "Node: " << node << " value: ";
		T[node] = pdiv(A[i]);
		// printdi(T[node], "\n");
	}else{	
		int mid = (i+j)/2;
		build(node*2, i, mid);
		build(2*node + 1, mid+1, j);
		// cout << "Combining " << 2*node << " and " << 2*node+1 << " : ";
		combine(T[2*node], T[2*node+1], T[node]);
		// printdi(T[node], "\n");
	}
}
 
void update(int node, int st, int en, int i, int j){
	
	// Performing the pending update on current node
	while (lazy[node] > 0 and !T[node].empty()){
		lazy[node] -= 1;
		T[node].pop_front();
		if(2*node < 4*n+5){

			lazy[2*node] += 1;
			lazy[2*node + 1] += 1;
		}
	}
	if (T[node].empty()){
		return;
	}
 
	if (i < st or j > en or st > en or i > j){
		return;
	}
	if (st == i and en == j){
		lazy[node] += 1;
		while (lazy[node] > 0 and !T[node].empty()){
			lazy[node] -= 1;
			T[node].pop_front();
			if(2*node <= 4*n+5){

				lazy[node*2] += 1;
				lazy[2*node+1] += 1;
			}
		}
	}else{
		int mid = (st+en)/2;
		
		if (j <= mid){
			update(2*node, st, mid, i, j);
		}else if (i > mid){
			update(2*node+1, mid+1, en, i, j);
		}else{
			update(2*node, st, mid, i, mid);
			update(2*node+1, mid+1, en, mid+1, j);
		}
		// cout << "Combining: " << 2*node << " and " << 2*node+1 << endl;
		// let's perform due updates before combining
		while (lazy[2*node]>0 and !T[2*node].empty()){
			lazy[2*node] -= 1;
			T[2*node].pop_front();
			if(4*node < 4*n+5){
				lazy[2*(2*node)] += 1;
				lazy[2*(2*node)+1] += 1;
			}
		}
		while(lazy[2*node+1] > 0 and !T[2*node+1].empty()){
			lazy[2*node+1] -= 1;
			T[2*node+1].pop_front();
			if(4*node+2 < 4*n+5){
				lazy[2*(2*node+1)] += 1;
				lazy[2*(2*node+1)+1] += 1;
			}
		}
		combine(T[2*node], T[2*node+1], T[node]);
	}
}
 
int get(int node, int st, int en, int i, int j){
	// cout << "node: " << node << " st: " << st << " en: " << en << " i: " << i << " j: " << j << endl;
	while(lazy[node]>0 and !T[node].empty()){
		T[node].pop_front();
		lazy[node] -= 1;
		if(2*node < 4*n+5){
			
			lazy[2*node] += 1;
			lazy[2*node+1] += 1;
		}
	}
	if(T[node].empty()){
		return 1;
	}
	if (i < st or j > en){
		return 1;
	}
 
	if (st == i and en == j){
		if (T[node].empty()){
			return 1;
		}else{
			return T[node][0];
		}
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
	cin >> t;
	while(t--){
		int m, type, x, y;
		cin >> n >> m;
		A = new int[n];
		lazy = new int[4*n+5];
		fill_n(lazy, 4*n+5, 0);
		T = new di[4*n+5];
		for(int i = 0; i< n; i+=1){
			cin >> A[i];
		}
		// cout << "Array is: ";
		// print(A, n);
		build(1, 0, n-1);
		// cout << "Initial segment tree is: " << endl;
		// for (int i = 1; i <= 4*n; i += 1){
		// 	cout << i<<":( ";
		// 	for(int s: T[i]){
		// 		cout << s << " ";
		// 	}
		// 	cout << " ), ";
		// }
		// cout << endl;
		for (int i = 0 ; i < m; i += 1){
			cin >> type >> x >> y;
			x -= 1;
			y -= 1;
			if (type == 0){
				update(1, 0, n-1, x, y);
				// cout << "Segment tree is: " << endl;
				// for (int i = 1; i <= 4*n; i += 1){
				// 	cout << i<<":( ";
				// 	for(int s: T[i]){
				// 		cout << s << " ";
				// 	}
				// 	cout << " ), ";
				// }
				// cout << endl;
			}else{
				cout << get(1, 0, n-1, x, y) << " ";
			}
		}
		cout << endl;
		// delete[] lazy;
		// delete[] T;
		// delete[] A;
	}
	
 
} 