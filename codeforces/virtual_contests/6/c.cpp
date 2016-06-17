#include <iostream>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int start = 0, end = n-1, alice = 0, bob = 0, A=0, B=0;
	while (start < end){
		if(alice <= bob){
			alice += a[start];
			start += 1;
			A += 1;
		}
		if(bob < alice){
			bob += a[end];
			end -= 1;
			B += 1;
		}
	}
	if(start == end && A+B < n){
		if(alice <= bob){
			A += 1;
		}else{
			B += 1;
		}
	}
	cout << A << " " << B << endl;
}