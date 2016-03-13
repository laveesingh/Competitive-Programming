#include <iostream>

using namespace std;

int rangeBitwiseAnd(int m, int n) {
    int x = 0;
    while ((m|x) < n)
       x = (x<<1) | 1;

    return m & ~x;
}

int main(void){
	int n, m;
	cin >> m >> n;
	cout << rangeBitwiseAnd(m, n) << endl;
}