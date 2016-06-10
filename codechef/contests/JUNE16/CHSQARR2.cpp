#include <cstdio>
#include <algoritm>

using namespace std;
 
#define p(n) (int)pow(2, n)
#define pii pair<int,int>
#define mp make_pair
#define INF 1000000000
 
int **matrix;
int **sum;
int ***M;
int n, m;
 
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
 
void precompute_max1d(int x){
	int N = m;
	for (int i = 0; i < N; i += 1){
		M[x][i][0] = i;
	}
	for (int j = 1; 1<<j <= N; j += 1){
		for (int i = 0; i+(1<<j)-1 < N; i += 1){
			if(matrix[x][M[x][i][j-1]] > matrix[x][M[x][i+(1<<(j-1))][j-1]])
				M[x][i][j] = M[x][i][j-1];
			else
				M[x][i][j] = M[x][i+(1<<(j-1))][j-1];
		}
	}
}
 
void precompute_max(){
	for (int i = 0; i < n; i += 1){
		precompute_max1d(i);
	}
}
 
int calculate_max1d(int x, int i, int j){
	int k = (int)log2(j-i+1);
	return max(matrix[x][M[x][i][k]], matrix[x][M[x][j-(1<<k)+1][k]]);
}
 
int query(int x, int y){
	int qmax[n][m-y+1];
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < m-y+1; j += 1){
			qmax[i][j] = calculate_max1d(i, j, j+y-1);
		}
	}
	// cout << "Here's the qmax matrix: " << endl;
	// for (int i = 0; i < n; i += 1){
	// 	for (int j = 0; j < m-y+1; j += 1){
	// 		cout << qmax[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "Out of precomputing qmax" << endl;
	int minimum_time = INF;
	for (int i = 0; i < n-x+1; i += 1){
		for (int j = 0; j < m-y+1; j += 1){
			int i1 = i, j1 = j, i2 = i+x-1, j2 = j+y-1;
			// cout << "submatrix bound: " << i1 << "," << j1 << " and " << i2 << "," << j2 << endl ;
			// cout << "calculating sum for " << i1 << " " << j1 << " and " << i2 << " " << j2 ;
			// cout << "Bounds are: " << i1 << " " << j1 << " and " << i2 << " " << j2 ;
			int sum_sub = calculate_sum(i1,j1, i2,j2);
			// cout << " Sum: " << sum_sub << endl ;
			int cur_maximum = qmax[i1][j1];
			// cout << "Here's the qmax matrix: " << endl;
			// for (int i = 0; i < n; i += 1){
			// 	for (int j = 0; j < m-y+1; j += 1){
			// 		cout << qmax[i][j] << " ";
			// 	}
			// 	cout << endl;
			// }
			for (int ii = i1; ii <= i2; ii += 1){
				// cout << "q[" << ii << "][" << j1 <<"] to q["<< ii << "][" << j2 << "] : " << qmax[ii][j1] << endl;
				cur_maximum = max(cur_maximum, qmax[ii][j1]);
			}
			// cout << "Max for this bound: " << cur_maximum << " Sum for this bound: " << sum_sub << endl;
			int cur_time = cur_maximum*x*y - sum_sub;
			minimum_time = min(minimum_time, cur_time);
			// cout << "Minimum time for this bound; " << cur_time << endl;
		}
	}
	return minimum_time;
}
 
int main(void){
	// cout << "Enter n and m: " << endl;
	scanf("%d %d", &n, &m);
	int i1,i2,j1,j2, x, q, y;
	matrix = new int*[n];
	sum = new int*[n];
	M = new int**[n];
	// cout << "starting entering the values" << endl;
	for (int i = 0; i < n; i += 1){
		matrix[i] = new int[m];
		sum[i] = new int[m];
		M[i] = new int*[m];
		// cout << "First row please: " << endl;
		for (int j = 0; j < m; j += 1){
			M[i][j] = new int[(int)log2(m)+2];
		}
		for (int j = 0; j < m; j += 1){
			scanf("%d", &matrix[i][j]);
		}
	}
	// cout << "Precomputing sum: " << endl;
	precompute_sum();
	precompute_max();
	scanf("%d", &q);
	for (int i = 0; i < q; i += 1){
		scanf("%d %d", &x, &y);
		// cout << calculate_max1d(0, x, y) << endl;
		printf("%d\n", query(x,y));
	}
} 