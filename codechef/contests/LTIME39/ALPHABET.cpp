/*input
act
2
cat
dog
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
#define F(i,n) for (int i = 0; i < n; i += 1)
#define inp(a,n) F(i,n) cin>>a[i]
#define print(a,n) F(i,n) {cout << a[i] << " ";} cout << endl
// graphs all will be 1 based indexed
#define uduwginp(g, m) F(i,m){cin>>x>>y;g[x].psb(y);g[y].psb(x);}
#define duwginp(g,m) F(i,m){cin>>x>>y; g[x].psb(y);}
#define printgraph(g,n) for(int i = 1; i <= n; i += 1){cout<< endl<<i<<": "; for(int adj:g[i]) cout << adj <<" ";} cout << endl


int main(void){
	ios::sync_with_stdio(false);
	string a;
	cin >> a;
	set<char> store(a.begin(), a.end());
	int n;
	cin >> n;
	for (int i = 0; i < n; i += 1){
		string b;
		cin >> b;
		set<char> cur(b.begin(), b.end());
		vector<char> v(10);
		vector<char>::iterator it = set_difference(cur.begin(), cur.end(), store.begin(), store.end(), v.begin());
		if ((it-v.begin()) == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}	
}