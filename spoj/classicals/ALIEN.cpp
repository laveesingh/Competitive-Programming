#include <cstdio>
#include <iostream>

using namespace std;

void solve(int a[], int n, int max){
	int csum = 0, msum = 0, i = 0, j = 0, count = 0;
	while ( i < n){
		if(i-j == count && msum > csum){
			msum = csum;
		}
		if (i < n){
			csum += a[i];
			i += 1;
		}
		// cout << "BEGIN: i: " << i << " j: " << j << " csum: " << csum << " msum: " << msum << " count: " << count << endl;
		if (csum <= max){
			if (i-j > count){
				count = i-j;
				msum = csum;
			}
			if(i-j == count && msum > csum){
				msum = csum;
			}
		}else{
			csum -= a[j];
			j += 1;
		}
		// cout << "END: i: " << i << " j: " << j << " msum: " << msum << " count: " << count << endl;

	}
	while(j < n){
		if (csum <= max){
			if(i-j > count){
				count = i-j;
				msum = csum;
			}
			if (i-j==count && msum > csum){
				msum = csum;
			}
		}
		j += 1;
		csum -= a[j];
		// cout << "END: i: " << i << " j: " << j << " msum: " << msum << " count: " << count << endl;

	}
	printf("%d %d\n", msum, count);

}

int main(void){
	int t, n, max;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &max);
		int a[n];
		for (int i = 0; i < n; i += 1){
			scanf("%d", &a[i]);
		}
		solve(a, n, max);
	}
}