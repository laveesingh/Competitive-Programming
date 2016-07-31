#include <bits/stdc++.h>


using namespace std;


#define pii pair<int, int>

int **a, ans = 1,points=0;
vector<pii> positions;

void print(int *a, int n){
	for (int i = 0; i < n; i += 1){
		cout << a[i] << " ";
	}
	cout << endl;
}

void fill(int i, int j, int n, int m){
	if (m == 1 || m == 0){
		return;
	}
	// cout << "First" << endl;
	for (int jj = j; jj < n-j; jj += 1){
		a[i][jj] = ans++;
		if(a[i][jj]%11 == 0){
			positions.push_back({i,jj});
			points++;
		}
	}
	// cout << "Second " << endl;
	for (int ii = i+1; ii < n-i; ii += 1){
		a[ii][n-j-1] = ans++;
		if(a[ii][n-j-1]%11 == 0){
			positions.push_back({ii,n-j-1});
			points++;
		}
	}
	// cout << "Third" << endl;
	for (int jj = n-j-2; jj > j; jj -= 1){
		a[n-i-1][jj] = ans++;
		if(a[n-i-1][jj]%11 == 0){
			positions.push_back({n-i-1,jj});
			points++;
		}
	}
	// cout << "Fourth" << endl;
	for (int ii = n-i-1; ii > i; ii -= 1){
		a[ii][j] = ans++;
		if(a[ii][j]%11 == 0){
			positions.push_back({ii,j});
			points++;
		}
	}
	// cout << "After fill m = " << m << endl;
	// for (int i = 0; i <n; i += 1){
	// 	print(a[i], n);
	// }
	fill(i+1,j+1,n,m-1);
}

int main(void){
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	a = new int*[n];
	for (int i = 0; i < n; i += 1){
		a[i] = new int[n];
	}
	a[0][0] = 1;
	fill(0, 0, n, n);
	// for (int i = 0; i < n; i += 1){
	// 	print(a[i],n);
	// }
	cout << "Total Power points : " << points+1 << endl;
	cout << "(0,0)" << endl;
	for (pii x: positions){
		cout << "(" << x.first << "," << x.second << ")" << endl;
	}
}