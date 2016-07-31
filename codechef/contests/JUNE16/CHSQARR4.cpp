#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int T[16000001], **matrix, n, m, **sum;

int max(int a, int b, int c, int d){
	return max(max(a,b), max(c,d));
}

void precompute_sum(){
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < m; j += 1){
			if (j == 0){
				sum[i][j] = matrix[i][j];
			}else{
				sum[i][j] = sum[i][j-1]+matrix[i][j];
			}
		}
	}
	for (int j = 0; j < m; j += 1){
		for (int i = 1; i < n; i += 1){
			sum[i][j] = sum[i-1][j]+sum[i][j];
		}
	}
	// Print(sum, n, m);
}


int calculate_sum(int i1, int j1, int i2, int j2){
	cout << "Calculating for "<< i1 << " " << j1 << " " << i2 << " " << j2 << endl;

	if (i1 == 0 && j1 == 0){
		cout <<" Found: " << sum[i2][j2] << endl;
		return sum[i2][j2];
	}else if(i1 == 0){
		return calculate_sum(0,0,i2,j2) - calculate_sum(0,0,i2,j1-1);
	}else if(j1 == 0){
		return calculate_sum(0,0,i2,j2) - calculate_sum(0,0,i1-1,j2);
	}else{
		return calculate_sum(0, 0, i2, j2)-calculate_sum(0,0,i1-1,j2)-calculate_sum(i1,0,i2,j1-1);
	}
}

// recursively build segment tree
void build(int node, int a1, int b1, int a2, int b2){
	// cout << "Looking to build for: " << a1 << " " << b1 << "  and " << a2 << " " << b2 << endl;
	if (a1 > a2 || b1 > b2) return;
	if(a1 > n-1 || b1 > m-1) return;
	if (a1 == a2 && b1 == b2){
		// cout << "Geting first: ";
		T[node] = matrix[a1][b1];
		// cout << "maximum element in bound: " << a1 << " " << b1 << "  and " << a2 << " " << b2 << " is " << T[node] << endl;
	}else{
		build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 );
		build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 );
		build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2);
		build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2);
		// cout << "Getting second: ";
		T[node] = max(T[node*4-2], T[node*4-1], T[node*4], T[node*4+1]);
		// cout << "maximum element in bound: " << a1 << " " << b1 << "  and " << a2 << " " << b2 << " is " << T[node] << endl;
	}
}

int query(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2){
	if (x1 > a2 || y1 > b2 || x2 < a1 || y2 < b1 || a1 > a2 || b1 > b2) {
		cout << "For query " << a1 << " " << b1 << " and " << a2 <<" " << b2 << "returning max " << -INF << endl;
		return -INF;
	}
	if (x1 <= a1 && y1 <= b1 && a2 <= x2 && b2 <= y2) {
		cout << "For query " << a1 << " " << b1 << " and " << a2 <<" " << b2 << "returning max " << T[node] << endl;
		return T[node];
	}
	/*
	if(x2 <= (a1+a2)/2 && y2 <= (b1+b2)/2){
		return query(4*node-2, a1, b1, (a1+a2)/2, (b1+b2)/2, x1, y1, x2, y2);
	}
	if(x2 <= (a1+a2)/2){
		int mx1 =  query(4*node-2, a1, b1, (a1+a2)/2, (b1+b2)/2, x1, y1, x2, y2);
		int mx2 = query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2+1, b2, x1, y1, x2, y2);
		return max(mx1, mx2);
	}
	if(y2 <= (b1+b2)/2){
		int mx1 = query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2);
		int mx2 = query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2);
		return max(mx1, mx2);
	}
	if(x1 > (a1+a2)/2 && y1 > (b1+b2)/2){
		return query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2);

	}
	if(x1 > (a1+a2)/2){
		int mx2 = query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2);
		int mx4 = query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2);
		return max(mx2, mx4);
	}
	if(y1 > (b1+b2)/2){
	int mx3 = query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2+1, b2, x1, y1, x2, y2);
	int mx4 = query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2);
		return max(mx3, mx4);
	}
	*/
	int mx1 = query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2);
	int mx2 = query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2);
	int mx3 = query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2+1, b2, x1, y1, x2, y2);
	int mx4 = query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2);
	cout << "For query " << a1 << " " << b1 << " and " << a2 <<" " << b2 << "returning max " << max(mx1, mx2, mx3, mx4) << endl;
	return max(mx1, mx2, mx3, mx4);
}

int query(int x1, int y1, int x2, int y2){
	return query(1, 0, 0, n-1, m-1, x1, y1, x2, y2);
}

int ans(int x, int y){
	int mintime = INF;
	for (int i = 0; i < n-x+1; i += 1){
		for (int j = 0; j < m-y+1; j += 1){
			int i1 = i, j1 = j, i2 = i+x-1, j2 = j+y-1;
			int maxelem = query(i1,j1,i2,j2);
			int cursum = calculate_sum(i1,j1,i2,j2);
			// cout << "For bounds " << i1 << " " << j1 << " and " << i2 << " " << j2 << " max is " << maxelem << " and sum is " << cursum << endl;
			mintime = min(mintime, maxelem*x*y - cursum);
		}
	}
	return mintime;
}

int main(void){
	scanf("%d %d", &n, &m);
	int i1, i2, j1, j2, x, y, q, a1, a2, b1, b2;

	matrix = new int*[n];
	sum = new int*[n];

	for (int i = 0; i < n; i += 1){
		matrix[i] = new int[m];
		sum[i] = new int[m];
		for (int j = 0;j < m; j += 1){
			scanf("%d", &matrix[i][j]);
		}
	}
	precompute_sum(); // precomputation of sum
	build(1, 0, 0, n-1, m-1); // segment tree building
	do{
		cin >> i1 >> j1 >> i2 >> j2;
		cout << query(i1, j1, i2,j2) << endl;
	}while(1);
	// cout << "Here is the tree : ";
	// for (int i = 0; i < 24; i += 1){
	// 	cout << T[i] << " ";
	// }
	// cout << endl;
	// scanf("%d", &q);
	// for (int i = 0; i < q; i += 1){
	// 	scanf("%d %d", &x, &y);
	// 	printf("%d\n", ans(x, y));
	// }
}
