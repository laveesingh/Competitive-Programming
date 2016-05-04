#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
	int a[] = {10,20,30,5,15};
	vector<int> v(a,a+5);
	make_heap(v.begin(), v.end());
	for (int s: v) cout << s << " ";
	cout << endl;
	pop_heap(v.begin(), v.end());
	for (int s: v) cout << s << " ";
	cout << endl;
}