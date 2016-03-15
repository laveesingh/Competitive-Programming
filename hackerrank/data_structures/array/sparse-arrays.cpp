#include <iostream>
#include <map>

using namespace std;

int main(void){
	int n;
	cin >> n;
	map<string, int> a;
	string temp;
	for (int i = 0; i < n; i += 1){
		cin >> temp;
		a[temp] += 1;
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; i += 1){
		cin >> temp;
		cout << a[temp] << endl;
	}
}