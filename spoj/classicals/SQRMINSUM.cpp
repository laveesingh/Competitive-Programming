#include <iostream>
#include <set>

using namespace std;

int main(void){
	int t, n, k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		int arr[n];
		for (int i = 1; i <= n; i += 1){
			arr[i-1] = i;
		}
		multiset<int> a(arr, arr+n);
		multiset<int>::iterator it, it1;
		while(k--){
			it = a.end();
			it1 = it;
			it1--;
			int cur = *it1;
			a.erase(it1, it);
			a.insert((int))
		}
	}
}