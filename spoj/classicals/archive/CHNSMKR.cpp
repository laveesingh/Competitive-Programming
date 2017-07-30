#include <iostream>

using namespace std;

int main(void){
	int x, y, temp;
	while (1){
		cin >> x >> y;
		if (x == 0 && y == 0){
			break;
		}else{
			if (y/20 < x) cout << "Not Possible" << endl;
			else{
				for (int i = 25; i >= 20; i -= 1){
					if (y/i >= x){
						cout << y/i << " " << y%i << endl;
						break;
					}
				}
			}
		}
	}
}