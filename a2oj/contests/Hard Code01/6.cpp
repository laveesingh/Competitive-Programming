#include <iostream>

using namespace std;

int main(void){
	string a, b;
	cin >> a;
	cin >> b;
	string c = "";
	for (int i = 0; i < a.length(); i += 1){
		if (a[i] == b[i]){
			c.push_back('0');
		}else{
			c.push_back('1');
		}
	}
	cout << c << endl;
}