#include <bits/stdc++.h>
using namespace std;

int main(void){
	string a;
	cin >> a;
	sort(a.rbegin(), a.rend());
	cout << a << endl;
	prev_permutation(a.begin(), a.end());
	cout << a << endl;
}
