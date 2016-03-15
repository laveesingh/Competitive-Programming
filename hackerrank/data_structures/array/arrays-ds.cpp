#include <iostream>
#include <array>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	for (int i = n-1; i > -1; i -= 1){
		cout << a[i] << " ";
	}
	cout << endl;
}