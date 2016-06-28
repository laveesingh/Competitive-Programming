#include <iostream>

using namespace std;


int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i< n ; i += 1){
		cin >> a[i];
	}
	int mindist = 1000000;
	for (int i = 0; i< n-1; i += 1){
		for (int j = i+1; j < n; j += 1){
			if(a[i]==a[j]){
				if(j-i < mindist){
					mindist = j-i;
				}
			}
		}
	}
	if (mindist > n){
		cout << -1 << endl;
	}else{
		cout << mindist << endl;
	}
}