#include <iostream>

using namespace std;

int main(void){
	int a, b, c;
	while(1){
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;
		if (b/(float)a == c/(float)b){
			cout << "GP ";
			cout << c*(b/a) << endl;
		}else{
			cout << "AP ";
			cout << c+(b-a) << endl;;
		}
	}

}