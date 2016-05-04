#include <iostream>

using namespace std;

int main(void){
	int t, x, y;
	cin >> t;
	while (t--){
		cin >> x>> y;
		if (x%2 == 0 && (x == y || x == y+2)){
			cout << x+y << endl;
		}else if(x%2 && (x == y || x == y+2)){
			cout << x+y-1 << endl;
		}else{
			cout << "No Number" << endl;
		}
	}

}