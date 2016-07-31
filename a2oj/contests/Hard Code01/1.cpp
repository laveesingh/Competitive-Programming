#include <iostream>

using namespace std;

int min(int a, int b){
	if(a < b) return a;
	return b;
}

int main(void){
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int totaldrink = k*l;
	cout << min(totaldrink/nl, min(p/np, c*d))/n << endl;
}