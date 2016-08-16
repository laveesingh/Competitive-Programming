/*input
4 6
1 2
1 4
1 2
3 3
1 3
1 3
*/

#include <bits/stdc++.h>

using namespace std;

#define limit 300000
#define ll long long

int T[4*limit + 4], n, q;
vector<int> fupd; // first type updates

void build(int node, int i, int j){
	if (i == j){
		T[node] = 0;
		return;
	}
	int mid = (i+j)/2;
	build(2*node, i, mid);
	build(2*node+1, mid+1, j);
	T[node] = T[2*node]+T[2*node+1];
	return;
}

void inc(int node, int st, int en, int i){
	if (i < st || i > en) return;
	if (st == en){
		T[node] += 1;
		return;
	}
	int mid = (st+en)/2;
	inc(2*node, st, mid, i);
	inc(2*node+1, mid+1, en, i);
	T[node] = T[2*node] + T[2*node+1];
}

void dec(int node, int st, int en, int i){
	if (i < st || i > en) return ;
	if (st == en){
		T[node] -= (T[node] > 0 ? 1 : 0);
		return;
	}
	int mid = (st+en)/2;
	dec(2*node, st, mid, i);
	dec(2*node+1, mid+1, en, i);
	T[node] = T[2*node] + T[2*node+1];
}

void setz(int node, int st, int en, int i){
	if (i < st || i > en) return;
	if (st == en){
		T[node] = 0;
		return;
	}
	int mid = (st+en)/2;
	setz(2*node, st, mid, i);
	setz(2*node+1, mid+1, en, i);
	T[node] = T[2*node] + T[2*node+1];
}

void update3(int t){
	for (int i = 0; i < t; i += 1){
		dec(1, 0, n-1, fupd[i]);
	}
}



int main(void){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	build(1, 0, n-1);
	int type, x;
	for (int qu = 0; qu < q; qu += 1){
		cin >> type >> x;
		if (type == 1){
			x -= 1;
			fupd.push_back(x);
			inc(1, 0, n-1, x);
		}else if(type == 2){
			x -= 1;
			setz(1, 0, n-1, x);
		}else{
			update3(x);
		}
		cout << T[1] << endl;
	}
}