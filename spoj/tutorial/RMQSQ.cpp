#include <iostream>
#include <algorithm>

using namespace std;

#define INF 1000000000

int T[400000], *a;

void build(int i, int l, int r){
	if(l == r){
		T[i] = a[l];
	}else{
		int mid = l + (r-l)/2;
		build(2*i, l, mid);
		build(2*i+1, mid+1, r);
		T[i] = min(T[2*i], T[2*i+1]);
	}
}

int query(int start, int end, int x, int y, int pos){
	cout << "querying: " << start << " " << end << endl;
	if(x > end || y < start || start > end) return INF;
	if (x <= start && y >= end) return T[pos];
	int mid = (start+end)/2;
	return min(query(start, mid, x, y, 2*pos), query(mid+1, end, x, y, 2*pos+1));
}

int main(void){
	int n, q;
	cin >> n;
	a = new int[n];
	for(int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	build(1, 0, n-1);
	for (int i = 0; i < 4*n; i += 1){
		cout << T[i] << " ";
	}
	cout << endl;
	cin >> q;
	int x, y;
	while(q--){
		cin >> x >> y;
		cout << query(0, n-1, x, y, 0) << endl;
	}
}