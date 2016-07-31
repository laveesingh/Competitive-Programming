#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int arr[] = {a, b, c, d, e};
	sort(arr, arr+5);
	int sum = a+b+c+d+e;
	int tod = 0;
	int n = 5;
	for (int i = n-1; i > 0; i -= 1){
		if (arr[i] == arr[i-1]){
			if(i-2 >= 0 && arr[i-1] == arr[i-2]){
				tod = max(tod, 3*arr[i]);
			}else{
				// tod = 2*a[i];
				tod = max(tod, 2*arr[i]);
			}
		}
	}
	cout << sum-tod << endl;
}