#include <iostream>

using namespace std;

int main(void){
	int n;
	string temp;
	int tf=0, of=0, h=0, rof=0;
	int ans = 1;
	cin >> n;
	
	for (int i = 0; i < n; i += 1){
		cin >> temp;
		if (temp[2] == '2') h += 1;
		else if(temp[0] == '3') tf += 1;
		else of += 1;
	}

	ans += (h+1)/2;
	if (h%2) rof = 2;

	ans += tf;
	rof += tf;
	of -= rof;
	if (of > 0)
		ans += (of+3)/4;
	
	cout << ans << endl;
}