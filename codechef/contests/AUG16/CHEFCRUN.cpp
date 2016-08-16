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

int min(int a, int b, int c){
	return min(a, min(b,c));
}

int solve(int start, int end){ 
	int ans = 0, cost = 0, cost2 = 0, j = 0, i = start;
	while (i != end){
		ans += pay(i, nex(i));
		i = nex(i);
	}
	i = start, cost = ans, cost2 = ans, j = end;
	while (j != prev(i)){
		cost2 += 2*pay(j, nex(j));
		ans = min(cost2, ans);
		j = nex(j);
	}
	j = end;
	map<int, int> dp, dpd;
	dp[end] = 0;
	dpd[end] = 0;
	while (j != prev(i)){
		dpd[nex(j)] = dpd[j] + 2*pay(j,nex(j));
		dp[nex(j)] = min(dp[j], dpd[nex(j)]);
		j = nex(j);
	}
	while(i != end){
		cost += 2*pay(i, prev(i));
		ans = min(ans, cost);
		cost2 = cost;
		cost2 += dp[prev(i)];
		ans = min(cost2, ans);
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
		if (n == 1){
			cout << 0 << endl;
		}else if (n == 2){
			int x = dist[{0,1}];
			int y = dist[{1,0}];
			int ans = 2*min(x,y)+max(x,y);
			ans = min(ans, min(x,y));

			cout << ans << endl;
		}else{
			st--;
			en--;
			int ans = min(solve(st, en), solve(en, st));
			cout << ans << endl;
		}
	}	
}

