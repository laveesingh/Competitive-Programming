#include <bits/stdc++.h>

using namespace std;

#define p(n) (int)pow(2, n)
#define pii pair<int,int>
#define mp make_pair
#define INF 1000000000

int **matrix;
int **sum;
int M[1000][1000][10][10];
int n, m;

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

void precompute_max(){
	for (int i = 0 ; (1<<i) <= n; i += 1){
	    for(int j = 0 ; (1<<j) <= m ; j += 1){
	        for (int x = 0 ; x + (1<<i) -1 < n; x+= 1){
	            for (int y = 0 ;  y + (1<<j) -1 < m; y+= 1){
	                if (i == 0 and j == 0)
	                    M[x][y][i][j] = matrix[x][y]; // store x, y
	                else if (i == 0)
	                    M[x][y][i][j] = max(M[x][y][i][j-1], M[x][y+(1<<(j-1))][i][j-1]);
	                else if (j == 0)
	                    M[x][y][i][j] = max(M[x][y][i-1][j], M[x+ (1<<(i-1))][y][i-1][j]);
	                else 
	                    M[x][y][i][j] = max(M[x][y][i-1][j-1], M[x + (1<<(i-1))][y][i-1][j-1], M[x][y+(1<<(j-1))][i-1][j-1], M[x + (1<<(i-1))][y+(1<<(j-1))][i-1][j-1]);
	                // cout << "from i="<<x<<" j="<<y<<" of length="<<(1<<i)<<" and length="<<(1<<j) <<"max is: " << M[x][y][i][j] << endl;
	            }
	        }
	    }
	}
}

int compute_max(int x, int y, int x1, int y1){
	int k = log2(x1 - x + 1);
	int l = log2(y1 - y + 1);
	// cout << "Value of k="<<k<<" l="<<l<<endl;
	int ans = max(M[x][y][k][l], M[x1 - (1<<k) + 1][y][k][l], M[x][y1 - (1<<l) + 1][k][l], M[x1 - (1<<k) + 1][y1 - (1<<l) + 1][k][l]);
	return ans;
}

int query(int x, int y){
	int mtime = INF;
	for (int i = 0; i < n-x+1; i += 1){
		for (int j = 0; j < m-y+1; j += 1){
			int i1 = i, j1 = j, i2 = i+x-1, j2 = j+y-1;
			// cout << "submatrix bound: " << i1 << "," << j1 << " and " << i2 << "," << j2 << endl;
			int submatsum = calculate_sum(i1,j1,i2,j2);
			int submatmax = compute_max(i1,j1,i2,j2);
			// cout << "Max for this bound; " << submatmax << " max for this bound; " << submatsum << endl;
			int curtime = (submatmax*x*y)-submatsum;
			mtime = min(mtime, curtime);
			// cout << "Minimum time for this bound: " << curtime << endl;
		}
	}
	return mtime;
}

int main(void){
	// cout << "Enter n and m: " << endl;
	scanf("%d %d", &n, &m);
	int i1,i2,j1,j2, x, q, y;
	matrix = new int*[n];
	sum = new int*[n];
	// M = new int**[n];
	// cout << "starting entering the values" << endl;
	for (int i = 0; i < n; i += 1){
		matrix[i] = new int[m];
		sum[i] = new int[m];
		// M[i] = new int*[m];
		// cout << "First row please: " << endl;
		// for (int j = 0; j < m; j += 1){
			// M[i][j] = new int[(int)log2(m)+2];
		// }
		for (int j = 0; j < m; j += 1){
			scanf("%d", &matrix[i][j]);
		}
	}
	// cout << "Precomputing sum: " << endl;
	precompute_sum();
	precompute_max();
	// cout << "Max in the given bounds is " << compute_max(0, 0, 6, 1) << endl;
	scanf("%d", &q);
	for (int i = 0; i < q; i += 1){
		scanf("%d %d", &x, &y);
		// cout << calculate_max1d(0, x, y) << endl;
		printf("%d\n", query(x,y));
	}
	// do{
	// 	cin >> i1 >> j1 >> i2 >> j2;
	// 	cout << compute_max(i1, j1, i2, j2) << endl;
	// }while(1);
}