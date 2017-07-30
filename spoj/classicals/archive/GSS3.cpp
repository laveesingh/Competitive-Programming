#include <cstdio>
#include <iostream>

using namespace std;

class node{
public:
	int lsum, rsum, totalsum, maxsum;
	node(){}
	node(int l, int r, int t, int m){
		lsum = l;
		rsum = r;
		totalsum = t;
		maxsum = m;
	}
};

node *T;
int *a, n;

int max(int a, int b){
	if(a >= b) return a;
	return b;
}


node add(node a, node b){
	int maxsum = a.maxsum;
	maxsum = max(maxsum, b.maxsum);
	maxsum = max(maxsum, a.rsum+max(b.totalsum, b.lsum));
	maxsum = max(maxsum, b.lsum+max(a.totalsum, a.rsum));
	maxsum = max(maxsum, a.totalsum+b.totalsum);
	int lsum = max(a.lsum, a.totalsum+b.lsum);
	int rsum = max(b.rsum, b.totalsum+a.rsum);
	int totalsum = a.totalsum+b.totalsum;
	return node(lsum, rsum, totalsum, maxsum);
}


void build(int v, int i, int j){
	// cout << "Looking to build for " << i << " " << j << endl;
	if(i == j){
		T[v] = node(a[i], a[i], a[i], a[i]);
	}else{
		int mid = (i+j)/2;
		build(2*v, i, mid);
		build(2*v+1, mid+1, j);
		T[v] = add(T[2*v], T[2*v+1]);
	}
}



node query(int v, int tl, int tr, int l, int r){
	// cout << "querying for: " << tl << " " << tr << endl;
	if(tl == l && tr == r){
		return T[v];
	}
	if(r <= (tl+tr)/2){
		return query(2*v, tl, (tl+tr)/2, l, r);
	}
	if(l > (tl+tr)/2){
		return query(2*v+1, (tl+tr)/2+1, tr, l, r);
	}
	int mid = (tl+tr)/2;
	node left = query(2*v, tl, mid, l, mid);
	node right = query(2*v+1, mid+1, tr, mid+1, r);
	return add(left, right);
}

int query(int x, int y){
	node cur = query(1, 0, n-1, x, y);
	return cur.maxsum;
}

void update(int v, int tl, int tr, int pos, int val){
	if(tl == tr){
		T[v] = node(val, val, val, val);
	}else{
		int mid= (tl+tr)/2;
		if(pos <= mid){
			update(2*v, tl, mid, pos, val);
		}else{
			update(2*v+1, mid+1, tr, pos, val);
		}
		T[v] = add(T[2*v], T[2*v+1]);
	}
}

int main(void){
	scanf("%d", &n);
	T = new node[4*n+1];
	a = new int[n];
	for (int i = 0; i < n; i += 1){
		scanf("%d", &a[i]);
	}
	// cout << "input taken" << endl;
	build(1, 0, n-1);
	int q, type, x, y;
	scanf("%d", &q);
	for (int i = 0; i < n; i += 1){
		scanf("%d %d %d", &type, &x, &y);
		if(type == 0){
			update(1, 0, n-1, x-1, y);
		}else{
			printf("%d\n", query(x-1, y-1));
		}
	}
}