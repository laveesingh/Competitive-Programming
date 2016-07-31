#include <iostream>
#include <deque>

using namespace std;

#define INF 1000000000

int **matrix, **sum, **dpmax, **tempmax;
int n, m;

int max(int a, int b){
	if (a >= b) return a;
	return b;
}

int max(int a, int b, int c, int d){
	return max(max(a,b), max(c,d));
}

void print(deque<int> a){
	for(deque<int>::iterator it = a.begin(); it != a.end(); it++){
		cout << *it << " ";
	}
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
}


int calculate_sum(int i1, int j1, int i2, int j2){

	if (i1 == 0 && j1 == 0){
		return sum[i2][j2];
	}else if(i1 == 0){
		return calculate_sum(0,0,i2,j2) - calculate_sum(0,0,i2,j1-1);
	}else if(j1 == 0){
		return calculate_sum(0,0,i2,j2) - calculate_sum(0,0,i1-1,j2);
	}else{
		return calculate_sum(0, 0, i2, j2)-calculate_sum(0,0,i1-1,j2)-calculate_sum(i1,0,i2,j1-1);
	}
}

void precompute_max(int x, int y){
	tempmax = new int*[n];
	dpmax = new int*[n];
	for(int i = 0; i < n; i += 1){
		tempmax[i] = new int[m];
		dpmax[i] = new int[m];
	}
	for(int i = 0; i < n; i += 1){
		int k = y;
		deque<int> q;
		for(int j = 0; j < k; j += 1){
			while(!q.empty() && matrix[i][j] >= matrix[i][q.back()]){
				q.pop_back();
			}
			q.push_back(j);
		}
		for(int j = k; j < m; j += 1){
			tempmax[i][j-1] = matrix[i][q.front()];
			while(!q.empty() && j-k >= q.front()){
				q.pop_front();
			}

			while(!q.empty() && matrix[i][j] >= matrix[i][q.back()]){
				q.pop_back();
			}
			q.push_back(j);
		}
		tempmax[i][m-1] = matrix[i][q.front()];
	}
	// cout << "Here's the tempmax array: " << endl;
	// for(int i = 0; i < n; i += 1){
	// 	for (int j = 0; j < m; j += 1){
	// 		cout << tempmax[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int j = 0; j < m; j += 1){
		int k = x;
		deque<int> q;
		for(int i = 0; i < k; i += 1){
			while(!q.empty()  && tempmax[i][j] >= tempmax[q.back()][j]){
				q.pop_back();
			}
			q.push_back(i);
		}
		for(int i = k; i < n; i += 1){
			dpmax[i-1][j] = tempmax[q.front()][j];
			while(!q.empty() && i-k >= q.front()){
				q.pop_front();
			}

			while(!q.empty() && tempmax[i][j] >= tempmax[q.back()][j]){
				q.pop_back();
			}
			q.push_back(i);
		}
		dpmax[n-1][j] = tempmax[q.front()][j];
	}
	// cout << "Here's the dpmax array: " << endl;
	// for(int i = 0; i < n; i += 1){
	// 	for (int j = 0; j < m; j += 1){
	// 		cout << dpmax[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
}




int query(int x, int y){
	int mtime = INF;
	for (int i = 0; i < n-x+1; i += 1){
		for (int j = 0; j < m-y+1; j += 1){
			int i1 = i, j1 = j, i2 = i+x-1, j2 = j+y-1;
			int submatsum = calculate_sum(i1,j1,i2,j2);
			int submatmax = dpmax[i2][j2];
			int curtime = (submatmax*x*y)-submatsum;
			mtime = min(mtime, curtime);
		}
	}
	return mtime;
}

int main(void){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	int i1,i2,j1,j2, x, q, y;
	matrix = new int*[n];
	sum = new int*[n];
	for (int i = 0; i < n; i += 1){
		matrix[i] = new int[m];
		sum[i] = new int[m];
		for (int j = 0; j < m; j += 1){
			cin >> matrix[i][j];
		}
	}
	precompute_sum();
	cin >> q;
	for (int i = 0; i < q; i += 1){
		cin >> x >> y;
		precompute_max(x, y);
		
		cout << query(x, y) << endl;
	}

}