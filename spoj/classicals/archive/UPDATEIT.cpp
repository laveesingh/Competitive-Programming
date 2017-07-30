#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)

const int N = 10001;
int a[N];

int main(void){
	int t, n, u, x, y, val;
	iint(t);
	while(t--){
		iint(n); iint(u);
		memset(a, 0, sizeof(a));
		for(int i = 0; i < u; i += 1){
			iint(x); iint(y); iint(val);
			a[x] += val;
			if(y < n-1) a[y+1] -= val;
		}
		for(int i = 1; i < n; i++)
			a[i] += a[i-1];
		iint(u);
		for(int i = 0 ; i < u; i++){
			iint(x);
			oint(a[x]);
		}
	}
}

