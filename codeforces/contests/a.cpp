#include <iostream>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int n, R, r;
	cin >> n >> R >> r;
	float pi = 3.14;
	float space = 2*pi*(R-r);
	float require = 2*n*r;
	if (n == 1 and r <= R){
		cout << "YES" << endl;
	}else if(space >= require){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
}