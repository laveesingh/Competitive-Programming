#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)

const int N = 1e5+1;
int a[N], temp[N], n;

inline int merge(int left, int mid, int right){
	int i = left, j = mid, k =left;
	int count = 0;
	while(i <= mid-1 and j <= right){
		if(a[i] <= a[j])
			temp[k++] = a[i++];
		else{
			temp[k++] = a[j++];
			count += mid - i;
		}
	}
	while(i <= mid-1) temp[k++] = a[i++];
	while(j <= right) temp[k++] = a[j++];
	for(int i = left; i <= right; i++)
		a[i] = temp[i];
	return count;
}

int invCount(int left, int right){
	int count = 0;
	if(left < right){
		int mid = (left + right)/2;
		count += invCount(left, mid);
		count += invCount(mid+1, right);
		count += merge(left, mid+1, right);
	}
	return count;
}



int main(void){
	int t;
	iint(t);
	while(t--){
		iint(n);
		for(int i = 0; i < n; i++) iint(a[i]);
		oint(invCount(0, n-1));
		//for(int i = 0; i < n; i ++) oint(a[i]);
	}
}

