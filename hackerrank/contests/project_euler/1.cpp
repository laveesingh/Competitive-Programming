#include <iostream>

using namespace std;

long long solve(long long n){
	long long l3, l5, l15;
	long long s1, s2, s3;
	//n = 1;
	l3 = n/3;
	if (n%3 == 0) l3 -= 1;
	l5 = n/5;
	if (n%5 == 0) l5 -= 1;
	l15 = n/15;
	if (n%15 == 0) l15 -= 1;
	s1 = (l3*(l3+1))/2;
	s1 *= 3;
	s2 = (l5*(l5+1))/2;
	s2 *= 5;
	s3 = (l15*(l15+1))/2;
	s3 *= 15;
	return (s1+s2-s3);
}

int main(void){
	long long t, n;
	cin >> t;
	while (t--){
		cin >> n;
		cout << solve(n) << endl; 
	}
}