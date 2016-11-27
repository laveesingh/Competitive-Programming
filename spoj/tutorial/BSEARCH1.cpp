#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)

const int N = 100001;
int a[N];

int bsearch(int i, int j, int x){
	if(i == j){
		if(a[i] == x) return i;
		return -1;
	}
	int mid = (i+j)/2;
	if(a[mid] >= x) return bsearch(i, mid, x);
	return bsearch(mid+1, j, x);
}

int main(void){
	int n, q, x;
	iint(n);
	iint(q);
	for(int i = 0; i <n; i++) iint(a[i]);
	for(int i = 0; i < q; i++){
		iint(x);
		oint(bsearch(0, n-1, x));
	}

}

