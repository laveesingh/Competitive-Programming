#include <bits/stdc++.h>

using namespace std;

int main(void){
	int t, s, x;
	cin >> t >> s >> x;
	if (t == x){
		cout << "YES" << endl;
	} else{
		float n1 = (float)(x-t)/(float)s;
		float n2 = (float)(x-t-1)/(float)s;
		if((n1 == (int)n1 && n1 > 0)|| (n2 == (int)n2 && n2 > 0)){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}
}