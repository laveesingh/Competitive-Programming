#include <bits/stdc++.h>
using namespace std;

#define fill(a) memset(a, 0, sizeof(a))
#define ll long long

int main(void){
	int t;
	scanf("%d", &t);
	while(t--){
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%lld\n", (ll)a*b);
	}
}

