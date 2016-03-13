#include <iostream>

using namespace std;

int main(void){
	int n ;
	cin >> n;
	int  x = 0;
	string stat;
	for (int i = 0; i < n; i += 1){
		cin >> stat;
		if (stat[0] == '-' || stat[2] == '-') x -= 1;
		else x += 1;
	}
	cout << x << endl;
}