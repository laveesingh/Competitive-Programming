#include <iostream>
#include <cstdio>

using namespace std;
#define INF 100000000

class Node{
public:
	int maxsum, totalsum, lsum, rsum;
	Node(){}
	Node(int a, int b, int c, int d){
		maxsum = a;
		totalsum = b;
		lsum = c;
		rsum = d;
	}
};

Node T[200000];
int *A, n;


Node add(Node a, Node b){
	int maxsum = a.maxsum;
	maxsum = max(maxsum, b.maxsum);
	maxsum = max(maxsum, a.rsum+max(b.totalsum, b.lsum));
	maxsum = max(maxsum, b.lsum+max(a.totalsum, a.rsum));
	maxsum = max(maxsum, a.totalsum+b.totalsum);
	int lsum = max(a.lsum, a.totalsum+b.lsum);
	int rsum = max(b.rsum, b.totalsum+a.rsum);
	int totalsum = a.totalsum+b.totalsum;
	return Node(maxsum, totalsum, lsum, rsum);
}


void build(int node, int i, int j){
	// cout << "Looking to build for node= " << node << " and i= "<< i << " and j= " << j << endl;
	if(i == j){
		T[node] = Node(A[i], A[i], A[i], A[i]);
		// cout << "Setting for i = " << i << " the value = " << T[i].maxsum << " at node = " << node << endl;
	}else{
		build(2*node, i, (i+j)/2);
		build(2*node+1, (i+j)/2+1, j);
		T[node] = add(T[2*node], T[2*node+1]);
		// cout << "For i = " << i << " Setting the value = " << T[i].maxsum << " at node = " << node << endl;
	}
	// cout << "Tree till now is: ";
	// for (int i = 0; i < 20; i += 1){
	// 	cout << T[i].maxsum << " ";
	// }
	// cout << endl;
}



Node query(int node, int a, int b, int i, int j){
	// cout << "Querying node= " << node << " a= " << a << " b= " << b << " i= " << i << " j= " << j << " ";
	// if (i < a || j > b){
	// 	return Node(-INF, -INF, -INF, -INF);
	// }
	if(a == i && b == j){
		// cout << "Returning: " << T[node].maxsum << endl;
		return T[node];
	}
	if(j <= (a+b)/2){
		Node ans = query(2*node, a, (a+b)/2, i, j);
		// cout << "Returning: " << ans.maxsum << endl;
		return ans;
	}else if(i > (a+b)/2){
		Node ans = query(2*node+1, (a+b)/2+1, b, i, j);
		// cout << "Returning " << ans.maxsum << endl;
		return ans;
	}
	Node left = query(2*node, a, (a+b)/2, i, (a+b)/2);
	Node right = query(2*node+1, (a+b)/2+1, b, (a+b)/2+1, j);
	// cout << "Returning " << add(left,right).maxsum << endl;
	return add(left, right);
}

int query(int x, int y){
	Node cur =  query(1, 0, n-1, x, y);
	return cur.maxsum;
}

int main(void){
	// cin >> n;
	scanf("%d", &n);
	A = new int[n];
	for (int i = 0; i < n; i += 1){
		// cin >> A[i];
		scanf("%d", &A[i]);
	}
	// cout << "building segment tree" << endl;
	build(1, 0, n-1);
	// cout << "Built the segment tree" << endl;
	int q, x, y;
	// cout << "Here's the tree"  << endl;
	// for (int i = 0; i < 4*n; i += 1){
	// 	cout << T[i].maxsum << " " ;
	// }
	// cout << endl;
	// cin >> q;
	scanf("%d", &q);
	while(q--){
		// cin >> x >> y;
		scanf("%d %d", &x, &y);
		printf("%d\n", query(x-1, y-1));
		// cout << query(x-1, y-1) << endl;
	}
}