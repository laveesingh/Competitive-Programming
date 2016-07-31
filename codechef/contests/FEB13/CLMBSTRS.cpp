#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000007;
int fib[1000001];

void fibo(){
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 2;
	for(int i = 3; i < 1000001; i += 1){
		fib[i] = (fib[i-1]+fib[i-2])%mod;;
	}
}
int main(void){
	fibo();
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n, g;
		cin >> n >> g;
		if(__builtin_popcount(fib[n]) == g){
			cout << "CORRECT" << endl;
		} else {
			cout << "INCORRECT" << endl;
		}
	}
}