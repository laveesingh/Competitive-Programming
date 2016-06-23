#include <cstdio>
#include <algorithm>

using namespace std;

int abs(int a){
	if(a < 0) return -a;
	return a;
}

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		int a[n];
		for (int i = 0; i < n;i += 1){
			scanf("%d", &a[i]);

		}
		int m;
		scanf("%d", &m);
		int b[m];
		for (int i = 0 ; i < m; i += 1){
			scanf("%d", &b[i]);
		}


		/* NlogM solution */
		sort(a, a+n);
		sort(b, b+m);
		// int diff = abs(a[0]-b[0]);
		// for (int i = 0; i < n; i += 1){
		// 	int low = *lower_bound(b, b+m, a[i]);
		// 	int high = *upper_bound(b, b+m, a[i]);
		// 	diff = min(diff, abs(low-a[i]));
		// 	diff = min(diff, abs(high-a[i]));
		// }
		// printf("%d\n", diff);


		/* NxM solution */
		// int diff = abs(a[0]-b[0]);
		// for (int i = 0; i < n; i += 1){
		// 	for (int j = 0; j < m; j += 1){
		// 		diff = min(diff, abs(a[i]-b[j]));
		// 	}
		// }
		// printf("%d\n", diff);

		/* Linear time solution */
		int diff = abs(a[0]-b[0]);
		int i = 0;
		int j = 0;
		while (i < n && j <m){
			diff = min(diff,abs(a[i]-b[j]));
			if(a[i] < b[j]){
				i++;
			}	else{
				j++;
			}
		}
		printf("%d\n", diff);
	}
}