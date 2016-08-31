/*input
6
1
17 77 79 46 68 96 62 18 55 18 98 31 63 78 45 34 11 56
56 11 34 45 78 63 31 98 18 55 18 62 96 68 46 79 77
1
14 74 31 90 69 21 39 44 47 40 60 11 96 25 81
81 25 96 11 60 40 47 44 39 21 69 90 31 74
1
3 86 28 92
86 28 92
1
14 72 24 50 36 74 19 85 85 62 21 59 42 16 81
72 24 50 36 74 19 85 85 62 21 59 42 16 81
1
14 28 40 21 34 51 25 52 98 70 27 9 96 49 62
62 49 96 9 27 70 98 52 25 51 34 21 40 28
1
12 5 24 82 32 36 95 76 17 82 56 30 57
5 24 82 32 36 95 76 17 82 56 30 57
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
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		assert(n==1);
		stack<int> ans;
		int num,temp;
 
		for (int i = 0; i <n; i += 1){
			cin >> num;
			for (int j = 0; j < num; j+=1){
				cin >> temp;
				ans.push(temp);
			}
		}
		vi check;
		for (int i = 0; i < num; i += 1){
			cin >> temp;
			check.psb(temp);
		}
		vi rev;
		while (!ans.empty()){
			rev.psb(ans.top());
			ans.pop();
		}
		if (rev == check) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
} 