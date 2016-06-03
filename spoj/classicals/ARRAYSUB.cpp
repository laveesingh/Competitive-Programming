#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int k;
	cin >> k;
	multiset<int> myset(a,a+k);
	cout << *myset.rbegin();
	multiset<int>::iterator it1, it2;
	for(int i = 0; i < n-k; i += 1){
		it1 = myset.find(a[i]);
		it2 = it1;
		it2++;
		myset.erase(it1,it2);
		myset.insert(a[i+k]);
		cout <<  " " << *myset.rbegin() ;
	}
	cout << endl;
}