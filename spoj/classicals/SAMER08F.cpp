#include <iostream>

using namespace std;

int main(void){
	int n;
	while (1){
		cin >> n;
		if (n == 0) break;
		cout << (n*(2*n+1)*(n+1))/6 << endl;
	}
}