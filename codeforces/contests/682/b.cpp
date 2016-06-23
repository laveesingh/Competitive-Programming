#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0;i < n; i += 1){
		cin >> a[i];
	}
	vector<int> vec;
	sort(a, a+n);
	vec.push_back(1);
	for (int i = 1; i < n; i += 1){
		int bck = vec.back();
		if(a[i] > bck){
			vec.push_back(bck+1);
		}
	}
	cout << vec.size()+1 << endl;

}