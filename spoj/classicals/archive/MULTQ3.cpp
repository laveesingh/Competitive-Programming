#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define max 100001

// class Node{
// public:
// 	vector<int> arr;
// 	Node(){
// 		arr.push_back(0);
// 		arr.push_back(0);
// 		arr.push_back(0);
// 	}
// 	friend ostream &operator<<(ostream &output, Node a){
// 		output << a.arr[0] << "," << a.arr[1] << "," << a.arr[2];
// 		return output;
// 	}
// };

// // Node *tree;
int tree[max<<2][3];
int lazy[max<<2], n;

void swap1(int &a, int &b, int &c){
	int ta, tb, tc;
	ta = a;
	tb = b;
	tc = c;
	b = ta;
	c = tb;
	a = tc;
}

void swap2(int &a, int &b, int &c){
	int ta,  tb, tc;
	ta = a;
	tb = b;
	tc = c;
	a = tb;
	b = tc;
	c = ta;
}

// Node add(Node a, Node b){
// 	Node temp;
// 	for (int i = 0; i < 3; i += 1){
// 		temp.arr[i] = a.arr[i]+b.arr[i];
// 	}
// 	return temp;
// }

void build(int node, int i, int j){
	// cout << "Looking to build for " << i << " " << j << endl;
	if( i == j){
		tree[node][0] = 1;
		tree[node][1] = tree[node][2] = 0;
	}else{
		build(2*node, i, (i+j)/2);
		build(2*node+1, (i+j)/2+1, j);
		// tree[node] = add(tree[node*2], tree[2*node+1]);
		tree[node][1] = tree[node][2] = 0;
		tree[node][0] = tree[node*2][0]+tree[node*2+1][0];
	}
}

// void cycle(vector<int>& arr, int n){
// 	n %= 3;
// 	int temp;
// 	if(n == 1){
// 		temp = arr[2];
// 		arr[2] = arr[1];
// 		arr[1] = arr[0];
// 		arr[0] = temp;
// 	}else if(n == 2){
// 		temp = arr[1];
// 		arr[1] = arr[2];
// 		arr[2] = arr[0];
// 		arr[0] = temp;
// 	}
// }

void update(int node, int tl, int tr, int i, int j){
	
	if(lazy[node] != 0){
		if(tl != tr){
			lazy[2*node] = (lazy[node]+lazy[2*node])%3;
			lazy[2*node+1] = (lazy[node]+lazy[2*node+1])%3;
		}
		// cycle(tree[node].arr, lazy[node]);
		if(lazy[node] == 1){
			swap1(tree[node][0], tree[node][1], tree[node][2]);
		}
		if(lazy[node]==2){
			swap2(tree[node][0], tree[node][1], tree[node][2]);
		}
		lazy[node] = 0;
	}
	if(tl > tr || i > tr || j < tl) return;
	if(i <= tl && j >= tr){
		
		if(tl != tr){
			lazy[2*node] = (1 + lazy[2*node])%3;
			lazy[2*node+1] = (1 + lazy[2*node+1])%3;
		}
		// cycle(tree[node].arr, 1);
		swap1(tree[node][0], tree[node][1], tree[node][2]);
		return;
	}
	int mid = (tl+tr)/2;
	update(node*2, tl, mid, i, j);
	update(node*2+1, mid+1, tr, i, j);
	// tree[node] = add(tree[node*2], tree[2*node+1]);
	for (int k = 0; k < 3; k += 1){
		tree[node][k] = tree[2*node][k] + tree[2*node + 1][k];
	}
}

int Query(int node, int tl, int tr, int i, int j){
	if(lazy[node] != 0){
		// cycle(tree[node].arr, lazy[node]);
		if(tl != tr){
			lazy[2*node] = (lazy[node] + lazy[2*node])%3;
			lazy[2*node + 1] = (lazy[node] + lazy[2*node+1])%3;
		}
		if(lazy[node] == 1){
			swap1(tree[node][0], tree[node][1], tree[node][2]);
		}
		if(lazy[node] == 2){
			swap2(tree[node][0], tree[node][1], tree[node][2]);
		}
		lazy[node] = 0;
	}
	if(tl > tr || i > tr || j < tl){
		return 0;
	}
	if(i <= tl && j >= tr){
		return tree[node][0];
	}
	int mid = (tl+tr)/2;
	return (Query(2*node, tl, mid, i, j) + Query(2*node+1, mid+1, tr, i, j));

}



int main(void){
	int q, type, x, y;
	scanf("%d %d", &n, &q);
	build(1, 0, n-1);
	fill_n(lazy, 4*n+1, 0);
	for (int query = 0; query < q; query += 1){
		scanf("%d %d %d", &type, &x, &y);
		if(type == 1){
			printf("%d\n", Query(1, 0, n-1, x, y));
		}else{
			update(1, 0, n-1, x, y);
		}
		// cout << "Current tree is: " << endl;
		// for (int i = 0; i < 8; i += 1){
		// 	cout << tree[i] << " ";
		// }
		// cout << endl;
	}
}