#include <iostream>
#include <map>

using namespace std;

#define pii pair<int, int>
#define mp make_pair

int **a;

int max(int a, int b, int c){
	if (a >= b && a >= c) return a;
	if (b >= c) return b;
	return c;
}

int solve(int m, int n){
	map <pii, pii> store;
	int fi, si;
	int arr[m][n];
	for (int i = 0; i < n; i += 1){
		arr[0][i] = 0;
		store[mp(0,i)] = mp(1,1);
	}
	for (int i = 0; i < m; i += 1){
		arr[i][0] = 0;
		store[mp(i,0)] = mp(1,1);
	}
	int maxi = 1;
	for (int i = 1; i < m; i += 1){
		for (int j = 1; j < n; j += 1){
			if (max(a[i-1][j], a[i-1][j-1], a[i][j-1]) < a[i][j]){
				cout << "Here it goes" << endl;
				cout << "max : " << max(a[i-1][j], a[i-1][j-1], a[i][j-1]) << ": " << a[i][j] << endl;
				fi = store[mp(i-1,j)].first + 1;
				si = store[mp(i,j-1)].second + 1;
				store[mp(i,j)] = mp(fi,si);
				if (fi*si > maxi) maxi = f
					i*si;  
			}
		}
	}
	return maxi;
}

int main(void){
	int t, m, n;
	cin >> t;
	while (t--){
		cin >> m >> n;
		a = new int*[m];
		for (int i = 0; i < m; i += 1){
			a[i] = new int[n];
		}
		for (int i = 0; i < m; i += 1){
			for (int j = 0; j < n; j += 1){
				cin >> a[i][j];
			}
		}
		cout << solve(m, n) << endl;
	}
}