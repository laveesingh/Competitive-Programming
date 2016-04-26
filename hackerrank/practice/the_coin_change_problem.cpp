#include <iostream>
#include <map>
#include <utility>

using namespace std;

map<pair<int, int>,long long> store;
long long solve(int a[], int m, int n){
	if (n==0) return 1;
	if (n < 0) return 0;
	if (m <= 0 && n >= 1) return 0;
	long long x = store[make_pair(m-1,n)];
	x = x ? x : solve(a, m-1,n);
	store[make_pair(m-1,n)] = x;
	long long y = store[make_pair(m,n-a[m-1])];
	y = y ? y : solve(a,m,n-a[m-1]);
	store[make_pair(m,n-a[m-1])] = y;
	return x+y;
	// return solve(a, m-1,n)+solve(a,m,n-a[m-1]);
}

int main(void){
	int n, m;
	cin >> n >> m;
	int a[m];
	for (int i = 0; i < m; i += 1){
		cin >> a[i];
	}
	cout << solve(a, m, n) << endl;
}