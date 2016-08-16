/*input
3 2
*/

#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	float n, m;
	cin >> n >> m;
	float ans = n*ceil(double(m)/n) - m;
	cout << (int)ans << endl;	
}
