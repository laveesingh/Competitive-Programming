#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)

const int N  = 1e5 + 1;
char str[N];

int main(void){
	int t;
	iint(t);
	while(t--){
		istr(str);
		int n = strlen(str);
		int ans = 0;
		for(int i = 1; i < n; i += 1)
			if(str[i] == '>' and str[i-1] == '<') ans++;
		oint(ans);
	}

}

