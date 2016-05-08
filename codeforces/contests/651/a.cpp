#include <iostream>

using namespace std;

int main(void){
	int a, b;
	cin >> a >> b;
	int i = 0;
	while (a > 0 && b > 0){
		if (a < 2 && b < 2){
			break;
		}else{
			if (a < b){
				a += 1;
				b -= 2;
			}else{
				a -= 2;
				b += 1;
			}
		}
		i += 1;
	}
	cout << i << endl;
}