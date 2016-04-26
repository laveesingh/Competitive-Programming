#include <iostream>

using namespace std;

bool solve(long long n, long long m){
	if (n == 1) return m == 2;
	if (m == 1) return n == 2;	
	return (n%2 == 0) || (m%2 == 0);
}

int main(void){
	int t;
	long long m, n;
	cin >> t;
	for (int i = 0; i < t; i += 1){
		cin >> m >> n;
		cout << (solve(m,n)?"Yes":"No") << endl;
	}
}