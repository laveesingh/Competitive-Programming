#include <iostream>
#include <algorithm>

using namespace std;

long long sum(long long a[], long long n){
	long long temp = 0;
	for (long long  i = 0; i < n; i += 1){
		temp += a[i];
	}
	return temp;
}

long long solve(long long a[], long long n){
	sort(a, a+n);
	long long temp = sum(a, n);
	for (long long i =0; i < n;i += 1){
		temp += (i+1)*a[i];
	}
	temp -= a[n-1];
	return temp;
}

int main(void){
	long long n;
	cin >> n;
	long long a[n];
	for (long long i =0;i < n; i += 1) cin >> a[i];
	cout << solve(a, n) << endl;

}