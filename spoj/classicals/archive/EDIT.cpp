#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)

const int N = 1001;
char str[N];

inline int solve(int n){
	int cur = 0, cur2 = 0;
	for(int i = 0; i < n; i += 1){
		if(i%2){
			if(islower(str[i])) cur++;
			else cur2++;
		}else{
			if(islower(str[i])) cur2++;
			else cur++;
		}
	}
	return min(cur, cur2);
}

int main(void){
	int n;
	while(scanf("%s", str) == 1){
		n = strlen(str);
		oint(solve(n));
	}
}

