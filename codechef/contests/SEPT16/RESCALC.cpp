/*input
3
2
6 1 2 3 4 5 6
9 3 3 3 4 4 4 5 5 5
2
5 2 3 4 5 6
7 1 1 2 2 3 3 4
3
4 1 1 2 3
4 1 2 2 3
4 1 2 3 3
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
	while (t--){
		int n, ci;
		cin >> n;
		int score[n];
		fill_n(score, n, 0);
		for (int i = 0; i < n; i += 1){
			cin >> ci;
			int cia[ci];
			int freq[7];
			fill_n(freq, 7, 0);
			for (int j = 0; j < ci; j += 1){
				cin >> cia[j];
				freq[cia[j]] += 1;
			}
			score[i] += ci;
			bool flag = true;
			while (flag){
				
				flag = false;
				int cnt= 0;
				for (int k = 1; k <= 6; k += 1){
					if(freq[k] > 0){
						flag = true;
						cnt += 1;
						freq[k] -= 1;
					}
				}
				if (cnt == 4){
					score[i] += 1;
				}else if(cnt == 5){
					score[i] += 2;
				}else if (cnt == 6){
					score[i] += 4;
				}else{
					// do nothing
				}
			}	
		}
		int max_index = max_element(score, score+n) - score;
		int cnt = 0;
		for (int i = 0; i < n; i += 1){
			if (score[i] == score[max_index]){
				cnt += 1;
			}
		}
		if (cnt > 1){
			cout << "tie" << endl;
		}else{
			if (max_index == 0) cout << "chef" << endl;
			else cout << max_index+1 << endl;
		}
	}
}