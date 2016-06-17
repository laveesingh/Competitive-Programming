#include <cstdio>
#include <algorithm>
#include <limits.h>
#include <iostream>

using namespace std;

#define ll long long

class Number{
public:
	ll num;
	char sym;

};

Number expr[50];

ll **mins, **maxs;

ll solve(ll i, ll j){
	if(maxs[i][j]) return maxs[i][j];
	if(i == j){
		// cout << "For i= " << i << " and j= " << j << " ans= " << expr[i].num << endl;
		return maxs[i][j] = expr[i].num;
	}
	ll temp = 0;
	for(ll k = i; k < j; k += 1){
		if(expr[k+1].sym=='+'){
			temp = max(temp, solve(i,k)+solve(k+1,j));
		}else{
			temp = max(temp, solve(i,k)*solve(k+1,j));
		}
	}
	// cout << "For i= " << i << " and j= " << j << " ans= " << temp << endl;
	return maxs[i][j] = temp;
}

// solve(ll x, ll y, ll n){
// 	ll dp[n+1][n+1];
// 	for ( i = 0; i <= n; i += 1){
// 		for (ll )
// 	}
// }

ll solve2(ll i, ll j){
	if(mins[i][j]) return mins[i][j];
	if(i == j){
		// cout << "For i= " << i << " and j= " << j << " ans= " << expr[i].num << endl;
		return mins[i][j] = expr[i].num;
	}
	ll temp = LLONG_MAX;
	for(ll k = i; k < j; k += 1){
		if(expr[k+1].sym=='+'){
			temp = min(temp, solve2(i,k)+solve2(k+1,j));
		}else{
			temp = min(temp, solve2(i,k)*solve2(k+1,j));
		}
	}
	// cout << "For i= " << i << " and j= " << j << " ans= " << temp << endl;
	return mins[i][j] = temp;
}

int main(void){
	ll t;
	scanf("%lld", &t);
	while(t--){
		char temp[100];
		scanf("%s", temp);
		ll i = 0, j = 0;
		expr[0].num = temp[0]-'0';
		expr[0].sym = '+';
		i+=1;j += 1;
		while(temp[i] != '\0'){
			expr[j].sym = temp[i];
			i += 1;
			expr[j].num = temp[i]-'0';
			i +=1;
			j += 1;
		}
		mins = new ll*[j];
		maxs = new ll*[j];
		for(ll k = 0; k < j; k += 1){
			mins[k] = new ll[j];
			maxs[k] = new ll[j];
			for (ll l = 0; l < j; l += 1){
				mins[k][l] = 0;
				maxs[k][l] = 0;
			}
		}
		printf("%lld %lld\n", solve(0,j-1), solve2(0,j-1));
	}
}