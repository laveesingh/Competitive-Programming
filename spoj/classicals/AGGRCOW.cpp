#include <cstdio>
#include <algorithm>

using namespace std;

bool fits(int a[], int n, int cur, int c){
	int cows = 1;
	int dist = 0;
	for (int i = 1; i < n; i += 1){
		dist += a[i]-a[i-1];
		if (dist >= cur){
			cows += 1;
			dist = 0;
			if (cows == c) return 1;
		}
	}
	return 0;
}

int solve(int a[], int n, int c){
	sort(a, a+n);
	int cur, cows, dist;
	int low = 0;
	int high = a[n-1];
	int max = -1;
	while (low < high){
		cur = low + (high-low)/2;
		if (fits(a, n, cur, c)){
			if (cur > max) max = cur;
			low = cur + 1;
		}else{
			high = cur;
		}
	}
	return max;
}

int main(void){
	int n, t, c;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &n, &c);
		int a[n];
		for (int i = 0; i < n; i += 1){
			scanf("%d",&a[i]);
		}
		printf("%d\n",solve(a, n, c));
	}
}