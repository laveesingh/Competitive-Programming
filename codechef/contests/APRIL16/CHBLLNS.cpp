#include <cstdio>

using namespace std;

long long min(long long a, long long b, long long c){
	if (a <= b && a <= c) return a;
	if (b <= c) return b;
	return c;
}

long long max(long long a, long long b, long long c){
	if (a >= b && a >= c) return a;
	if (b >= c) return b;
	return c;
}

long long mid(long long a, long long b, long long c){
	return (a+b+c)-(min(a,b,c)+max(a,b,c));
}

long long solve(long long r, long long g, long long b, long long k){
	long long ra, ga, ba;
	ra = min(r,g,b);
	ga = mid(r,g,b);
	ba = max(r,g,b);
	if (ra >= k-1) return 3*(k-1)+1;
	if (ga >= k-1) return 3*ra + 2*(k-ra-1) + 1;
	return ra+ga+k;
}
int main(void){
	long long r, g, b, k, t;
	scanf("%lld",&t);
	while (t--){
		scanf("%lld %lld %lld",&r,&g,&b);
		scanf("%lld",&k);
		printf("%lld\n",solve(r,g,b,k));
	}

}