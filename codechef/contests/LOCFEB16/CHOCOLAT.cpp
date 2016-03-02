#include <iostream>

using namespace std;

int main(void){
	int t, n, m;
	cin >> t ;
	while (t--){
		cin >> n >> m ;
		if (n == m) cout << "No Winner" << endl;
		else if (n > m) cout << "Bipin " << (n-m) << endl;
		else cout << "Balaji " << (m-n) << endl;
	}
}