#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int arr, b, c, d;
	cin >> arr >> b >> c >> d;
	int a[] = {arr, b, c, d};
	sort(a, a+4);
	if(a[3] < (a[2]+a[1]) || a[2] < (a[0]+a[1])){
		cout << "TRIANGLE" << endl;
	}else if(a[3] == (a[2]+a[1]) || a[2] == (a[1]+a[0])){
		cout << "SEGMENT" << endl;
	}else{
		cout << "IMPOSSIBLE" << endl;
	}
}