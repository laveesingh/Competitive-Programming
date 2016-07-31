#include <iostream>

using namespace std;

int main(void){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i +=1){
		cin >> a[i];
	}
	k -= 1;
	int i = k, j = k, count = 0;
	while (i >= 0 || j < n){
		if(i>= 0 && j < n){
			if(a[i] == a[j] && a[i] == 1){
				count += (i == j ? 1 : 2);
			}
			i -= 1;
			j += 1;
		}else if(i >= 0){
			if(a[i] == 1){
				count += 1;
			}
			i -= 1;
		}else if(j < n){
			if(a[j] == 1){
				count += 1;
			}
			j += 1;
		}
	}
	cout << count << endl;
}