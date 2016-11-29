#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)
#define ll long long

const int N = 1001;
ll poly[N];

ll eval(ll n, ll x){
	ll ans = poly[0];
	for(ll i = 1; i <= n; i++)
		ans = (ans*x + poly[i]);
	return ans;
}

int main(void){
	ll n, x, q;
	int game = 1;
	while(1){
		ilong(n);
		if(n==-1) break;
		printf("Case %d:\n", game++);
		for(int i = 0; i <= n; i++) ilong(poly[i]);
		ilong(q);
		while(q--){
			ilong(x);
			olong(eval(n, x));
		}
	}
}

