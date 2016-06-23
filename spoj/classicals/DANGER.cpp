#include <iostream>
#include <cmath>

using namespace std;

#define powi(n, p) (int)pow(n,p)

int des2(int n){
	int cnt = 0;
	while(n){
		cnt++;
		n >>= 1;
	}
	return (1<<(cnt-1));
}

int validator(string a){
	int n = (a[0]-'0')*10+(a[1]-'0');
	n = n*pow(10,a[3]-'0');
	// cout << "Number is " << n << endl;
	return n;
}

int main(void){
	string a;
	cin >> a;
	int n = validator(a);
	while(n){
		int x = des2(n);
		if(n%2){
			if(n==1){
				cout << 1 << endl;
			}else{
				int t = (n-x)/2;
				cout << (4*t+3) << endl;
			}
		}else{
			int t = (n-x)/2;
			cout << (4*t+1) << endl;
		}
		cin >> a;
		n = validator(a);
	}
}