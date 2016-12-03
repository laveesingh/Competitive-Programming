#include <bits/stdc++.h>
using namespace std;

const int N = 1025;
int mat[N][N];
int T[8*N*N];
int n;

void build(int node, int i1, int j1, int i2, int j2){
	if(i1 == i2 and j1 == j2){
		T[node] = mat[i1][j1];
	}else{
		build(4*node-2, i1, j1, (i1+i2)/2, (j1+j2)/2);	
		build(4*node-1, (i1+i2)/2+1, j1, i2, (j1+j2)/2);	
		build(4*node+0, i1, (j1+j2)/2+1, (i1+i2)/2, j2);	
		build(4*node+1, (i1+i2)/2+1, (j1+j2)/2+1, i2, j2);
		T[node] = T[4*node-2] + T[4*node-1] + T[4*node+0] + T[4*node+1];
	}
}

int query(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2){
	if(a2 < x1 or a1 > x2 or b2 < y1 or b1 > y2 or a1 > a2 or b1 > b2) return 0;
	if(a1 >= x1 and x2 >= a2 and b1 >= y1 and y2 >= b2) {
//		cerr << "Querying " << a1 << "," << b1 << " to " << a2 << "," << b2  << " and " << x1 << "," << y1 << " to " << x2 << "," << y2 << endl;
		return T[node];
	}
	int ans = 0;
	ans += query(4*node-2, a1, b1, (a1+a2)/2, (b1+b2)/2, x1, y1, x2, y2);
	ans += query(4*node-1, (a1+a2)/2+1, b1, a2, (b1+b2)/2, x1, y1, x2, y2);	
	ans += query(4*node+0, a1, (b1+b2)/2+1, (a1+a2)/2, b2, x1, y1, x2, y2);	
	ans += query(4*node+1, (a1+a2)/2+1, (b1+b2)/2+1, a2, b2, x1, y1, x2, y2);
	return ans;
}

void update(int node, int a1, int b1, int a2, int b2, int x, int y, int val){
	if(x < a1 or x > a2 or y < b1 or y > b2) return;
	if(x == a1 and x == a2 and y == b1 and y == b2){
		T[node] = val;
		return;
	}
	update(4*node-2, a1, b1, (a1+a2)/2, (b1+b2)/2, x, y, val);
	update(4*node-1, (a1+a2)/2+1, b1, a2, (b1+b2)/2, x, y, val);	
	update(4*node+0, a1, (b1+b2)/2+1, (a1+a2)/2, b2, x, y, val);	
	update(4*node+1, (a1+a2)/2+1, (b1+b2)/2+1, a2, b2, x, y, val);
	T[node] = T[4*node-2] + T[4*node-1] + T[4*node+0] + T[4*node+1];
}
inline void update(int x, int y, int val){
	update(1, 0, 0, n-1, n-1, x, y, val);
}

inline int query(int x1, int y1, int x2, int y2){
	return query(1, 0, 0, n-1, n-1, x1, y1, x2, y2);
}

int main(void){
	int t, x1, y1, x2, y2, val;
	char type[4];
	scanf("%d",&t);
	while(t--){
		memset(T, 0, sizeof(int)*6*(n*n));
		scanf("%d", &n);
		while(1){
			scanf("%s", type);
			if(type[1] == 'N') break;
			if(type[1] == 'E'){
				scanf("%d %d %d", &x1, &y1, &val);
				update(x1, y1, val);
			}else{
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				printf("%d\n", query(x1, y1, x2, y2));
			}
		}
//		printf("\n");
	}
}

