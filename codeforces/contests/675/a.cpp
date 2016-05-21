#include <iostream>

using namespace std;

int main(void){
	int a, b, c;
	cin >> a >> b >> c;
	int x = a+c;
	if (a == b) cout << "YES" << endl;
	else if(x > a && b > a){
		// cout << "b-a: " << b-a << " c " << c << endl;

		if ((b-a) % c == 0){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}else if(x < a && b < a){
		if ((b-a) %c == 0){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}else{
		cout << "NO" << endl;
	}
}