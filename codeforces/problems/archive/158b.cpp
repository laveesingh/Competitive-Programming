#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	int total,cnt = 0;
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	
	int b[n];
	for (int i = 0; i < n; i += 1){
		b[i] = 0;
	}
	
	sort(a, a+n);
	
	for (int i = n-1; i >= 0; i -= 1){
		if (b[i] == 0){
			//cout << endl << "Here goes i " << i << endl;
			cnt += 1;
			b[i] = 1;
			total = a[i];
			//cout << "Total is "<< total << " now is going inside iteration : " ;
			for (int j = 0; j < i; j += 1){
				if (b[j] == 0){
					total += a[j];
					//cout << j << ":" <<total;
					if (total <= 4){
						//cout << j << "should change";
						b[j] = 1;
					}else{
						break;
					}
				}
			}
		}
	}
	//for (int i = 0; i < n; i += 1) cout << b[i] << " ";
	
	cout << cnt << endl;

}