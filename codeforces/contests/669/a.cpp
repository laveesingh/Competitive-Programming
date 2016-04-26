#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int x = (n/3) * 2;
	if (n%3 == 0){
		cout << x << endl;
	}else{
		cout << x+1 << endl;
	}
}