#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
#define MAX 10000001

bool iss(int x){
	float s = sqrt(x);
	return (s-(int)s == 0);
}

bool ispal(int x){
	return iss(5*x*x-4) || iss(5*x*x+4);
}

int prec[MAX];

int main(void){
	

	int a = 0 ,b = 1;
	for (int i = 0; i < MAX; i += 1){
		if (i > b){
			if(b+a > b){
				b = b+a;
				a = b-a;
			}else{
				b = 2*b;
				a = b/2;
			}
		}
		if (b-i <= i-a){
			prec[i] = b;
		}else{
			prec[i] = a;
		}
	}
	
	while (1){
		int n;
		scanf("%d", &n);
		if (n == 0) break;
		int arr[n];
		for (int i = 0 ;i < n; i += 1){
			scanf("%d", &arr[i]);
		}
		int b[n];
		for (int i = 0;  i < n; i += 1){
			b[i] = prec[arr[i]];
		}
		sort(b, b+n);
		for (int i = 0; i < n; i+= 1){
			cout << b[i] << " " ;
		}

		cout << endl;
	}
	// cout << ispal(8) << endl;
}