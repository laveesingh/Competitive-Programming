#include <iostream>

using namespace std;

int main(void){
	int n, m;
	cin >> n >> m;
	if (n == 1) cout << 1 << endl;
	else if(n %2 == 1 && (n+1)/2 > m){
		cout << m+1 << endl;
	}else if(n%2 == 0 && n/2 >= m){
		cout << m + 1 << endl;
	}else{
		cout << m-1 << endl;
	}
}