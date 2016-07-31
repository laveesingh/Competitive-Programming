#include <cstdio>

using namespace std;

#define ll long long

int main(void){
	ll t;
	scanf("%lld", &t);
	while(t--){
		ll r, c, m, k, j;
		scanf("%lld %lld %lld %lld %lld", &r, &c, &m, &k, &j);
		if((r*c) == (m+k+j)){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
}