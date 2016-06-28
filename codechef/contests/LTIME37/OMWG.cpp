#include <iostream>

using namespace std;

int main(void){
	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;
		cout << ((n+m-2) + 2*(n-1)*(m-1)) << endl;
	}
}