#include <bits/stdc++.h>

using namespace std;

#define INF 1000000000

int **P, n, m, **sum;

int max(int a, int b, int c, int d){
	return max(max(a,b), max(c,d));
}

void precompute_sum(){
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < m; j += 1){
			if (j == 0){
				sum[i][j] = P[i][j];
			}else{
				sum[i][j] = sum[i][j-1]+P[i][j];
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
	// cout << "Calculating for "<< i1 << " " << j1 << " " << i2 << " " << j2 << endl;

	if (i1 == 0 && j1 == 0){
		// cout <<" Found: " << sum[i2][j2] << endl;
		return sum[i2][j2];
	}else if(i1 == 0){
		return calculate_sum(0,0,i2,j2) - calculate_sum(0,0,i2,j1-1);
	}else if(j1 == 0){
		return calculate_sum(0,0,i2,j2) - calculate_sum(0,0,i1-1,j2);
	}else{
		return calculate_sum(0, 0, i2, j2)-calculate_sum(0,0,i1-1,j2)-calculate_sum(i1,0,i2,j1-1);
	}
}




















/* 2D Segment Tree node */
struct Point {
    int x, y, mx;
    Point() {}
    Point(int x, int y, int mx) : x(x), y(y), mx(mx) {}

    bool operator < (const Point& other) const {
        return mx < other.mx;
    }
};

struct Segtree2d {
    Point T[16000000]; // TODO: calculate the accurate space needed
    int n, m;

    // initialize and construct segment tree
    void init(int n, int m) {
        this -> n = n;
        this -> m = m;
        // cout << "Now building the tree" << endl;
        build(1, 0, 0, n-1, m-1);
    }

    // build a 2D segment tree from data [ (a1, b1), (a2, b2) ]
    // Time: O(n logn)
    Point build(int node, int a1, int b1, int a2, int b2) {
        // out of range
        // cout << "Building for " << a1 << " " << b1 << " and " << a2 << " " << b2 << endl;
        if (a1 > a2 or b1 > b2)
            return def();

        // if it is only a single index, assign value to node
        if (a1 == a2 and b1 == b2)
            return T[node] = Point(a1, b1, P[a1][b1]);

        // split the tree into four segments
        T[node] = def();
        T[node] = maxNode(T[node], build(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2 ) );
        T[node] = maxNode(T[node], build(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2 ));
        T[node] = maxNode(T[node], build(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2) );
        T[node] = maxNode(T[node], build(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2) );
        return T[node];
    }

    Point query(int node, int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2) {
        if (x1 > a2 or y1 > b2 or x2 < a1 or y2 < b1 or a1 > a2 or b1 > b2)
            return def();

        if (x1 <= a1 and y1 <= b1 and a2 <= x2 and b2 <= y2)
            return T[node];

        Point mx = def();
        mx = maxNode(mx, query(4 * node - 2, a1, b1, (a1 + a2) / 2, (b1 + b2) / 2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node - 1, (a1 + a2) / 2 + 1, b1, a2, (b1 + b2) / 2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node + 0, a1, (b1 + b2) / 2 + 1, (a1 + a2) / 2, b2, x1, y1, x2, y2) );
        mx = maxNode(mx, query(4 * node + 1, (a1 + a2) / 2 + 1, (b1 + b2) / 2 + 1, a2, b2, x1, y1, x2, y2));

        return mx;
    }

    int query(int x1, int y1, int x2, int y2) {
        return query(1, 0, 0, n-1, m-1, x1, y1, x2, y2).mx;
    }


    virtual Point maxNode(Point a, Point b) {
        return max(a, b);
    }

    virtual Point def() {
        return Point(0, 0, -INF);
    }
};

Segtree2d Tmax;











int ans(int x, int y){
	int mintime = INF;
	for (int i = 0; i < n-x+1; i += 1){
		for (int j = 0; j < m-y+1; j += 1){
			int i1 = i, j1 = j, i2 = i+x-1, j2 = j+y-1;
			int maxelem = Tmax.query(i1,j1,i2,j2);
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

	P = new int*[n];
	sum = new int*[n];

	for (int i = 0; i < n; i += 1){
		P[i] = new int[m];
		sum[i] = new int[m];
		for (int j = 0;j < m; j += 1){
			scanf("%d", &P[i][j]);
		}
	}
	// cout << "The matrix is filled" << endl;
	precompute_sum(); // precomputation of sum
	// cout << "Sum is precomputed" << endl;




	Tmax.init(n, m);
	// cout << "Tree is initialized " << endl;





	scanf("%d", &q);
	for (int i = 0; i < q; i += 1){
		scanf("%d %d", &x, &y);
		printf("%d\n", ans(x, y));
	}
}
