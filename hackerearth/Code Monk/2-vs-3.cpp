#include <bits/stdc++.h>

using namespace std;

int T[400004];
string a;

int pow(int a, int b, int m){
	if (b == 0) return 1;
	if (b == 1) return a;
	if (b%2) return (a*pow(a,b-1,m))%m;
	int x = pow(a, b/2, m);
	return (x*x)%m;
}

void build(int node, int i, int j){
	if(i == j){
		T[node] = (int)(a[i]-'0');
	}else{
		int mid = (i+j)/2;
		build(2*node, i, mid);
		build(2*node+1, mid+1, j);
		T[node] = pow(2,j-mid, 3)*T[2*node] + T[2*node+1];
		T[node] %= 3;
	}
}

int query(int node, int x, int b, int i, int j){
	if(x == i and b == j){
		return T[node];
	}
	int mid = (x+b)/2;
	if(j <= mid){
		return query(2*node, x, mid, i, j);
	}
	if (i > mid){
		return query(2*node+1, mid+1, b, i, j);
	}
	int l = query(2*node, x, mid, i, mid);
	int r = query(2*node+1, mid+1, b, mid+1, j);
	return (l*(pow(2, j-mid, 3)) + r)%3;
}

void update(int node, int i, int j, int x){
	if(i == j){
		T[node] = 1;
	}else{
		int mid = (i+j)/2;
		if(x <= mid){
			update(2*node, i, mid, x);
		}else if(x > mid){
			update(2*node+1, mid+1, j, x);
		}
		T[node] = pow(2,j-mid, 3)*T[2*node] + T[2*node+1];
		T[node]%= 3;
	}
}

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	cin >> a;
	build(1, 0, n-1);
	int q, type, x, y;
	cin >> q;
	while(q--){
		cin >> type;
		if (type == 0){
			cin >> x >> y;
			cout << query(1, 0, n-1, x, y) << endl;
		}else{
			cin >> x;
			update(1, 0, n-1, x);
		}
	}
}
