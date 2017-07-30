#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)
#define ll long long

const int N = 1e5 + 1;
char str[N];

int main(void){
	int t, n, m, len;
	iint(t);
	while(t--){
		istr(str);
		len = strlen(str);
		iint(m);
		iint(n);
		int x = 0, cur = 0;
		for(int i = 0; i < len; i++){
			if(str[i] != 'a')
				cur = 0;
			else{
				cur += 1;
				if(cur == m){
					cur = 0;
					x += 1;
				}
			}
		}
		ll y = len;
		y -= (ll)m*x;
		y += (ll)n*x;
		printf("%lld %lld\n", min((ll)len, y), max((ll)len, y));
	}
}

