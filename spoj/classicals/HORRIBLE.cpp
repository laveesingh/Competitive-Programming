#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

#define ll long long

ll *tree, *lazy;

void update(ll node, ll tl, ll tr, ll i, ll j, ll val){
	// printf("Update began!!!\n");
	if(lazy[node] != 0){
		// printf("Entered the first if\n" );
		tree[node] += (lazy[node]*(tr-tl+1));
		if(tl != tr){
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(tl > tr || i > tr || j < tl){
		// printf("tl=%lld, tr=%lld, i=%lld, j=%lld\n", tl, tr, i, j);
		// printf("Entered the second iff\n");
		return;
	}

	if(i <= tl && j >= tr){
		// printf("Entered the third iff\n");
		tree[node] += val*(tr-tl+1);
		if(tl != tr){
			lazy[2*node] += val;
			lazy[2*node+1] += val;
		}
		return;
	}
	ll mid = (tl + tr)/2;
	update (2*node, tl, mid, i, j, val);
	update(2*node+1, mid+1, tr, i, j, val);
	// printf("Finally udpating the current node\n");
	tree[node] = tree[node*2] + tree[node*2+1];
}

ll getsum(ll node, ll tl, ll tr, ll i, ll j){
	if(lazy[node]  != 0){
		tree[node] += lazy[node]*(tr-tl+1);
		if(tl != tr){
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(tl > tr || j < tl || i > tr){
		return 0;
	}
	if(i <= tl && j >= tr){
		return tree[node];
	}
	ll mid = (tl+tr)/2;
	return getsum(2*node, tl, mid, i, j) + getsum(2*node+1, mid+1, tr, i, j);
}

int main(void){
	ll t, n, q, type, x, y, val;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld", &n, &q);
		tree = new ll[4*n+1];
		lazy = new ll[4*n+1];
		fill_n(tree, 4*n+1, 0);
		fill_n(lazy, 4*n+1, 0);
		for (ll query = 0; query < q; query += 1){
			scanf("%lld", &type);
			if(type == 0){
				scanf("%lld %lld %lld",&x, &y, &val);
				update(1, 0, n-1, x-1, y-1, val);
			}else{
				scanf("%lld %lld", &x, &y);
				ll ans = getsum(1, 0, n-1, x-1, y-1);
				printf("%lld\n", ans);
			}
			// for (int i = 0; i < 4*n+1; i += 1){
			// 	printf("%lld ", tree[i]);
			// }
		}
	}
}