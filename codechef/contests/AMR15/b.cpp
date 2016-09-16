/*input
4
3 2 1 4
2
0
2
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


int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int a[n];
	inp(a,n);
	sort(a, a+n);
	int dp[n];
	dp[0]=a[0];
	for (int i = 1; i < n; i += 1){
		dp[i] = dp[i-1]+a[i];
	}
	int q;
	cin >> q;
	for(int i = 0; i < q; i += 1){
		int k; 
		cin >> k;
		if(k > n-1) k = n-1;
		int ind = n/(k+1) + (n%(k+1) > 0);
		cout << dp[ind-1] << endl;
	}
	
}