/*input
4
daBcd
ABC
alcse
LCS
albccse
LCS
ababaca
ACA
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

int **L;

int lcs(string a, string b){
	int m = a.length();
	int n = a.length();
	L = new int*[m+1];
	for (int i = 0; i <= m; i += 1) L[i] = new int[n+1];
	for (int i = 0; i <= m; i += 1){
		for (int j = 0; j <= n; j += 1){
			if (i == 0 || j == 0){
				L[i][j] = 0;
			}else if (a[i-1] == b[j-1]){
				L[i][j] = L[i-1][j-1]+1;
			}else{
				L[i][j] = max(L[i-1][j], L[i][j-1]);
			}
		}
	}
	return L[m][n];
}

bool equal(char x, char y){
	if (toupper(x) == toupper(y)) return true;
	return false;
}

bool kmp(string a, string b){
	string pat = b+"$"+a;
	int n = a.length();
	int m = b.length();
	int lps[n+m+1];
	int i = 1, j = 0;
	lps[0] = 0;
	while (i < m+n+1){
		if (equal(pat[i], pat[j])){
			lps[i++] = ++j;
			if (j == m) return true;
		}else{
			if (j != 0){
				j = lps[j-1];
			}else{
				lps[i++] = 0;
			}
		}
	}
	return false;
}

int main(void){
	ios::sync_with_stdio(false);
	int q;
	cin >> q;
	while(q--){
		string a, b;
		cin >> a;
		cin >> b;


		// for(int i = 0; i < a.length(); i += 1) {a[i] = toupper(a[i]);}
		// if (lcs(a,b) == b.length()){
		// 	cout << "YES" << endl;
		// }else{
		// 	cout << "NO" << endl;
		// }



		if (kmp(a, b)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}