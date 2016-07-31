#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	if(m*a <= b){
		cout << n*a << endl;
	}else{
		cout << ((n/m)*b + min(b, (n%m)*a)) << endl;
	}
}