#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	for (int i = 0; i < n; i += 1){
		int temp;
		cin >> temp;
		cout << temp + 1 << endl;
	}
}