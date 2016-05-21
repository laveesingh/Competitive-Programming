#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	if (n <= 9){
		cout << n << endl;
	}else if(n == 10){
		cout << 1 << endl;
	}else if(n == 11){
		cout << 0 << endl;
	}else{
		n -= 11;
		if (n%20 == 0){
			cout << 0 << endl;
		}else if(n % 10 == 0){
			cout << 5 << endl;
		}else{
			cout << (n+1)/20 + 1 << endl;
		}
	}
}