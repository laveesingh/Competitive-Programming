#include <iostream>
#include <vector>

using namespace std;


int main(void){
	int q, x, y;
	cin >> q;
	int count = 0;
	for (int i = 0; i < q; i += 1){
		x = 0;
		for (int j = 0; j<3; j += 1){
			cin >> y;
			if (y == 1) x += 1;
		}
		if (x >= 2) count += 1;
	}
	cout << count << endl;
	
}