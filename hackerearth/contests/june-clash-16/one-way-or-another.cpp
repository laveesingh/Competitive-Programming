#include <iostream>
#include <cstdio>

using namespace std;

#define ll long long

int main(void){
	ll t;
	// cin >> t;
	scanf("%lld", &t);
	while(t--){
		ll n;
		// cin >> n;
		scanf("%lld", &n);
		ll r, c, x, ri, ci, xi;
		bool flag = false;
		// cin >> r >> c >> x;
		scanf("%lld %lld %lld", &r, &c, &x);
		while(--n){
			// cin >> ri >> ci >> xi;
			scanf("%lld %lld %lld", &ri, &ci, &xi);
			if((r+c)%2 == (ri+ci)%2){
				if(x%2 != xi%2){
					flag=true;
				}
			}else{
				if(x%2 == xi%2){
					flag = true;
				}
			}
		}
		if(flag == false){
			// cout << "Yes" << endl;
			printf("Yes\n" ) ;
		}else{
			// cout << "No" << endl;
			printf("No\n");
		}
	}
}