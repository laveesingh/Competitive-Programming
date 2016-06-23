#include <cstdio>

using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll extended(ll a, ll b){
	ll s,ols,t,olt,r,olr;
	s = 0, ols = 1, t = 1, olt = 0, r = b, olr = a;
	while(r != 0){
		ll q = (olr / r);
		ll temp;
		temp  = olr;
		olr = r;
		r = temp-q*r;
		temp = ols;
		ols = s;
		s = temp-q*s;
		temp = olt;
		olt = t;
		t = temp-q*t;
	}
	return ols;
}

int main(void){
	ll a1, p, n, t;
	scanf("%lld", &t);
	while(t--){
		scanf("%lld %lld %lld", &a1, &p, &n);
		if(gcd(a1, p) != 1){
			printf("-1\n");
		}else{
			ll x = (extended(a1, p)+p)%p;
			ll sum = 0;
			sum += (a1*(n/2));
			sum += (x*(n/2));
			if(n%2) sum += a1;
			printf("%lld\n", sum);
		}
	}
}