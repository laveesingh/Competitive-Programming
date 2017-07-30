/*input
3
#...#
.###.
#.#.#.
.#.#.#
#...
#...
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


void solve(string a, string b, int& sw, bool& flag){
	int i = 0, cl = 1;
	while (i < a.size()){
		if (a[i] == '#' and b[i] == '#'){
			flag = false;
			return;
		}else{
			if(cl == 1){
				if (a[i] == '.'){
					i++;
				}else{
					i++;
					sw++;
					cl = 2;
				}
			}else{
				if (b[i] == '.'){
					i++;
				}else{
					i++;
					sw++;
					cl = 1;
				}
			}
		}
	}
	flag = true;
	return;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		string a, b;
		cin >> a >> b;
		int s1 = 0, s2=0;
		bool flag1=false, flag2=false;
		solve(a, b, s1, flag1);
		solve(b, a, s2, flag2);
		if (flag1 and flag2){
			cout << "Yes" << endl;
			cout << min(s1, s2) << endl;
		}else if(flag1){
			cout << "Yes" << endl;
			cout << s1 << endl;
		}else if(flag2){
			cout << "Yes" << endl;
			cout << s2 << endl;
		}else{
			cout << "No" << endl;
		}
	}
	
}