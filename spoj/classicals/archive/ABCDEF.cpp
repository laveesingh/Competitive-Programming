#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i += 1){
		cin >> a[i];
	}
	int left[n*n*n], right[n*n*n];
	int l = 0;
	for (int i = 0; i < n; i += 1){
		for (int j = 0; j < n; j +=1){
			for (int k = 0; k < n; k += 1){
				int cur = (a[i]*a[j] + a[k]);
				// cout << cur << " ";
				left[l++] = cur;
			}
		}
	}
	int limit1 = l;
	l=0;
	for (int i = 0; i < n; i += 1){
		if(a[i] != 0){
			for (int j = 0; j < n; j +=1){
				for (int k = 0; k < n; k += 1){
					int cur = (a[i]*(a[j] + a[k]));
					right[l++] =cur;
					// cout << cur << " ";
				}
			}
		}
	}
	int limit2 = l;
	int count = 0;
	sort(left, left+limit1);
	sort(right, right+limit2);
	// cout << "limit1 is " << limit1 << " and limit2 is  " << limit2 << endl;
	// for(int i = 0; i < limit1; i += 1){
	// 	cout << left[i] << " ";
	// }
	// cout << endl;
	// for (int j = 0; j < limit2; j += 1){
	// 	cout << right[j] << " ";
	// }
	// cout << endl;
	int i =0;
	while (i < limit1){
		int ind = lower_bound(right, right+limit2, left[i])-right;
		if(right[ind] == left[i]){
			int c1 = 1, c2 = 1;
			ind++;
			while(right[ind]==right[ind-1]){
				ind++;
				c2++;
			}
			i++;
			while(left[i] == left[i-1]){
				i++;
				c1++;
			}
			count += c1*c2;
		}else{
			i++;
			while(left[i]==left[i-1]){
				i++;
			}
		}
	}

	cout << count << endl;
}
