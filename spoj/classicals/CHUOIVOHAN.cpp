#include <iostream>

using namespace std;

int main(void){
	long long a, b, c;
	cin >> a >> b >> c;
	if (b > a && a+c < a){
		cout << "NO" << endl;
	}else if(b < a && a+c > a){
		cout << "NO" << endl;
	}else if(c == 0){
		if(a == b) {
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}else{
		if ((b-a)%c == 0 || (a-b)%c == 0){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}