#include <iostream>

using namespace std;

int main(void){
	int n, a, b;
	cin >> n;
	int max = 0;
	int cur = 0;
	while (n--){
		cin >> a >> b;
		cur -= a;
		cur += b;
		if (cur > max) max = cur;
	}
	cout << max << endl;
}