#include <bits/stdc++.h>

using namespace std;
#define ll long long 
int main(void){
ll a, b, c, n;
	cin >> n >> a >> b >> c;
	if((n+1)%4 == 0)
		cout << min(a, min(c+b, 3*c)) << endl;
	else if((n+2)%4 == 0)
		cout << min(2*a, min(b, 2*c)) << endl;
	else if((n+3)%4 == 0)
		cout << min(min(3*a, a+b), c) << endl;
	else 
		cout << 0 << endl;
}
