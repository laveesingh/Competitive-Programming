#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)

int solve(int n, int d){
	if(n == 1) return 1;
	return (solve(n-1, d) + d-1) % n + 1;
}

int main(void){
	int n, d;
	while(1){
		iint(n);
		iint(d);
		if(n == 0 && d == 0) break;
		printf("%d %d ", n, d);
		oint(solve(n, d));
	}
}

