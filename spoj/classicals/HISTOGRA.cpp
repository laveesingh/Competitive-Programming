#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

#define ll long long


ll INF = 100000000000000;

ll *H, *tree, n;

ll max(ll a, ll b, ll c){
	return max(a, max(b,c));
}

void build(ll node, ll i, ll j){
	// cout << "Looking to build for " << node << " " << i << " " << j << endl;
	if(i == j){
		tree[node] = i;
		return;
	}
	if(i > j) return;
	build(2*node, i, (i+j)/2);
	build(2*node+1, (i+j)/2+1, j);
	if(H[tree[2*node]] < H[tree[2*node+1]]){
		tree[node] = tree[2*node];
	}else{
		tree[node] = tree[2*node+1];
	}
}

ll query(ll node, ll tl, ll tr, ll i, ll j){
	if(tl > tr || i > tr || j < tl) return -1;
	if(i <= tl && j >= tr){
		return tree[node];
	}
	ll mid = (tl+tr)/2;
	ll f = query(2*node, tl, mid, i, j);
	ll s = query(2*node+1, mid+1, tr, i, j);
	if(f == -1) return s;
	if(s == -1) return f;
	if(H[f] < H[s]){
		return f;
	}
	return s;
}

ll getmin(ll i, ll j){
	return query(1, 0, n-1, i, j);
}

ll solve(ll i, ll j){
	// cout << "Solving for " << i << " " << j << endl;
	if(i == j){
		return H[i];
	}
	if (i > j){
		return 0;
	}
	ll mini = getmin(i,j);
	// cout << H[mini] << " is the minimum for " << i << " " << j << endl;
	return max(solve(i, mini-1), 
		solve(mini+1, j),
		H[mini]*(j-i+1));
}

int main(void){
	/*
		set tree[0] = INF;
	*/
	while(1){
		scanf("%lld", &n);
		if(n == 0) break;
		H = new ll[n];
		for (ll i = 0; i < n; i += 1){
			scanf("%lld", &H[i]);
		}
		tree = new ll[4*n+3];
		tree[0] = INF;
		tree[4*n+1] = INF;
		build(1, 0, n-1);
		// cout << "Tree has been built" << endl;
		printf("%lld\n", solve(0, n-1));
	}
}