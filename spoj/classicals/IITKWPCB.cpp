#include <iostream>

using namespace std;



long long solve(long long n){
	if (n%2)return n/2;
	else{
		long long ans = n/2 - 1;
		return ans%2 ? ans : ans-1;
	}
}

int main(void){
	long long t,n;
	cin >> t;
	while (t--){
		cin >> n;
		cout << solve(n) << endl;
	}
}