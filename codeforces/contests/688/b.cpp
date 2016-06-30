#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	string a;
	cin >> a;
	cout << a;
	reverse(a.begin(), a.end());
	cout << a << endl;
}