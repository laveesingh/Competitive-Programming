#include <iostream>
#include <math.h>

using namespace std;


int main(void){

		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i = 0; i < n ;i += 1) cin >> a[i];
		if (k == 1 || k == 2){
			cout << a[0] << endl;
		}else{

			// int ks = sqrt(k);
			// int lim = (ks*(ks+1))/2;
			// int kfinal = k-lim;
			// int f;
			// while(1){
			// 	if(kfinal <= ks){
			// 		cout << a[kfinal-1] << endl;
			// 	}else{

			// 	}
			// }
			int f = 0;
			while (1){
				k -= f;
				f += 1;
				if (k <= f) {
					cout << a[k-1] << endl;
					break;
				}
			}
		}

}