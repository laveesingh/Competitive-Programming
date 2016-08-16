/*input
1
6
-10 -49 73 -67 -7 51
4 6

*/
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define pii pair<int, int>
#define inf INT_MAX
 
map<pii, int> dist;
int n;
 
int nex(int i){
	return (i+1)%n;
}
 
int prev(int i){
	return (i-1+n)%n;
}
 
int pay(int i, int j){
	if (dist[{i,j}]) return dist[{i,j}];
	return dist[{j,i}];
}
 
int solve(int start, int end){
	int ans = 0, cost, cost2;
	int j,i = start;
	while (i != end){
		ans += pay(i, nex(i));
		i = nex(i);
	}
	// cout << "Initial answer is " << ans << " start " << start << " end " << end << endl;
	i = start;
	cost = ans, cost2 = ans;
	j = end;
	while (j != prev(i)){
		// cout << "Second " << j << " cost to add " << pay(j,nex(j)) << endl ;
		cost2 += 2*pay(j, nex(j));
		ans = min(cost2, ans);
		j = nex(j);
	}
	while (i != end){
		// cout << "First " << i << endl;
		cost += 2*pay(i, prev(i));
		ans = min(cost, ans);
 
		cost2 = cost;
		j = end;
		while (j != prev(i)){
			// cout << "Second " << j << " cost to add " << pay(j,nex(j)) << endl ;
			cost2 += 2*pay(j, nex(j));
			ans = min(cost2, ans);
			j = nex(j);
		}
		i = prev(i);
	}
	return ans;
}
 
int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		dist.clear();
		cin >> n;
		int temp;
		for (int i = 0; i < n; i += 1){
			cin >> temp;
			dist[{i, (i+1)%n}] = temp;
		}
		int st, en;
		cin >> st >> en;
		st--;
		en--;
		int ans = min(solve(st, en), solve(en, st));
		cout << ans << endl;
	}	
}
 