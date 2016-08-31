/*input
5
XX|XX
XX|XX
XO|OX
XO|OO
OX|XO
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
	int n;
	cin >> n;
	string a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	bool flag = false;	
	for (int i = 0; i < n; i += 1){
		for (int j = 1; j < 5; j += 1){
			if (a[i][j] == 'O' and a[i][j-1] == 'O'){
				a[i][j] = '+';
				a[i][j-1] = '+';
				flag = true;
				break;
			}
		}
		if (flag == true) break;
	}
	if (!flag){
		cout << "NO" << endl;
	}else{
		cout << "YES" << endl;
		for(int i= 0; i < n; i += 1){
			cout << a[i] << endl;
		}
	}
}