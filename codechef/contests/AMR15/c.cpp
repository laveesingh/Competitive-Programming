/*input
3
2 2
3 0
3 1
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


int n, k;


bool solve(int *perm){
	//cerr << "Solving for " << n << endl;
	if (k > n/2) return false;
	int i = 0, curk = 0;
	for (int i = 0; i < n; i += 1){
		perm[i] = i+1;
	}
	if (k == 0) return true;
	while (i+2*k <= n){
		//cerr << "i: " << i << endl;
		for(int j = 0; j < k; j += 1){
			//cerr << "In the for" << endl;
			if(i>=n) break;
			//cerr << "Really" << endl;
			perm[i++] = j+1+k+curk;
		}
		for(int j = 0; j < k; j += 1){
			if (i >= n) break;
			perm[i++] = j+1+curk;
		}
		curk += 2*k;
	}
	//cerr << "After while" << endl;
	if (n%(2*k) == 0) return true;
	int bind = n-2*k;
	int eind = n-k;
	while (eind < n){
		swap(perm[bind++],perm[eind++]);
	}
	return true;
}


int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> k;
		int *perm = new int[n];
		if(solve(perm)){
			for(int i = 0; i< n; i += 1){
				cout << perm[i] << " ";
			}
			cout << endl;
		}else{
			cout << -1 << endl;
		}
	}
	
}