#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pb push_back
#define INF 1000000000

vii findsubsets(int a[], int n){
	vii ssets(1<<n, vi());
	for(int i = 0; i < 1<<n; i += 1){
		vi sset;
		for(int j = 0; j < n; j += 1){
			if(i&(1<<j)){
				sset.pb(j);
			}
		}
		ssets[i] = sset;
	}
	return ssets;
}

bool isbad(int a[], int n, int k, int m){
	for(int i = 0; i < n-k+1; i += 1){
		int mxelem = *max_element(a+i, a+i+k);
		if(count(a+i, a+i+k, mxelem) >= m) return true;
	}
	return false;
}

int main(void){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, k, m;
		cin >> n >> k >> m;
		int a[n];
		for (int i = 0; i < n; i += 1){
			cin >> a[i];
		}
		vii subsets = findsubsets(a, n);
		int ans = INF;
		for(int i = 0; i < 1<<n; i += 1){
			int b[n];
			copy(a, a+n, b);
			for (int j = 0; j < subsets[i].size(); j += 1){
				b[subsets[i][j]] += 1;
			}
			if(!isbad(b, n, k, m)) ans = min(ans, (int)subsets[i].size());
		}
		cout << (ans == INF ? -1 : ans) << endl;
	}
}