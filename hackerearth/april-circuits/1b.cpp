#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, q, i,gain;
	// cin >> n >> q;
	// long long arr[n] = {0};
	// for (int part = 0; part < n; part += 1){
	// 	cin >> i >> gain;
	// 	arr[i-1] += gain;
	// 	int newi = lower_bound
	// }
	vector<int>::iterator low, high;
	vector <int> a;
	a.push_back(2);
	a.push_back(3);
	a.push_back(5);
	a.push_back(8);
	a.push_back(13);
	low = lower_bound(a.begin(), a.end(), );
	cout << (low-a.begin()) << endl;
}