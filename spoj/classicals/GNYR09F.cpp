#include <bits/stdc++.h>
using namespace std;

#define iint(a) scanf("%d", &a)
#define ilong(a) scanf("%lld", &a)
#define oint(a) printf("%d\n", a)
#define olong(a) printf("%lld\n", a)
#define istr(a) scanf("%s", a)
#define ostr(a) printf("%s\n",a)

const int N = 101;
int n, k;
int dp[N][2], store[N][N][2];

inline void Set(){
	dp[1][0] = 2;
	dp[1][1] = 1;
	for(int i = 2; i < N; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}
}

int main(void){
	int t,game;
	Set();
	iint(t);
	store[0][0][0] = 0;
	store[0][0][1] = 0;
	for(int i = 1; i < N; i++){
		store[i][0][0] = dp[i][0];
		store[i][0][1] = dp[i-1][0];
	}
	for(int i = 1; i < N; i++){
		for(int j = 1; j < N; j++){
			if(i < j){
				store[i][j][0] = 0;
				store[i][j][1] = 0;
			}else	if(i-1 == j){
				store[i][j][0] = 1;
				store[i][j][1] = 1;
			}else{
				store[i][j][0] = store[i-1][j][0] + store[i-1][j][1];
				store[i][j][1] = i==j ? 1 : store[i-1][j-1][1]+store[i-1][j][0];
			}
		}
	}
	while(t--){
		iint(game);
		iint(n);
		iint(k);
		printf("%d ",game);
		oint(store[n][k][0]);
	}
}

