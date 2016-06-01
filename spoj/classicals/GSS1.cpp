#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 70000

struct no{
	int lsum, rsum, msum;
};

int array[MAX+1], sums[MAX+1];

no tree[4*MAX+1];

void init(int node, int i, int j){
	if (i == j){
		tree[node] = (no){array[i],array[i],array[i]};
	}else{
		init(node*2, i, (i+j)/2);
		init(node*2+1, (i+j)/2 + 1, j);
		no left = tree[node*2];
		no right = tree[node*2+1];
		tree[node].lsum = max(left.lsum, sums[(i+j)/2]-sums[i-1]+right.lsum);
		tree[node].rsum = max(right.rsum, sums[j]-sums[(i+j)/2]+left.rsum);
		tree[node].msum = max(left.msum, max(right.msum, right.lsum+left.rsum));
	}
}

no query(int node, int a, int b, int i, int j){
	if(a == i && b == j){
		return tree[node];
	}else if(j <= (a+b)/2){
		return query(node*2, a, (a+b)/2, i, j);
	}else if(i > (a+b)/2){
		return query(node*2+1, (a+b)/2+1,b,i,j);
	}
	no left = query(node*2, a, (a+b)/2, i, (a+b)/2);
	no right = query(node*2+1,(a+b)/2+1, b, (a+b)/2+1, j);
	return (no){
		max(left.lsum, sums[(a+b)/2]-sums[i-1]+right.lsum),
		max(right.rsum, sums[b]-sums[(a+b)/2]+left.rsum),
		max(left.msum, max(right.msum, left.rsum+right.lsum))
	};
}



int main(void){
	int n, q, l, r;
	scanf("%d", &n);
	scanf("%d",&array[0]);
	sums[0] = array[0];
	for(int i = 1; i < n; i += 1){
		scanf("%d",&array[i]);
		sums[i] = sums[i-1]+array[i];
	}
	init(1, 0, n-1);
	scanf("%d", &q);
	for (int i = 0; i < q; i += 1){
		scanf("%d %d", &l, &r);
		printf("%d\n", query(1,0,n-1,l-1,r-1).msum);
	}
}