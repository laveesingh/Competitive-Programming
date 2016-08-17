#include <bits/stdc++.h>

using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	int a[] = {2, 3, 4, 4, 8};
	auto it = equal_range(a, a+4, 5);
	cout << (it.second - it.first) << endl;
}
