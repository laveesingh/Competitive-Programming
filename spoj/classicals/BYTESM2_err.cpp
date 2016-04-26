#include <iostream>
#include <algorithm>
#include <map>
#include <utility>


using namespace std;

int **a;
map<pair<int, int>, int> store;

int maxpath(int i, int j, int n){
	if (i == 0){
		return a[i][j];
	}
	if (j== 0){
		int f = store[make_pair(i-1, j)] ? store[make_pair(i-1, j)] : maxpath(i-1, j, n);
		store[make_pair(i-1, j)] = f;
		int s = store[make_pair(i-1, j+1)] ? store[make_pair(i-1, j+1)] :maxpath(i-1, j+1, n);
		store[make_pair(i-1, j+1)] = s;
		return (a[i][j] + max(f, s));
	}
	if (j == n-1){
		int f = store[make_pair(i-1, j)] ? store[make_pair(i-1, j)] : maxpath(i-1, j, n);
		store[make_pair(i-1, j)] = f;
		int s = store[make_pair(i-1, j-1)] ? store[make_pair(i-1, j-1)] :maxpath(i-1, j-1, n);
		store[make_pair(i-1, j+1)] = s;
		return (a[i][j] + max(f, s));
	}
	int f = store[make_pair(i-1, j)] ? store[make_pair(i-1, j)] : maxpath(i-1, j, n);
	store[make_pair(i-1, j)] = f;
	int s = store[make_pair(i-1, j+1)] ? store[make_pair(i-1, j+1)] :maxpath(i-1, j+1, n);
	store[make_pair(i-1, j+1)] = s;
	int t = store[make_pair(i-1, j-1)] ? store[make_pair(i-1, j-1)] :maxpath(i-1, j-1, n);
	store[make_pair(i-1, j-1)] = t;
	return (a[i][j] + max(max(f, s), t));
}

int solve(){
	int m, n;
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
	// for (int i = 0; i < m; i += 1){
	// 	for (int j = 0; j < n; j += 1){
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// vector<int> temp;
	// for (int i = 0; i < n; i += 1){
	// 	temp.push_back(maxpath(m-1, i, n));
	// }
	// int maxx = temp[0];
	// for (int i = 1; i < temp.size(); i += 1){
	// 	if (temp[i] > maxx) maxx = temp[i];
	// }
	int temp[n];
	for (int i = 0; i < n; i += 1){
		temp[i] = maxpath(m-1, i, n);
	}
	int maxx = temp[0];
	for (int i = 1; i < n; i += 1){
		if (temp[i] > maxx) maxx = temp[i];
	}
	return maxx;
}

int main(void){
	int t;
	cin >> t;
	while (t--){
		cout << solve() << endl;;
	}
}