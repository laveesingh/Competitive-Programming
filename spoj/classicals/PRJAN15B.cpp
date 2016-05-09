#include <iostream>
#include <algorithm>

using namespace std;

#define ull unsigned long long

int interestings[24];

ull intrst(ull a, ull b){
	if (a > 23){
		return (b-a+1);
	}else if (b > 23){
		return intrst(a,23)+intrst(24,b);
	}else{
		int ans = 0;
		for (int i = a; i <= b; i += 1){
			if (interestings[i]) ans += 1;
		}
		return ans;
	}
}

int main(void){
	int t;
	cin >> t;
	ull a, b;
	int temp[] = {1, 2, 3, 5, 6, 7, 10, 11, 14, 15, 19, 23};
	fill_n(interestings, 24, 1);
	for (int i = 0; i < 12; i += 1){
		interestings[temp[i]] = 0;
	}
	while (t--){
		cin >> a >> b;
		cout << intrst(a, b) << endl;
	}
}