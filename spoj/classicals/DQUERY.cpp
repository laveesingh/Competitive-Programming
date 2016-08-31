#include <bits/stdc++.h>

using namespace std;

set<int> T[100000];
int a[30005];

void build(int node, int i, int j){
	if (j < i) return;
	if(i == j){
		T[node].insert(a[i]);
		return;
	}
	mid = (i+j)/2;
	build(2*node, i, mid);
	build(2*node+1, mid+1, j);
	T[node] = set_union(T[node*2], T[2*node+1]);
}

int query

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

}
