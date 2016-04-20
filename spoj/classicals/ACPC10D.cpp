#include <iostream>

using namespace std;

long long **a;

long long min(long long a, long long b){
	if (a <= b) return a;
	return b;
}

long long min(long long a, long long b, long long c){
	if (a <= b && a <= c) return a;
	if (b <= c ) return b;
	return c;
}

long long solve(long long n, int i, int j){

}

int main(void){
	long long n;
	cin >> n;
	long long test = 1;
	do{

		a = new long long*[n];
		for (long long i = 0; i < n; i += 1){
			a[i] = new long long[3];
		}
		for (long long i = 0; i < n; i += 1){
			for (long long j = 0; j < 3; j += 1){
				cin >> a[i][j];
			}
		}
		cout << test << ". " << solve(a, n) << endl;

		cin >> n;
		test += 1;
		delete[] a;
	}while(n);

}