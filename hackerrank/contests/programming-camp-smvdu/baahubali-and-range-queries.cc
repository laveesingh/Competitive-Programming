#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>

int *a;
pii *T;

void build(int node, int st, int en){
	if (st == en){
		T[node].first = a[st];
		T[node].second = a[st];
	}else{
		int mid = (st + en)/2;
		build(2*node, st, mid);
		build(2*node+1, mid+1, en);
		T[node].first = min(T[2*node].first, T[2*node+1].first);
		T[node].second = max(T[2*node].second, T[2*node+1].second);
	}
}

pii get(int node, int st, int en, int x, int y){
	if(x == st and y == en){
		return T[node];
	}else{
		int mid = (st+en)/2;
		if (y <= mid){
			return get(2*node, st, mid, x, y);
		}else if(x > mid){
			return get(2*node+1, mid+1, en, x, y);
		}else{
			pii F = get(2*node, st, mid, x, mid);
			pii S = get(2*node+1, mid+1, en, mid+1, y);
			pii x = {min(F.first, S.first), max(F.second, S.second)};
			return x;
		}
	}
}

int main(void){
	ios::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	a = new int[n];
	for(int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	T = new pii[4*n+4];
	build(1, 0, n-1);
	int x, y;
	for (int i = 0; i < q; i += 1){
		cin >> x >> y;
		x -= 1;
		y -= 1;
		pii ans = get(1, 0, n-1, x, y);
		cout << ans.first + ans.second << endl;
	}
}
