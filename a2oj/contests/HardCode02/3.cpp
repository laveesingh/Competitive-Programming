#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

#define mp make_pair
#define pii pair<int, int>

const int limit = 400041;

pii t[limit];
int *a;

pii max2(int a, int b, int c, int d){
	int arr[] = {a, b, c, d};
	sort(arr, arr+4);
	return mp(arr[2], arr[3]);
}

void build(int node, int left, int right){
	if(left == right){
		t[node] = mp(0, a[left]);
		return;
	}
	int mid = (left+right)/2;
	build(2*node, left, mid);
	build(2*node+1, mid+1, right);
	int x,y,z,w;
	x = t[2*node].first;
	y = t[2*node].second;
	z = t[2*node+1].first;
	w = t[2*node+1].second;
	t[node] = max2(x, y, z, w);
	return;
}

pii query(int node, int left, int right, int i, int j){
	if(j < left or i > right) return mp(0,0);
	if(i <= left and j >= right) return t[node];
	int mid = (left+right)/2;
	pii f = query(2*node, left, mid, i, j);
	pii s = query(2*node+1, mid+1, right, i, j);
	return max2(f.first, f.second, s.first, s.second);
}

void update(int node, int left, int right, int i, int x){
	if(i > right or i < left) return;
	if(left == right and right == i){
		t[node] = mp(0,x);
		return;
	}
	int mid = (left+right)/2;
	update(2*node, left, mid, i, x);
	update(2*node + 1, mid+1, right, i, x);
	pii f = t[2*node];
	pii s = t[2*node+1];
	t[node] = max2(f.first, f.second, s.first, s.second);
	return;
}

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	build(1, 0, n-1);
	int q, x, y;
	char type;
	cin >> q;
	for(int i = 0; i < q; i += 1){
		cin >> type >> x >> y;
		if (type == 'Q'){
			pii cur = query(1, 0, n-1, x-1, y-1);
			cout << cur.first+cur.second << endl;
		} else {
			update(1, 0, n-1, x-1, y);
		}
	}
}