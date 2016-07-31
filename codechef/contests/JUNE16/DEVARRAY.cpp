#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n, q, qi;
	cin >> n >> q;
	int a[n];
	for (int i = 0; i < n;i += 1){
		cin >> a[i];
	}
	int min, max;
	min = *min_element(a, a+n);
	max = *max_element(a, a+n);
	for (int i = 0; i < q; i += 1){
		cin >> qi;
		if (qi >= min && qi <= max){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
}